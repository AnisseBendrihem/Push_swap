# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 15:29:53 by abendrih          #+#    #+#              #
#    Updated: 2025/08/17 19:57:11 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
# ┌─────────────────────────────┐
# │         REPERTOIRES          │
# └─────────────────────────────┘
SRC_DIR     = src
PARSING_DIR = parsing
RULES_DIR   = rules
INCLUDE_DIR = include
LIBFT_DIR   = libft

LIBFT_LIB   = $(LIBFT_DIR)/libft.a

# ┌─────────────────────────────┐
# │           SOURCES            │
# └─────────────────────────────┘
SRC         = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/utils_2.c \
	$(SRC_DIR)/choose.c \
	$(SRC_DIR)/cost.c \
	$(SRC_DIR)/execute.c \
	$(SRC_DIR)/finish.c \
	$(SRC_DIR)/position.c \
	$(SRC_DIR)/target.c \
	$(PARSING_DIR)/parsing_1.c \
	$(PARSING_DIR)/parsing_2.c \
	$(RULES_DIR)/push_command.c \
	$(RULES_DIR)/rotate_command.c \
	$(RULES_DIR)/r_rotate_command.c \
	$(RULES_DIR)/swap_command.c 

OBJ         = $(SRC:.c=.o)

# ┌─────────────────────────────┐
# │         COMPILATION          │
# └─────────────────────────────┘
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3

# ┌─────────────────────────────┐
# │          COULEURS            │
# └─────────────────────────────┘
RESET       = \033[0m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
CYAN        = \033[0;36m
MATRIX_GRAY = \033[38;5;246m
MATRIX_GREEN= \033[38;5;46m

MATRIX_CODE = "\n\
$(MATRIX_GREEN)\
> Initializing stack sequences...\n\
> Injecting LIBFT Core [OK]\n\
> Algorithmic brain connected.\n\
> Binary path secured: $(NAME)\n\
> Ready for sorting reality.\n\
> [▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓] 100%\n\
> SYSTEM READY.\n\
$(RESET)"

MATRIX_CLEAN = "\n\
\033[38;5;93m╔════════════════════════════════════╗\n\
\033[38;5;93m║ \033[38;5;51mPurging temporals...\033[0m               \033[38;5;93m║\n\
\033[38;5;93m║ \033[38;5;51m[▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓] \033[38;5;198m100%%\033[0m         \033[38;5;93m║\n\
\033[38;5;93m║ \033[38;5;201mAll objects neutralized\033[0m            \033[38;5;93m║\n\
\033[38;5;93m║ \033[38;5;51mPush_Swap Reactor Offline\033[0m          \033[38;5;93m║\n\
\033[38;5;93m╚════════════════════════════════════╝\n\
$(RESET)"

# ┌─────────────────────────────┐
# │          COMMANDES           │
# └─────────────────────────────┘
all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory 2>&1 | grep -v '^gcc'
	@echo "$(GREEN)Linking with LIBFT...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_LIB)
	@echo $(MATRIX_CODE)

%.o: %.c
	@echo "$(CYAN)Compiling$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(CYAN)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@echo $(MATRIX_CLEAN)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)Removing binary:$(RESET) $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
