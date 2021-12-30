#include <bits/stdc++.h>
using namespace std;
// almost copied from here https://codeforces.com/contest/1616/submission/141049454

template <typename T>
class FenwickTree {
    public:
        vector<T> t;
        int n;
        FenwickTree(vector<T> a) {
            n = a.size();
            t.assign(a.size(), 0);
            for(int i = 0; i<a.size(); i++)
                add(i, a[i]);
        }
        T sum(int r) {
            int ans = 0;
            while (r >= 0) {
                ans += t[r];
                r = (r & (r + 1)) - 1;
            }
            return ans;
        }
        T sum(int l, int r) {
            return sum(r) - sum(l-1);
        }
        void add(int i, int delta) {
            while (i<n) {
                t[i]+=delta;
                i |= i+1;
            }
        }
};

long long f() {
	int n; string s, t;
	cin >> n >> s >> t;
	FenwickTree<long long> ft(vector<long long>(n, 1));
	long long inf = 1000000000000000000LL;
	vector<long long> sol(n, inf);
	vector<vector<int> > pos(26);
	vector<int> ptr(26,0);
	for(int i = 0; i<n; i++) {
		pos[s[i]-'a'].push_back(i);
	}
	long long cost_prefix = 0;
	for(int i = 0; i<n; i++) {
		int char_to = t[i] - 'a';
		// Compute sol[i]
		for(int c = 0; c < char_to; c++) {
			if (ptr[c] < pos[c].size()) {
				int idx = pos[c][ptr[c]];
				sol[i] = min(sol[i], cost_prefix+ft.sum(idx-1));
			}
		}
		// compute prefix
		if (ptr[char_to] == pos[char_to].size()) break;
		cost_prefix += ft.sum(pos[char_to][ptr[char_to]]-1);
		ft.add(pos[char_to][ptr[char_to]], -1);
		ptr[char_to]++;
	}
	long long ans = sol[0];
	for(int i = 1; i<n; i++) ans = min(ans, sol[i]);
	if (ans == inf) return -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
