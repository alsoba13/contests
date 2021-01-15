#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	int min_sum = d+1;
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++){
			min_sum = min(min_sum, a[i]+a[j]);
		}
	}
	if(min_sum <= d) return true;
	for(int i = 0; i<n; i++){
		if(a[i] > d) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << endl;
	}
	return 0;
}
