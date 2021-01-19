#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		reverse(a[i].begin(),a[i].end());
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<n; i++){
		reverse(a[i].begin(),a[i].end());
		cout << a[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){ 
		cout << "Case " << i << ":" << '\n';
		slv();
	}
	return 0;
}
