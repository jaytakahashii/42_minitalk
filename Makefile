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
CFLAGS = -g
AR = ar
ARFLAGS = rcs
RM = rm -rf
NORM = norminette

SERVER_SRC_FILES = server.c

CLIENT_SRC_FILES = client.c

SERVER_OBJ_FILES = $(SERVER_SRC_FILES:%.c=%.o)

CLIENT_OBJ_FILES = $(CLIENT_SRC_FILES:%.c=%.o)

SREVER_SRCS = $(addprefix $(SRC_DIR), $(SERVER_OBJ_FILES))

CLIENT_SRCS = $(addprefix $(SRC_DIR), $(CLIENT_OBJ_FILES))

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
	@echo "\n"
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(B) "*** $(NAME) creating ***" $(X)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER)
	@echo "\n"
	@echo $(G) "!!!!!!! $(SERVER) created success !!!!!!!" $(X)

# $(NAME_LINUX): $(OBJ_DIR) $(OBJS)
# 	@echo "\n"
# 	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
# 	@$(MAKE) -C $(LIBFT_DIR)
# 	@echo $(B) "*** $(NAME_LINUX) creating ***" $(X)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME_LINUX)
# 	@echo "\n"
# 	@echo $(G) "!!!!!!! $(NAME_LINUX) created success !!!!!!!" $(X)

$(CLIENT): $(OBJ_DIR) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT)
	@echo "\n"
	@echo $(G) "!!!!!!! $(CLIENT) created success !!!!!!!" $(X)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(B) "Compiling $< into $@" $(X)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	@echo $(R) "<< $(SERVER) $(CLIENT) cleaning >>" $(X)
	@echo "\n"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(SERVER) $(CLIENT)
	@echo $(R) "<< $(SERVER) $(CLIENT) fcleaning >>" $(X)
	@echo "\n"

re: fclean all

# relinux: fclean linux

norm:
	@echo $(R) "<<< $(NAME) error count >>>" $(X)
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error | wc -l
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error || true
	@echo "\n"
	@$(MAKE) -C $(LIBFT_DIR) norm

.PHONY: all clean fclean re norm
# .PHONY: all clean fclean re norm linux relinux
