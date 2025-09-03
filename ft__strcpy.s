global	ft__strcpy


section .text
	ft__strcpy:
		mov			rax, rsi
	loop:
		mov			al, [rsi]
		mov			[rdi], al
		inc 		rsi
		inc 		rdi
		test		al, al
		jne	loop 
		ret

section .note.GNU-stack noexec