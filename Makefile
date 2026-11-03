#====Config====#

BOLD   := \033[1m
RESET  := \033[0m
GREEN  := \033[32m
CYAN   := \033[36m
YELLOW := \033[33m
RED    := \033[31m

define PRINT_HEADER
	@echo "$(CYAN)$(BOLD)"
	@echo "                                       "
	@echo "  ██╗     ██╗██████╗ ███████╗████████╗"
	@echo "  ██║     ██║██╔══██╗██╔════╝╚══██╔══╝"
	@echo "  ██║     ██║██████╔╝█████╗     ██║   "
	@echo "  ██║     ██║██╔══██╗██╔══╝     ██║   "
	@echo "  ███████ ██║██████╔╝██║        ██║   "
	@echo "  ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   "
	@echo "$(RESET)"
	@echo "$(MAGENTA)$(BOLD) ╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)$(BOLD) ║$(RESET)  $(BOLD)Lib:$(RESET) $(GREEN)$(NAME)$(RESET)  │  $(BOLD)CC:$(RESET) $(YELLOW)$(CC)$(RESET)  │  $(BOLD)Flags:$(RESET) $(BLUE)$(CFLAGS)$(RESET)  $(MAGENTA)$(BOLD)║$(RESET)"
	@echo "$(MAGENTA)$(BOLD) ╚════════════════════════════════════════════════════════════╝$(RESET)\n"
endef

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_bzero.c\
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
OBJ = $(SRC:.c=.o)

#====Rules====#
all: $(NAME)

$(NAME): $(OBJ)
	$(PRINT_HEADER)
	@echo "\n$(BOLD)$(CYAN)📦 making .o files$(RESET)"
	@echo "\n$(BOLD)$(CYAN)📦 Archiving library $(NAME)...$(RESET)\n"
	ar rcs $(NAME) $(OBJ)
	@echo "\n$(BOLD)$(GREEN)✨ $(NAME) compiled successfully!$(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n$(BOLD)$(YELLOW)🧹 Removing object files (.o)...$(RESET)\n"
	rm -fr $(OBJ)
	@echo "\n$(GREEN)✔ Object files removed.$(RESET)\n"

fclean: clean
	@echo "\n$(BOLD)$(RED)🗑️  Removing $(NAME)...$(RESET)\n"
	rm -fr $(NAME)
	@echo "\n$(GREEN)✔ Full cleanup completed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re