NAME_SERVER			:= server
NAME_CLIENT			:= client
NAME_SERVER_BONUS	:= server_bonus
NAME_CLIENT_BONUS	:= client_bonus
SRC_SERVER			:= server.c tools.c
SRC_CLIENT			:= client.c tools.c
SRC_SERVER_BONUS	:= server_bonus.c tools.c
SRC_CLIENT_BONUS	:= client_bonus.c tools.c
SRC_SERVER			:= $(addprefix src/,$(SRC_SERVER))
SRC_CLIENT			:= $(addprefix src/,$(SRC_CLIENT))
SRC_SERVER_BONUS	:= $(addprefix src/,$(SRC_SERVER_BONUS))
SRC_CLIENT_BONUS	:= $(addprefix src/,$(SRC_CLIENT_BONUS))
FLAGS				:= -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):$(SRC_SERVER)
	gcc  $(FLAGS) $(SRC_SERVER) -Iinclude -o $@

$(NAME_CLIENT):$(SRC_CLIENT)
	gcc  $(FLAGS) $(SRC_CLIENT) -Iinclude -o $@

debug:$(SRC_SERVER) $(SRC_CLIENT)
	gcc  $(FLAGS) -fsanitize=address -g $(SRC_SERVER) -Iinclude -o $(NAME_SERVER)
	gcc  $(FLAGS) -fsanitize=address -g $(SRC_CLIENT) -Iinclude -o $(NAME_CLIENT)

clean:
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

fclean:clean clean_bonus

re: clean all

$(NAME_SERVER_BONUS):$(SRC_SERVER_BONUS)
	gcc  $(FLAGS)  $(SRC_SERVER_BONUS) -Iinclude -o $@
	
$(NAME_CLIENT_BONUS):$(SRC_CLIENT_BONUS)
	gcc  $(FLAGS)  $(SRC_CLIENT_BONUS) -Iinclude -o $@

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean_bonus:
	rm -rf $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)