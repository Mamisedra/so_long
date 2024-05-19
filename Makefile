NAME	= so_long
PRINTF_DIR	= ./ft_printf
LIBFT_DIR	= ./libft
GNL_DIR	= ./GetNextLine
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
MLX		= -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS	= interface.c main.c initMap.c getMap.c checkerror.c error_utils.c\
		$(GNL_DIR)/get_next_line_utils_bonus.c $(GNL_DIR)/get_next_line_bonus.c
OBJS	= ${SRCS:.c=.o}

all : ${NAME}

.c:.o
	$(CC) $(FLAGS) -Iminilibx-linux -c $< -o $@

fusion : ft_printf libft ${OBJS}
	@make -C ${PRINTF_DIR}
	@make -C ${LIBFT_DIR}
	@cp ${PRINTF_DIR}/libftprintf.a ./
	@cp ${LIBFT_DIR}/libft.a ./

${NAME} : fusion
	@${CC} ${OBJS} libft.a libftprintf.a ${MLX} -o ${NAME}

clean :
	@make clean -C ${PRINTF_DIR}
	@make clean -C ${LIBFT_DIR}
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME} libft.a libftprintf.a so_long

re : fclean all

.PHONY :
	all clean fclean re
