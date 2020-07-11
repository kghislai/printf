NAME = libftprintf.a

HEADER = ft_print.h

OBJ =  ft_printf.o \
	print_u.o \
	print_xX.o \
	print_percent.o \
	accuracy.o \
	lenght_line.o \
	output_function.o \
	ft_atoi.o \
	additional_function.o\
	print_d.o \
	print_s.o \
	print_p.o \
	print_c.o \
	
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