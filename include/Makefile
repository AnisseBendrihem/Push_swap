# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 15:29:53 by abendrih          #+#    #+#              #
#    Updated: 2025/07/20 17:16:16 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = push_swap

# Fichiers source
SRC = 

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Compilateur & flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Couleurs
NEON_GREEN = \033[38;2;57;255;20m
NEON_PINK = \033[38;2;255;20;147m
NEON_CYAN = \033[38;2;0;255;255m
NEON_PURPLE = \033[38;2;180;0;255m
RESET = \033[0m

# Règle par défaut
all: $(NAME)
	@echo "$(NEON_GREEN)💾 [SYSTEM] Compilation de Push Swap... [OK]$(RESET)"

# Compilation de l'exécutable
$(NAME): $(OBJ)
	@echo "$(NEON_CYAN)🔧 Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Nettoyage des fichiers objets
clean:
	@echo "$(NEON_PURPLE)🧽 Nettoyage des fichiers .o...$(RESET)"
	@rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	@echo "$(NEON_PINK)💣 Destruction de l'exécutable $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Recompilation from scratch
re: fclean all

# Test d'exécution
run: all
	@echo "$(NEON_CYAN)👾 Lancement de $(NAME)...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run
