#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Pour utiliser strlen et strcpy standard pour comparaison

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define GREY "\033[1;37m"
#define ORANGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"

// Déclarations externes pour les fonctions en assembleur
extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

// Fonctions de test
void test_strlen(void)
{
	printf(ORANGE "========================\n");
	printf("=   Test de strlen :   =\n");
	printf("========================\n\n" RESET);

	char *strings[] = {
		"",						   // Chaîne vide
		"hello",				   // Chaîne normale
		"this is a longer string", // Chaîne plus longue
		NULL					   // Fin du tableau
	};

	char *test_title[] = {
		"Chaîne vide\n",
		"Chaîne normale\n",
		"Chaîne plus longue\n",
		NULL};

	for (int i = 0; strings[i] != NULL; i++)
	{
		printf(PURPLE "%s" RESET, test_title[i]);
		printf("ft_strlen :         Length of '%s' is %zu.\n", strings[i], ft_strlen(strings[i]));
		printf("strlen standard :    Length of '%s' is %zu.", strings[i], strlen(strings[i]));
		if (strlen(strings[i]) == ft_strlen(strings[i]))
			printf(GREEN " |--> YOUPI C'EST BON !\n\n" RESET);
		else
			printf(RED " |--> HOUSTON, ON A UN PROBLEME...\n\n" RESET);
	}

	// CAS DU POINTEUR NULL : ATTENTION la fonction strlen std n'est pas protégée contre NULL -> Segfault...
	// char *null_string = NULL;

	// printf(PURPLE "Test with NULL pointer\n" RESET);
	// printf("ft_strlen : Length of null_string is %zu.\n", ft_strlen(null_string));
	// printf("strlen standard : Length of null_string is %zu.", strlen(null_string));
	// if (strlen(null_string) == ft_strlen(null_string))
	//     printf(GREEN " |--> YOUPI C'EST BON !\n\n" RESET);
	// else
	//     printf(RED " |--> HOUSTON, ON A UN PROBLEME...\n\n" RESET);
}

int test_strcpy(void)
{
	printf(ORANGE "========================\n");
	printf("=   Test de strcpy :   =\n");
	printf("========================\n\n" RESET);

	char *ft_dest = NULL;
	char *std_dest = NULL;

	char *src[] = {
		"",						   // Chaîne vide
		"hello",				   // Chaîne normale
		"this is a longer string", // Chaîne plus longue
		NULL					   // Fin du tableau
	};

	char *test_title[] = {
		"Chaîne vide\n",
		"Chaîne normale\n",
		"Chaîne plus longue\n",
		NULL};

	for (int i = 0; src[i] != NULL; i++)
	{
		printf(PURPLE "%s" RESET, test_title[i]);
		ft_dest = malloc(strlen(src[i]) + 1);
		if (ft_dest == NULL)
		{
			perror("malloc");
			return 1;
		}
		std_dest = malloc(strlen(src[i]) + 1);
		if (std_dest == NULL)
		{
			perror("malloc");
			return 1;
		}
		ft_dest = ft_strcpy(ft_dest, src[i]);
		std_dest = strcpy(std_dest, src[i]);

		printf("ft_strcpy :         Destination = %s\n", ft_dest);
		printf("strcpy standard :    Destination = %s", std_dest);
		if (strcmp(ft_dest, std_dest) == 0)
			printf(GREEN " |--> YOUPI C'EST BON !\n\n" RESET);
		else
			printf(RED " |--> HOUSTON, ON A UN PROBLEME...\n\n" RESET);
	}

	free(ft_dest);
	free(std_dest);
	return 0;
}

void test_strcmp(void)
{
	printf(ORANGE "========================\n");
	printf("=   Test de strcmp :   =\n");
	printf("========================\n\n" RESET);

	char *first[] = {
		"",							// Chaîne vide
		"same string",				// Chaînes identiques
		"First octet different",	// Chaînes différente
		"Interior octet different", // Chaînes différentes
		"Chaîne très très très grande",
		"Chaîne petite",
		NULL // Fin du tableau
	};

	char *second[] = {
		"",							// Chaîne vide
		"same string",				// Chaînes identiques
		"first octet different",	// Chaînes différentes
		"Interior Octet different", // Chaînes différente
		"Chaîne petite",
		"Chaîne très très très grande",
		NULL // Fin du tableau
	};

	char *test_title[] = {
		"On compare des chaînes vides\n",
		"On compare deux chaînes identiques\n",
		"On compare des chaînes différentes au 1er octet\n",
		"On compare des chaînes différentes à octet milieu\n",
		"Chaîne first plus longue que chaîne second\n",
		"Chaîne first plus petite que chaîne second\n",
		NULL};

	int ft_res;
	int std_res;

	for (int i = 0; first[i] != NULL; i++)
	{
		printf(PURPLE "%s" RESET, test_title[i]);
		printf("chaîne 1 = %s\nchaîne 2 = %s\n\n", first[i], second[i]);

		ft_res = ft_strcmp(first[i], second[i]);
		std_res = strcmp(first[i], second[i]);

		printf("ft_strcmp :         Destination = %d\n", ft_res);
		printf("strcmp standard :    Destination = %d", std_res);
		if (ft_res == std_res)
			printf(GREEN " |--> YOUPI C'EST BON !\n\n" RESET);
		else
			printf(RED " |--> HOUSTON, ON A UN PROBLEME...\n\n" RESET);
	}
}

int main()
{
	test_strlen(); // Tester ft_strlen
	test_strcpy(); // Tester ft_strcpy
	test_strcmp();
	return 0;
}
