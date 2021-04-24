#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, K;
	cin >> n >> K;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int k = 0; k<K; k++) {
		int ii = -1;
		for(int i = 0; i<n-1; i++) {
			if(a[i] != 0) {
				ii = i;
				break;
			}
		}
		if (ii == -1) break;
		a[ii]--;
		a[n-1]++;
	}
	for(int i = 0; i<n; i++) cout << a[i] << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
