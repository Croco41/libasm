section .text
global ft_read
extern __errno_location

ft_read:
    mov rax, 0          ; Numéro de l'appel système pour `read`
    syscall             ; Appeler le noyau

    ; Vérifier si une erreur s'est produite
    test rax, rax       ; Tester si rax est négatif
    jns .done           ; Si rax n'est pas négatif (aucune erreur), sauter à .done

    ; Récupérer l'adresse de errno
    neg rax             ; Négativer rax pour obtenir la valeur positive de l'erreur
    mov rdi, rax        ; Placer la valeur de l'erreur dans rdi
    call __errno_location ; Appeler __errno_location pour obtenir le pointeur vers errno
    mov [rax], edi      ; Stocker l'erreur dans errno
    mov rax, -1         ; Mettre rax à -1 pour indiquer une erreur

.done:
    ret                 ; Retourner la valeur de `syscall`
