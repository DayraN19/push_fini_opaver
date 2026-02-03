*This project has been created as part of the 42 curriculum by bgranier [,axmancea].*

# push_swap

## Description

**push_swap** is an algorithmic project whose goal is to sort a stack of integers using
a limited set of operations and a second auxiliary stack.  
The challenge is not only to sort the data correctly, but to do so using the **minimum
number of operations** possible.

The program takes a list of integers as input, builds an initial stack (A), and outputs
a sequence of operations that results in the stack being sorted in ascending order.
All operations must follow the strict rules defined by the subject.

This implementation also includes a **custom adaptive strategy** that dynamically
selects the most appropriate internal sorting method based on the measured disorder
of the input.

---

## Instructions

### Compilation
make and ./push_swap [options] <numbers>

#### Example
./push_swap 3 2 1
./push_swap --bench 5 1 4 2 3
./push_swap --medium 8 3 6 2 9 1

*This project has been created as part of the 42 curriculum by bgranier.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a stack of integers using a **limited set of operations** and an auxiliary stack **B**, while minimizing the total number of operations.

The program receives a list of integers, initializes them in stack **A**, and outputs a sequence of operations to sort the stack in ascending order.  

This implementation includes a **custom adaptive strategy** that selects the most efficient internal sorting method based on the **disorder** of the input stack.

---

## Instructions

### Compilation

```bash
make
```