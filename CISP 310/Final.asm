; Michael Dinh - CISP 310 - Final Exam
; Array Value Check
; 12/16/2020

.586
.MODEL FLAT
INCLUDE io.h ; input/output header
.STACK 4096 ; allocate stack memory

.DATA 
prompt1 BYTE "Enter array value.", 0
prompt2 BYTE "Enter value to check instances of.", 0
resultLb BYTE "This number was seen this many times:", 0
string BYTE 40 DUP (?)
number BYTE 2 DUP (?)
array DWORD 10 DUP (?)

.CODE
_MainProc PROC
        ; to-do:
        ; - user inputs 10 number array and value to check for in array
        ; - put values in array sequentially, reset index for check
        ; - check each value of the array, if match, increment some tally
        ; - output tally after this process is done

        ; set ESI to first index
        mov esi, 0
        
        ; loop array input until ESI = 9
        ; load address into EBX (EAX will be busy doing input)
arrayI: lea ebx, array[4*esi];
        ; get the input and put it in the array
        input prompt1, string, 40
        atod string
        mov [ebx], eax
        ; increment index
        inc esi
        ; compare index to 9
        cmp esi, 9
        ; if the index is greater than 9, exit
        jg exitArI
        ; otherwise keep going
        jmp arrayI
exitArI:

        ; get the comparison value, store in EBX (we're not using it anymore)
        input prompt2, string, 40
        atod string
        mov ebx, eax

        ; set ECX to 10 for our for loop
        mov ecx, 10
        ; set EDX to 0 (we're using it as a tally)
        mov edx, 0
        ; load first address into EAX
        lea eax, array;

        ; loop to analyze the array, increment EDX if match
        ; compare array element to EBX value
arrayC: cmp [eax], ebx
        ; if not equal, jump past increment
        jne increA
        ; otherwise, match found, increment EDX
        inc edx
        ; move array to next address
increA: add eax, 4
        ; continue loop
        loop arrayC

        ; output whatever number is in EDX
        dtoa number, edx
        output resultLb, number

        mov eax, 0  ; exit w/ return code 0
        ret
_MainProc ENDP
END
