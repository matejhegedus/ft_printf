NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putnbr_unsigned_fd.c ft_putnbr_base_unsigned.c
OBJ = $(SRC:.c=.o) libft/libft.a
HDR = ft_printf.h ./libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -g -o $@ $<

libft/libft.a:
	(cd libft && make)

a.out: $(OBJ)
	$(CC) $(CFLAGS) -g -o $@ $^

test: a.out
	./a.out

clean:
	rm -vf $(OBJ) a.out
	(cd libft && make fclean)

fclean: clean
	rm -vf $(NAME)
	
re: fclean all

.PHONY=all clean fclean re test