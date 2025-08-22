NAME = webserv

FLAGS = -std=c++98 -Wall -Werror -Wextra -g

CC = c++

OBJ_DIR = objs

INCLUDES = -I ../includes/

SRC = configServer.cpp Location.cpp main.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
	@clear
	@echo "\n\e[1;91mExecute the program with \e[0m./"$(NAME)"\n"

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p '$(@D)'
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean :
	@rm -rf $(OBJ_DIR)
	@clear
	@echo "\n\e[1;32mLibrary successfuly deleted\e[0m\n"

fclean : clean
	@rm -rf $(NAME)
	@clear
	@echo "\n\e[1;32mLibrary successfuly deleted\e[0m\n"

re : fclean all

.PHONY : all clean fclean re
