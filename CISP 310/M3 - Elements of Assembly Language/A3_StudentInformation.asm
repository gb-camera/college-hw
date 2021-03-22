; CISP 310 - Michael Dinh
; Assignment 3: Student Information
; 9/27/2020

INCLUDE io.h

.DATA
creditsH  DWORD   ?
creditsT  DWORD   ?
prompt1   BYTE    "Enter your name.", 0
prompt2   BYTE    "Enter the name of your degree program.", 0
prompt3   BYTE    "Enter number of credits taken so far.", 0
prompt4   BYTE    "Enter total number of credits required.", 0
yourName  BYTE    40 DUP (?)
degree    BYTE    40 DUP (?)
string    BYTE    40 DUP (?)
resultLb1 BYTE    "Your name is", 0
resultLb2 BYTE    "Your degree / major is", 0
resultLb3 BYTE    "The number of credits you need to graduate is", 0
creditsN  BYTE    11 DUP(?), 0

.CODE
MainProc  PROC
		  ; reserve stack space
          sub     rsp, 120

		  ; first, read user's name and degree
          input   prompt1, yourName, 40
          input   prompt2, degree, 40

		  ; next, get # of credits obtained and convert to integer
		  input   prompt3, string, 40
		  atod    string
		  mov     creditsH, eax

		  ; repeat this process for # of credits needed to graduate
		  input   prompt4, string, 40
		  atod    string
		  mov     creditsT, eax
        
		  ; rather than adding values, we need to subtract
		  ; credits total - credits earned = credits needed

          mov     eax, creditsT         ; put creditsT to EAX
          sub     eax, creditsH         ; sub creditsH from EAX
          dtoa    creditsN, eax         ; convert to ASCII, store in creditsN

		  ; last, we need to output our results to the user
		  output  resultLb1, yourName
		  output  resultLb2, degree
          output  resultLb3, creditsN

		  ; program end
          add     rsp, 120              ; restore stack
          mov     rax, 0                ; value to return (0)
          ret

MainProc ENDP
END

