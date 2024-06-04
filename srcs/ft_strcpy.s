;char *strcpy(char *dest, const char *src);
;The  strcpy() function copies the string pointed to by src, 
;including the terminating null byte ('\0'), to the buffer pointed to by dest.  
;The strings may not overlap, and the destination string dest must be large enough to receive the  copy.
; The strcpy() and strncpy() functions return a pointer to the destination string dest.

section .text
global ft_strcpy

;1er arg rdi, 2 eme arg rsi
ft_strcpy:

	;push		rsi
	;push		rdi
	mov			rax, rdi

	test		rsi, rsi  ; Vérifier si le premier argument (rsi) est NULL
    jz			.return_null    ; Sauter à return si la chaîne est NULL

.copy_char:
	movzx		r8, byte [rsi]     ; Charger un caractère de 'src' dans r8
	mov			[rdi], r8b           ; Écrire le caractère dans 'dest'
	test		r8, r8             ; Vérifier si le caractère est le caractère nul
	je			.return              ; Si c'est '\0' (fin de la chaîne), sauter à return
    inc			rsi                 ; Sinon, incrémenter src
	inc			rdi                 ; Sinon, incrémenter dest
    jmp			.copy_char          ; Sauter à next_char pour continuer la boucle

.return_null:
    ;xor			rax, rax              ; Mettre rax à 0 pour indiquer un retour NULL
	;pop			rdi                 ; Restaurer le registre rsi
    ;pop			rsi                 ; Restaurer le registre rdi
    ret

.return:
	;pop			rdi
	;pop			rsi
    ret                   ; Retourner la valeur de rdi