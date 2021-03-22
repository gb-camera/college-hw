; CISP 310 - Michael Dinh
; Assignment 6: Weight Loss
; 10/18/2020

INCLUDE io.h

.DATA
; constant
weightLoss DWORD 4

; data
initialWeight DWORD ?

; program variables
prompt BYTE "Enter your initial weight.", 0
string BYTE 40 DUP (?)
resultLb BYTE "A month passes; this is your diet weight now.", 0
dietWeight BYTE 11 DUP (?)

.CODE
MainProc  PROC
        ; reserve stack space
        sub rsp, 120

        ; first, read in the user's weight and convert/store
        input prompt, string, 40
        atod string
        mov initialWeight, eax
        
        ; now we need to loop the weight loss six times
        ; per the diet, the person should lose 4 lb/month
        ; ergo each loop should subtract 4 from the weight
        
        ; use a while loop w/counter for this
        mov ecx, 0 ; set the count
        mov eax, initialWeight ; set the sum
whileN: cmp ecx, 6 ; set the counter for 6
        jnl endWhileN ; set the escape condition
        ; on a successful iteration...
        sub eax, weightLoss ; subtract 4
        dtoa dietWeight, eax ; move/convert the result to dietWeight
        output resultLb, dietWeight ; output the result to the user
        inc ecx ; increment the counter
        jmp whileN ; check if we loop again
endWhileN:

        ; program end
        add rsp, 120 ; restore stack
        mov rax, 0 ; value to return (0)
        ret

MainProc ENDP
END
