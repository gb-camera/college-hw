; CISP 310 - Michael Dinh
; Assignment 5: Leap Year
; 10/18/2020

INCLUDE io.h

.DATA
; constants
factorFour DWORD 4
factorHund DWORD 100
factorFHun DWORD 400

; data
year DWORD ?

; program variables
prompt BYTE "Enter the year you wish to check.", 0
string BYTE 40 DUP (?)
resultLb BYTE "Number of days in February for your year is", 0
leapYearD BYTE "29", 0
normYearD BYTE "28", 0

.CODE
MainProc  PROC
		; reserve stack space
        sub rsp, 120

		; first, read in the user's desired year and convert/store
        input prompt, string, 40
		atod string
		mov year, eax
        
		; now we need to determine if the year is a leap year
		; leap years are either divisible by 4...
		; or are NOT divisible by 100 AND divisible by 400
		
		; no mod function, so easiest way to do this would be to...
		; use div and check remainder in EDX
		
		; first check if divisible by 100
        mov eax, year
		div factorHund
		cmp edx, 0

		; if equal, jump to 400 comparison
		je cmp400
		
		; if not equal, continue to 4 comparison
		; clear edx to avoid overflow
		mov edx, 0
		mov eax, year
		div factorFour
		cmp edx, 0
		
		; if equal, we have a leap year
		je leapT
		; if not equal, we don't have a leap year
		jne leapF
		
		; now we need our 400 comparison
		; clear edx to avoid overflow
cmp400:	mov edx, 0
		mov eax, year
		div factorFHun
		cmp edx, 0
		
		; same jump parameters as 4 comparison
		je leapT
		jne leapF

		; last, we need to leave jump points for output
leapT: 	output resultLb, leapYearD
		jmp ending ; don't want the program to output the other statement
leapF:	output resultLB, normYearD

		; program end
ending: add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END