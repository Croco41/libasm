# Makefile for the ft_strlen function in assembly

NAME = libasm.a
NASM = nasm
FLAGS = -f elf64
AR = ar rcs # Commande pour archiver les fichiers objets en une bibliothèque statique.
RM = rm -f
SRCS = srcs/ft_strlen.s srcs/ft_strcpy.s
OBJS = $(SRCS:.s=.o)
TEST = test
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(TEST)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(FLAGS) $< -o $@

$(TEST): $(NAME)
	$(CC) $(CFLAGS) -o $(TEST) test.c -L. -lasm

clean:
	$(RM) $(OBJS) $(TEST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
