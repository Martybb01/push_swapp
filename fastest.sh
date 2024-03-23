#!/bin/bash

make
test()
{
	echo $1
	echo $2
	if [ "$1" = "$2" ]; then
		echo "OK"
	else
		echo "KO"
	fi
}


# output=$(./push_swap 2 13 17 12 8 16 7 19 1 4 14 10 15 6 18 11 9 5 20 3 | tr '\n' ' ' | sed 's/.*://')

# expected=$(seq 1 20 | tr '\n' ' ')

# test "$output" "$expected"

# # _______________________________________________
# output=$(./push_swap 2 6 1 3 4 5 7 | tr '\n' ' ' | sed 's/.*://')

# expected=$(seq 1 7 | tr '\n' ' ')

# test "$output" "$expected"

# #____________________________________________________

# output=$(./push_swap 5 3 4 2 1 6 | tr '\n' ' ' | sed 's/.*://')

# expected=$(seq 1 6 | tr '\n' ' ')

# test "$output" "$expected"

# #____________________________________________________

# output=$(./push_swap 6 4 5 2 3 1  | tr '\n' ' ' | sed 's/.*://')

# expected=$(seq 1 6 | tr '\n' ' ')


# test "$output" "$expected"

# # _______________________________________________

# output=$(./push_swap 6 4 1 5 3 2 | tr '\n' ' ' | sed 's/.*://')
# expected=$(seq 1 6 | tr '\n' ' ')

# test "$output" "$expected"


# # _______________________________________________

# output=$(./push_swap 5 6 1 3 2 4 | tr '\n' ' ' | sed 's/.*://')
# expected=$(seq 1 6 | tr '\n' ' ')

# test "$output" "$expected"

# # _______________________________________________
# output=$(./push_swap 4 5 1 2 6 3 | tr '\n' ' ' | sed 's/.*://')
# expected=$(seq 1 6 | tr '\n' ' ')

# test "$output" "$expected"

# # _______________________________________________
# output=$(./push_swap 1 6 2 5 4 3 | tr '\n' ' ' | sed 's/.*://')
# expected=$(seq 1 6 | tr '\n' ' ')

# test "$output" "$expected"

# _______________________________________________
output=$(./push_swap 1 3 4 2 5 6 | tr '\n' ' ' | sed 's/.*://')
expected=$(seq 1 6 | tr '\n' ' ')

test "$output" "$expected"

