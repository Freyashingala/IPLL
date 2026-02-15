;Name: Freya Mitulbhai Shingala
;Roll no.: 230101094

section .data
    askstr1 db "enter str 1: ", 0
    len1 equ $ - askstr1
    askstr2 db "enter str 2: ", 0
    len2 equ $ - askstr2
    noMatch db "-1", 0xA
    newLine db 0xA

section .bss
    str1 resb 100
    str2 resb 100
    prstr resb 10

section .text
    global _start

_start:
    ;print 1
    mov eax, 4
    mov ebx, 1
    mov ecx, askstr1
    mov edx, len1
    int 0x80

    ;read 1
    mov eax, 3
    mov ebx, 0
    mov ecx, str1
    mov edx, 100
    int 0x80

    ;print 2
    mov eax, 4
    mov ebx, 1
    mov ecx, askstr2
    mov edx, len2
    int 0x80

    ;read 2
    mov eax, 3
    mov ebx, 0
    mov ecx, str2
    mov edx, 100
    int 0x80

    mov byte [str2 + eax - 1], 0  ;replace \n with \0(for comparision that is not at the end)

    xor ecx, ecx   ;ecx will be outer loop index (i=0)

outer_loop:
    ;check if we reached end of str1
    mov al, [str1 + ecx]
    cmp al, 0
    je notFound

    ;inner Loop
    mov esi, ecx   ;esi = current position in str1
    xor edi, edi   ;edi = position in str2

inner_loop:
    mov al, [str2 + edi]
    cmp al, 0   ;character in str2=0?
    je match                

    mov bl, [str1 + esi]
    cmp bl, al
    jne next_outer  ;break loop

    ;move to next char
    inc esi
    inc edi
    jmp inner_loop

next_outer:
    inc ecx
    jmp outer_loop

match:
    mov eax, ecx    ;for printing
    call print_number
    jmp exit_prog

notFound:
    mov eax, 4
    mov ebx, 1
    mov ecx, noMatch
    mov edx, 3
    int 0x80
    jmp exit_prog

exit_prog:
    mov eax, 1
    xor ebx, ebx
    int 0x80

print_number:
    push eax
    push ebx
    push ecx
    push edx

    mov ecx, prstr
    add ecx, 9  ;last index
    mov byte [ecx], 0xA ;newline

    ;if eax=0
    cmp eax, 0
    jne start_convert
    dec ecx
    mov byte [ecx], '0'
    jmp print_digits

start_convert:
    mov ebx, 10

convert_loop:
    dec ecx
    xor edx, edx
    div ebx ;eax=eax/10 , edx=remainder
    add dl, '0'
    mov [ecx], dl

    cmp eax, 0
    jne convert_loop

print_digits:
    ;print string from ecx to end
    mov eax, 4
    mov ebx, 1
    mov edx, prstr
    add edx, 10
    sub edx, ecx
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax
    ret
