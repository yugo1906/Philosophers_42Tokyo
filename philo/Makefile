NAME				=	philo
CFLAGS			=	-Wall -Wextra -Werror
SRC_DIR			=	./src
SRCS 				= main.c \
							validation/validate_args.c \
							utils/ft_atoi.c \
							utils/ft_isdigit.c \
							service/init.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 				= ${SRCS:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJS) philosophers.h
	cc $(CFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean $(NAME)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

.PHONY: all clean fclean re sanitize