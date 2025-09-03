global ft__strlen

section .text
	ft__strlen:
		mov	rax, 0
		jmp loop
		
	advance_ptr:
		inc rdi
		inc rax
	
	loop:
		cmp byte	[rdi], 0
		jne 		advance_ptr
		ret

section .note.GNU-stack noexec