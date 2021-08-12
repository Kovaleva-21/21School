section .text
    global _ft_strcmp
_ft_strcmp:
    xor rax, rax
    xor rbx, rbx
    xor r9, r9
_cmp:
    mov al, byte[rdi + r9]
    mov bl, byte[rsi + r9]
    cmp al, 0
    je  _return
    cmp bl, 0
    je  _return
    cmp al, bl
    jne  _return
    inc r9
    jmp _cmp
_return:
    sub rax, rbx
    ret

