NAME			=	iter
OBJ_DIR 		=	obj

RM				=	rm -rf
CC				=	clang++
CFLAGS			=	-g3 -Wall -Werror -Wextra -std=c++98 -Wshadow

SRCS			=	main.cpp	\

OBJS			=	$(SRCS:.cpp=.o)
PREFIXED		=	$(addprefix $(OBJ_DIR)/, $(OBJS))

RED				=	"\\x1b[31m"
GREEN			=	"\\x1b[32m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# =================================== RULES ===================================

all:	$(NAME)

$(NAME):	$(PREFIXED)
	@printf \
	"                                                                       \n%-33.33s\r"
	@printf \
	"$(YELLOW)-------------- Project's files compiled --------------\n\n$(RESET)%-33.33s\r"
	@$(CC) $(CFLAGS) $(PREFIXED) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(YELLOW)Compiling project's file -> $(RESET)%-33.33s\r" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# ================================= FUNCTIONS =================================

clean:
	@$(RM) $(OBJ) $(OBJ_DIR)
	@echo "\n${GREEN}---------------------- Cleaned! ----------------------\n${RESET}"

fclean:	clean
	@$(RM) $(NAME) $(NAME).dSYM

re:		fclean all

valgrind : clean all 
	valgrind --memcheck:leak-check=full --suppressions=./cout.supp ./$(NAME)

.PHONY: all clean fclean re valgrind
