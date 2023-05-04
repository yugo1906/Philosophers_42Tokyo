NAME		=	libgnl.a
CFLAGS	=	-Wall -Wextra -Werror
SRCS		=	get_next_line.c \
					get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
