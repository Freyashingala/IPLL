#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJ_CODE 70

typedef struct {
    char mnemonic[10];
    char opcode[10];
} Opcode;

Opcode OPTAB[] = {
    {"LDA", "00"},
    {"LDX", "04"},
    {"LDL", "08"},
    {"STA", "0C"},
    {"STX", "10"},
    {"STL", "14"},
    {"LDCH", "50"},
    {"STCH", "54"},
    {"ADD", "18"},
    {"SUB", "1C"},
    {"MUL", "20"},
    {"DIV", "24"},
    {"COMP", "28"},
    {"J", "3C"},
    {"JLT", "38"},
    {"JEQ", "30"},
    {"JGT", "34"},
    {"JSUB", "48"},
    {"RSUB", "4C"},
    {"TIX", "2C"},
    {"TD", "E0"},
    {"RD", "D8"},
    {"WD", "DC"},
    {"MOV", "E4"}, 
    {"JLE", "E8"},
    {"PUSH", "EC"},
    {"POP", "F0"},
    {"JGE", "F4"},
    {"JNE", "F8"}
};

// SYMTAB to store labels foud in the 1st pass of the compiler
struct symbol {
    char name[10];
    int addr;
} SYMTAB[100];

int symcount = 0;  // number of symbols
int program_length;   // program length for header record of pass 2
int start_addr;    // start address

// getting value of opcode from OPTAB
char* get_opcode(char *mnemonic) {
    for (int i = 0 ; i < 29 ; i++) {
        if (strcmp(OPTAB[i].mnemonic, mnemonic) == 0) return OPTAB[i].opcode;
    }
    return NULL;
}

// add symbol to SYMTAB
void insert_symbol(char *label, int addr) {
    for(int i=0; i < symcount; i++) {
        if(strcmp(SYMTAB[i].name, label) == 0) {
            printf("Error: Duplicate symbol %s\n", label);
            return;
        }
    }
    strcpy(SYMTAB[symcount].name, label);
    SYMTAB[symcount].addr = addr;
    symcount++;
}

// search symbol address from SYMTAB
int search_symbol(char *label) {
    for(int i=0 ; i < symcount ; i++) {
        if(strcmp(SYMTAB[i].name, label) == 0) {
            return SYMTAB[i].addr;
        }
    }
    return -1;
}

// pass 1
void pass1() {
    FILE *input = fopen("sample_input.txt", "r");   // opening the sample input file
    FILE *intermediate = fopen("intermediate_twopass.txt", "w");    // creating an intermediate file for 2 pass
    
    char line[100], label[20], mnemonic[20], operand[20];
    int location_counter = 0;

    if (!input || !intermediate) {
        printf("Error opening files\n"); 
        exit(1);
    }
    
    fgets(line, 100, input);
    sscanf(line, "%s %s %s", label, mnemonic, operand); // scanning the laber, mnemonic and operand

    if (strcmp(mnemonic, "START") == 0) {   // checking if the mnemonic is START
        start_addr = (int)strtol(operand, NULL, 16);    // saving start address
        location_counter = start_addr;
        fprintf(intermediate, "%X %s %s %s\n", location_counter, label, mnemonic, operand);
    } else {
        location_counter = 0;
    }

    while (fgets(line, 100, input)) {
        strcpy(label, ""); 
        strcpy(mnemonic, ""); 
        strcpy(operand, "");

        char w1[20], w2[20], w3[20];
        int count = sscanf(line, "%s %s %s", w1, w2, w3);

        if (count == 3) {
            strcpy(label, w1); 
            strcpy(mnemonic, w2); 
            strcpy(operand, w3);
        }
        else if (count == 2) { 
            if (get_opcode(w1) != NULL || strcmp(w1, "END") == 0) {
               strcpy(mnemonic, w1); 
               strcpy(operand, w2);
            } else {
               strcpy(label, w1); 
               strcpy(mnemonic, w2);
            }
        } else if (count == 1)
            strcpy(mnemonic, w1);
        
        if (strcmp(mnemonic, "END") == 0) break;
        if (line[0] == '.') continue; 

        fprintf(intermediate, "%X %s %s %s\n", location_counter, (strlen(label)>0)?label:"-", mnemonic, (strlen(operand)>0)?operand:"-");

        if (strlen(label) > 0) insert_symbol(label, location_counter);

        if (get_opcode(mnemonic) != NULL) location_counter += 3;    // if there's the mnemonic, so add 3 to location counter
        else if (strcmp(mnemonic, "WORD") == 0) location_counter += 3;  // if mnemonic is word, its 24bits => 3 bytes
        else if (strcmp(mnemonic, "RESW") == 0) location_counter += 3 * atoi(operand);  // residual word is 3 bytes each
        else if (strcmp(mnemonic, "RESB") == 0) location_counter += atoi(operand);  // residual byte is 1 byte each
        else if (strcmp(mnemonic, "BYTE") == 0) {
            int len = strlen(operand) - 3;
            if (operand[0] == 'C') location_counter += len; // character string
            if (operand[0] == 'X') location_counter += len/2;   // hex string (/2 as 2 hex digits is 1 byte)
        }
    }

    fprintf(intermediate, "%X - %s %s\n", location_counter, mnemonic, operand);
    program_length = location_counter - start_addr;
    
    fclose(input);
    fclose(intermediate);
}

