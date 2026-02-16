#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mnemonic[10];
    int opcode;
} Opcode;

Opcode OPTAB[] = {
    {"LDA",0x00},
    {"LDX",0x04},
    {"LDL",0x08},
    {"STA",0x0C},
    {"STX",0x10},
    {"STL",0x14},
    {"LDCH",0x50},
    {"STCH",0x54},
    {"ADD",0x18},
    {"SUB",0x1C},
    {"MUL",0x20},
    {"DIV",0x24},
    {"COMP",0x28},
    {"J",0x3C},
    {"JLT",0x38},
    {"JEQ",0x30},
    {"JGT",0x34},
    {"JSUB",0x48},
    {"RSUB",0x4C},
    {"TIX",0x2C},
    {"TD",0xE0},
    {"RD",0xD8},
    {"WD",0xDC},
    {"MOV",0xE4},
    {"JLE",0xE8},
    {"PUSH",0xEC},
    {"POP",0xF0},
    {"JGE",0xF4},
    {"JNE",0xF8}
};

// incomplete node (stored here if symbol used before not defined)
typedef struct {
    int location;        // location of incomplete instruction
    char symbol[30];     // symbol that needs to be resolved
} Incomplete;

Incomplete INCTAB[500];
int inccount = 0;

typedef struct {
    char name[30];
    int addr;
    int defined;
} Symbol;

Symbol SYMTAB[500];
int symcount = 0;

// storing the target code generated
typedef struct {
    int loc;
    char obj[20];
} TargetCode;

TargetCode target[500];
int targetcount = 0;

int location_counter = 0;
int start_addr = 0;
int execution_addr = 0;
int program_length = 0;
char program_name[10];

int get_opcode(char *mnemonic) {
    for(int i=0;i<29;i++)
        if(strcmp(OPTAB[i].mnemonic,mnemonic)==0)
            return OPTAB[i].opcode;
    return -1;
}

int search_symbol(char *symbol) {
    for(int i=0;i<symcount;i++)
        if(strcmp(SYMTAB[i].name,symbol)==0)
            return i;
    return -1;
}

int insert_symbol(char *sym) {
    strcpy(SYMTAB[symcount].name,sym);
    SYMTAB[symcount].addr=-1;
    SYMTAB[symcount].defined=0;
    symcount++;
    return symcount-1;
}

// function to fix the conflicts whenever a new symbol is defined
void patch_symbol(char *symbol, int addr) {
    for(int i=0 ; i<inccount ; i++) {
        if(strcmp(INCTAB[i].symbol, symbol) == 0) {
            int opcode;
            sscanf(target[INCTAB[i].location].obj,"%2X",&opcode);   // get the opcode
            sprintf(target[INCTAB[i].location].obj, "%02X%04X", opcode, addr);  // paste he address of that opcode in the target address
        }
    }
}

// BYTE conversion
void convert_BYTE(char *operand, char *obj) {
    if(operand[0] == 'C') { // if character
        int len = strlen(operand), k = 0;

        for(int i=2 ; i<len-1 ; i++) {  // from i=2 as first 2 characters are C' and last character is '
            sprintf(obj+k, "%02X", operand[i]);   // convert each character to ascii hex
            k += 2; // +2 as each hex is of 2 bytes
        }
        obj[k] = '\0';    // manually adding \0 in the end
    }
    else if(operand[0] == 'X') {  // if its already hexadecimal
        int len = strlen(operand);
        strncpy(obj, operand+2, len-3);
        obj[len-3] = '\0';
    }
}

