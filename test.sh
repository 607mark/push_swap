#!/bin/bash

# Function to run a test and check if it outputs "Error\n" to stderr
run_test() {
    output=$(./push_swap "$1" 2>&1)
    if [ "$output" == "Error" ]; then
        echo "Test '$1': Passed (Error)"
    else
        echo "Test '$1': Failed (Expected Error)"
    fi
}

# Function to run a valid test and check if it does NOT output "Error\n" to stderr
run_valid_test() {
    output=$(./push_swap "$1" 2>&1)
    if [ "$output" == "Error" ]; then
        echo "Test '$1': Failed (Unexpected Error)"
    else
        echo "Test '$1': Passed"
    fi
}

# Valid Tests
run_valid_test "1 3 5 +9 20 -4 50 60 04 08"
run_valid_test "3 4 6 8 9 74 -56 +495"
run_valid_test "2147483647 2 4 7"
run_valid_test "99 -2147483648 23 545"
run_valid_test "2147483647 843 56544 24394"
run_valid_test "95 99 -9 10 9"

# Invalid Tests
run_test "1 3 dog 35 80 -3"
run_test "a"
run_test "1 2 3 5 67b778 947"
run_test "12 4 6 8 54fhd 4354"
run_test "1 -- 45 32"
run_test "1 3 58 9 3"
run_test "3 03"
run_test "49 128 50 38 49"
run_test "54867543867438 3"
run_test "-2147483647765 4 5"
run_test "214748364748385 28 47 29"

