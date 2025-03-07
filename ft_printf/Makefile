LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

NAME = libft_printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./libft

RM = rm -f

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_utils2.c \
	./libft/ft_putchar_fd.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_putnbr_fd.c \
	./libft/ft_itoa.c \
	./libft/ft_strlen.c \

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
