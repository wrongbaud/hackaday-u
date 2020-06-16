section .text
		global _start
	_start:
		mov rax, 0x2FFF
		mov rbx, 0x3000
		or rax,rbx
		mov rcx, 0x10000
		sub rcx, rax
		add rcx, rbx
		cmp rax,rbx
		jg _greater
		mov rax, 0x2
	_greater:
		mov rax, 0x1
		ret
