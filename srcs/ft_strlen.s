; File: ft_strlen.s


;section .text : Cette directive indique que le code qui suit sera placé dans la section "text" du fichier binaire. 
;La section text est typiquement là où le code exécutable est stocké.

section .text
global ft_strlen            ; Rendre la fonction accessible de l'extérieur, appelable par d'autres fichiers

ft_strlen:
    xor rax, rax            ; rax est utilisé pour le compteur de longueur, initialisé à 0
	;xor est une opération logique XOR; XOR'ing un registre avec lui-même efface son contenu (le met à zéro)

    test rdi, rdi           ; Vérifier si le premier argument (rdi) est NULL
	; teste si le registre rdi (qui contient le premier argument de la fonction, 
	;c'est-à-dire le pointeur vers la chaîne de caractères) est égal à zéro (NULL).

    jz .return              ; Sauter à return si la chaîne est NULL
	;Saut conditionnel à l'étiquette .return si ZF (flag zéro) est mis par le test. jz signifie "jump if zero",
	;donc si rdi est NULL, il saute à la fin de la fonction pour retourner la valeur actuelle de rax (qui est 0)

;Boucle pour compter la longueur
.next_char:
    cmp byte [rdi + rax], 0 ; Comparer le caractère à l'index rax avec 0
	
	;cmp byte [rdi + rax], 0 : Compare le caractère pointé par rdi + rax (où rdi est l'adresse de début de la chaîne 
	;et rax est l'index du caractère actuel) avec 0 (le caractère nul qui marque la fin des chaînes)

    je .return              ; Si c'est '\0' (fin de la chaîne), sauter à return
    inc rax                 ; Sinon, incrémenter rax
    jmp .next_char          ; Sauter à next_char pour continuer la boucle
.return:
    ret                     ; Retourner la valeur de rax (la longueur)
