# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:33:10 by gbonis            #+#    #+#              #
#    Updated: 2024/02/01 18:33:33 by gbonis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	 ft_print_char.c\
	ft_printf.c\
	ft_printf_utils.c\
	ft_print_str.c\
	ft_print_int.c\
	ft_print_hex.c\
	ft_print_unsigned.c\
	ft_print_ptr.c\


	
CC = cc

CFLAGS = -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	 cp $(LIBFT) $(NAME)
	 $(AR) rcs $@ $(OBJ)

$(LIBFT): 
	make -C ./libft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

run: all
	cc $(CFLAGS) $(OBJ) $(NAME)
	./a.out

clean : 
	make -C ./libft clean
	rm -f $(OBJ) 

fclean: 
	make -C ./libft fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re run
