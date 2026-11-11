[org 0x0100]

MOV CX, 3
MOV SI, 1
MOV BL, [arr]
label:
	MOV AL, [arr+SI]
	cmp AL, BL
	JAE SKIP 
	MOV BL, AL
SKIP:
	INC SI
	LOOP label
MOV AX, 4c00h
INT 21H
arr: db 10, 20, 50, 40
