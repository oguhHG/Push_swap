# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 15:03:17 by hgrandje          #+#    #+#              #
#    Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
SRCS_DIR	= srcs
OBJ_DIR		= objs
INC_DIR		= includes
LIBFT_DIR	= libft

# Source files
SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/parsing/parse_args.c \
			  $(SRCS_DIR)/parsing/parse_flags.c \
			  $(SRCS_DIR)/parsing/valid_input.c \
			  $(SRCS_DIR)/stack/stack_init.c \
			  $(SRCS_DIR)/stack/stack_utils.c \
			  $(SRCS_DIR)/stack/stack_free.c \
			  $(SRCS_DIR)/operations/swap.c \
			  $(SRCS_DIR)/operations/push.c \
			  $(SRCS_DIR)/operations/rotate.c \
			  $(SRCS_DIR)/operations/reverse_rotate.c \
			  $(SRCS_DIR)/algorithms/sort_dispatcher.c \
			  $(SRCS_DIR)/algorithms/simple/simple_sort.c \
			  $(SRCS_DIR)/algorithms/simple/simple_sort_utils.c \
			  $(SRCS_DIR)/algorithms/medium/medium_sort.c \
			  $(SRCS_DIR)/algorithms/medium/medium_sort_utils.c \
			  $(SRCS_DIR)/algorithms/complex/turk_sort.c \
			  $(SRCS_DIR)/algorithms/complex/turk_sort_utils.c \
			  $(SRCS_DIR)/algorithms/complex/turk_cost.c \
			  $(SRCS_DIR)/algorithms/complex/turk_moves.c \
			  $(SRCS_DIR)/algorithms/complex/turk_push_back.c \
			  $(SRCS_DIR)/disorder/compute_disorder.c \
			  $(SRCS_DIR)/utils/utils.c \
			  $(SRCS_DIR)/utils/is_sorted.c \
			  $(SRCS_DIR)/benchmark/benchmark.c

SRCS_BONUS	= $(SRCS_DIR)/bonus/checker_main_bonus.c \
			  $(SRCS_DIR)/bonus/checker_utils_bonus.c \
			  $(SRCS_DIR)/parsing/parse_args.c \
			  $(SRCS_DIR)/parsing/parse_flags.c \
			  $(SRCS_DIR)/parsing/validate_input.c \
			  $(SRCS_DIR)/stack/stack_init.c \
			  $(SRCS_DIR)/stack/stack_utils.c \
			  $(SRCS_DIR)/stack/stack_free.c \
			  $(SRCS_DIR)/operations/swap.c \
			  $(SRCS_DIR)/operations/push.c \
			  $(SRCS_DIR)/operations/rotate.c \
			  $(SRCS_DIR)/operations/reverse_rotate.c \
			  $(SRCS_DIR)/utils/utils.c \
			  $(SRCS_DIR)/utils/is_sorted.c

OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

bonus: $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(CHECKER)
	@echo "$(GREEN)✓ $(CHECKER) compiled successfully!$(NC)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)✓ Object files removed$(NC)"

fclean: clean
	@$(RM) $(NAME) $(CHECKER)
	@echo "$(RED)✓ Executables removed$(NC)"

re: fclean all

.PHONY: all clean fclean re bonus