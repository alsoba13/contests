#include <bits/stdc++.h>
using namespace std;

const int n = 6;

void comb(vector<int> &a, int lenght, int start, vector<int> &sofar) {
    if(lenght == sofar.size()){
        for(int i = 0; i<lenght; i++) cout << sofar[i] << " "; cout << endl;
    }
    for(int i = start; i<n; i++){
        sofar.push_back(a[i]);
        comb(a, lenght, i+1, sofar);
        sofar.pop_back();
    }
}

void combinationsOf(vector<int> &a, int lenght) {
    vector<int> v;
    comb(a, lenght, 0, v);
}


int main() {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for(int i = 0; i<n; i++) cout << a[i] << " "; cout << endl;
    for(int i = 1; i<=n; i++){
        cout << " - Combinations of " << i << " elements:" << endl;
        combinationsOf(a, i);
    }
	return 0;
}
