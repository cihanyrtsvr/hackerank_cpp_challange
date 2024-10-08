# Deque-STL 
Maximum of Each Subarray of Size K Using Deque
## Problem Description

Given a set of arrays of size `N` and an integer `K`, you have to find the maximum integer for each and every contiguous subarray of size `K` for each of the given arrays.

## Input Format

- The first line of input will contain the number of test cases `T`.
- For each test case:
  - The first line will contain two integers `N` (size of array) and `K` (size of subarray).
  - The second line will contain `N` space-separated integers representing the elements of the array `A_i`.

## Constraints

- \( 1 \leq T \leq 10 \)
- \( 1 \leq N \leq 10^5 \)
- \( 1 \leq K \leq N \)
- \( 0 \leq A_i \leq 10^6 \), where \( A_i \) is the \( i \)-th element of the array.

## Output Format

For each test case, print the maximum integer for each contiguous subarray of size `K`.

## Example

### Sample Input

```plaintext
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
```

### Sample Output
```plaintext
4 6 6 4
8 8 8 10
```

### Explanation 
First test case: The contiguous subarrays of size 2 are {3, 4}, {4, 6}, {6, 3}, and {3, 4}. The maximum values for these subarrays are: 4 6 6 4.

Second test case: The contiguous subarrays of size 4 are {3, 4, 5, 8}, {4, 5, 8, 1}, {5, 8, 1, 4}, and {8, 1, 4, 10}. The maximum values for these subarrays are: 8 8 8 10.
