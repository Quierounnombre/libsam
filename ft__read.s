global	ft__read

extern __errno_location

section	.text
	ft__read:
		mov				rax, 0
		syscall
		test			rax, rax
		js		error		
		ret

	error:
		mov				r15, rax
		call			__errno_location
		neg				r15
		mov				[rax], r15
		mov				rax, -1
		ret

section .note.GNU-stack noexec