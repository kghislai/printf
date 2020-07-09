NAME = libftprintf.a

HEADER = ft_print.h

OBJ =  ft_printf.o
	
SRC = $(OBJ:.o=.c)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):$(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o:%.c
	gcc -I $(HEADER) -c $< -o $@
test:
	gcc -g $(SRC) main.c
	./a.out
testF:
	gcc -g $(SRC) main.c $(FLAGS)
	./a.out
clean:
	/bin/rm -f $(OBJ)
fclean:clean
	/bin/rm -f $(NAME)
re:fclean all