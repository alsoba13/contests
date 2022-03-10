#include <bits/stdc++.h>
using namespace std;

int shift(vector<int> &a, int f) {
	vector<int> b(a.begin(), a.begin()+f+1);
	if(a[f] == f+1) return 0;
	int s = 1;
	for(int i = 0; i<f; i++) {
		if(a[i] == f+1) break;
		s++;
	}
	for(int i = f; i>=0; i--)
		a[i] = b[(i+s)%(f+1)];
	return s;
}

void slv() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	vector<int> sol(n, 0);
	for(int i = n-1; i>=0; i--) {
		sol[i] = shift(a, i);
	}
	for(int i = 0; i<n; i++) cout << sol[i] << " "; cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
		//cout << f() << '\n';
	}
	return 0;
}
