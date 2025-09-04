global	ft__strcmp

section	.text
	ft__strcmp:
		mov			rax, 0
	
	loop:
		mov			al, [rdi]
		test 		[rsi], al
		inc			rdi
		inc			rsi
		je 			loop
		mov			rax, [rdi]
		SUB			rax, [rsi]
		ret

section .note.GNU-stack noexec