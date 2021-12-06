#include <bits/stdc++.h>
using namespace std;

int n, o;
vector<long long> a, sum;

long long find_pair() {
    for (int i = o; i<n; i++) {
        bool found = false;
        for (int j = i-o; j < i-1; j++)
            for (int k = j+1; k < i; k++) 
                if (a[j] + a[k] == a[i])
                    found = true;
        if (!found) return a[i];
    }
    return -1;
}

long long find_cont(int acc) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+2; j < n+1; j++){
            if (sum[j] - sum[i] == acc){
                long long m = a[i], M = a[i];
                for (int k = i; k<j; k++) {
                    m = min(a[k], m);
                    M = max(a[k], M);
                }
                return m + M;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> o;
    a = vector<long long>(n);
    sum.push_back(0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum.push_back(sum.back()+a[i]);
    }
    int sol = find_pair();
    cout << "Problem1: " << sol << endl << "Problem2: " << find_cont(sol) << endl;
}