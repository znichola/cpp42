#!/bin/zsh

printf "generate cpp project boilerplate files\n"

help () {
	printf "usage: [project folder] [project name]\n"
}

make_header () {
	# file_name=$(printf "%s.hpp" "${1}" | awk '{print tolower($0)}')
	file_name=$(printf "%s.hpp" "${1}")
	# Set to upper the argument and append _H
	header_guard_name=$(printf "%s_H" "${1}" | awk '{print toupper($0)}')
	{
		printf "#ifndef %s\n" "${header_guard_name}" ;
		printf "# define %s\n\n" "${header_guard_name}";

		printf "#include <iostream>\n"

		printf "\n#endif /* %s */\n" "${header_guard_name}"
	} > includes/"${file_name}"
}

make_main () {
	file_name=$(printf "main.cpp")
	# Set to upper the argument and append _H
	{
		printf "#include <iostream>\n"
		printf "\n#include \"${1}.hpp\"\n"
		printf "\nint\tmain(int ac, char **av)\n{\n\t(void)ac;\n\t(void)av;\n"
		printf "\tstd::cout << \"hello ${1}!\" << std::endl;\n"
		printf "\treturn(0);\n}\n"
	} > srcs/"${file_name}"
}

make_make () {
	file_name=$(printf "%s.cpp" "main" | awk '{print tolower($0)}')
	{
		printf "NAME	= ${1}\n"
		printf '
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

OBJS_PATH = objs/
SRCS_PATH = srcs/
INCS_PATH = -Iincludes/.

SRCS	= $(addprefix $(SRCS_PATH), $(addsuffix .cpp, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))

all	: $(NAME)

$(OBJS_PATH)%%.o: $(SRCS_PATH)%%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCS_PATH) -o $@ $<

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

leaks : re
	leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re


		'
	} > "Makefile"

}

main () {
	mkdir $1
	cd $1
	mkdir srcs includes
	make_header $2
	make_main $2
	make_make $2
}

# Check the number of arguments
if [ ${#} -ne 2 ]; then
	help
	exit 1
fi

main "${1}" "${2}"

# ls -d */* | xargs -I {} bash -c "cd '{}' && make fclean"
