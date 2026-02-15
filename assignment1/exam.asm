section .data
     ask1 db "ques 1", 10, 0

     fmt_in db "%d", 0
     fmt_out db "%d ", 0

section .bss
     resd x1 1
     resd x2 1
     resb c 1

section .text
     global main
     extern printf
     extern scanf
     extern exit

main:
     push ebp
     mov ebp, esp

     push ask1
     call printf
     add esp, 4

     push x1
     push fmt_in
     call scanf
     add esp, 8

     push x2
     push fmt_in
     call scanf
     add esp, 8

     mov eax, x1
     add eax, x2
     
     push eax
     push fmt_out
     call printf
     add esp, 8

     push 0
     call exit