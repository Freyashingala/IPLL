# SIC Assembler in C (One-Pass & Two-Pass)

## Freya Mitulbhai Shingala, 230101094

This project contains C implementations of both a **Two-Pass Assembler** and a **One-Pass Assembler** for the standard SIC (Simplified Instructional Computer) architecture, featuring extended support for custom instructions.

## File Structure

To run these assemblers, your working directory must contain the following files:

- `twopass.c` / `onepass.c`: The C source code files containing the assembler logic.
- `sample_input.txt`: The text file containing your assembly code.

Upon execution, the assemblers will automatically generate:

- `output_twopass.txt` or `output_onepass.txt`: The final Object Code (Machine Code) containing Header (`H`), Text (`T`), and End (`E`) records.
- `intermediate_twopass.txt`: *(Two-Pass only)* A temporary file storing the parsed instructions, labels, and assigned memory addresses generated during Pass 1, which is then read by Pass 2.

---

## How to Run

### 1. Prepare the Input File (`sample_input.txt`)

Create a file named `sample_input.txt` in the same folder as your C code. Paste your SIC assembly code into this file.

> **CRITICAL: Input Formatting Rules**
> This assembler uses a strict token parsing system. You must format your code correctly:
>
> - **Labels:** Must start at the very first character of the line (Column 0).
> - **No Labels:** If a line does not have a label, it must start with a space or a tab.
> - **Separation:** Use spaces or tabs to separate Labels, Opcodes, and Operands.
> - **Comments:** Lines starting with a period (`.`) are completely ignored.

### 2. Compile the Code

Open your terminal or command prompt, navigate to the folder containing your files, and compile the C code using GCC:

```bash
# For Two-Pass
gcc 230101094_twopass.c -o 230101094_twopass

# For One-Pass
gcc 230101094_onepass.c -o 230101094_onepass
```

### 3. Execute

Run the compiled executable:

```bash
# On Windows:
230101094_twopass.exe
230101094_onepass.exe

# On Linux/macOS:
./230101094_twopass
./230101094_onepass
```

---

## Understanding the Output (One-Pass vs Two-Pass)

A Two-Pass Assembler and a One-Pass Assembler will generate structurally different output files for the exact same `sample_input.txt`. Both are mathematically correct and will result in the exact same data being loaded into the computer's memory.

### `sample_input.txt` for two-pass:

```text
COPY    START   1000
FIRST   STL     RETADR
CLOOP   JSUB    RDREC
        LDA     LENGTH
        COMP    ZERO
        JEQ     ENDFIL
        JSUB    WRREC
        J       CLOOP
ENDFIL  LDA     EOF
        STA     BUFFER
        LDA     THREE
        STA     LENGTH
        JSUB    WRREC
        LDL     RETADR
        RSUB
EOF     BYTE    C'EOF'
THREE   WORD    3
ZERO    WORD    0
RETADR  RESW    1
LENGTH  RESW    1
BUFFER  RESB    4096
.
.       SUBROUTINE TO READ RECORD INTO BUFFER
.
RDREC   LDX     ZERO
        LDA     ZERO
RLOOP   TD      INPUT
        JEQ     RLOOP
        RD      INPUT
        COMP    ZERO
        JEQ     EXIT
        STCH    BUFFER,X
        TIX     MAXLEN
        JLT     RLOOP
EXIT    STX     LENGTH
        RSUB
INPUT   BYTE    X'F1'
MAXLEN  WORD    4096
.
.       SUBROUTINE TO WRITE RECORD FROM BUFFER
.
WRREC   LDX     ZERO
WLOOP   TD      OUTPUT
        JEQ     WLOOP
        LDCH    BUFFER,X
        WD      OUTPUT
        TIX     LENGTH
        JLT     WLOOP
        RSUB
OUTPUT  BYTE    X'05'
        END     FIRST
```

### Two-Pass Assembler: 

The Two-Pass assembler reads the file twice.

- **Pass 1:** Assigns addresses to all labels and builds the Symbol Table.

- **Pass 2:** Generates the machine code. Because it already knows all addresses, it can generate long, contiguous Text (T) records (up to 30 bytes each).
---

