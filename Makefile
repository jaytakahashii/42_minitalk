NAME = minitalk
SERVER = server
CLIENT = client
LIBFT_NAME = libft
LIBFT_DIR = libft/
INCLUDE_DIR = include/
INCLUDE = -I $(INCLUDE_DIR)
LIBFT_INCLUDE = -I $(LIBFT_DIR)$(INCLUDE_DIR)
SRC_DIR = src/
OBJ_DIR = .obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf
NORM = norminette

SERVER_SRC_FILES = server.c

CLIENT_SRC_FILES = client.c

SERVER_OBJ_FILES = $(SERVER_SRC_FILES:%.c=%.o)

CLIENT_OBJ_FILES = $(CLIENT_SRC_FILES:%.c=%.o)

SERVER_SRCS = $(addprefix $(SRC_DIR), $(SERVER_SRC_FILES))

CLIENT_SRCS = $(addprefix $(SRC_DIR), $(CLIENT_SRC_FILES))

SERVER_OBJS = $(addprefix $(OBJ_DIR), $(SERVER_OBJ_FILES))

CLIENT_OBJS = $(addprefix $(OBJ_DIR), $(CLIENT_OBJ_FILES))

Y 			= "\033[33m"
R 			= "\033[31m"
G 			= "\033[32m"
B 			= "\033[34m"
X 			= "\033[0m"
UP 			= "\033[A"
CUT 		= "\033[K"

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_DIR) $(SERVER_OBJS)
	@echo $(Y) "$(NAME) successfully compiled\n" $(X)
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(B) "<-- Out of $(LIBFT_DIR)\n" $(X)
	@echo $(B) "$(SERVER) creating" $(X)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER)
	@echo $(G) "!! $(SERVER) created !!" $(X)

$(CLIENT): $(OBJ_DIR) $(CLIENT_OBJS)
	@echo $(B) "$(CLIENT) creating\n" $(X)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT)
	@echo $(G) "!! $(SERVER) created !!" $(X)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(B) "Compiling $<" $(X)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@
	@printf $(UP)$(CUT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo $(R) "$(NAME) cleaned\n" $(X)

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME) $(NAME_LINUX)
	@echo $(R) "$(NAME) fcleaned\n" $(X)

re: fclean all

norm:
	@echo $(R) "<<< $(NAME) error count >>>" $(X)
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error | grep -v Error! | wc -l
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error || true
	@$(MAKE) -C $(LIBFT_DIR) norm

.PHONY: all clean fclean re norm
# .PHONY: all clean fclean re norm linux relinux
