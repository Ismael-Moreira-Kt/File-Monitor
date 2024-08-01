section .text
global read_syscall


read_syscall:
    mov rax, 0
    syscall
    ret