#include <bits/stdc++.h>
using namespace std;

const int n = 11;

int factorial (int n) {
    int ans = 1;
    while(n>0){
        ans *= n;
        n--;
    }
    return ans;
}

int nCk(int n, int k){
    return factorial(n)/factorial(k)/factorial(n-k);
}

int main() {
    cout << "Number of permutations of size N: " << factorial(n) << endl;
    for(int i = 0; i<=n; i++) {
        printf("nCk(%d, %d) = %d\n", n, i, nCk(n, i));
    }
	return 0;
}