int main() {
    FILE *fin = fopen("sample_input.txt","r");
    FILE *fout = fopen("output_onepass.txt","w");

    if(!fin) {
        printf("Input file not found\n");
        return 0;
    }

    char line[100];

    while(fgets(line,sizeof(line),fin)) {
        if(line[0]=='.' || line[0]=='\n') continue; // if comment(.) or empty line ignore

        char label[30] = "", opcode[30] = "", operand[50] = "";
        int i = 0, j = 0;

        while(line[i] == ' ' || line[i] == '\t')    // skip if spaces or tabs
            i++;

        if(line[0] != ' ' && line[0] != '\t') { // if first character is not a space or tab, then label exists
            while(line[i] != ' ' && line[i] != '\t' && line[i] != '\n') // read label
                label[j++] = line[i++];

            label[j] = '\0';    // add \0 manually at the end
            j = 0;

            while(line[i] == ' ' || line[i] == '\t')    // skipping spaces and tabs to reach opcode
                i++;
        }

        // reading opcode
        while(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            opcode[j++] = line[i++];

        opcode[j] = '\0';
        j = 0;

        while(line[i] == ' ' || line[i] == '\t')
            i++;

        // reading operand
        while(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            operand[j++] = line[i++];

        operand[j] = '\0';


        // if opcode is start
        if(strcmp(opcode,"START")==0) {
            strcpy(program_name,label); // program name is the label
            start_addr=(int)strtol(operand,NULL,16);    
            location_counter=start_addr;
            execution_addr=start_addr;
            continue;
        }

        // if opcode is end, end program
        if(strcmp(opcode,"END")==0)
            break;

        // label definition
        if(strlen(label)>0) {
            int index=search_symbol(label); // search in symbol table, if not found insert it and backpatch
            if(index==-1) index=insert_symbol(label);
            SYMTAB[index].addr=location_counter;
            SYMTAB[index].defined=1;
            patch_symbol(label, location_counter);
        }

        int op=get_opcode(opcode);

        // if opcode found in OPTAB
        if(op!=-1) {
            target[targetcount].loc=location_counter;
            int addr=0;
            int indexed=0;  // whether indexed addressing used(,X)

            if(strcmp(opcode,"RSUB")!=0) {  // RSUB has only 1 word (no operand), so we skip address processing that
                if(strstr(operand,",X")) {  // if indexed addressing, remove ,X and set indexed to 1
                    indexed=1;
                    operand[strlen(operand)-2]='\0';
                }

                int index=search_symbol(operand);
                if(index==-1) index=insert_symbol(operand);

                if(SYMTAB[index].defined)
                    addr=SYMTAB[index].addr;
                else {  // add to incomplete inxtruction table
                    strcpy(INCTAB[inccount].symbol, operand);
                    INCTAB[inccount].location = targetcount;
                    inccount++;
                }

                if(indexed) // sets highest bit of address field as 1
                    addr |= 0x8000;
            }

            sprintf(target[targetcount].obj,"%02X%04X",op,addr);
            targetcount++;
            location_counter+=3;
        }

        else if(strcmp(opcode,"WORD")==0) {
            target[targetcount].loc=location_counter;
            sprintf(target[targetcount].obj,"%06X",atoi(operand));  // store as hex after converting from string to integer (6 digit hex)
            targetcount++;
            location_counter+=3;    // as 3 bytes occupied by word
        }

        else if(strcmp(opcode,"BYTE")==0) {
            target[targetcount].loc=location_counter;
            convert_BYTE(operand,target[targetcount].obj);
            location_counter+=strlen(target[targetcount].obj)/2;    // /2 as 2 hex digits=1 byte
            targetcount++;
        }

        else if(strcmp(opcode,"RESW")==0)
            location_counter+=3*atoi(operand);  // reserve 3 bytes

        else if(strcmp(opcode,"RESB")==0)
            location_counter+=atoi(operand);    // reserve 1 byte
    }

    fclose(fin);

    program_length = location_counter - start_addr;

    fprintf(fout,"H%-6s%06X%06X\n", program_name, start_addr, program_length);

    int i=0;
    while(i<targetcount) {
        int record_start = target[i].loc;
        int length = 0;
        char record[60]=""; // maximum 30 bytes so 60 hex chars
        int j=i;
        int last_loc = target[i].loc;   // helps in detecting memory gaps

        while(j<targetcount) {

            int current_loc = target[j].loc;
            int bytes = strlen(target[j].obj)/2;

            if(j>i && current_loc != last_loc)  // if crossed the given memory
                break;

            if(length + bytes > 30) // if more than 30 bytes
                break;

            strcat(record,target[j].obj);
            length += bytes;
            last_loc = current_loc + bytes;
            j++;
        }

        fprintf(fout,"T%06X%02X%s\n",record_start,length,record);
        i=j;
    }

    fprintf(fout,"E%06X\n",execution_addr);
    fclose(fout);

    printf("Output written to output_onepass.txt\n");
    return 0;
}
