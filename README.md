*This project has been created as part of the 42 curriculum by colassin, hgrandje.*

# Push_swap

## Description

Push_swap is an algorithmic project that sorts data on a stack using a limited set of operations with the minimum number of actions. The program takes a list of integers as input and outputs the sequence of operations needed to sort them in ascending order.

The project implements four distinct sorting strategies with different complexity classes:
- **Simple Algorithm**: O(n²) - Selection sort adaptation
- **Medium Algorithm**: O(n√n) - Chunk-based sorting
- **Complex Algorithm**: O(n log n) - Radix sort (LSD binary)
- **Adaptive Algorithm**: Automatically selects the best strategy based on disorder metric

## Instructions

### Compilation

```bash
# Compile the main program
make

# Compile with bonus (checker program)
make bonus

# Clean object files
make clean

# Full clean (objects + executables)
make fclean

# Recompile
make re
```

### Usage

```bash
# Basic usage (adaptive mode - default)
./push_swap 4 67 3 87 23

# Force specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Enable benchmark mode
./push_swap --bench 5 4 3 2 1

# Combine with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack a |
| `sb` | Swap first two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b onto a |
| `pb` | Push top of a onto b |
| `ra` | Rotate stack a (first becomes last) |
| `rb` | Rotate stack b (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (last becomes first) |
| `rrb` | Reverse rotate b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithm Explanation and Justification

### 1. Simple Algorithm - O(n²)

**Implementation**: Selection Sort Adaptation

**How it works**:
- Find the minimum element in stack a
- Rotate stack a to bring minimum to top
- Push to stack b
- Repeat until all elements are in b (sorted)
- Push all back to a

**Complexity Analysis**:
- Finding minimum: O(n) per iteration
- n iterations needed
- Total: O(n²) operations

**Use case**: Best for nearly sorted data or very small inputs where the overhead of more complex algorithms isn't justified.

### 2. Medium Algorithm - O(n√n)

**Implementation**: Chunk-based Sorting

**How it works**:
- Divide indices into √n chunks
- For each chunk, find the closest element in range
- Push to b, rotating smaller half to bottom
- After all pushed, rebuild a by finding max each time

**Complexity Analysis**:
- √n chunks, each containing √n elements
- Each element requires at most n/2 rotations to reach
- Optimized finding reduces average to O(√n) per element
- Total: O(n × √n) = O(n√n) operations

**Use case**: Good balance for moderately disordered data.

### 3. Complex Algorithm - O(n log n)

**Implementation**: Radix Sort (LSD Binary)

**How it works**:
- Uses binary representation of indices
- For each bit position (LSB to MSB):
  - Elements with bit=0 go to b
  - Elements with bit=1 stay (rotate) in a
  - Push all back from b to a
- After log(n) passes, stack is sorted

**Complexity Analysis**:
- log(n) bit positions to process
- n elements per pass
- Total: O(n × log n) operations

**Use case**: Optimal for highly disordered data where consistent performance is needed.

### 4. Adaptive Algorithm

**Implementation**: Disorder-based Strategy Selection

**How it works**:
- Computes disorder metric (inversion count ratio)
- Selects algorithm based on thresholds:
  - disorder < 0.2 → Simple O(n²)
  - 0.2 ≤ disorder < 0.5 → Medium O(n√n)
  - disorder ≥ 0.5 → Complex O(n log n)

**Threshold Justification**:
- **0.2 threshold**: At low disorder, simple insertion-style moves are efficient because few elements are out of place. The constant factors of O(n²) are lower than O(n log n).
- **0.5 threshold**: At medium disorder, chunk-based sorting balances between the simplicity of selection and the efficiency of radix, as approximately half the pairs are inverted.
- **Above 0.5**: High disorder means the data is significantly scrambled, where the logarithmic factor of radix sort provides the best asymptotic performance.

### Disorder Metric

```
disorder = inversions / total_pairs
```

Where an inversion is a pair (i, j) where i < j but a[i] > a[j].

- 0.0 = perfectly sorted
- 1.0 = reverse sorted (maximum disorder)

## Performance Benchmarks

| Input Size | Target (Pass) | Target (Good) | Target (Excellent) |
|------------|---------------|---------------|-------------------|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

## Project Structure

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h
├── libft/
└── srcs/
    ├── main.c
    ├── parsing/
    ├── stack/
    ├── operations/
    ├── algorithms/
    ├── disorder/
    ├── utils/
    ├── benchmark/
    └── bonus/
```

## Resources

### Documentation
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting)
- [Big-O Complexity Chart](https://www.bigocheatsheet.com/)
- [Radix Sort Explanation](https://en.wikipedia.org/wiki/Radix_sort)

### AI Usage

AI was used in this project for:
- **Conceptual discussions**: Understanding algorithmic complexity trade-offs
- **Code review**: Identifying potential memory leaks and norm violations
- **Documentation**: Helping structure the README and comments

All code was written, tested, and understood by the team members. AI suggestions were reviewed and adapted to fit the 42 norm requirements.

## Contributors

- **<login1>**: Parsing, stack operations, simple algorithm, benchmark
- **<login2>**: Medium algorithm, complex algorithm, adaptive selection, checker

## License

This project is part of the 42 school curriculum.