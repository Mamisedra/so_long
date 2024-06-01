NAME	= so_long
PRINTF_DIR	= ./ft_printf
LIBFT_DIR	= ./libft
GNL_DIR	= ./GetNextLine
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
MLX		= -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS	= Game_finish.c Game_to_list.c input_image.c Perso_move.c add_utils.c\
		Map_error_utils.c Map_error.c Map_print.c Player_pos.c main.c multibonus.c\
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