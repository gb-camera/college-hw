; CISP 310 - Michael Dinh
; Assignment 4: Gas Mileage
; 10/11/2020

INCLUDE io.h

.DATA
tankCap   DWORD   ?
gasMile   DWORD   ?
prompt1   BYTE    "Enter how many gallons of gas your car can hold.", 0
prompt2   BYTE    "Enter how many miles your car can drive on a full tank.", 0
string    BYTE    40 DUP (?)
resultLb  BYTE    "Total approx. MPG your car gets is", 0
mpgN      BYTE    11 DUP(?), 0

.CODE
MainProc  PROC
		  ; reserve stack space
          sub     rsp, 120

		  ; first, read gas capacity and mileage, and convert to int
          input   prompt1, string, 40
		  atod	  string
		  mov	  tankCap, eax

          input   prompt2, string, 40
		  atod	  string
		  mov	  gasMile, eax
        
		  ; now we need to calculate the gas mileage
		  ; gas mileage = gasMile / tankCap 
		  ; i.e. total miles on a full tank / capacity of the tank
		  
		  ; since we are dealing with integer division, 
		  ; assume we can drop the remainder for our purposes

          mov     eax, gasMile          ; put gasMile to EAX
          div	  tankCap				; perform div with tankCap as divisor
          dtoa    mpgN, eax             ; convert to ASCII, store in mpgN

		  ; last, we need to output our results to the user
		  output  resultLb, mpgN

		  ; program end
          add     rsp, 120              ; restore stack
          mov     rax, 0                ; value to return (0)
          ret

MainProc ENDP
END