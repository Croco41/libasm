;ssize_t write(int fd, const void *buf, size_t count);

section .text
global ft_write

; Déclaration de l'extern pour accéder à errno
extern __errno_location

ft_write:
    mov			rax, 1          ; Numéro de l'appel système pour `write`
    syscall             ; Appeler le noyau, invoque l'appel systeme


    ; Vérifier si une erreur s'est produite
    test        rax, rax        ; tester si rax est negatif
    jns			.done           ; Si pas d'erreur (rax n'est pas negatif), sauter à .done

    ; Récupérer l'adresse de errno
    neg         rax             ; Négativer rax pour obtenir la valeur positive de l'erreur
    mov         rdi, rax        ; Placer la valeur de l'erreur dans rdi
    call		__errno_location
    mov			[rax], edi      ; Stocker l'erreur dans errno
    mov         rax, -1         ; Mettre rax à -1 pour indiquer une erreur

.done:
    ret                 ; Retourner la valeur de `syscall`
