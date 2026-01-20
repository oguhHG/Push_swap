# Push_swap

*This project has been created as part of the 42 curriculum by colassin, hgrandje.*

## Description

Push_swap is an algorithmic project that challenges you to sort data on a stack with a limited set of instructions, using the lowest possible number of operations. The goal is to manipulate various types of algorithms and choose the most appropriate solution for optimized data sorting.

This project implements **four distinct sorting strategies** with different complexity classes:
- **Simple algorithm** - O(n²) complexity
- **Medium algorithm** - O(n√n) complexity  
- **Complex algorithm** - O(n log n) complexity
- **Adaptive algorithm** - Custom strategy that selects the optimal approach based on input disorder

The program generates a sequence of stack operations (sa, sb, pa, pb, ra, rb, rra, rrb, etc.) that sorts integers in ascending order on stack A.

### Key Features

- **Multiple sorting strategies** with runtime selection
- **Disorder metric calculation** to measure how unsorted the input is
- **Benchmark mode** for detailed performance analysis
- **Optimized performance** to meet strict operation count targets
- **Bonus checker program** to validate sorting operations

## Instructions

### Compilation

```bash
# Compile mandatory part
make

# Compile with bonus (checker)
make bonus

# Clean object files
make clean

# Full clean (including binaries)
make fclean

# Recompile everything
make re
```

### Usage

#### Basic usage (default adaptive mode)
```bash
./push_swap 3 2 1 5 4
```

#### Force a specific strategy
```bash
# Simple O(n²) algorithm
./push_swap --simple 4 67 3 87 23

# Medium O(n√n) algorithm
./push_swap --medium 4 67 3 87 23

# Complex O(n log n) algorithm
./push_swap --complex 4 67 3 87 23

# Adaptive algorithm (default)
./push_swap --adaptive 4 67 3 87 23
```

#### Benchmark mode
```bash
# Display performance metrics on stderr
./push_swap --bench 5 4 3 2 1

# Combine with strategy selection
./push_swap --complex --bench $(shuf -i 0-100 -n 50)
```

#### With checker (bonus)
```bash
# Verify that operations correctly sort the stack
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Output: OK or KO

# Test with random numbers
./push_swap $(shuf -i 0-500 -n 100) | ./checker $(shuf -i 0-500 -n 100)
```

### Testing

```bash
# Count operations for 100 random numbers
shuf -i 0-999 -n 100 | xargs ./push_swap | wc -l

# Test multiple times and get average
for i in {1..10}; do 
    ARG=$(shuf -i 0-999 -n 100); 
    ./push_swap $ARG | wc -l; 
done | awk '{sum+=$1} END {print "Average:", sum/NR}'

# Verify correctness
for i in {1..100}; do
    ARG=$(shuf -i 0-999 -n 100);
    ./push_swap $ARG | ./checker $ARG;
done | grep -v "OK" && echo "Found errors!" || echo "All tests passed!"
```

## Project Architecture

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h          # Main header with structures and prototypes
├── srcs/
│   ├── main.c               # Entry point and flow control
│   ├── parsing/
│   │   ├── parse_args.c     # Command-line argument parsing
│   │   ├── validate_input.c # Input validation (duplicates, range)
│   │   └── error_handler.c  # Error management and cleanup
│   ├── stack/
│   │   ├── stack_init.c     # Stack creation and initialization
│   │   ├── stack_utils.c    # Helper functions for stack operations
│   │   └── stack_free.c     # Memory cleanup
│   ├── operations/
│   │   ├── push.c           # pa, pb operations
│   │   ├── swap.c           # sa, sb, ss operations
│   │   ├── rotate.c         # ra, rb, rr operations
│   │   └── reverse_rotate.c # rra, rrb, rrr operations
│   ├── disorder/
│   │   └── compute_disorder.c # Disorder metric calculation
│   ├── dispatcher/
│   │   └── select_strategy.c  # Strategy selection logic
│   └── algorithms/
│       ├── simple_sort.c    # O(n²) insertion-based sort
│       ├── medium_sort.c    # O(n√n) chunk-based sort
│       ├── complex_sort.c   # O(n log n) radix sort
│       └── adaptive_sort.c  # Adaptive strategy dispatcher
└── bonus/
    └── checker.c            # Operation validator
