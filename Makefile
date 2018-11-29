# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprasol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 15:48:45 by kprasol           #+#    #+#              #
#    Updated: 2018/11/28 16:31:35 by kprasol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = main.c \
flags.c \
print_directory.c \
sort_directory.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft: 
	make -C libft

$(NAME): libft $(OBJ)
	gcc $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME) -I ./libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

%.o: %.c
	 gcc $(CFLAGS) -c -o $@ $< -I ./libft

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft

