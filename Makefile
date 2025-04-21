MAKEFILE = Makefile

NAME = minitalk

BONUS_NAME = minitalk_bonus

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

LIBFT_NAME = libft.a
LIBFT_DIR = libft/

INCLUDE_DIR = include/
INCLUDE = -I $(INCLUDE_DIR)
LIBFT_INCLUDE = -I $(LIBFT_DIR)$(INCLUDE_DIR)

SRC_DIR = src/
OBJ_DIR = .obj/

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
NORM = norminette

# mandatory part
SRC_FILES = server.c client.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OJB_FILES = $(SRC_FILES:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR), $(OJB_FILES))

SERVER_OBJS = $(addprefix $(OBJ_DIR), server.o)
CLIENT_OBJS = $(addprefix $(OBJ_DIR), client.o)

# bonus part
SRC_FILES_BONUS = server_bonus.c client_bonus.c
SRCS_BONUS = $(addprefix $(SRC_DIR), $(SRC_FILES_BONUS))
OJB_FILES_BONUS = $(SRC_FILES_BONUS:%.c=%.o)
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(OJB_FILES_BONUS))

SERVER_BONUS_OBJS = $(addprefix $(OBJ_DIR), server_bonus.o)
CLIENT_BONUS_OBJS = $(addprefix $(OBJ_DIR), client_bonus.o)

Y 			= "\033[33m"
R 			= "\033[31m"
G 			= "\033[32m"
B 			= "\033[34m"
X 			= "\033[0m"
UP 			= "\033[A"
CUT 		= "\033[K"

all: $(OBJ_DIR) $(OBJS) $(SERVER) $(CLIENT)

bonus: $(OBJ_DIR) $(OBJS_BONUS) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(OBJ_DIR) $(SERVER_OBJS)
	@echo $(Y) "$(NAME) src files successfully compiled\n" $(X)
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(B) "<-- Out of $(LIBFT_DIR)\n" $(X)
	@echo $(B) "$(SERVER) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER)
	@echo $(G) "!! $(SERVER) created !!\n" $(X)

$(CLIENT): $(OBJ_DIR) $(CLIENT_OBJS)
	@echo $(B) "$(CLIENT) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT)
	@echo $(G) "!! $(CLIENT) created !!" $(X)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(Y) "Compiling $<" $(X)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@
	@printf $(UP)$(CUT)

$(SERVER_BONUS): $(OBJ_DIR) $(SERVER_BONUS_OBJS)
	@echo $(Y) "$(BONUS_NAME) srs files successfully compiled\n" $(X)
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(B) "<-- Out of $(LIBFT_DIR)\n" $(X)
	@echo $(B) "$(SERVER_BONUS) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER_BONUS)
	@echo $(G) "!! $(SERVER_BONUS) created !!\n" $(X)

$(CLIENT_BONUS): $(OBJ_DIR) $(CLIENT_BONUS_OBJS)
	@echo $(B) "$(CLIENT_BONUS) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT_BONUS)
	@echo $(G) "!! $(CLIENT_BONUS) created !!" $(X)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo $(R) "$(NAME) cleaned\n" $(X)

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo $(R) "$(NAME) fcleaned\n" $(X)

re: fclean all

rebonus: fclean bonus

norm:
	@echo $(R) "<<< $(NAME) error count >>>" $(X)
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error | grep -v Error! | wc -l
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error || true
	@$(MAKE) -C $(LIBFT_DIR) norm

.PHONY: all clean fclean re norm
# .PHONY: all clean fclean re norm linux relinux
