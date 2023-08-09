#include <stdio.h>

#define MAX_SIZE 1000 // set the size of the array as needed

int F(int n) {
    int dp[MAX_SIZE] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    return dp[n];
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

// Dynamic programming (bottom-up approach)
// This is a bottom-up approach. It avoids recursion and builds the solution iteratively from the base case to the target value. It also has a linear time complexity and requires extra space to store the intermediate results.