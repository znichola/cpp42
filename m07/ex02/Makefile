# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:20:46 by znichola          #+#    #+#              #
#    Updated: 2023/07/04 14:18:48 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= array

CC		= c++
CFLAGS	= -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -std=c++98 -pedantic

ifdef DEBUG
CFLAGS	+= -g3 -fsanitize=address
else
ifdef DEBUGL
CFLAGS += -g3
endif
endif

ifdef WSL_DISTRO_NAME
LEAKS_CHECK = valgrind
else
LEAKS_CHECK = leaks -atExit --
endif

FILES	= main main2

OBJS_PATH = objs/
SRCS_PATH = srcs/
INCS_PATH = -Iincludes/.

SRCS	= $(addprefix $(SRCS_PATH), $(addsuffix .cpp, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))

all	: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCS_PATH) -o $@ $<

$(NAME)	: objs/main.o
	$(CC) $(CFLAGS) $< -o $@

$(NAME)_given	: objs/main2.o
	$(CC) $(CFLAGS) $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

run : all
	./$(NAME)

leaks : re
	$(LEAKS_CHECK) ./$(NAME)

.PHONY: all clean fclean re
