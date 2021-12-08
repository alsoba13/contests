#include <bits/stdc++.h>
using namespace std;

int slv(vector<string> a, int n, int m) {
    int g = 0, e = 0;
    for(int i = 0; i<m; i++) {
        int cnt = 0;
        for(int j = 0; j<n; j++)
            if (a[j][i] == '1') cnt++;
            else cnt--;
        e <<= 1;
        g <<= 1;
        if(cnt>0) g++;
        else e++;
    }
    return e*g;
}

int slv2(vector<string> a, int n, int m, bool lcb) {
    vector<int> candidates(n);
    iota(candidates.begin(), candidates.end(), 0);
    for(int i = 0; i<m && candidates.size()>1; i++) {
        int cnt = 0;
        for(int j = 0; j<candidates.size(); j++)
            if(a[candidates[j]][i] == '1') cnt++;
            else cnt--;
        vector<int> new_candidates;
        char to_find = ((cnt < 0)^lcb)+'0';
        for(int j = 0; j<candidates.size(); j++) 
            if(a[candidates[j]][i] == to_find) 
                new_candidates.push_back(candidates[j]);
        candidates = new_candidates;
    }
    int sol = 0;
    for(int i = 0; i<m; i++) sol = sol*2 + a[candidates[0]][i]-'0';
    return sol;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Problem1: " << slv(a, n, m) << endl;
    cout << "Problem2: " << slv2(a, n, m, true) * slv2(a, n, m, false) << endl;
}