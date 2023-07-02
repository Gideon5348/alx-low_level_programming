section .data
	message db 'Hello, Holberton', 0
	format db "%s", 0

section .text
	extern printf

global main
main:
	sub rsp, 8
	mov rdi, format
	mov rsi, message
	xor eax, eax
	call printf
	add rsp, 8
	xor eax, eax
	ret
format: db `Hello, Holberton\n`,0
