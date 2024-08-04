# push_swap Project

This repository contains my implementation to a fun and challenging sorting algorithm problem. The goal is to sort a list of numbers using a limited set of operations on two stacks.

## What's This About?

In this project, you'll find a program that sorts integers using two stacks (stack A and stack B) and a set of 11 predefined operations. The challenge is to figure out how to sort the numbers with as few moves as possible.

## Results

- For a set of 100 integers: 584 instructions on average.
- For a set of 500 integers: 5,177 instructions on average.
- For a set of 1,000 integers: 13,693 instructions on average.
- All 120 combinations of 5 integers are sorted in 12 moves or fewer.

## The Operations

Here's a quick rundown of the moves you can use:

- `sa`: Swap the first two elements on stack A.
- `sb`: Swap the first two elements on stack B.
- `ss`: Swap the first two elements on both stacks A and B.
- `pa`: Push the top element from stack B to stack A.
- `pb`: Push the top element from stack A to stack B.
- `ra`: Rotate stack A up by one (the first element goes to the end).
- `rb`: Rotate stack B up by one (the first element goes to the end).
- `rr`: Rotate both stacks A and B up by one.
- `rra`: Reverse rotate stack A down by one (the last element goes to the front).
- `rrb`: Reverse rotate stack B down by one (the last element goes to the front).
- `rrr`: Reverse rotate both stacks A and B down by one.

## Features

- **Flexible Input**: You can test different sets of numbers by passing them as command line arguments.
- **Error Handling**: It handles invalid inputs and edge cases gracefully.

## Getting Started

### What You Need

- A C compiler (like GCC)
- Make

### How to Set It Up

1. Clone this repository:
    ```sh
    git clone https://github.com/607mark/push_swap
    ```
2. Go into the project directory:
    ```sh
    cd push_swap
    ```
3. Compile the project:
    ```sh
    make
    ```

### How to Use It

Run the program with a list of numbers you want to sort:
```sh
./push_swap 3 2 5 1 4
```
or
```sh
./push_swap "3 2 5 1 4"
```
or (whatever)
```sh
./push_swap "3 2" 5 '1 4'
```
### test.sh

The `test.sh` script checks if your push_swap program processes the input correctly. To ensure it runs properly, you need to disable the instruction output.
