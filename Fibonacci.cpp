#include <stdio.h>

// Memoization array to store computed Fibonacci values for reuse
int memo[100] = {0};

// Function to compute the nth Fibonacci number using memoization
int f(int n) {
    // Base case: Fibonacci(0) and Fibonacci(1) are 1
    if (n <= 1) {
        return 1;    
    // If the value has already been computed, return it
    } else if (memo[n] != 0) {
        return memo[n];    
    // Otherwise, compute the value, store it in the memo array, and return it
    } else {
        return memo[n] = f(n - 1) + f(n - 2);
    }
}

int main() {
    // Print the 45th Fibonacci number using memoization
    printf("%d\n", f(45));

    // TABULATION SECTION


    // Tabulation array to store computed Fibonacci values iteratively
    int memoTabu[100] = {0};
    int n = 45;

    // Base cases: Fibonacci(0) and Fibonacci(1) are 1
    memoTabu[0] = 1;
    memoTabu[1] = 1;

    // Compute the Fibonacci values iteratively from 2 to n
    for (int i = 2; i <= n; i++) {
        memoTabu[i] = memoTabu[i - 1] + memoTabu[i - 2];
    }

    // Print the 45th Fibonacci number using tabulation
    printf("%d\n", memoTabu[n]);
    return 0;
}
