[org 0x0100]

mov bx, 0
mov cx, 10
mov word [max], arr
start:
	add AX, [arr+bx]
	cmp [max], AX
	jge changemax
	add bx, 1
	sub cx, 1
	jnz start
	jmp exit
changemax:
	mov [max], AX
	add bx, 1
	sub cx, 1
	jnz start
exit:
mov AX, 4c00h
int 21h

arr: dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
max: dw 0
