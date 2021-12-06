#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n+1, 0), ways(n+2, 0);
    for (int i = 0; i<n; i++)
        cin >> a[i+1];
    sort(a.begin(), a.end());
    a.push_back(a[n]+3);
    int ones = 0, threes = 0;
    for(int i = 1; i<n+2; i++) {
        if(a[i]-a[i-1] == 1) ones++;
        if(a[i]-a[i-1] == 3) threes++;
    }
    ways[0] = 1;
    for(int i = 0; i<n+1; i++) 
        for(int j = i+1; j <= min(n+1, i+3); j++) 
            if(a[j] - a[i] <= 3) 
                ways[j] += ways[i];
    cout << "Problem1: " << ones*threes << endl << "Problem2: " << ways[n+1] << endl;
}