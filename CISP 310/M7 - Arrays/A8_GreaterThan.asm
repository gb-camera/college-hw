; CISP 310 - Michael Dinh
; Assignment 8 - Greater Than
; 11/09/2020

INCLUDE io.h

.DATA
; data
numbers DWORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
arraySize DWORD ?
biggerThan DWORD ?

; program variables
prompt1 BYTE "Enter array size (up to 10)", 0
prompt2 BYTE "Enter number (up to 9)", 0
string BYTE 40 DUP (?)
resultLb BYTE "Number found!", 0
elementNum BYTE 11 DUP (?)

.CODE
MainProc PROC
		; assuming the program wants a predefined array and to simply list values in array
		
        ; reserve stack space
        sub rsp, 120

		; ask for array size
		input prompt1, string, 40
		atod string
		mov arraySize, eax
		; ask the user for value that numbers should be larger than
		input prompt2, string, 40
		atod string
		mov biggerThan, eax
		
		; now we need to find the values in the array
		; move array into ESI
		lea esi, numbers
		; clear ECX
		mov ecx, 0
		mov edx, biggerThan
		mov ebx, arraySize

whileN: cmp ecx, ebx
		je endWhileN
		mov eax, [esi]
		cmp eax, edx
		jng normal
		dtoa elementNum, eax
		output resultLb, elementNum
normal: add esi, 4
		mov eax, 0
		inc ecx
		jmp whileN
endWhileN:

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END