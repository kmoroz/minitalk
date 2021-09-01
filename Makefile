SERVER = server
CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = libft.a
LIBFT_DIR = libft/

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	@make -C $(LIBFT_DIR)
	@gcc $(OBJ_SERVER) $(LIBFT_DIR)$(LIBFT) -o $(SERVER)
	@echo "\e[32m$@ built 🖥️\e[0m\n"

$(CLIENT): $(OBJ_CLIENT)
	@make -C $(LIBFT_DIR)
	@gcc $(OBJ_CLIENT) -o $(CLIENT)
	@echo "\e[35m$@ built 💼\e[0m\n"

%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(LIBFT) $(LIBFT_DIR)$(LIBFT)

re: fclean all
