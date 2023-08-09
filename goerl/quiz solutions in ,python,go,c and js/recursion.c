#include <stdio.h>

int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return F(n - 3) + F(n - 2);
}

int main() {
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

// Recursion (top-down approach)

// In this approach, the function is simple and easy to understand. However, it's inefficient because it has an exponential time complexity due to the repeated calculations of the same subproblems