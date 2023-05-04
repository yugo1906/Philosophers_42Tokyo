NAME				=	test
CFLAGS			=	-Wall -Wextra -Werror
LIBFT_DIR		=	./include_libft
PRINTF_DIR	=	./include_ft_printf
GNL_DIR			=	./include_gnl
SRC_DIR			=	./src
SRCS 				= main.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 				= ${SRCS:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make -C $(GNL_DIR)
	cc $(CFLAGS) \
	$(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a -o $@

clean :
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		make clean -C $(GNL_DIR)
		rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(NAME)

re: fclean $(NAME)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

.PHONY: all clean fclean re sanitize