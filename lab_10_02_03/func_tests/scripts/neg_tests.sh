#!/bin/bash

main_func()
{
    echo -e "\tNegative Tests:"
    echo

	touch ../../func_tests/data/out.txt
	num=1 # counter
	green_col=$'\e[32mPASSED\e[0m' # green color
	red_col=$'\e[31mFAILED\e[0m' # red color

	while [[ "$num" -lt 10 && -e "../../func_tests/data/neg_0${num}_in.txt" ]]; do
		echo "TEST 0${num}:"
		
		../../app.exe < ../../func_tests/data/neg_0${num}_in.txt > ../../func_tests/data/out.txt
			
		rc=$? 
			
		if diff -Z "../../func_tests/data/neg_0${num}_out.txt" "../../func_tests/data/out.txt" && [ $rc -ne 0 ]; then 
			echo "pos_0${num}.txt: " "${green_col}"
		else
			echo "pos_0${num}.txt: " "${red_col}"
		fi
		
		echo
		(( num++ )) #counter increase
	done
}
main_func
rm ../data/out.txt