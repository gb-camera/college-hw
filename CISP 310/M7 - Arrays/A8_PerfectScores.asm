; CISP 310 - Michael Dinh
; Assignment 8 - Perfect Scores
; 11/09/2020

INCLUDE io.h

.DATA
; data
array WORD 10 DUP (?)

; program variables
prompt BYTE "Enter score.", 0
errorPrompt1 BYTE "Error!", 0
errorPrompt2 BYTE "Invalid input; score must be between 0 and 100 inclusive.", 0
string BYTE 40 DUP (?)
resultLb BYTE "Number of perfect scores is", 0
scoreCount BYTE 11 DUP (?)

.CODE
MainProc PROC
        ; reserve stack space
        sub rsp, 120
		
		; load the array into RBX
		lea rbx, array
		; count for test scores
		mov ecx, 0
		; use edx to keep count of perfect scores
		mov edx, 0
		jmp whileN
		
errorJ: output errorPrompt1, errorPrompt2
		
whileN: cmp ecx, 10
		je endWhileN
		; get test score
        input prompt, string, 40
        atod string
		; error check
		cmp eax, 0
		jl errorJ
		cmp eax, 100
		jg errorJ
		; if not equal, score isn't perfect, skip perfect tally
		jne normal
		inc edx
		; after we've got a valid number
normal: mov [rbx], eax ; send it to the array
		add rbx, 2 ; point to the next element
		inc ecx
		jmp whileN
endWhileN:

		; now we need to output
        dtoa scoreCount, edx
        output resultLb, scoreCount

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END