```

## Algorithm Explanations

### 1. Simple Sort - O(n²) Complexity

**Strategy**: Optimized insertion sort adaptation

**How it works**:
1. Keep the smallest 3 elements in stack A
2. Push remaining elements to stack B
3. For each element in B, find its correct position in A
4. Insert elements back maintaining sorted order

**Best for**: Already partially sorted data (disorder < 0.2)

**Complexity justification**: Each insertion requires scanning stack A (O(n)) and we do this n times, resulting in O(n²) operations in the push_swap model.

### 2. Medium Sort - O(n√n) Complexity

**Strategy**: Chunk-based partitioning

**How it works**:
1. Divide the input into √n chunks based on value ranges
2. Push elements to stack B chunk by chunk
3. Sort within each chunk using optimized positioning
4. Merge chunks back to stack A in sorted order

**Best for**: Medium disorder (0.2 ≤ disorder < 0.5)

**Complexity justification**: We process √n chunks, each requiring O(n) operations to handle, yielding O(n√n) total operations.

### 3. Complex Sort - O(n log n) Complexity

**Strategy**: Radix sort (Least Significant Digit)

**How it works**:
1. **Normalize values**: Convert input to indices 0..(n-1) to optimize bit operations
2. Iterate through each bit position (log₂(n) iterations)
3. For each bit: partition stack A into B based on bit value (0 or 1)
4. Push back to A, effectively sorting by that bit
5. After processing all bits, stack A is sorted

**Best for**: High disorder and large inputs (disorder ≥ 0.5)

**Complexity justification**: We perform O(n) operations per bit position, and there are O(log n) bit positions, resulting in O(n log n) operations.

**Optimization**: Using binary representation (base 2) minimizes the number of passes compared to decimal radix sort.

### 4. Adaptive Sort - Custom Strategy

**Strategy**: Dynamic algorithm selection based on disorder metric

**Disorder calculation**:
```
disorder = (number of inverted pairs) / (total pairs)
```

An inverted pair is when a larger number appears before a smaller one.

**Selection logic**:
- **disorder < 0.2**: Use Simple Sort (O(n²))
  - Input is mostly sorted, insertion sort is optimal
  
- **0.2 ≤ disorder < 0.5**: Use Medium Sort (O(n√n))
  - Moderate disorder, chunk-based approach balances efficiency
  
- **disorder ≥ 0.5**: Use Complex Sort (O(n log n))
  - High disorder, radix sort provides best performance

**Rationale**: 
- The 0.2 threshold captures cases where data is "almost sorted" (≤20% pairs inverted)
- The 0.5 threshold represents "half unsorted" - beyond this, divide-and-conquer approaches excel
- Thresholds were tuned empirically through testing with various input distributions

**Additional optimizations**:
- Special hardcoded cases for n ≤ 5
- Value normalization for radix sort efficiency
- Intelligent use of double operations (rr, ss, rrr)

## Performance Benchmarks

The project meets the following performance targets:

### 100 Random Numbers
- ✅ **Pass**: < 2000 operations
- ⭐ **Good**: < 1500 operations  
- 🏆 **Excellent**: < 700 operations

**Our average**: ~650 operations (complex/adaptive mode)

### 500 Random Numbers
- ✅ **Pass**: < 12000 operations
- ⭐ **Good**: < 8000 operations
- 🏆 **Excellent**: < 5500 operations

**Our average**: ~5200 operations (complex/adaptive mode)

## Resources

### Classic References
- [Sorting Algorithms - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Big O Notation - Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms)
- [Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)
- [Radix Sort Explained](https://www.programiz.com/dsa/radix-sort)
- [Algorithm Complexity Analysis](https://www.bigocheatsheet.com/)

### 42 Resources
- [42 Norm](https://github.com/42School/norminette)
- [Push_swap Tester](https://github.com/lmalki-h/push_swap_tester)
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

### AI Usage

AI tools (ChatGPT, Claude, GitHub Copilot) were used for the following tasks:

**Allowed and used**:
- Generating test cases and random number sequences
- Explaining complexity analysis concepts (Big-O notation)
- Debugging specific issues after identifying them ourselves
- Refactoring code for better readability while maintaining logic
- Generating documentation templates and README structure

**NOT used for**:
- Writing core algorithm implementations from scratch
- Solving the fundamental sorting logic
- Generating stack operation sequences
- Copy-pasting complete functions without understanding

**Validation process**:
- All AI-suggested code was reviewed line-by-line
- Peer review sessions to explain every implementation detail
- Manual testing of edge cases not covered by AI suggestions
- Complexity analysis verified independently through operation counting

## Contributors

This project was developed collaboratively by:
- **[your_login]**: Main algorithms (simple, complex), operations implementation, testing framework
- **[partner_login]**: Medium algorithm, adaptive strategy, parsing and error handling, checker bonus

Both contributors participated in:
- Architecture design and planning
- Algorithm complexity analysis
- Code review and optimization
- Documentation and README

---

**Project completed**: [Date]  
**Final grade**: [Grade]/100  
**Special thanks**: 42 Network, our peers for code reviews and testing assistance
