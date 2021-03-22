; CISP 310 - Michael Dinh
; Assignment 6: Pennies for Pay
; 10/18/2020

INCLUDE io.h

.DATA
; constant
salaryIncrease DWORD 2

; data
daysWorked DWORD ?

; program variables
prompt BYTE "Enter how many days you've been on the job.", 0
string BYTE 40 DUP (?)
errorLb1 BYTE "Error!", 0
errorLb2 BYTE "Input has to be between 1 and 31 inclusive!", 0
resultLb1 BYTE "Your first day! Your meager pay is this many pennies:", 0
resultLb2 BYTE "A day passes; your pay is now this many pennies:", 0
resultLb3 BYTE "You made this amount of pennies. Hope you're happy.", 0
dailySalary BYTE 11 DUP (?)
monthlyTotal BYTE 11 DUP (?)

.CODE
MainProc  PROC
        ; reserve stack space
        sub rsp, 120
		
		; jump to inputD before error check message
		jmp inputD
		; jump here if there's an input error
inputE: output errorLb1, errorLb2

        ; first, read in the user's days worked and convert
inputD: input prompt, string, 40
        atod string
		
		; check if the value is valid between 1 and 31
		cmp eax, 1
		jl inputE ; jump if value is less than 1
		cmp eax, 31
		jg inputE ; jump if value is greater than 31
		
		; input is valid otherwise
        mov daysWorked, eax
		
		; first day
		mov eax, 1 ; keep salary rate in eax
		mov ebx, 1 ; keep running total of salary in ebx
		mov ecx, 1 ; keep count in ecx
		dtoa dailySalary, eax
		output resultLb1, dailySalary
        
        ; now we need to loop for as many days as specified
        ; salary should multiply by 2 for every day
        ; then we add this daily salary to the running total
        
        ; use a while loop w/counter for this
whileN: cmp ecx, daysWorked ; set the counter for daysWorked
        jnl endWhileN ; set the escape condition
        ; on a successful iteration...
        mul salaryIncrease ; multiply eax by 2
		add ebx, eax ; add eax (daily salary) to ebx (total salary)
        dtoa dailySalary, eax ; move/convert the result to dailySalary
        output resultLb2, dailySalary ; output the result to the user
        inc ecx ; increment the counter
        jmp whileN ; check if we loop again
endWhileN:
		
		; now we need to output the total salary
		dtoa monthlyTotal, ebx
		output resultLb3, monthlyTotal

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END
