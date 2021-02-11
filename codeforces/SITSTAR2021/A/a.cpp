#include <bits/stdc++.h>
using namespace std;

void slv() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a*b==c){
		cout << "YES\n" << a << " " << b << " " << c << '\n';
		return;
	}
	if(a*c==b){
		cout << "YES\n" << a << " " << c << " " << b << '\n';
		return;
	}
	if(c*b==a){
		cout << "YES\n" << c << " " << b << " " << a << '\n';
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
