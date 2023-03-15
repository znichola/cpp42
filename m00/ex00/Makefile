# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 18:33:56 by znichola          #+#    #+#              #
#    Updated: 2023/03/15 02:45:15 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC	= c++
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=c++98

FILES	= megaphone

SRCS	:= $(addsuffix .c, $(FILES))
OBJS	:= $(addsuffix .o, $(FILES))

all	: $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

leaks : re
	leaks -atExit -- ./$(NAME) this is a leaks " test!!?> ! " "slkdjf sdf"

.PHONY: all clean fclean re
