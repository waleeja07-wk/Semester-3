[org 0x0100]

MOV SI, 0
MOV CX, 3
label:
	MOV Al, [arr+SI]
	CMP Al, 25
	JE exit
	INC SI
	LOOP label
exit:
MOV AX, 4c00h
INT 21H

arr: db 10, 20, 25, 50
