section .text
    global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy
_ft_strdup:
    push rdi
    call _ft_strlen     ; rax = strlen(rdi)
    inc rax             ; for "\n"
    mov rdi, rax
    call _malloc        ; rax = malloc(rdi)
    cmp rax, 0
    je _return
    mov rdi, rax
    pop rsi
    call _ft_strcpy     ; rax =  strcpy(rdi, rsi)
_return:
    ret