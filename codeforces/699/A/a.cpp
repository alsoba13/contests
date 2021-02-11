#include <bits/stdc++.h>
using namespace std;

bool f (){
	int x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	int r, l, d, u;
	r=l=d=u=0;
	for(int i = 0; i<s.size(); i++){
		switch (s[i])
		{
		case 'R': r++; break;
		case 'L': l++; break;
		case 'U': u++; break;
		case 'D': d++; break;
		}
	}
	if(x>0 && r<x) return false;
	if(x<0 && l<-x) return false;
	if(y>0 && u<y) return false;
	if(y<0 && d<-y) return false;
	return true;
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
