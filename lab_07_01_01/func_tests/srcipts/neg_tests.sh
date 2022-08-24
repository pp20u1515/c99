#!/bin/bash

main_func()
{
    echo -e "\tNegative Tests:"
    echo

	num=1 # counter
	green_col=$'\e[32mPASSED\e[0m' # green color
	red_col=$'\e[31mFAILED\e[0m' # red color

	while [[ "$num" -lt 10 && -e "../data/neg_0${num}_args.txt" ]]; do
		echo "TEST 0${num}:"
		
		# using wc command to count number of words
		argc=`wc --word < ../data/neg_0${num}_args.txt`

		if [[ "$argc" -eq 2 || "$argc" -eq 3 ]]; then
			cat ../data/neg_0${num}_args.txt | xargs ../../app.exe > ../data/out.txt

			rc=$? 

			if diff -Z "../data/neg_0${num}_out.txt" "../data/out.txt" && [ $rc -ne 0 ]; then 
				echo "neg_0${num}.txt: " "${green_col}"
			else
				echo "neg_0${num}.txt: " "${red_col}"
			fi
		else
			echo "neg_0${num}.txt: " "${green_col}"
		fi
		
		echo
		(( num++ )) #counter increase
	done
}

main_func
rm out.txt