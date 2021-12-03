NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_printf.c printers.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
			${CC} ${FLAGS} -c ${SRC}
			${AR} ${NAME} ${OBJ}
			echo 'Archive created, object files created'
clean:
			${RM} ${OBJ}
			echo 'Object files cleaned'

fclean: clean
			${RM} ${NAME}
			echo 'Archive cleaned'

re: fclean all

.PHONY: all, clean, fclean, re
