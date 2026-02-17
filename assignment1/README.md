Name: Freya Mitulbhai Shingala

Roll number: 230101094

Set a: Question 10
    Commands: 
        nasm -f elf32 230101094_seta.asm -o 230101094_seta.o
        ld -m elf_i386 230101094_seta.o -o 230101094_seta
        ./230101094_seta
        input:  enter str 1: abcd
                enter str 2: cd
        output: 2


Set b, part 1: Question 9
    Commands:
        nasm -f elf32 230101094_setb_part1.asm -o 230101094_setb_part1.o
        ld -m elf_i386 230101094_setb_part1.o -o 230101094_setb_part1
        ./230101094_setb_part1
        input:  Enter the filename: test.txt
        output: Words: 2
                Vowels: 3
                Consonants: 7

Set b, part 2: Question 5
    Commands:
        nasm -f elf32 230101094_setb_part2.asm -o 230101094_setb_part2.o
        gcc -m32 230101094_setb_part2.o -o 230101094_setb_part2
        ./230101094_setb_part2
        input: Enter dimensions M (rows) and N (cols): 2 1
        Enter elements for Matrix A: 2 3
        Enter elements for Matrix B: 1 4
        output: Result Matrix C (2x2):
                2 8 
                3 12 