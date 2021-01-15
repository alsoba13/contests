#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i<2*k-n; i++){
		cout << i << " ";
	}
	for(int i = k; i>=2*k-n;i--) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
