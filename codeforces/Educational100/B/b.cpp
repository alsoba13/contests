#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for(int i = 0; i<n; i++){
			int a, b = 1;
			cin >> a;
			while(b <= a) b*=2;
			cout << b/2 << " ";
		}
		cout << endl;
	}
	return 0;
}