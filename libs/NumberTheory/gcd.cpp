#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

int main() {
	for(int i = 1; i<10; i++) {
        for(int j = i+1; j<10; j++) {
            printf("gcd(%d, %d) = %d\n", i, j, gcd(i,j));
        }
    }
	for(int i = 1; i<10; i++) {
        for(int j = i+1; j<10; j++) {
            printf("lcm(%d, %d) = %d\n", i, j, lcm(i,j));
        }
    }
	return 0;
}
