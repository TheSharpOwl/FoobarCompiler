#!/bin/bash

for TEST in ./examples/*.txt; do
    echo "$TEST"
    echo $TEST | ./a.out > $TEST.res
    cmp $TEST.res $TEST.correct
done
