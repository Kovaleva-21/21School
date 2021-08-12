section .text
    global _ft_strlen
_ft_strlen:
    xor rax, rax
_length:
    cmp byte[rdi + rax], 0
    je _return
    inc rax
    jmp _length
_return:
    ret