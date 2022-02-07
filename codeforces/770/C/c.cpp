#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n,k;
	cin >> n >> k;
	if(k == 1 || n%2 == 0) {
		cout << "YES\n";
		for(int i = 0; i<n/2+n%2; i++) {
			for(int j = 0; j<k; j++) {
				cout << 2*i*k+1+2*j << " ";
			}
			cout << "\n";
		}
		for(int i = 0; i<n/2; i++) {
			for(int j = 0; j<k; j++) {
				cout << 2*i*k+2+2*j << " ";
			}
			cout << "\n";
		}
		return;
	}
	cout << "NO\n";
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