- `intermediate_twopass.txt`
    ```text
    1000 COPY START 1000
    1000 FIRST STL RETADR
    1003 CLOOP JSUB RDREC
    1006 - LDA LENGTH
    1009 - COMP ZERO
    100C - JEQ ENDFIL
    100F - JSUB WRREC
    1012 - J CLOOP
    1015 ENDFIL LDA EOF
    1018 - STA BUFFER
    101B - LDA THREE
    101E - STA LENGTH
    1021 - JSUB WRREC
    1024 - LDL RETADR
    1027 - RSUB -
    102A EOF BYTE C'EOF'
    102D THREE WORD 3
    1030 ZERO WORD 0
    1033 RETADR RESW 1
    1036 LENGTH RESW 1
    1039 BUFFER RESB 4096
    2039 RDREC LDX ZERO
    203C - LDA ZERO
    203F RLOOP TD INPUT
    2042 - JEQ RLOOP
    2045 - RD INPUT
    2048 - COMP ZERO
    204B - JEQ EXIT
    204E - STCH BUFFER,X
    2051 - TIX MAXLEN
    2054 - JLT RLOOP
    2057 EXIT STX LENGTH
    205A - RSUB -
    205D INPUT BYTE X'F1'
    205E MAXLEN WORD 4096
    2061 WRREC LDX ZERO
    2064 WLOOP TD OUTPUT
    2067 - JEQ WLOOP
    206A - LDCH BUFFER,X
    206D - WD OUTPUT
    2070 - TIX LENGTH
    2073 - JLT WLOOP
    2076 - RSUB -
    2079 OUTPUT BYTE X'05'
    207A - END FIRST
    ```


- `output_twopass.txt`

    ```text
    HCOPY  00100000107A
    T0010001E1410334820390010362810303010154820613C100300102A0C103900102D
    T00101E150C10364820610810334C0000454F46000003000000
    T0020391E041030001030E0205D30203FD8205D2810303020575490392C205E38203F
    T0020571C1010364C0000F1001000041030E02079302064509039DC20792C1036
    T002073073820644C000005
    E001000
    ```



### One-Pass Assembler:

The One-Pass assembler generates code on the fly. When it encounters a "Forward Reference" (using a label before it is defined), it must guess the address and fix it later.

- **Table of Incomplete Instructions (TII):** It writes a dummy 0000 address into memory and logs the location in the TII. Once the label is finally found, it uses the TII to go back and overwrite the 0000 with the real address (Backpatching).

- **Memory Map (Dirty Bit):** To ensure RESW and RESB gaps are not printed as giant blocks of zeros, the assembler uses a MEM_MAP array. It only writes a T-record for memory addresses that were explicitly touched by an instruction.

- **Result:** The output features shorter, fragmented T-records. This happens because the assembler writes data as it discovers it, skipping empty memory gaps.

---
-  `output_onepass.txt`
    ```text
    HCOPY  00100000107A
    T0010001E1410334820390010362810303010154820613C100300102A0C103900102D
    T00101E150C10364820610810334C0000454F46000003000000
    T0020391E041030001030E0205D30203FD8205D2810303020575490392C205E38203F
    T0020571C1010364C0000F1001000041030E02079302064509039DC20792C1036
    T002073073820644C000005
    E001000
    ```

---

## Supported Instruction Set

**Standard SIC Directives:**
`START`, `END`, `WORD`, `BYTE`, `RESW`, `RESB`

**Standard SIC Opcodes:**
`LDA`, `LDX`, `LDL`, `STA`, `STX`, `STL`, `LDCH`, `STCH`, `ADD`, `SUB`, `MUL`, `DIV`, `COMP`, `J`, `JEQ`, `JGT`, `JLT`, `JSUB`, `RSUB`, `TIX`, `TD`, `RD`, `WD`

**Extended Custom Opcodes:**
`JMP`, `JLE`, `JE`, `JGE`, `JNE`, `JL`, `JG`, `MOV`, `CALL`, `RET`, `PUSH`, `POP`
