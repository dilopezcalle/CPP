NAME			=	megaphone
SRC_DIR			=	src
OBJ_DIR 		=	obj

RM				=	rm -rf
CC				=	clang++
CFLAGS			=	-Wall -Werror -Wextra -g3

SRCS			=	megaphone.cpp	\

OBJS			=	$(SRCS:.cpp=.o)
PREFIXED		=	$(addprefix $(OBJ_DIR)/, $(OBJS))

RED				=	"\\x1b[31m"
GREEN			=	"\\x1b[32m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# =================================== RULES ===================================

$(NAME):	$(PREFIXED)
	@printf \
	"$(YELLOW)-------------- Project's files compiled --------------\n$(RESET)%-33.33s\r"
	@$(CC) $(CFLAGS) $(PREFIXED) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(YELLOW)Compiling project's file -> $(RESET)%-33.33s\r" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# ================================= FUNCTIONS =================================

all:	$(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ_DIR)
	@echo "${GREEN}---------------------- Cleaned! ----------------------${RESET}"

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus print_init