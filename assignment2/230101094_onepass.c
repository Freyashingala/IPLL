#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MEM 0x5000  // Simulated Memory Size (20KB)

// --- DATA STRUCTURES ---

// 1. Memory to store Object Code (Simulates Load-and-Go)
unsigned char MEMORY[MAX_MEM]; 
int START_ADDR = 0;
int PROG_LEN = 0;

// 2. Opcode Table (with your custom instructions)
typedef struct {
    char mnemonic[10];
    unsigned char opcode;
} Opcode;

Opcode OPTAB[] = {
    {"LDA", 0x00}, {"LDX", 0x04}, {"LDL", 0x08}, {"STA", 0x0C},
    {"STX", 0x10}, {"STL", 0x14}, {"LDCH", 0x50}, {"STCH", 0x54},
    {"ADD", 0x18}, {"SUB", 0x1C}, {"MUL", 0x20}, {"DIV", 0x24},
    {"COMP", 0x28}, {"J", 0x3C}, {"JLT", 0x38}, {"JEQ", 0x30},
    {"JGT", 0x34}, {"JSUB", 0x48}, {"RSUB", 0x4C}, {"TIX", 0x2C},
    {"TD", 0xE0}, {"RD", 0xD8}, {"WD", 0xDC},
    // Custom Opcodes
    {"MOV", 0xA0}, {"JLE", 0x32}, {"PUSH", 0xA4},
    {"POP", 0xA8}, {"JGE", 0x36}, {"JNE", 0x3A}
};

// 3. Linked List for Forward References (The "Fix-up List")
struct FixupNode {
    int address_to_patch; // Where in MEMORY needs the address
    struct FixupNode *next;
};

// 4. Symbol Table
struct Symbol {
    char name[10];
    int address;        // Value of the symbol
    int is_defined;     // 0 = Forward Ref (Unknown), 1 = Defined
    struct FixupNode *fixups; // List of addresses waiting for this symbol
} SYMTAB[100];

int sym_count = 0;

// --- HELPER FUNCTIONS ---

int get_opcode(char *mnemonic) {
    int size = sizeof(OPTAB) / sizeof(Opcode);
    for (int i = 0; i < size; i++) {
        if (strcmp(OPTAB[i].mnemonic, mnemonic) == 0) return OPTAB[i].opcode;
    }
    return -1;
}

// Find symbol index, or create new undefined one if not found
int get_or_create_symbol(char *label) {
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(SYMTAB[i].name, label) == 0) return i;
    }
    // Create new undefined symbol
    strcpy(SYMTAB[sym_count].name, label);
    SYMTAB[sym_count].address = 0;
    SYMTAB[sym_count].is_defined = 0;
    SYMTAB[sym_count].fixups = NULL;
    return sym_count++;
}

// Add a location to the fix-up list
void add_fixup(int sym_index, int loc_to_patch) {
    struct FixupNode *newNode = malloc(sizeof(struct FixupNode));
    newNode->address_to_patch = loc_to_patch;
    newNode->next = SYMTAB[sym_index].fixups;
    SYMTAB[sym_index].fixups = newNode;
}

// Back-patching: Resolve a list of fixups
void resolve_fixups(int sym_index) {
    struct FixupNode *current = SYMTAB[sym_index].fixups;
    int value = SYMTAB[sym_index].address;
    
    while (current != NULL) {
        // Patch MEMORY: Write the address into the 2 bytes at the location
        // Note: Target addresses are 16-bit (2 bytes) in standard SIC
        int mem_idx = current->address_to_patch - START_ADDR;
        
        // Handle Indexing Bit (if stored previously)
        int existing_val = (MEMORY[mem_idx] << 8) | MEMORY[mem_idx+1];
        if (existing_val & 0x8000) value += 0x8000; // Preserve X bit

        MEMORY[mem_idx] = (value >> 8) & 0xFF;   // High Byte
        MEMORY[mem_idx+1] = value & 0xFF;        // Low Byte
        
        struct FixupNode *temp = current;
        current = current->next;
        free(temp);
    }
    SYMTAB[sym_index].fixups = NULL; // Clear list
}

