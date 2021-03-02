#include <bits/stdc++.h>
using namespace std;

bool g(string a, int A, int B, int C){
	for(int i = 0; i<a.size(); i++){
		if(a[i]=='A') a[i] = (A?'(':')');
		if(a[i]=='B') a[i] = (B?'(':')');
		if(a[i]=='C') a[i] = (C?'(':')');
	}
	int c = 0;
	for(int i = 0; i<a.size(); i++){
		if(a[i]=='(')c++;
		else c--;
		if(c<0) return false;
	}
	return c==0;
}

bool f() {
	string a;
	cin >> a;
	for(int A = 0; A<2; A++){
		for(int B = 0; B<2; B++){
			for(int C = 0; C<2; C++){
				if(g(a, A, B, C)) return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << (f()?"YES":"NO") << '\n';
	}
	return 0;
}
