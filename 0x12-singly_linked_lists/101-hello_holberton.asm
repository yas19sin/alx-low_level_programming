section .data
	hello db 'Hello, Holberton', 0

section .text
	global main

main:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, 17
	int 0x80

	mov eax, 1
	xor ebx, ebx
	int 0x80
