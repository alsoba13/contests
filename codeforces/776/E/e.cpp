#include <bits/stdc++.h>
using namespace std;

int getU(vector<int> &a) {
	int u = a[0]-1;
	for(int i = 1; i<a.size(); i++) u = min(u, a[i]-a[i-1]-1);
	return u;
}

vector<int> getCandidates(vector<int> &a, int u) {
	vector<int> candidates;
	int last = 0;
	for(int i = 0; i<a.size(); i++) {
		if(a[i]-last-1 == u) candidates.push_back(i);
		last = a[i];
	}
	return candidates;
}

int best (vector<int> &aa, int to_delete, int d) {
	vector<int> b;
	for(int i = 0; i<aa.size(); i++) {
		if(i!=to_delete) b.push_back(aa[i]);
	}
	int u = getU(b);
	int best_so_far = -1;
	for(int i = 0; i<b.size(); i++) {
		int l;
		if(i == 0) l = b[i]-1;
		else l = b[i]-b[i-1]-1;
		if(l == 0) continue;
		best_so_far = max(best_so_far, (l-1)/2);
	}
	if(b.back()!=d) {
		best_so_far = max(best_so_far, d-b.back()-1);
	}
	return min(u,best_so_far);
}

int f() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int u = getU(a);
	vector<int> candidates = getCandidates(a, u);
	if (candidates.size()>2) return u;
	if (candidates.size() == 2 && abs(candidates[0]-candidates[1])>1) return u;
	if (candidates.size() == 1) {
		if(candidates[0]==0)
			return best(a, candidates[0], d);
		return max(best(a, candidates[0], d), best(a, candidates[0]-1, d));
	}
	return max(best(a, candidates[0], d), best(a, candidates[1], d));
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
