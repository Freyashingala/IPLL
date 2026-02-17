section .data
    askNum1 db "Enter the first number to multiply: ", 0    ; asking for the first number
    askNum2 db "Enter the second number to multiply: ", 0   ; asking for the second number
    ansNum db "The answer is %d", 10, 0     ; printing the multiplication answer
    ansError db "Error: Numbers are out of range of 32-bit unsigned integer.", 10, 0  ; error for when any of the numbers entered are out of range

    fmt_in db "%d", 0   ; helper for scanf

section .bss
    ; initializing temporary variables num1 and num2 to store the 2 integers that the user inputs
    num1 resd 1
    num2 resd 1

section .text
    global main
    extern printf   ; calling C functions
    extern scanf
    extern exit

main:
    push ebp
    mov ebp, esp

    ; asking for the first number
    push askNum1
    call printf
    add esp, 4

    ; scanning the first number in num1
    push num1
    push fmt_in
    call scanf
    add esp, 8

    ; asking for second number
    push askNum2
    call printf
    add esp, 4

    ; scanning the second number in num2
    push num2
    push fmt_in
    call scanf
    add esp, 8

    mov ebx, [num1] ; saving num1 in ebx
    mov ecx, [num1] ; saving num1 in ecx (for repeated addition in loop)
    mov eax, [num2] ; saving num2 in eax (for the loop constraint)
    call BitwiseMultiply

BitwiseMultiply:
    cmp ebx, 0
    je loopZero
    jl inputError

    cmp eax, 0  ; if num2 is 0, then answer is 0 (as multiplication 0)
    je loopZero
    jl inputError
    cmp eax, 1  ; id num2 is 1, that means we have added num1 "num2" times
    je loopEnd  ; jump to loopEnd
    jne loop    ; if num2>1, that means loop is still left so continue the addition

loop:
    add ebx, ecx    ; add num1 to ebx (the final product)
    sub eax, 1  ; subtract eax by 1 (num2 = num2 - 1)
    call BitwiseMultiply    ; check again in BitwiseMultiply if multiplication loop over or still left

; code will jump here if num2 is 1, i.e. multiplication is over
loopEnd:
    ; print the value stored in eax
    mov eax, ebx    ; move the final product ebx to eax(as asked in the question)
    push eax
    push ansNum
    call printf
    add esp, 8
    
    ; return 0 and exit the program
    push 0
    call exit

; code jumps to this if num is 0
loopZero:
    ; prints answer as 0
    push 0
    push ansNum
    call printf
    add esp, 8

    push 0
    call exit

; jumps here when any of the input in out of range
inputError:
    push ansError
    call printf
    add esp, 4

    push 0
    call exit