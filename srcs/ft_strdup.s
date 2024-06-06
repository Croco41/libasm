;char *strdup(const char *s);
;The  strdup()  function  returns  a  pointer to a new string which is a duplicate of the string s.  
;Memory for the new string is obtained with mal‐loc(3), and can be freed with free(3).

section .text
global ft_strdup
extern malloc
extern ft_strcpy
extern ft_strlen

;1 er arg rdi , 2eme arg rsi
ft_strdup:
	; Sauvegarder les registres utilisés
    push		rdi

	; Calculer la longueur de la chaîne source (s) + 1 (pour le caractère nul)
	;mov			r9, rdi      ; Déplacer le premier argument (la chaîne source) dans rdi
    call		ft_strlen     ; Appeler ft_strlen pour obtenir la longueur de la chaîne
    add			rax, 1        ; Ajouter 1 pour inclure le caractère nul

    ; Allouer de la mémoire pour la nouvelle chaîne
    mov			rdi, rax       ; Déplacer la taille nécessaire dans rdi
    call		malloc        ; Appeler malloc

    ; Vérifier si malloc a réussi
    test 		rax, rax      ; Tester si rax (le pointeur retourné par malloc) est nul
    je 			.malloc_failed  ; Sauter à .malloc_failed si malloc a échoué

	; Sauvegarder le pointeur vers la nouvelle mémoire allouée
    ;mov			rdx, rax       ; Sauvegarder le pointeur de la nouvelle mémoire dans rdx


    ; Copier la chaîne source dans la nouvelle mémoire
	pop			r8
    mov 		rdi, rax     ; Déplacer le pointeur vers la nouvelle mémoire dans rdi
    mov 		rsi, r8       ; Déplacer le pointeur vers la chaîne source dans rsi
    call 		ft_strcpy     ; Appeler ft_strcpy

    ; Retourner le pointeur vers la nouvelle chaîne
	;mov			rax, rdx		; placer le ponteur de la new chaine dans rax
    ;pop			rdi
	ret

.malloc_failed:
    xor 		rax, rax       ; Mettre rax à 0 pour indiquer l'échec
    pop			rdi
	ret