section .text
    global _ft_strcpy
_ft_strcpy:
    xor rax, rax
_cpy:
    cmp byte[rsi + rax], 0
    je _return
    mov dl, byte[rsi + rax]
    mov byte[rdi + rax], dl
    inc rax
    jmp _cpy
_return:
    mov byte[rdi + rax], 0
    mov rax, rdi
    ret