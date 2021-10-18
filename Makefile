# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 11:23:22 by ogarthar          #+#    #+#              #
#    Updated: 2021/09/27 18:19:30 by ogarthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server

NAME_CLIENT = client

LIST_SERVER = server.c

LIST_CLIENT = client.c

NAME_SERVER_B = server_bonus

NAME_CLIENT_B = client_bonus

LIST_SERVER_B = server_bonus.c

LIST_CLIENT_B = client_bonus.c

VPATH = src:

OBJ_SERVER = $(patsubst %.c,%.o,$(LIST_SERVER))

OBJ_CLIENT = $(patsubst %.c,%.o,$(LIST_CLIENT))

OBJ_SERVER_B = $(patsubst %.c,%.o,$(LIST_SERVER_B))

OBJ_CLIENT_B = $(patsubst %.c,%.o,$(LIST_CLIENT_B))

HEADER = $(patsubst %.c,%.d,$(LIST_SERVER) $(LIST_SERVER_B) $(LIST_CLIENT) $(LIST_CLIENT_B))

HEADER_B = $(patsubst %.c,%.d,$(LIST_SERVER_B) $(LIST_CLIENT_B))

LIBFT_DIR =	./libft

LIBFT =	./libft/libft.a

SOURCES_LIBFT =	$(addprefix $(DIR_LIBFT), $(LIBFT))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -MD

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

bonus: $(NAME_SERVER_B) $(NAME_CLIENT_B)

$(NAME_SERVER_B):	$(OBJ_SERVER_B) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(LIBFT) -o $(NAME_SERVER_B)

$(NAME_CLIENT_B):	$(OBJ_CLIENT_B) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(LIBFT) -o $(NAME_CLIENT_B)

$(LIBFT):
		$(MAKE) -C libft

clean :
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(HEADER)
	@rm -f $(OBJ_SERVER_B) $(OBJ_CLIENT_B) $(HEADER_B)

fclean : clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@rm -f $(NAME_SERVER_B) $(NAME_CLIENT_B)

re : fclean all

-include $(HEADER)
-include $(HEADER_B)

.PHONY : all clean fclean re bonus
