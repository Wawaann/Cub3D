SRC		=	main.c					\
			audio.c					\
			close.c					\
			load_img.c				\
			update.c				\
			draw/get_minimap.c		\
			draw/hand.c				\
			draw/minimap_utils.c	\
			draw/minimap.c			\
			draw/obj_utils.c		\
			draw/objects.c			\
			draw/put_pixel.c		\
			draw/stamina.c			\
			event/door.c			\
			event/input.c			\
			event/key.c				\
			event/minimap.c			\
			event/mouse.c			\
			event/move.c			\
			event/move_utils.c		\
			parsing/check_arg.c		\
			parsing/convert.c		\
			parsing/exit.c			\
			parsing/flood_fill.c	\
			parsing/get_arg.c		\
			parsing/get_map.c		\
			parsing/get_param.c		\
			parsing/test_map.c		\
			parsing/test_param.c	\
			parsing/utils.c			\
			pathfinding/astar.c		\
			pathfinding/lst.c		\
			pathfinding/node.c		\
			pathfinding/utils.c		\
			raycast/draw_column.c	\
			raycast/draw_texture.c	\
			raycast/init.c			\
			raycast/raycasting.c	\

SRC		:=	$(addprefix src/, $(SRC))

OBJ_DIR	=	obj/
OBJ		=	$(patsubst src/%.c,$(OBJ_DIR)%.o,$(SRC))

INCLUDE	=	-I./include/

MLX_INCLUDE	=	-I./.mlx

UNAME := $(shell uname -s)

MINILIB	=	libmlx_Linux.a
LIB		=	-L./lib -lft -L./.mlx -lmlx_Linux -lXext -lX11 -lbsd -lm
CC		=	clang -o $(NAME) $(MLX_INCLUDE) $(INCLUDE) $(OBJ) $(LIB) $(FLAG)

FLAG	=	-Wall -Wextra -Werror -g3

NAME	=	Cub3D

DEFAULT	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
CYAN	=	\033[0;36m
BOLD	=	\033[1m

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)draw
	@mkdir -p $(OBJ_DIR)event
	@mkdir -p $(OBJ_DIR)parsing
	@mkdir -p $(OBJ_DIR)pathfinding
	@mkdir -p $(OBJ_DIR)raycast
	@echo "$(CYAN)Compiling:$(DEFAULT) $<"
	@clang $(INCLUDE) $(MLX_INCLUDE) $(FLAG) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@if [ ! -e ./.mlx/libmlx_Linux.a ]; then \
		echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) libmlx";	\
		make -C .mlx/ --quiet;	\
		echo "$(GREEN)$(BOLD)Done$(DEFAULT)";	\
	fi
	@if [ ! -e ./lib/libft.a ]; then \
		echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) libft";	\
		make -C lib/ --quiet;	\
		echo "$(GREEN)$(BOLD)Done$(DEFAULT)";	\
	fi
	@echo "$(YELLOW)$(BOLD)Creating:$(DEFAULT) ./$(NAME)"
	@$(CC)
	@echo "$(GREEN)$(BOLD)Done$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning:$(DEFAULT) $(OBJ)"
	@make clean -C lib/ --quiet
	@rm -rf $(OBJ_DIR)
	@rm -f $(MAINOBJ)
	@echo "$(GREEN)Done:$(DEFAULT) $(OBJ)"

fclean:	clean
	@rm -f $(NAME)
	@rm -f code

libclean:
	@echo "$(RED)Cleaning lib...$(DEFAULT)"
	@make fclean -C lib/ --quiet
	@rm -rf ./.mlx/*.a
	@echo "$(GREEN)Done.$(DEFAULT)"

re:	fclean all

.PHONY: all clean fclean libclean re
