; CISP 310 - Michael Dinh
; Assignment 6: Calories Burned
; 10/18/2020

INCLUDE io.h

.DATA
; constant
lostCal DWORD 20

; program variables
resultLb1 BYTE "Running for five minutes, you've burnt this many calories:", 0
resultLb2 BYTE "Running for another five minutes, you've burnt this many calories:", 0
burnedCal BYTE 11 DUP (?)

.CODE
MainProc  PROC
		; reserve stack space
        sub rsp, 120
        		
		; just need to loop and output calorie loss on a 4 cal/min treadmill
		; since we're doing increments of five minutes, 4 x 5 = 20 cal/5 min
		
		; output the first instance manually
		mov eax, lostCal
		dtoa burnedCal, eax
		output resultLb1, burnedCal
		
		; use a while loop w/counter for all other instances
		mov ecx, 0 ; set the count
whileN:	cmp ecx, 5 ; set the counter for 5 since we have 5 other checks
		jnl endWhileN ; set the escape condition
		; on a successful iteration...
		add eax, lostCal ; add 20
		dtoa burnedCal, eax ; move/convert the result to burnedCal
		output resultLb2, burnedCal ; output the result to the user
		inc ecx ; increment the counter
		jmp whileN ; check if we loop again
endWhileN:

		; program end
		add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret
		
MainProc ENDP
END