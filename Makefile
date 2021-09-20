SERVER = server
CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = libft.a
LIBFT_DIR = libft/

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)$(LIBFT) .

$(SERVER): $(LIBFT) $(OBJ_SERVER)
	@gcc $(OBJ_SERVER) $(LIBFT) -o $(SERVER)
	@echo "\n\033[92m $@ built 🖥️\033[0m\n"

$(CLIENT): $(LIBFT) $(OBJ_CLIENT)
	@gcc $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "\n\033[92m $@ built 💼\033[0m\n"

%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@echo "\n\033[36m object files removed 👋\033[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(LIBFT)
	@echo "\n\033[36m executables removed 👋\033[0m\n"

re: fclean all
