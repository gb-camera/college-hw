; CISP 310 - Michael Dinh
; Assignment 7 - Calculator
; 11/08/2020

INCLUDE io.h

.DATA
; data
operator BYTE 11 DUP (?)

; program variables
prompt1 BYTE "Enter first number.", 0
prompt2 BYTE "Enter operator.", 0
prompt3 BYTE "Enter second number."
string BYTE 40 DUP (?)
resultLb BYTE "Operation result is", 0
result BYTE 11 DUP (?)

.CODE
addition PROC
		mov eax, ebx
		add eax, ecx
		ret
addition ENDP

multiplication PROC
		mov eax, ebx
		mul ecx
		ret
multiplication ENDP

subtraction PROC
		mov eax, ebx
		sub eax, ecx
		ret
subtraction ENDP

division PROC
		mov eax, ebx
		div ecx
		ret
division ENDP

MainProc PROC
        ; reserve stack space
        sub rsp, 120
        
whileN: ; get first number
        input prompt1, string, 40
		; if user inputs e here, exit program
		cmp string, "e";
		je endWhileN
		; otherwise keep going
        atod string
		mov ebx, eax
        
		; get the operator
		input prompt2, operator, 40
		; if user inputs e here, exit program
		cmp operator, "e";
		je endWhileN
		; otherwise keep going
		
		; clear string for prompt
		mov string, 0
		; get second number
        input prompt3, string, 40
		; if user inputs e here, exit program
		cmp string, "e";
		je endWhileN
		; otherwise keep going
        atod string
        mov ecx, eax
        
        ; compare our user input operators and jump appropriately
		cmp operator, "+";
		je addit
		cmp operator, "-";
		je subtr
		cmp operator, "*";
		je multi
		cmp operator, "/";
		je divis
		
addit:  call addition ; add and go to result phase
		jmp display
subtr:  call subtraction ; sub and go to result phase
		jmp display
multi:  call multiplication ; multiply and go to result phase
		jmp display
divis:  call division ; divive, result phase follows

display: ; now we need to output
        dtoa result, eax
        output resultLb, result
		jmp whileN ; loop again
endWhileN:

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END