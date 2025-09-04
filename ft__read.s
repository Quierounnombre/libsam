global	ft__read

section	.text
	ft__read:
		mov			rax, 0
		syscall
		ret

section .note.GNU-stack noexec