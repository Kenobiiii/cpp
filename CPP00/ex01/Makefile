RM = rm -f
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

USER = paromero
OBJ_DIR = objs
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
SRCS = main.cpp Contact.cpp PhoneBook.cpp

NAME = PhoneBook

GREEN = \033[1;32m
RESET = \033[0m

# Headers
HEADERS = Contact.hpp PhoneBook.hpp

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling objects...$(RESET)"
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

# Dependencias específicas de headers
$(OBJ_DIR)/main.o: main.cpp PhoneBook.hpp Contact.hpp | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

$(OBJ_DIR)/PhoneBook.o: PhoneBook.cpp PhoneBook.hpp Contact.hpp | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

$(OBJ_DIR)/Contact.o: Contact.cpp Contact.hpp | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re