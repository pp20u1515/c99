#!/bin/bash

main_func()
{
	echo -e "\tPositive Tests:"
	echo
	
	touch ../../func_tests/data/out.txt
	num=1 # counter
	green_col=$'\e[32mPASSED\e[0m' # green color
	red_col=$'\e[31mFAILED\e[0m' # red color
	
	while [[ "$num" -lt 10 && -e "../../func_tests/data/pos_0${num}_args.txt" ]]; do
		echo "TEST 0${num}:"
		
		# using wc command to count number of words
		argc=`wc --word < ../../func_tests/data/pos_0${num}_args.txt`
		
		if [[ "$argc" -eq 3 || "$argc" -eq 4 ]]; then
			cat ../../func_tests/data/pos_0${num}_args.txt | xargs ../../app.exe
			
			rc=$? 
			
			if diff -Z "../../func_tests/data/pos_0${num}_out.txt" "../../func_tests/data/out.txt" && [ $rc -eq 0 ]; then 
				echo "pos_0${num}.txt: " "${green_col}"
			else
				echo "pos_0${num}.txt: " "${red_col}"
			fi
		else
			echo "pos_0${num}.txt: " "${red_col}"
		fi
		
		echo
		(( num++ )) #counter increase
	done
}

main_func
rm ../../func_tests/data/out.txt
