# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguan <sguan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 23:05:22 by sguan             #+#    #+#              #
#    Updated: 2025/03/07 23:37:18 by sguan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libft_printf.a

LIBFT_DIR = ./ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./src -I./ft_printf -I./ft_printf/libft
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lft_printf
RM = rm -f

SRC = operation_list1.c \
      operation_list2.c \
      operations.c \
      partition_utils.c \
      partition.c \
      sort_bucket_three.c \
      sort_bucket_two.c \
      sort_small_stack.c \
      sort_utils.c \
      sort.c \
      stack_utils.c \
      stack.c \
      utils.c \
      push_swap.c

OBJS = $(SRC:.c=.o)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
