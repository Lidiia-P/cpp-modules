NAME = megaphone
SRC = megaphone.cpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror 
CFLAGS += -std=c++17
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
