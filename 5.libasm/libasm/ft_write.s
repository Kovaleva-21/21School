section .text
    global _ft_write
extern ___error
_ft_write:
    mov rax, 0x2000004          ; rax = syscall write number
    syscall
    jc _error
    ret
_error:
    push rbx                    ; save rbx value to stack
    mov  rbx, rax               ; rbx = rax
    call ___error
    mov  [rax], rbx             ; dereferenced rax = rbx
    mov  rax, -1                ; set rax as -1
    pop  rbx                    ; extract old rbx's value from stack
    ret