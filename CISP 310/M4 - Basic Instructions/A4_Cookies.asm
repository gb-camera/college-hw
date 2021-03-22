; CISP 310 - Michael Dinh
; Assignment 4: Cookie Calories
; 10/11/2020

INCLUDE io.h

.DATA
cookies   DWORD   ?
calories  DWORD   80 ; constant, see below for why this value in particular
prompt    BYTE    "How many cookies did you eat? Don't lie to me.", 0
string    BYTE    40 DUP (?)
resultLb  BYTE    "I hope you're happy. The total calories you consumed was", 0
totalCal  BYTE    11 DUP(?), 0

.CODE
MainProc  PROC
		  ; reserve stack space
          sub     rsp, 120

		  ; first, read in cookies eaten and convert to int

          input   prompt, string, 40
		  atod	  string
		  mov	  cookies, eax
        
		  ; now we need to calculate total calories consumed
		  ; since there's 10 servings in a bag of 30 cookies, we can assume that 30/10 = 3 cookies per serving
		  ; since one serving is 240 calories, we can also assume that 240/3 = 80 calories per cookie
		  ; ergo to get total calories we multiple number of cookies eaten by 80

          mov     eax, cookies          ; put cookies to EAX
		  mul     calories				; mul EAX by 80 (using calories constant)
		  dtoa    totalCal, eax			; convert to ASCII, store in totalCal

		  ; last, we need to output our results to the user

		  output  resultLb, totalCal

		  ; program end
          add     rsp, 120              ; restore stack
          mov     rax, 0                ; value to return (0)
          ret

MainProc ENDP
END