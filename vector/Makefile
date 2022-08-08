NAME = vector
NAME2 = vector_tester

SRC2 = mamoussa_tester.cpp
SRC = main.cpp

OBJECT = $(SRC:.cpp=.o)
OBJECT2 = $(SRC2:.cpp=.o)

all : $(NAME) $(NAME2)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) 
	@echo "✅✅✅"
$(NAME2):
	@c++ -Wall -Wextra -Werror $(SRC2) -o $(NAME2) 
	@echo "✅✅✅"
clean:
	@rm -f $(OBJECT) $(OBJECT2)
	@echo "🗑️ 🗑️ 🗑️"
fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "🚮🚮🚮"
re: fclean all
