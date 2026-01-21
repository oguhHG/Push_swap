# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:43:36 by hgrandje          #+#    #+#              #
#    Updated: 2026/01/21 12:33:47 by colassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_DIR = ./srcs

SRCS =	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/stack/stack_init.c \
		$(SRCS_DIR)/stack/stack_utils.c \
		$(SRCS_DIR)/stack/stack_free.c \
		$(SRCS_DIR)/parsing/parse_args.c \
		$(SRCS_DIR)/parsing/parse_flags.c \
		$(SRCS_DIR)/parsing/parse_utils.c \
		$(SRCS_DIR)/parsing/validate_input.c \
		$(SRCS_DIR)/parsing/error_handler.c \
		$(SRCS_DIR)/operations/swap.c \
		$(SRCS_DIR)/operations/push.c \
		$(SRCS_DIR)/operations/rotate.c \
		$(SRCS_DIR)/operations/reverse_rotate.c \
		$(SRCS_DIR)/disorder/compute_disorder.c \
		$(SRCS_DIR)/algorithms/simple_sort.c \
		$(SRCS_DIR)/algorithms/simple_sort_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = ./includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I./includes -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
