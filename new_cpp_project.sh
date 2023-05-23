#!/bin/zsh


printf "generate cpp project boilerplate files\n"

help () {
	printf "usage: [project folder] [project name] <Class1> <Class2> <ClassN> \n"
}

################ file header ##########

std_header () {
	file_name="${1}"

	creation_date=$(date +'%Y/%m/%d')
	creation_time=$(date +'%H:%M:%S')

	printf "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   "
	printf "%-44s" ${file_name}

	printf "       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: "
	printf "%-43s" "$USER <$USER@student.42lausanne.ch>"
	printf "+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${creation_date} ${creation_time} by znichola          #+#    #+#             */
/*   Updated: ${creation_date} ${creation_time} by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

"
}

std_header_make () {
	file_name="${1}"

	creation_date=$(date +'%Y/%m/%d')
	creation_time=$(date +'%H:%M:%S')

	printf "# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    "
	printf "%-44s" ${file_name}

	printf "       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: "
	printf "%-43s" "$USER <$USER@student.42lausanne.ch>"
	printf "+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: ${creation_date} ${creation_time} by znichola          #+#    #+#              #
#    Updated: ${creation_date} ${creation_time} by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

"
}

################# header ##################

make_header () {
	# file_name=$(printf "%s.hpp" "${1}" | awk '{print tolower($0)}')
	file_name=$(printf "%s.hpp" "${1}")
	shift

	# Set to upper the argument and append _H
	header_guard_name=$(printf "%s_HPP" "${1}" | awk '{print toupper($0)}')
	{
		std_header $file_name

		printf "#ifndef %s\n" "${header_guard_name}" ;
		printf "# define %s\n\n" "${header_guard_name}";

		printf "# include <iostream>\n\n"

		for var in "$@"
		do
			printf "# include \"$var.hpp\"\n"
		done

		printf "\n#endif /* %s */\n" "${header_guard_name}"
	} > includes/"${file_name}"
}

################## main ###################

make_main () {
	file_name=$(printf "main.cpp")

	# Set to upper the argument and append _H
	{

		std_header $file_name

		printf "#include <iostream>\n"
		printf "\n#include \"${1}.hpp\"\n"

		printf "\nint\tmain(int ac, char **av)\n{\n\t(void)ac;\n\t(void)av;\n"
		printf "\tstd::cout << \"hello ${1}!\" << std::endl;\n"
		printf "\treturn(0);\n}\n"
	} > srcs/"${file_name}"
}

################## class ###################

make_class_header () {
	class_name="${1}"
	file_name=$(printf "%s.hpp" "${class_name}")

	header_guard_name=$(printf "%s_HPP" "${class_name}" | awk '{print toupper($0)}')
	{
		std_header $file_name

		printf "#ifndef %s\n" "${header_guard_name}" ;
		printf "# define %s\n" "${header_guard_name}";

		print "
class ${class_name}
{
private:

public:
// Default constructor
	${class_name}();

// Copy constructor
	${class_name}(const ${class_name} &other);

// Destructor
	~${class_name}();

// Copy assignment operator
	${class_name} & operator=(const ${class_name} &other);
};
"

		printf "#endif /* %s */\n" "${header_guard_name}"
	} > includes/"${file_name}"
}

make_class_source () {
	class_name="${1}"

	file_name=$(printf "%s.cpp" "${class_name}")

	{
		std_header $file_name

		printf "
#include \"${class_name}.hpp\"

// Default constructor
${class_name}::${class_name}()
{
}

// Copy constructor
${class_name}::${class_name}(const ${class_name} &other)
{
	*this = other;
}

// Destructor
${class_name}::~${class_name}()
{
}

// Copy assignment operator
${class_name} &${class_name}::operator=(const ${class_name} &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


"
	} > srcs/"${file_name}"
}

make_class () {
	class_name="${1}"

	make_class_header $class_name
	make_class_source $class_name
}

################## make ###################

make_make () {
	file_name="Makefile"
	project_name="${1}"
	shift

	{
		std_header_make $file_name

		printf "NAME	= ${project_name}\n"
		printf '
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

FILES	= main'

	for var in "$@"
	do
		printf " $var"
	done

printf '

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

run : all
	./$(NAME)

leaks : re
	$(LEAKS_CHECK) ./$(NAME)

.PHONY: all clean fclean re


		'
	} > $file_name

}

main () {
	project_dir=${1}
	project_name=${2}
	echo $project_name >> .gitignore
	shift
	shift

	mkdir $project_dir
	cd $project_dir
	mkdir srcs includes
	make_header $project_name $@
	make_main $project_name
	make_make $project_name $@

	for var in "$@"
	do
		make_class "$var"
	done
}

# Check the number of arguments
if [ ${#} -lt 2 ]; then
	help
	exit 1
fi

if [ "$1" = "class" ]; then
	echo "make a class!"

	shift

	for var in "$@"
	do
		make_class "$var"
	done

	exit 1
fi

# main "${1}" "${2}" "${3}" "${4}"
main $@

# ls -d */* | xargs -I {} bash -c "cd '{}' && make fclean"
