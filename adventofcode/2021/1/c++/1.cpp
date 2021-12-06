#include <bits/stdc++.h>
using namespace std;

int slv(vector<int> a, int n, int window_width) {
    int ans = 0;
    for(int i = 0; i < n-window_width; i++)
        if(a[i] < a[i+window_width]) ans++;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Problem1: " << slv(a, n, 1) << endl;
    cout << "Problem2: " << slv(a, n, 3) << endl;
}