// --- ONE PASS ALGORITHM ---
void one_pass_assemble() {
    FILE *fp_in = fopen("sample_input.txt", "r");
    FILE *fp_obj = fopen("output_onepass.txt", "w");
    
    if (!fp_in || !fp_obj) { printf("Error: Missing input.txt\n"); return; }
    
    char line[100], label[20], mnemonic[20], operand[20];
    int locctr = 0;
    
    // Initialize Memory to 0
    memset(MEMORY, 0, MAX_MEM);

    // 1. Read First Line (Header)
    fgets(line, 100, fp_in);
    sscanf(line, "%s %s %s", label, mnemonic, operand);
    if (strcmp(mnemonic, "START") == 0) {
        START_ADDR = (int)strtol(operand, NULL, 16);
        locctr = START_ADDR;
    }

    // 2. Main Loop
    while (fgets(line, 100, fp_in)) {
        strcpy(label, ""); strcpy(mnemonic, ""); strcpy(operand, "");
        char w1[20], w2[20], w3[20];
        int count = sscanf(line, "%s %s %s", w1, w2, w3);

        if (count == 3) { strcpy(label, w1); strcpy(mnemonic, w2); strcpy(operand, w3); }
        else if (count == 2) {
             if (get_opcode(w1) != -1 || strcmp(w1, "END")==0 || strcmp(w1, "RET")==0) {
                 strcpy(mnemonic, w1); strcpy(operand, w2);
             } else { strcpy(label, w1); strcpy(mnemonic, w2); }
        } else { strcpy(mnemonic, w1); }
        
        if (strcmp(mnemonic, "END") == 0) break;
        if (line[0] == '.') continue;

        // --- DEFINE SYMBOL (Label Handling) ---
        if (strlen(label) > 0) {
            int sym_idx = get_or_create_symbol(label);
            if (SYMTAB[sym_idx].is_defined) {
                printf("Error: Duplicate Symbol %s\n", label);
            } else {
                SYMTAB[sym_idx].address = locctr;
                SYMTAB[sym_idx].is_defined = 1;
                resolve_fixups(sym_idx); // BACK-PATCHING HAPPENS HERE
            }
        }

        // --- ASSEMBLE INSTRUCTION ---
        int opcode_val = get_opcode(mnemonic);
        if (opcode_val != -1) {
            // Instruction format: [Opcode (8)] [Address (16)]
            int mem_idx = locctr - START_ADDR;
            MEMORY[mem_idx] = opcode_val;

            if (strlen(operand) > 0) {
                int is_indexed = 0;
                char sym_name[20];
                strcpy(sym_name, operand);
                
                // Handle Indexing
                if (strlen(sym_name) > 2 && sym_name[strlen(sym_name)-2] == ',') {
                    sym_name[strlen(sym_name)-2] = '\0';
                    is_indexed = 1;
                }

                int sym_idx = get_or_create_symbol(sym_name);
                
                if (SYMTAB[sym_idx].is_defined) {
                    // Symbol known: Use value immediately
                    int target = SYMTAB[sym_idx].address;
                    if (is_indexed) target += 0x8000;
                    MEMORY[mem_idx+1] = (target >> 8) & 0xFF;
                    MEMORY[mem_idx+2] = target & 0xFF;
                } else {
                    // Symbol Unknown: Forward Reference!
                    // Add this location (locctr + 1) to Fix-up List
                    add_fixup(sym_idx, locctr + 1);
                    
                    // Store placeholder (preserve X bit if needed)
                    int placeholder = is_indexed ? 0x8000 : 0x0000;
                    MEMORY[mem_idx+1] = (placeholder >> 8) & 0xFF;
                    MEMORY[mem_idx+2] = placeholder & 0xFF;
                }
            } else {
                // No operand (e.g., RSUB/RET)
                MEMORY[mem_idx+1] = 0;
                MEMORY[mem_idx+2] = 0;
            }
            locctr += 3;
        }
        else if (strcmp(mnemonic, "BYTE") == 0) {
            int mem_idx = locctr - START_ADDR;
            if (operand[0] == 'C') {
                for (int i=2; i<strlen(operand)-1; i++) {
                    MEMORY[mem_idx++] = operand[i];
                    locctr++;
                }
            } else if (operand[0] == 'X') {
                // Parse hex string "X'F1'" -> 0xF1
                char hex[3] = {0};
                for (int i=2; i<strlen(operand)-1; i+=2) {
                    strncpy(hex, &operand[i], 2);
                    MEMORY[mem_idx++] = (unsigned char)strtol(hex, NULL, 16);
                    locctr++;
                }
            }
        }
        else if (strcmp(mnemonic, "WORD") == 0) {
            int mem_idx = locctr - START_ADDR;
            int val = atoi(operand);
            MEMORY[mem_idx]   = (val >> 16) & 0xFF;
            MEMORY[mem_idx+1] = (val >> 8) & 0xFF;
            MEMORY[mem_idx+2] = val & 0xFF;
            locctr += 3;
        }
        else if (strcmp(mnemonic, "RESW") == 0) {
            locctr += 3 * atoi(operand);
        }
        else if (strcmp(mnemonic, "RESB") == 0) {
            locctr += atoi(operand);
        }
    }
    
    PROG_LEN = locctr - START_ADDR;

    // --- WRITE OBJECT FILE FROM MEMORY ---
    // Header
    fprintf(fp_obj, "H%-6s%06X%06X\n", label, START_ADDR, PROG_LEN);

    // Text Records
    int text_start = START_ADDR;
    int i = 0;
    while (i < PROG_LEN) {
        // Find next block of data (skip empty RESW/RESB areas if we want, 
        // but for simplicity, we often dump continuous code blocks)
        
        // Simple Logic: Dump 30 bytes at a time, skip "empty" holes if necessary
        // In "Load-and-Go", RESW areas are just skipped addresses.
        // We check if we are in a RESW/RESB block by comparing indexes to known holes.
        // For this specific logic, we'll just check for 0s? No, RESW might be initialized 0.
        // Correct way: Only write if we actually generated code there.
        // Since we didn't track "generated vs reserved" in the array, 
        // we will use the logic: "If block is huge zeros, it might be RESB". 
        // BUT, for the COPY program, we can simply dump non-zero blocks 
        // or just standard sequential blocks.
        
        // Let's stick to standard 30-byte blocks logic used in Pass 2.
        // NOTE: Since RESW/RESB advances locctr but doesn't write to MEMORY, 
        // those parts of MEMORY are 0.
        // Real assemblers know where RESW starts/ends. 
        // For this specific code, assume data is continuous for simplicity 
        // OR iterate strictly based on valid ranges if we tracked them.
        
        // BETTER APPROACH FOR OUTPUT:
        // Just write sequential 30-byte chunks.
        // If we hit a large block of zeros (BUFFER), it writes zeros. 
        // Standard assemblers break Text records for RESW.
        // For this assignment, writing continuous text records is usually acceptable.
        
        char text_rec[70] = "";
        int len = 0;
        int start_curr = START_ADDR + i;
        
        // Check if we are potentially in a RESW area (heuristic or check map)
        // Since we lost the "map" of RESW in this simple array implementation,
        // we will just output all bytes. The output will be slightly larger 
        // (including 00s for BUFFER) but correct.
        
        for (int j=0; j<30 && (i+j) < PROG_LEN; j++) {
            sprintf(text_rec + strlen(text_rec), "%02X", MEMORY[i+j]);
            len++;
        }
        
        if (len > 0) {
            fprintf(fp_obj, "T%06X%02X%s\n", start_curr, len, text_rec);
        }
        i += len;
    }

    fprintf(fp_obj, "E%06X\n", START_ADDR);
    
    printf("One-Pass Assembly Complete. Output: output_onepass.txt\n");
    fclose(fp_in);
    fclose(fp_obj);
}

int main() {
    one_pass_assemble();
    return 0;
}