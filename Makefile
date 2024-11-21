NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c print_int.c print_ptr.c print_str_or_null.c print_uint_base.c
OBJ = $(SRC:.c=.o) libft/libft.a
HDR = ft_printf.h ft_printf_utils.h ./libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	cp libft/libft.a $(NAME)
	ar rs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<

libft/libft.a:
	(cd libft && make)

a.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: a.out
	./a.out

clean:
	rm -vf $(OBJ) a.out
	(cd libft && make fclean)

fclean: clean
	rm -vf $(NAME)
	
re: fclean all

.PHONY=all clean fclean re test