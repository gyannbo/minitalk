# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 10:58:14 by gbonis            #+#    #+#              #
#    Updated: 2024/07/11 11:51:19 by gbonis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT = client.c\
             wrapper.c\

SRC_SERVER = server.c\
	   wrapper.c\

SRC_CLIENT_BONUS = wrapper.c\
       	           client_bonus.c\

SRC_SERVER_BONUS = server_bonus.c\
		   wrapper.c\

LIBFT = ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
	
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJ = $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

NAMES = $(NAME_CLIENT) $(NAME_SERVER) 

NAMES_BONUS = $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

all : $(NAMES)

bonus : $(NAMES_BONUS)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) 

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS) $(LIBFT) $(FT_PRINTF)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT) $(FT_PRINTF)

$(LIBFT) :
	make -C ./libft

$(FT_PRINTF) :
	make -C ./ft_printf

%.o: %.c 
	$(CC) $(CFLAGS) -c  $< 

clean : 
	make -C ./libft clean
	make -C ./ft_printf clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -f $(NAMES) $(NAMES_BONUS)

re : fclean all 

.PHONY: all clean fclean re bonus
