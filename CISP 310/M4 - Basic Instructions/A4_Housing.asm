; CISP 310 - Michael Dinh
; Assignment 4: Housing Costs
; 10/11/2020

INCLUDE io.h

.DATA
rentMort  DWORD   ?
utilCost  DWORD   ?
phoneCost DWORD   ?
cableCost DWORD   ?
months	  DWORD   12 ; constant for # of months in a year
prompt1   BYTE    "Enter your monthly rent/mortgage payment.", 0
prompt2   BYTE    "Enter your monthly utilities cost.", 0
prompt3	  BYTE    "Enter your monthly phone bill cost.", 0
prompt4	  BYTE	  "Enter your monthly cable bill cost.", 0
string    BYTE    40 DUP (?)
resultLb1 BYTE    "Total monthly cost of these expenses is", 0
resultLb2 BYTE	  "Total annual cost of these expenses is", 0
monthN    BYTE    11 DUP(?), 0
yearN     BYTE    11 DUP(?), 0

.CODE
MainProc  PROC
		  ; reserve stack space
          sub     rsp, 120

		  ; first, read all values, and convert to int on the fly

          input   prompt1, string, 40
		  atod	  string
		  mov	  rentMort, eax

          input   prompt2, string, 40
		  atod	  string
		  mov	  utilCost, eax

		  input   prompt3, string, 40
		  atod	  string
		  mov	  phoneCost, eax

		  input   prompt4, string, 40
		  atod	  string
		  mov	  cableCost, eax
        
		  ; now we need to calculate monthly cost
		  ; simple summation of all values together

          mov     eax, rentMort         ; put rentMort to EAX
          add	  eax, utilCost			; sum utilCost to EAX
		  add	  eax, phoneCost		; ...then phoneCost
		  add	  eax, cableCost		; ...then cableCost
          dtoa    monthN, eax           ; convert to ASCII, store in monthN

		  ; now we need to calculate yearly cost
		  ; just need to multiply monthN by 12

		  mul     months				; mul EAX by 12 (using months constant)
		  dtoa    yearN, eax			; convert to ASCII, store in yearN

		  ; last, we need to output our results to the user

		  output  resultLb1, monthN
		  output  resultLb2, yearN

		  ; program end
          add     rsp, 120              ; restore stack
          mov     rax, 0                ; value to return (0)
          ret

MainProc ENDP
END