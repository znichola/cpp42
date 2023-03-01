# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 18:33:56 by znichola          #+#    #+#              #
#    Updated: 2023/03/01 19:38:23 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC	= c++
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=c++98

FILES	= megaphone

OBJS_PATH = 
SRCS_PATH =  

SRCS	:= $(addsuffix .c, $(FILES))
OBJS	:= $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))

all	: $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mdfir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all clean fclean re
