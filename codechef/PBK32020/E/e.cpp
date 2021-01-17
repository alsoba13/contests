#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i<n/2; i++) {
		cout << a[i*2+1] << " " << a[i*2] << " ";
	}
	if(n%2 == 1) {
		cout << a[n-1];
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//cout << f() << '\n';
		slv();
	}
	return 0;
}
