# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 18:33:56 by znichola          #+#    #+#              #
#    Updated: 2023/03/09 01:34:39 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie

CC	= c++
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=c++98

ifdef DEBUG
CFLAGS	+= -g3 -fsanitize=address
endif

FILES	= main Zombie newZombie randomChmp zombieHorde

OBJS_PATH = objs/
SRCS_PATH =
INCS_PATH = -I.

SRCS	= $(addprefix $(SRCS_PATH), $(addsuffix .cpp, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))

all	: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCS_PATH) -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all clean fclean re
