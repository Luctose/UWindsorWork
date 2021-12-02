#!/bin/bash

echo "Start building main program:"
echo "Compiling to assembly lines ..."
cc main.c -S
cc increment.c -S
echo "translating to opcodes ..."
cc main.s -c
cc increment.s -c
echo "Statically linking all required opcodes ..."
cc main.o increment.o -o main
echo "Build successfully done!"
#echo "Running the main program:"
#./main
#echo "Running the main for input 4:"
#./main <<< 4
#echo "Running the main for input 10:"
#./main <<< 10

pass=0
fail=0
IFS=","
counter=0
while read input
do
	
	for i in $input
	do
		if [ $(( $counter % 2 )) -eq 0 ]
		then
			sepinput=$i
		else
			correct_output=$i
		fi
		counter=$(( $counter + 1 ))
	done
	counter=0
	output=$(./main <<< $sepinput)
	echo -n "Input: $sepinput"
	echo -n ", Main: $output"
	echo -n ", Correct: $correct_output ==> "	
	if [[ "$output" -eq "$correct_output" ]];
	then
		pass=$(( $pass + 1 ))
		echo "Passed"
	else
		fail=$(( $fail + 1 ))
		echo "Failed"
	fi
done < "./test_inputs.txt"
echo "Total passed: $pass"
echo "Total failed: $fail"
