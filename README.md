# Push Swap

## About

Push Swap is a sorting algorithm project from the 42 School curriculum. The goal is to sort a stack of integers using a limited set of predefined operations while generating the smallest possible sequence of instructions.

The project focuses on algorithm optimization, data structures, complexity analysis, and problem-solving. Instead of directly sorting the data, the challenge is to determine the most efficient sequence of operations that transforms an unsorted stack into a sorted one.

## The Challenge

You are given a stack of integers called **stack A** and an empty **stack B**. Using only a restricted set of operations, you must sort all numbers in ascending order in stack A.

The objective is not only to sort the numbers but also to minimize the total number of operations performed.

## Allowed Operations

### Swap

```text
sa  - Swap the first two elements of stack A
sb  - Swap the first two elements of stack B
ss  - Execute sa and sb simultaneously
```

### Push

```text
pa  - Push the first element of stack B to stack A
pb  - Push the first element of stack A to stack B
```

### Rotate

```text
ra  - Shift all elements of stack A up by one
rb  - Shift all elements of stack B up by one
rr  - Execute ra and rb simultaneously
```

### Reverse Rotate

```text
rra - Shift all elements of stack A down by one
rrb - Shift all elements of stack B down by one
rrr - Execute rra and rrb simultaneously
```

## Features

- Input validation and error handling.
- Detection of already sorted stacks.
- Efficient sorting strategies for small and large datasets.
- Optimized operation generation.
- Memory leak prevention.
- Robust argument parsing.

## Usage

Compile the project:

```bash
make
```

Run the program:

```bash
./push_swap 2 1 3 6 5 8
```

Example output:

```text
sa
ra
pb
ra
pa
```

The output represents the sequence of operations required to sort the stack.

## Project Structure

```text
push_swap/
├── includes/
│   └── push_swap.h
├── src/
│   ├── parsing/
│   ├── operations/
│   ├── sorting/
│   ├── algorithms/
│   └── utils/
├── Makefile
└── README.md
```

## Compilation

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

The compilation generates:

```bash
./push_swap
```

## Sorting Strategy

Depending on the number of elements, different approaches can be used:

### Small Stacks

For small datasets (typically 2–5 numbers), dedicated sorting routines are used to achieve the minimum number of operations.

### Large Stacks

For larger datasets, more advanced strategies may be implemented, such as:

- Radix Sort
- Chunk-Based Sorting
- Cost-Based Insertion
- Hybrid Optimization Techniques

The goal is always to reduce the total number of instructions while maintaining efficient execution.

## Error Handling

The program must display:

```text
Error
```

when:

- Non-numeric arguments are provided.
- Duplicate numbers are detected.
- Integer overflow occurs.
- Invalid input formatting is found.

## Learning Objectives

Through this project, I developed skills in:

- Algorithm design and optimization.
- Complexity analysis.
- Data structures using linked lists or arrays.
- Stack manipulation.
- Input validation.
- Memory management.
- Performance-oriented programming.

## Technologies

- C
- Makefile
- Custom Data Structures
- Algorithm Optimization


Developed as part of the 42 School curriculum.
