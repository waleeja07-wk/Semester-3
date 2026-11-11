[org 0x0100]

mov al, [marks]
mov SI, 0
mov DI, 10
mov bl, 0
;mov dl, 0

start:
	mov cl, [marks+SI]
	cmp cl, al
	jle next
	mov al, cl
next: 
	ADD SI, 1
	SUB DI, 1
	jnz start
	
mov ax, 4c00h
INT 21H

marks: db 14, 53, 82, 27, 10, 65, 51, 73, 92, 20

