NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OBJ = $(SRC:.c=.o) 
HDR = ft_printf.h ./libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<

a.out: $(OBJ) test.o
	$(CC) $(CFLAGS) -g -o $@ $^

test: a.out
	./a.out

clean:
	rm -vf $(OBJ) test.o a.out

fclean: clean
	rm -vf $(NAME)
	
re: fclean all

.PHONY=all clean fclean re test