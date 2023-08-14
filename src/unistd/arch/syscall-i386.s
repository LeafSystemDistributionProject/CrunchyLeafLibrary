.globl _syscall

_syscall:
	push %ebp

	mov 32(%esp), %ebp
	mov 28(%esp), %edi
	mov 24(%esp), %esi
	mov 20(%esp), %edx
	mov 16(%esp), %ecx
	mov 12(%esp), %ebx
	mov 8(%esp), %eax
	
	int $0x80

	pop %ebp
	ret
