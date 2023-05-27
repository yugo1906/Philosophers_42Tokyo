NAME				=	philo
CFLAGS			=	-Wall -Wextra -Werror -I ./include
CFLAGS			=	-I ./include
SRC_DIR			=	./src
OBJ_DIR			=	./obj
PHILO_DIR		=	philo_service/
SRCS 				= main.c \
							validation/validate_args.c \
							func_utils/ft_atoi.c \
							func_utils/ft_isdigit.c \
							$(PHILO_DIR)init.c \
							$(PHILO_DIR)put_philo_log.c \
							$(PHILO_DIR)error_handling.c \
							$(PHILO_DIR)philo_routine.c \
							$(PHILO_DIR)philo_routine_detail.c \
							$(PHILO_DIR)monitor_routine.c \
							$(PHILO_DIR)routine_utils_func.c \
							$(PHILO_DIR)philo_free_utils.c
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