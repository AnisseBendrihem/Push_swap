# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:38:49 by abendrih          #+#    #+#              #
#    Updated: 2025/07/30 23:19:03 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                                     ,-="""=.
#                                   .'        `.
#                                  (            `.
#                                   `.            `..
#                                    ,'             .'
#                                    `.            '.
#                                      `-.           `-.
#                                         )             `=-.
#                                       .'              `=-.
#                                     .`               .`-.
#                       _            (                \ `-.
#                    ,'   `.          `.        /`.    \
#                   /        `.         \      |   `.   `.
#                 ,'            `.       )    /      \    \
#                /     .'`.        `.    )    |       `.   \
#              ,'    .'    `.         `./     \         `.  \
#            ,'    .'        `.                \          \  \
#          ,'    .'            `.               \          `. \
#        ,'   .'                 `.              )          ) (__.
#      ,'   (                      `.            )          `."""'
#  _.-'    __)                       `.         .  
# `""'""                               `"""""""


EXEC        = main
NAME        = libft.a

SRC_LIBFT = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
	ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_strndup.c

SRC_LIBFT   := $(addprefix ft_lib/, $(SRC_LIBFT))

SRC_PRINTF  := $(addprefix ft_printf/, \
	ft_printf.c ft_convertf.c ft_put_unsigned_nbrf.c ft_putnbrf.c \
	ft_putstrf.c ft_puthexaf.c ft_putcharf.c)

SRC_GNL     := $(addprefix get_next_line/, \
	get_next_line.c)

SRC         = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL)
OBJ         = $(SRC:.c=.o)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

RESET       = \033[0m
NEON_GREEN  = \033[38;2;57;255;20m
NEON_PINK   = \033[38;2;255;20;147m
NEON_CYAN   = \033[38;2;0;255;255m
NEON_PURPLE = \033[38;2;180;0;255m
MATRIX_GRAY = \033[38;5;246m
MATRIX_GREEN = \033[38;5;46m

MATRIX_CODE = "\n\
$(MATRIX_GREEN)\
> >>> Injecting: LIBFT, FT_PRINTF, GNL...\n\
> >>> Object Layer Synchronized.\n\
> >>> Compilation virtualized.\n\
> >>> Welcome, Operator.\n\
> [▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓] 100%\n\
> SYSTEM READY.\n\
$(RESET)"

MATRIX_CLEAN = "\n\
$(MATRIX_GRAY)\
Cleaning object files...\n\
  [▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓] 100%\n\
  ALL FILES NEUTRALIZED.\n\
  WELCOME BACK TO THE VOID.\n\
$(RESET)"

all: $(NAME)
	@echo $(MATRIX_CODE)

$(NAME): $(OBJ)
	@echo "$(NEON_CYAN)🔧 Linking object files into $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo $(MATRIX_CLEAN)

fclean: clean
	@rm -f $(NAME) $(EXEC)
	@echo "$(NEON_PINK)💥 LIBRARY core fully erased.$(RESET)"

re: fclean all

run: all
	@echo "$(NEON_GREEN)⚙️  Compiling $(EXEC) with $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) main.c -L. -lft -o $(EXEC)
	@echo "$(NEON_CYAN)👾 Launching $(EXEC)...$(RESET)"
	@./$(EXEC)

.PHONY: all bonus clean fclean re run
