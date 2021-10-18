NAME = ft_printf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCDIR = src

SRCS := $(shell find $(SRCDIR) -name "*.c")
OBJ = $(SRC:.c=.o)

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: ${NAME}

${NAME}: 
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