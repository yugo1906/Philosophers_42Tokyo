NAME				=	philo
CFLAGS			=	-Wall -Wextra -Werror
SRC_DIR			=	./src
SRCS 				= main.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 				= ${SRCS:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean $(NAME)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

.PHONY: all clean fclean re sanitize