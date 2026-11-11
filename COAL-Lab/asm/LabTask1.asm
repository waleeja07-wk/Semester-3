[org 0x0100]

MOV SI, 0
MOV BL, 7
MOV CL, 0
label:
	MOV AL, [arr+SI]
	CMP AL, 3
	JNZ Next
	ADD CX, 1
Next:
	ADD SI, 1
	SUB BL, 1
	jnz label
MOV AX, 4c00h
INT 21h

arr: db 3, 7, 3, 9, 2, 7, 3
