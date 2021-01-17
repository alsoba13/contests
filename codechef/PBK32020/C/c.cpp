#include <bits/stdc++.h>
using namespace std;

string f() {
	string n; 
	cin >> n;
	sort(n.rbegin(), n.rend());
	return n;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << "\n";
	}
	return 0;
}
