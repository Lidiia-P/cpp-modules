RED = \033[0;31m
GREEN = \033[1;32m
YELLOW = \033[0;33m
RESET = \033[0m

NAME = base
SRC = main.cpp Base.cpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror 
CFLAGS += -std=c++17
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)✓ Project $(NAME) created.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)✓ Project $(NAME) and all files cleaned.$(RESET)"

re: clean all

.PHONY: all clean fclean re
