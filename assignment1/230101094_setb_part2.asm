;Name: Freya Mitulbhai Shingala
;Roll no.: 230101094

section .data
     askdim db "Enter dimensions M (rows) and N (cols): ", 0
     askA db "Enter elements for Matrix A:", 10, 0
     askB db "Enter elements for Matrix B:", 10, 0
     askC db "Result Matrix C (%dx%d):", 10, 0
    
     fmt_in db "%d", 0
     fmt_out db "%d ", 0
     newline db 10, 0

section .bss
     M resd 1
     N resd 1
    
     matA resd 100   ;100 values maximum (10x10 matrix)
     matB resd 100
     matC resd 100
    
     i resd 1
     j resd 1
     k resd 1
     temp resd 1

section .text
     global main     ;main for it to be visible to linker (GCC)
     extern printf   ;using the 3 C functions
     extern scanf
     extern exit

main:
     push ebp   ;saving the old base pointer
     mov ebp, esp    ;point old base pointer to current stack pointer

     ;input Dimensions
     push askdim
     call printf
     add esp, 4 ;remove the 1 argument pushed in the stack

     ;reading M
     push M
     push fmt_in
     call scanf
     add esp, 8     ;cleaning the stack which has 2 values (4 bytes each)

     ;read N
     push N
     push fmt_in
     call scanf
     add esp, 8

     ;input matrix A (Size M x N)
     push askA
     call printf
     add esp, 4    ;clean stack

     mov dword [i], 0    ;initialize row counter i to 0

;starting outer loop
A_row:
     mov eax, [i]   ;loading i into eax
     cmp eax, [M]   ;comparing if i<M
     jge A_done   ;if i>=M, jump to end

     mov dword [j], 0    ;initialize j=0

A_col:
     mov eax, [j]
     cmp eax, [N]
     jge A_nextrow    ;going to next row if j>=N

    ;calculating address A[i][j] = matA + (i * N + j) * 4 (2D address to 1D memory)
     mov eax, [i]
     imul eax, [N]  ;eax=i*N
     add eax, [j]   ;eax=i*N+j
     shl eax, 2     ;multiplying by 4 bytes per integer (eax*4)
     add eax, matA  ;pushing address of matA into eax

     ;scanning matA[i][j]
     push eax
     push fmt_in
     call scanf
     add esp, 8

     inc dword [j]  ;j++
     jmp A_col    ;repeat j loop

A_nextrow:
     inc dword [i]  ;i++
     jmp A_row    ;repeat i loop
A_done:

     ;input matrix B (Size N x M)
     push askB
     call printf
     add esp, 4

     mov dword [i], 0
B_row:
     mov eax, [i]
     cmp eax, [N]
     jge B_done

     mov dword [j], 0
B_col:
     mov eax, [j]
     cmp eax, [M]
     jge B_nextrow

     mov eax, [i]
     imul eax, [M]
     add eax, [j]
     shl eax, 2
     add eax, matB

     push eax
     push fmt_in
     call scanf
     add esp, 8

     inc dword [j]
     jmp B_col

B_nextrow:
     inc dword [i]
     jmp B_row

B_done:

     ;multiplication starts here
     mov dword [i], 0    ;i=0 for row of C
C_outer:
     mov eax, [i]
     cmp eax, [M]    ;comparing if i<M
     jge print_result

     mov dword [j], 0
C_middle:
     mov eax, [j]
     cmp eax, [M]    ;comparing if j<M
     jge C_outernext

     mov dword [temp], 0
     mov dword [k], 0
C_inner:
     mov eax, [k]
     cmp eax, [N]    ;comparing if k<N
     jge store_val  ;store after dot product done

     ;calculate A[i][k]
     mov eax, [i]
     imul eax, [N]
     add eax, [k]
     mov ebx, matA
     mov ecx, [ebx + eax*4]   ;loading value of A[i][k] into ecx

     ;calculate B[k][j]
     mov eax, [k]
     imul eax, [M]
     add eax, [j]
     mov ebx, matB
     mov edx, [ebx + eax*4]   ;loading value of B[k][j] into edx

     imul ecx, edx  ;ecx=ecx*edx
     add [temp], ecx     ;temp=temp+ecx

     inc dword [k];k++
     jmp C_inner

store_val:
     ;C[i][j]=temp
     mov eax, [i]
     imul eax, [M]
     add eax, [j]
     mov ebx, matC
     mov ecx, [temp]
     mov [ebx + eax*4], ecx

     inc dword [j]
     jmp C_middle

C_outernext:
     inc dword [i]
     jmp C_outer


     ;print result (M x M)
print_result:
     push dword [M]
     push dword [M]
     push askC
     call printf
     add esp, 12

     mov dword [i], 0
print_row:
     mov eax, [i]
     cmp eax, [M]
     jge exit_prog

     mov dword [j], 0
print_col:
     mov eax, [j]
     cmp eax, [M]
     jge print_newline

     ;get C[i][j]
     mov eax, [i]
     imul eax, [M]
     add eax, [j]
     mov ebx, matC
     mov ecx, [ebx + eax*4]

     push ecx
     push fmt_out
     call printf
     add esp, 8

     inc dword [j]
     jmp print_col

print_newline:
     push newline
     call printf
     add esp, 4
     
     inc dword [i]
     jmp print_row

exit_prog:
     push 0
     call exit