# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 18:33:56 by znichola          #+#    #+#              #
#    Updated: 2023/03/15 13:27:23 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= looserSed

CC	= c++
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=c++98

ifdef DEBUG
CFLAGS	+= -g3 -fsanitize=address
else
ifdef DEBUGL
CFLAGS += -g3
endif
endif

FILES	= main

TEST_FILES := iliad odyssey red
TEST_FILES := $(addsuffix .replace, $(TEST_FILES))

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
	$(RM) $(TEST_FILES)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

# leaks	:
# 	unset DEBUG
# 	export DEBUGL=1
# 	$(MAKE) -C .
# 	valgrind -s --leak-check=full --show-leak-kinds=definite,indirect,possible --track-origins=yes ./$(NAME) $(ARGS)
# 	unset DEBUGL
# 	export DEBUG=1

leaks : re
	leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re
