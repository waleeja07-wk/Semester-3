[org 0x0100]

MOV SI, 0
MOV CX, 4
MOV Bl, 0
MOV DL, 0

label:
	ADD Bl, [arr+SI]
	JNC noCarry
	MOV dl, 1

noCarry:
	MOV SI, 1
	loop label
MOV Ah, 4ch
MOV AL, DL
INT 21H
arr: db 200, 100, 50, 25
