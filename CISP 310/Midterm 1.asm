; CISP 310 - Michael Dinh
; Midterm 1 - Question 7
; 11/01/2020

INCLUDE io.h

.DATA
; program variables
prompt BYTE "Enter a number.", 0
string BYTE 40 DUP (?)
resultLb BYTE "The largest value was", 0
largest BYTE 11 DUP (?)

.CODE
MainProc  PROC
        ; reserve stack space
        sub rsp, 120
        
        ; since we need to loop for ten numbers,
        ; compare values on the fly and loop the same input 10 times
        
        mov ebx, 0 ; keep largest value in ebx
        mov ecx, 0 ; keep a tally in ecx
        
whileN: cmp ecx, 10 ; escape condition if tally is 10
        je endWhileN
        
        input prompt, string, 40 ; get user input
        atod string ; convert it
        
        cmp eax, ebx ; compare the values in eax and ebx
        jl lesser ; jump if eax is less than ebx
        
        ; if we didn't jump, eax is greater
        mov ebx, eax ; move the value in eax to ebx
        
        ; if we did jump, ebx is greater (and thus we don't do anything)
lesser: inc ecx ; increment the counter
        jmp whileN ; loop again
        
endWhileN:
        ; now we need to output the value we got
        dtoa largest, ebx
        output resultLb, largest

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END
