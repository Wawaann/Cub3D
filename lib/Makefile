SRC	=	ft_atoi.c				\
		ft_bzero.c				\
		ft_calloc.c				\
		ft_freetab.c			\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isprint.c			\
		ft_itoa.c				\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_nblen.c				\
		ft_printf.c				\
		ft_putchar_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_split.c				\
		ft_strchr.c				\
		ft_strdup.c				\
		ft_striteri.c			\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strlcpy.c			\
		ft_strlen.c				\
		ft_strmapi.c			\
		ft_strncmp.c			\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strtrim.c			\
		ft_substr.c				\
		ft_tolower.c			\
		ft_toupper.c			\
		get_next_line.c			\
		va_putchar.c			\
		va_putnbr.c				\
		va_putptr.c				\
		va_putstr.c				\

SRC		:=	$(addprefix src/, $(SRC))

OBJ_DIR	=	obj/
OBJ		=	$(patsubst src/%.c,$(OBJ_DIR)%.o,$(SRC))

INCLUDE	=	-I./include/

FLAG	=	-Wall -Wextra -Werror -g3

NAME	=	libft.a

all:	$(NAME)

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@clang $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
