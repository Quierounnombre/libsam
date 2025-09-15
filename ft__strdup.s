global	ft__strdup

extern	ft__strlen
extern	malloc
extern	ft__strcpy

section	.text
	ft__strdup:
		mov					r8, rdi
		call	ft__strlen
		inc					rax
		mov					rdi, rax
		call	malloc 		wrt ..plt
		test				rax, rax
		jz		error	
		mov					rdi, rax
		mov					rsi, r8
		call	ft__strcpy
		ret
		
	error:
		mov				rax, 0
		ret

section .note.GNU-stack noexec