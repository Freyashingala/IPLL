;Name: Freya Mitulbhai Shingala
;Roll no.: 230101094

section .data
    askFile db "filename: ", 0
    len equ $ - askFile
    
    err db "Error: could not open file", 0xA, 0
    lenerr equ $ - err
    
    msgWords db "Words: ", 0
    msgVowels db 0xA, "Vowels: ", 0
    msgCons db 0xA, "Consonants: ", 0
    newline db 0xA, 0

section .bss
    filename resb 64
    filebuf resb 4096   ;4KB
    printbuf resb 10   ;buffer
    
    fd_in resd 1    ;variable to store File Descriptor
    
    ;stats counters
    countWords resd 1
    countVowels resd 1
    countCons resd 1

section .text
    global _start

_start:
    mov dword [countWords], 0
    mov dword [countVowels], 0
    mov dword [countCons], 0

    ;ask filename
    mov eax, 4
    mov ebx, 1
    mov ecx, askFile
    mov edx, len
    int 0x80

    ;input filename
    mov eax, 3
    mov ebx, 0
    mov ecx, filename
    mov edx, 64
    int 0x80

    mov byte [filename + eax - 1], 0    ;remove \n from file to open it correctly

    ;open file
    mov eax, 5
    mov ebx, filename
    mov ecx, 0      ;flag:0 read only
    mov edx, 0
    int 0x80

    ;if eax<0, file open error
    cmp eax, 0
    jl file_error
    
    mov [fd_in], eax    ;save file descriptor

    ;read content
    mov eax, 3
    mov ebx, [fd_in]
    mov ecx, filebuf
    mov edx, 4096
    int 0x80
    
    ;check for empty file
    cmp eax, 0
    je close_file
    
    mov byte [filebuf + eax], 0     ;add 0 at the end

close_file:
    mov eax, 6
    mov ebx, [fd_in]
    int 0x80

    ;buffer process
    mov esi, filebuf
    xor ebx, ebx

scan_loop:
    mov al, [esi]
    cmp al, 0
    je print
    
    ;check whitespace
    cmp al, 32  ;space
    je set_out
    cmp al, 10  ;newline
    je set_out
    cmp al, 9  ;tab
    je set_out

    ;visible char
    cmp ebx, 0
    jne check
    
    ;new word
    inc dword [countWords]
    mov ebx, 1
    jmp check

set_out:
    mov ebx, 0
    inc esi
    jmp scan_loop

check:
    ;check A to z
    cmp al, 'A'
    jl next_char
    cmp al, 'z'
    jg next_char

    ;check gap between Z and a
    cmp al, 'Z'
    jle is_letter
    cmp al, 'a'
    jge is_letter
    jmp next_char

is_letter:
    ;force lowercase
    mov cl, al

    cmp cl, 'A'
    jl lower_done
    cmp cl, 'Z'
    jg lower_done
    add cl, 32  ;uppercase to lowercase

lower_done:
    ;if vowel
    cmp cl, 'a'
    je is_vow
    cmp cl, 'e'
    je is_vow
    cmp cl, 'i'
    je is_vow
    cmp cl, 'o'
    je is_vow
    cmp cl, 'u'
    je is_vow

    ;if consonant
    inc dword [countCons]
    jmp next_char

is_vow:
    inc dword [countVowels]

next_char:
    inc esi
    jmp scan_loop

print:
    ;print words
    mov eax, 4
    mov ebx, 1
    mov ecx, msgWords
    mov edx, 7
    int 0x80
    mov eax, [countWords]
    call print_number

    ;print vowels
    mov eax, 4
    mov ecx, msgVowels
    mov edx, 9
    int 0x80
    mov eax, [countVowels]
    call print_number

    ;print consonants
    mov eax, 4
    mov ecx, msgCons
    mov edx, 13
    int 0x80
    mov eax, [countCons]
    call print_number

    ;newline
    mov eax, 4
    mov ecx, newline
    mov edx, 1
    int 0x80
    jmp exit_prog

file_error:
    mov eax, 4
    mov ebx, 1
    mov ecx, err
    mov edx, lenerr
    int 0x80

exit_prog:
    mov eax, 1
    xor ebx, ebx
    int 0x80

print_number:
    push eax
    push ebx
    push ecx
    push edx

    mov ecx, printbuf
    add ecx, 9  ;last index
    mov byte [ecx], 0   ;null

    ;if answer 0
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
    div ebx ;eax=eax/10, edx=remainder
    add dl, '0'
    mov [ecx], dl

    cmp eax, 0
    jne convert_loop

print_digits:
    ;print string from ecx to end
    mov eax, 4
    mov ebx, 1
    mov edx, printbuf
    add edx, 9
    sub edx, ecx
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax
    ret
