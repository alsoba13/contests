#include <bits/stdc++.h>
using namespace std;

long long f() {
	int A, B, k;
	cin >> A >> B >> k;
	vector<int> a(k), b(k), ca(A), cb(B);
	for(int i = 0; i<k; i++) { 
		cin >> a[i];
		a[i]--;
		ca[a[i]]++;
	}
	for(int i = 0; i<k; i++) {
		cin >> b[i];
		b[i]--;
		cb[b[i]]++;
	}
	long long ans = 0;
	for(int i = 0; i<k; i++)
		ans += k - ca[a[i]] - cb[b[i]] + 1;
	return ans/2;
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
