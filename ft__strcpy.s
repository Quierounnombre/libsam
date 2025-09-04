global	ft__strcpy


section .text
	ft__strcpy:
		mov			rax, rdi
	loop:
		mov			r14b , [rsi]
		mov			[rdi], r14b
		inc 		rsi
		inc 		rdi
		test		r14b, r14b
		jne	loop 
		ret

section .note.GNU-stack noexec