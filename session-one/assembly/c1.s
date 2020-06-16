section .rodata
	msg: db 'hackaday-u',10;


section .text
		global _start
	_start:
		mov rdi, 1
		mov rsi, msg
		mov rdx, 10
		mov rax, 1
		syscall
		mov rdi, 0
		mov rax, 60
		syscall
