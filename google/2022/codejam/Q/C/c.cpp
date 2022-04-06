#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int best = 0;
	for(int i = 0; i<n; i++) {
		if(a[i]>best) best++;
	}
	return best;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
