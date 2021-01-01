#include <bits/stdc++.h>
using namespace std;

string f() {
	string a;
	cin >> a;
	if(a[0] == ')' || a.back() == '(' || a.size()%2 == 1) return "NO";
	return "YES";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << endl;
	}
	return 0;
}