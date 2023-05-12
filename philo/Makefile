NAME				=	philo
CFLAGS			=	-Wall -Wextra -Werror -I ./include
SRC_DIR			=	./src
OBJ_DIR			=	./obj
SRCS 				= main.c \
							validation/validate_args.c \
							func_utils/ft_atoi.c \
							func_utils/ft_isdigit.c \
							philo_service/init.c \
							philo_service/put_philo_log.c \
							philo_service/error_handling.c \
							philo_service/philo_thread_logic.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 				= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re: fclean $(NAME)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

.PHONY: all clean fclean re sanitize