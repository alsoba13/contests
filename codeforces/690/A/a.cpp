#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i<n; i++) cin>>a[i];
		for(int i = 0; i<n/2; i++) cout << a[i] << " " << a[n-1-i] << " ";
		if(n%2 == 1) cout << a[n/2];
		cout << endl;
	}
	return 0;
}