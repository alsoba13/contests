#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i<n-1; i++) {
		int j = i;
		for(int k = i+1; k<n; k++){
			if(a[k]<a[j]) j = k;
		}
		reverse(a.begin()+i, a.begin()+j+1);
		ans += j-i+1;
	}
	return ans;
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
