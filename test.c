#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Pour utiliser strlen et strcpy standard pour comparaison

// Déclarations externes pour les fonctions en assembleur
extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);

// Fonctions de test
void test_strlen(void)
{
	char *strings[] = {
		"",						   // Chaîne vide
		"hello",				   // Chaîne normale
		"this is a longer string", // Chaîne plus longue
		NULL					   // Fin du tableau
	};

	printf("\033[34mTest de la fonction ft_strlen:\033[0m\n");
	for (int i = 0; strings[i] != NULL; i++)
	{
		printf("Length of '%s' is %zu (ft_strlen).\n", strings[i], ft_strlen(strings[i]));
		printf("Length of '%s' is %zu (strlen).\n", strings[i], strlen(strings[i]));
	}

	char *null_string = NULL;

	// Test avec NULL
	printf("Test with NULL pointer: ");
	size_t length = ft_strlen(null_string);
	printf("Length is %zu.\n", length);
	printf("\n");
}

void test_strcpy(void)
{
	char src1[] = "Hello, world!";
	char dest1[50];
	char compare_dest1[50]; // Destination pour la fonction standard strcpy

	char src2[] = "Bonjour le monde";
	char dest2[50];
	char compare_dest2[50]; // Destination pour la fonction standard strcpy

	char src3[] = ""; // Chaîne vide
	char dest3[50];
	char compare_dest3[50]; // Destination pour la fonction standard strcpy

	char src4[] = "Hello";
	char dest4[] = "123456789";
	char compare_dest4[] = "123456789"; // Destination pour la fonction standard strcpy

	char src5[] = "toto";
	char dest5[] = "123456789";
	char compare_dest5[] = "123456789"; // Destination pour la fonction standard strcpy

	printf("\033[34mTest de la fonction ft_strcpy:\033[0m\n");

	ft_strcpy(dest1, src1);
	strcpy(compare_dest1, src1);
	printf("ft_strcpy copied '%s' into dest1: '%s'\n", src1, dest1);
	printf("strcpy copied '%s' into compare_dest1: '%s'\n", src1, compare_dest1);
	printf("\n");

	ft_strcpy(dest2, src2);
	strcpy(compare_dest2, src2);
	printf("ft_strcpy copied '%s' into dest2: '%s'\n", src2, dest2);
	printf("strcpy copied '%s' into compare_dest2: '%s'\n", src2, compare_dest2);
	printf("\n");

	ft_strcpy(dest3, src3);
	strcpy(compare_dest3, src3);
	printf("ft_strcpy copied an empty string into dest3: '%s'\n", dest3);
	printf("strcpy copied an empty string into compare_dest3: '%s'\n", compare_dest3);
	printf("\n");

	ft_strcpy(dest4, src4);
	strcpy(compare_dest4, src4);
	printf("ft_strcpy copied '%s' into dest4: '%s'\n", src4, dest4);
	printf("strcpy copied '%s' into compare_dest4: '%s'\n", src4, compare_dest4);
	printf("\n");

	ft_strcpy(dest5, src5);
	strcpy(compare_dest5, src5);
	printf("ft_strcpy copied '%s' into dest4: '%s'\n", src5, dest5);
	printf("strcpy copied '%s' into compare_dest4: '%s'\n", src5, compare_dest5);
	printf("\n");
}

int main()
{
	test_strlen(); // Tester ft_strlen
	test_strcpy(); // Tester ft_strcpy
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// // #include "libasm.a"

// #include <string.h>

// // Déclaration de la fonction pour que le compilateur C sache qu'elle existe et comment l'appeler.
// // extern size_t ft_strlen(const char *str);
// extern char *ft_strcpy(char *dest, const char *src);

// void test_strcpy(void)
// {
// 	char src[] = "toto";
// 	char dest[] = "123456789";

// 	ft_strcpy(dest, src);
// }

// int main()
// {
// 	test_strcpy();
// 	// char src[] = "toto";
// 	// char dest[] = "123456789";

// 	// ft_strcpy(dest, src);
// 	// strcpy(compare_dest5, src5);
// 	// printf("ft_strcpy copied '%s' into dest4: '%s'\n", src, dest);
// 	// printf("strcpy copied '%s' into compare_dest4: '%s'\n", src5, compare_dest5);
// 	// printf("\n");

// 	// printf("\nStrcpy :\n");
// 	// // printf("Source = '%s'\n", src);
// 	// // printf("Dest = '%s'\n", dest);
// 	// // printf("Dest after strcpy = '%s'\n", ft_strcpy(dest, src));
// 	// ft_strcpy(dest, src);
// 	// printf("Dest after strcpy = '%s'\n", dest);

// 	return 0;
// }
