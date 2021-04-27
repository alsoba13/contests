#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
const int seed = 1;

int bruteforce(int a[], int l, int r) {
    int sum = 0;
    for(int i = l; i<=r; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    srand(seed);
    int a[N];
    for(int i = 0; i<N; i++) a[i] = (rand()%1000);
    // preprocessing
    const int len = (int)sqrt(N)+1;
    int b[len];
    for(int i = 0; i<len; i++) b[i] = 0;
    for(int i = 0; i<N; i++) b[i/len] += a[i];

    for(int l = 0; l<N; l++){
        for(int r = l; r<N; r++){
            // answering queries
            int sum = 0;
            int c_l = l / len,   c_r = r / len;
            if (c_l == c_r)
                for (int i=l; i<=r; ++i)
                    sum += a[i];
            else {
                for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                    sum += a[i];
                for (int i=c_l+1; i<=c_r-1; ++i)
                    sum += b[i];
                for (int i=c_r*len; i<=r; ++i)
                    sum += a[i];
            }
            
            // testing
            int sum2 = bruteforce(a, l, r);
            assert(sum == sum2);
        }
    }

}
