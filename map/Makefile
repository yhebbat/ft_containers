NAME = map

SRC = main.cpp

OBJECT = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror $(SRC) -o $(NAME) 
	@echo "✅✅✅"

clean:
	@rm -f $(OBJECT)
	@echo "🗑️ 🗑️ 🗑️"
fclean: clean
	@rm -f $(NAME)
	@echo "🚮🚮🚮"
re: fclean all