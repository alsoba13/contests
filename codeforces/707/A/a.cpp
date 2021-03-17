#include <bits/stdc++.h>
using namespace std;

int f() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), tm(n);
	for(int i = 0; i<n; i++)
		cin >> a[i] >> b[i];
	for(int i = 0; i<n; i++)
		cin >> tm[i];
	int t = 0, b0 = 0;
	for(int i = 0; i<n; i++){
		if(i!=0)
			b0 = b[i-1];
		t+=a[i]-b0+tm[i];
		if(i<n-1){
			t+=(b[i]-a[i])/2+(b[i]-a[i])%2;
			t = max(b[i], t);
		}
	}
	return t;
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
