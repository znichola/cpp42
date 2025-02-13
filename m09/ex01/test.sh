#!/bin/bash

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
BOLD="\033[1m"

N=0

cmp() {
	A=$1
	shift
	local S=$(2>&1 ./RPN "$@")
	if [[ $A == $S ]]; then
		printf "${BLUE}%2s ${BOLD}${GREEN}OK${RESET}\n" "$N"
	else
		printf "${BLUE}%2s ${BOLD}${RED}KO${RESET}\n" "$N"
		printf "   ${BOLD}${RED}:${RESET}  Inputted '$@'\n"
		printf "   ${BOLD}${RED}:${RESET}  Expected '$A'\n"
		printf "   ${BOLD}${RED}:${RESET}  Received '$S'\n"
	fi
	N=$(($N + 1))
}

cmp 2 "1 2 3 - -"
cmp 1 "9 8 /"
cmp 0 "7 3 5 + - 7 5 1 + * /"
cmp 42 "6 7 *"
cmp 12 "6 4 * 2 / 1 *"
cmp Error "1 / 0"
cmp Error "11 2 /"
cmp Error "1 2+"
cmp Error "1 2 + 8*"
cmp Error "a b +"
cmp Error "8 - 9"
