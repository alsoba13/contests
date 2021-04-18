#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    return n*(n+1)/2;
}

int sum2(int n) {
    return (2 << n) - 1;
}

int main() {
    printf("Sum of 1+2+3+...+10 = %d\n", sum(10));
    printf("Sum of 1+2+4+8+...+1024 = %d\n", sum2(10));
}
