#include <iostream>
#include <vector>
using namespace std;

int gg(vector<vector<int> > &g, int x, int y) {
    int ans = 1;
    int N = 99;
    vector<pair<int, int> > d(4);
    d[0].first = 1; d[1].first = -1; d[2].second = 1; d[3].second = -1;
    for(int dd = 0; dd<d.size(); dd++) {
        int cnt = 0;
        int i, j;
        i = x, j = y;
        while(true) {
            i += d[dd].first;
            j += d[dd].second;
            if (i<0 || j<0 || i>=N || j>=N) break;
            cnt++;
            if (g[i][j]>=g[x][y]) break;
        }
        ans *= cnt;
    }
    return ans;
}

int f() {
	vector<vector<int> > g(99, vector<int>(99));
	for(int i = 0; i<99; i++){
		string a;
		cin >> a;
		for(int j = 0; j<99; j++) g[i][j] = a[j]-'0';
	}
    int ans = 0;
    for(int i = 0; i<99; i++){
        for(int j = 0; j<99; j++){
            ans = max(ans, gg(g, i, j));
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << f() << '\n';
	return 0;
}
