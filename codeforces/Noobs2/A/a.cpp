#include <bits/stdc++.h>
using namespace std;

char f() {
	int n, b = 0;
	string a;
	cin >> n >> a;
	for(int i = 0; i<n; i++){
		if (a[i]=='0') b++;
		else b--;
		if (b<0) b+=4;
	}
	return "ESWN"[b%4];
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
