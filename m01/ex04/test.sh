#!/bin/zsh

printf "diff the replacment\n"

help () {
	printf "usage: [file] [word] [word_replacment]\n"
}

main (){
	make
	./looserSed $1 $2 $3
	echo "\nrunning cmd : diff $1 $1\".replace\""
	diff $1 $1".replace"
	echo "\nrunning cmd : cat \"$1\" | grep \"$2\" # if nothing is printed grep found nothing"
	cat $1.replace | grep $2
}

# Check the number of arguments
if [ ${#} -ne 3 ]; then
	help
	exit 1
else
	printf "you used it wrong\n"
fi

main "${1}" "${2}" "${3}"
