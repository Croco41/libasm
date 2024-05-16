section .text
global ft_strcmp

ft_strcmp:
    xor rcx, rcx        ; Initialiser rcx à 0 pour l'utiliser comme index

.compare_loop:
    mov			al, [rdi + rcx] ; Charger le caractère actuel de s1 dans al
    mov			bl, [rsi + rcx] ; Charger le caractère actuel de s2 dans bl
    cmp			al, bl          ; Comparer les caractères de s1 et s2
    jne			.not_equal      ; Si les caractères ne sont pas égaux, sauter à .not_equal
    test		al, al         ; Vérifier si nous avons atteint la fin de s1 (al == 0)
    jz			.equal           ; Si c'est le cas, les chaînes sont égales, sauter à .equal
    inc			rcx             ; Incrémenter l'index
    jmp			.compare_loop   ; Répéter la comparaison

.not_equal:
    sub			al, bl          ; Calculer la différence entre les caractères
    movsx		eax, al       ; Étendre la différence en 32 bits signé
    ret                 ; Retourner la différence (eax contient la différence)

.equal:
    xor			eax, eax        ; Mettre eax à 0 (les chaînes sont égales)
    ret                 ; Retourner 0
