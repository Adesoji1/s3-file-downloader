#include <stdio.h>

#define MAX_SIZE 1000 // set the size of the cache as needed

int cache[MAX_SIZE];

int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (cache[n] != -1) return cache[n];  // return the cached result if it's already computed
    return cache[n] = F(n - 3) + F(n - 2);
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) cache[i] = -1;  // initialize the cache with -1
    printf("F(0) = %d\n", F(0));   // expects 0
    printf("F(1) = %d\n", F(1));   // expects 1
    printf("F(2) = %d\n", F(2));   // expects 2
    printf("F(3) = %d\n", F(3));   // expects 1
    printf("F(4) = %d\n", F(4));   // expects 3
    printf("F(5) = %d\n", F(5));   // expects 3
    printf("F(6) = %d\n", F(6));   // expects 4
    printf("F(7) = %d\n", F(7));   // expects 6
    printf("F(8) = %d\n", F(8));   // expects 7
    printf("F(9) = %d\n", F(9));   // expects 10
    printf("F(10) = %d\n", F(10)); // expects 13
    return 0;
}


// Memoization (top-down approach with caching)
// In this approach, we use an array to store the results of subproblems. This approach reduces the time complexity to linear, but it requires extra space for the cache. This is also a top-down approach like the recursive solution, but with added optimization.

