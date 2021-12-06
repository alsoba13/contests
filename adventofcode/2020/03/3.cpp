#include <bits/stdc++.h>
using namespace std;

int main() {
    int s; cin >> s;
    vector<pair<int, int> > slopes(s);
    for (int i = 0; i < s; i++) {
        cin >> slopes[i].first >> slopes[i].second;
    }
    int n, m; cin >> n >> m;
	vector<string> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    int sol = 1;
    for (int s = 0; s < slopes.size(); s++) {
        int trees = 0;
        for (int i = 0, j = 0; i < n; i+=slopes[s].first, j = (j+slopes[s].second)%m) if (mp[i][j] == '#') trees++;
        sol *= trees;
    }
    cout << sol << endl;
}
