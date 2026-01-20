# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:43:36 by hgrandje          #+#    #+#              #
#    Updated: 2026/01/20 16:51:22 by hgrandje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = checker.c \
       adaptive_sort.c \
       complex_sort.c \
       medium_sort.c \
       simple_sort.c \
       compute_disorder.c \
       select_strategy.c \
	   push.c \
	   rotate.c \
	   reverse_rotate.c \
	   swap.c \
	   error_handler.c \
	   parse_args.c \
	   validate_input.c \
	   stack_free.c \
	   stack_init.c \
	   stack_utils.c \
	   main.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

bonus: all

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus