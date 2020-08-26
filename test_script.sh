#!/bin/bash

for TEST in ./examples/*.txt; do
    
    echo $TEST | ./a.out > $TEST.res
    if test -f "$TEST.correct"; then
    	if cmp $TEST.res $TEST.correct &> /dev/null  # Подавление вывода.
		then echo "files $TEST and $TEST.correct are same"
		else echo "files $TEST and $TEST.correct are different"
		fi
	else 
		echo "$TEST"
		cat $TEST.res
	fi
    
    
done
