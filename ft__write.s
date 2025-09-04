global	ft__write

section	.text
	ft__write:
		mov			rax, 1
		syscall
		ret





section .note.GNU-stack noexec