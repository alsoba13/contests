#include <bits/stdc++.h>
using namespace std;

void slv() {
	long long a, b;
	cin >> a >> b;
	if (b == 1){
		cout << "NO\n";
		return;
	}
	cout << "YES\n" << a*b << " " << a << " " << a*b+a << endl;
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
