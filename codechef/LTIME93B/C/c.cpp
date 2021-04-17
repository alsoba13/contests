#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n; 
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 1; i<n; i++){
		if(a[i]>a[i-1]) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"Yes":"No") << '\n';
	}
	return 0;
}
