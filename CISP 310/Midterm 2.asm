; Michael Dinh - CISP 310 - Midterm Exam 2
; Array Displayed in Reverse
; 12/6/2020

.586
.MODEL FLAT
INCLUDE io.h ; input/output header
.STACK 4096 ; allocate stack memory

.DATA 
array DWORD 10, 25, 56, 80, 3
resultLabel BYTE "Here comes the array in reverse!", 0
number BYTE 11 DUP (?)

.CODE
_MainProc PROC
        ; instructions only say to display array in reverse
        ; easiest way to do this would be to get the last address
        ; in the array and then display backwards
        
        ; set ESI to last index
        mov esi, 4
        ; call reverse procedure
        call reverse

        mov eax, 0  ; exit w/ return code 0
        ret
_MainProc ENDP

reverse PROC
        ; send last address by register through random access
whileN: lea eax, array[4*esi]
        ; output the contents of the array element
        dtoa number, [eax]
        output resultLabel, number
        ; decrement the index
        dec esi
        ; compare index to 0
        cmp esi, 0
        ; if the index is less than 0, exit
        jl exitN
        ; otherwise keep going
        jmp whileN
exitN:  ret
reverse ENDP

END
