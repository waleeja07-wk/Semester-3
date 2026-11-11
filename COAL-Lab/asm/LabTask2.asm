[org 0x0100]

MOV SI, 0
MOV DI, 5
MOV CX, 3

label:
	MOV AL, [arr+SI]
	MOV BL, [arr+DI]
	MOV [arr+SI], BL    ; store back swapped
	MOV [arr+DI], AL
	ADD SI, 1
	SUB DI, 1
	SUB CX, 1
	JNZ label

MOV AX, 4c00h
INT 21h



arr: db 10, 20, 30, 40, 50, 60
