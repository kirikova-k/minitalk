# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 18:36:00 by ogarthar          #+#    #+#              #
#    Updated: 2021/09/21 18:36:11 by ogarthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =		ft_memchr.c	ft_isalpha.c	ft_atoi.c\
						ft_memmove.c	ft_split.c\
			ft_strdup.c	ft_strlcat.c	ft_memcpy.c\
						ft_strmapi.c	ft_memccpy.c\
			ft_memset.c	ft_toupper.c	ft_isprint.c \
						ft_isascii.c	ft_putnbr_fd.c\
						ft_strlcpy.c	ft_putendl_fd.c\
						ft_strrchr.c	ft_itoa.c\
						ft_strncmp.c	ft_bzero.c\
			ft_strlen.c	ft_strtrim.c	ft_calloc.c\
						ft_strjoin.c	ft_isalnum.c\
			ft_substr.c	ft_tolower.c	ft_isdigit.c \
						ft_strnstr.c	ft_putstr_fd.c\
			ft_memcmp.c	ft_strchr.c		ft_putchar_fd.c\

LIST_B =	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	 ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : $(OBJ_B)
	ar rcs $(NAME) $?

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

x: all
	./a.out

.PHONY : all clean fclean re bonus
