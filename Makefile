# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 15:29:53 by abendrih          #+#    #+#              #
#    Updated: 2025/08/04 03:30:56 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

SRC_DIR     = src
RULES_DIR   = rules
INCLUDE_DIR = include
LIBFT_DIR   = libft
LIBFT_MAKE  = $(LIBFT_DIR)/Makefile
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/push_swap.c \
              $(RULES_DIR)/rotate_command.c \
              $(RULES_DIR)/reverse_r_commande.c

OBJ         = $(SRC:.c=.o)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3

# ┌─────────────────────────────┐
# │          COULEURS           │
# └─────────────────────────────┘
RESET       = \033[0m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
BLUE        = \033[0;34m
PURPLE      = \033[0;35m
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
$(MATRIX_GRAY)\
Purging temporals...\n\
  [▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓] 100%\n\
  ALL OBJECTS NEUTRALIZED.\n\
  PUSH_SWAP REACTOR OFFLINE.\n\
$(RESET)"

# ┌─────────────────────────────┐
# │          COMMANDES          │
# └─────────────────────────────┘

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)Linking with LIBFT...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_LIB)
	@echo $(MATRIX_CODE)

%.o: %.c
	@echo "$(CYAN)Compiling$(RESET) $<"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

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