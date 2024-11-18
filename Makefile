CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printint.c ft_printu.c ft_printlh.c ft_printptr.c
INC = ft_printf.h
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
.PHONY = NAME, all, clean, fclean, re

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -c

$(NAME) : $(OBJ)
	ar -rcs $@ $^

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
