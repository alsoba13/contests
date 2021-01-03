#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		sum+=a[i];
	}
	for(int c = n; c>=1; c--) {
		if(sum % c != 0) continue;
		bool ok = true;
		for(int i = 0, s=0; i<n; i++){
			s+=a[i];
			if(s > sum/c) {
				ok = false;
				break;
			}
			if(s == sum/c) {
				s = 0;
			}
		}
		if(ok) return n-c;
	}
	return n-1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}