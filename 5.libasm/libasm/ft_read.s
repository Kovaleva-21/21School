section .text
    global _ft_read
extern ___error
_ft_read:
    mov rax, 0x2000003          ; rax = syscall read number
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