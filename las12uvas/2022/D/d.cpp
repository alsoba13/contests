#include <bits/stdc++.h>
using namespace std;

string p(string a){
	string ans;
	for(int i = 0; i<a.size(); i++) {
		if (a[i] != '.' && a[i] != ' ' && a[i] != ':' && a[i] != ';' && a[i] != ',') {
			char aa = a[i];
			if(a[i]<='Z') aa += ('a'-'A');
			ans += aa;
		}
	}
	return ans;
}

bool f() {
	string a, b;
	getline (std::cin,a);
	getline (std::cin,b);
	string aa, bb;
	aa = p(a);
	bb = p(b);
	return aa == bb;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	string kk;
	getline (std::cin,kk);
	while (t--) {
		//slv();
		cout << (f()?"SI":"NO") << '\n';
	}
	return 0;
}
