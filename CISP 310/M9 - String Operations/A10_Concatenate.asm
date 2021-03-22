; Michael Dinh - CISP 310 - Assignment 10
; String Concatenation
; 11/22/2020

.586
.MODEL FLAT
INCLUDE io.h ; input/output header
.STACK 4096 ; allocate stack memory

.DATA 
prompt1 BYTE "Enter the first string.", 0
prompt2 BYTE "Enter the second string.", 0
stringIn BYTE 40 DUP (?)
resultLbl BYTE "Your combined string is", 0
stringOut BYTE 80 DUP (?), 0

.CODE
_MainProc PROC
        ; things to do:
        ; get length of first string so we have a correct memory address
        ; manipulate strcopy protocol to concatenate
        ; append the second string to the first using said memory address

        ; use ecx and edx for counting / incrementing
        mov ecx, 0
        mov edx, 0

        ; get first string
        input prompt1, stringIn, 40
        lea eax, stringIn ; get the source address
        push eax ; push the source to the stack
        lea eax, stringOut ; get the destination address
        push eax ; push the destination to the stack
        call strcopy ; call string copy procedure
        add esp, 8 ; remove the parameters

        ; get the length of the string
        mov edi, eax ; move to register to measure
        mov al, 0 ; search for the null terminator
        mov ecx, -1 ; start the search at the first byte
        cld ; set forward 
        repne scasb ; scan string, decrements ecx for each character
        mov edx, -2 ; account for decrement
        sub edx, ecx ; get length in edx
        
        ; get second string
        input prompt2, stringIn, 40
        lea eax, stringIn ; get the source address
        push eax ; push the source to the stack
        lea eax, [stringOut + edx] ; get the dest address + first str length
        push eax ; push the modified destination to the stack
        call strcopy ; call string copy procedure
        add esp, 8 ; remove the parameters

        ; output result
        output resultLbl, stringOut
        mov eax, 0  ; exit w/ return code 0
        ret
_MainProc ENDP

strcopy PROC NEAR32 ; taken from the example program
        push ebp ; save the base pointer
        mov ebp, esp ; copy the stack pointer
        push edi ; save the registers
        push esi
        pushfd ; save the flags

        mov edi, [ebp+8] ; destination
        mov esi, [ebp+12] ; initial source address
        cld ; clear direction flag
whileNoNull:
        cmp BYTE PTR [esi], 0 ; if we're at the null source byte...
        je endWhileNoNull ; ...stop copying
        movsb ; otherwise, copy one byte
        jmp whileNoNull ; go back and check the next byte

endWhileNoNull:
        mov BYTE PTR [edi], 0 ; terminate the destination string
        popfd
        pop esi
        pop edi
        pop ebp
        ret
strcopy ENDP

END