// pass 2
void pass2() {
    FILE *intermediate = fopen("intermediate_twopass.txt", "r");
    FILE *fp_obj = fopen("output_twopass.txt", "w");
    
    char addr_str[20], label[20], mnemonic[20], operand[20];
    char buffer[100] = "";
    int buffer_start_addr = -1;
    int buffer_length = 0;

    if (!intermediate || !fp_obj) { 
        printf("Error opening files\n"); 
        exit(1); 
    }

    fscanf(intermediate, "%s %s %s %s", addr_str, label, mnemonic, operand);

    if (strcmp(mnemonic, "START") == 0) {   // if mnemonic is start
        fprintf(fp_obj, "H%-6s%06X%06X\n", label, start_addr, program_length);    // first line should be header
        fscanf(intermediate, "%s %s %s %s", addr_str, label, mnemonic, operand);
    }
    
    buffer_start_addr = (int)strtol(addr_str, NULL, 16);    // store string address in buffer addr

    while (strcmp(mnemonic, "END") != 0 && !feof(intermediate)) {
        int current_loc = (int)strtol(addr_str, NULL, 16);
        char object_code[MAX_OBJ_CODE] = "";
        char *op_value = get_opcode(mnemonic);

        if (op_value != NULL) {
            int target_addr = 0;
            int is_indexed = 0;

            // check if there is an operand
            if (strcmp(operand, "-") != 0) {
                char temp_op[20];
                strcpy(temp_op, operand);

                // check for indexing
                if (strlen(temp_op) > 2 && temp_op[strlen(temp_op)-2] == ',') {
                    temp_op[strlen(temp_op)-2] = '\0';
                    is_indexed = 1;
                }
                target_addr = search_symbol(temp_op);   // finding address of label in SYMTAB
            }
            
            if (is_indexed) target_addr += 0x8000;  // setting index bit to 1

            sprintf(object_code, "%s%04X", op_value, target_addr);
        }
        else if (strcmp(mnemonic, "BYTE") == 0) {
            if (operand[0] == 'C') {    // converts characters into their hex values (c to detect whether characters)
                int k = 0;
                for (int i = 2; i < strlen(operand) - 1; i++) {
                    sprintf(&object_code[k], "%02X", (unsigned char)operand[i]);
                    k += 2;
                }
                object_code[k] = '\0';
            } else if (operand[0] == 'X') { // if hex, excreact hex digits
                strncat(object_code, operand+2, strlen(operand)-3);
            }
        }
        else if (strcmp(mnemonic, "WORD") == 0) {   // convert decimal to hex(6 digit)
            sprintf(object_code, "%06X", atoi(operand));
        }

        if (strlen(object_code) > 0) {
            int len_bytes = strlen(object_code) / 2;

            // check if the record is getting longer than 30 bytes or if we encurred a gap (RESW)
            int expected = buffer_start_addr + buffer_length;
            if (buffer_length > 0 && (buffer_length + len_bytes > 30 || current_loc != expected)) {
                if (buffer_length > 0) {
                    fprintf(fp_obj, "T%06X%02X%s\n", buffer_start_addr, buffer_length, buffer);
                }
                
                // reset
                strcpy(buffer, "");
                buffer_length = 0;
                buffer_start_addr = current_loc;
            }

            // add code to the buffer
            strcat(buffer, object_code);
            buffer_length += len_bytes;
        }

        fscanf(intermediate, "%s %s %s %s", addr_str, label, mnemonic, operand);    // continue the loop
    }

    if (buffer_length > 0) fprintf(fp_obj, "T%06X%02X%s\n", buffer_start_addr, buffer_length, buffer);  // write the part which is still in the buffer

    fprintf(fp_obj, "E%06X\n", start_addr); // write end record

    fclose(intermediate);
    fclose(fp_obj);
}

int main() {
    pass1();
    pass2();
    printf("Assembly Complete. Output: output_twopass.txt\n");
    return 0;
}