#include <bits/stdc++.h>
using namespace std;

vector<int> bb(int a){
	vector<int> u(30);
	for(int i = 0; i<30; i++){
		u[i] = (a&(1<<i))>0;
	}
	return u;
}
bool f(){
	int a, b;
	cin >> a >> b;
	if(a>b) return false;
	vector<int> u, v;
	u = bb(a);
	v = bb(b);
	int cu = 0, cv = 0;
	for(int i = 0; i<30; i++){
		if(u[i]) cu++;
		if(v[i]) cv++;
		if(cv>cu) return false;
	}
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
