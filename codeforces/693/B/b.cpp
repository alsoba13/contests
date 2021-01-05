#include <bits/stdc++.h>
using namespace std;

bool f() {
	int n;
	cin >> n;
	int one = 0, two = 0;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		if (a == 1) one++;
		else two++;
	}
	if (two%2 == 0) return one%2 == 0;
	return one >= 2 && one%2 == 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (f()? "YES": "NO") << endl;
		//slv();
	}
	return 0;
}