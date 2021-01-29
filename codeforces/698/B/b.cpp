#include <bits/stdc++.h>
using namespace std;

bool f(int d, vector<int> jj) {
	int a;
	cin >> a;
	if(a>=10*d) return true;
	if(a%d == 0) return true;
	for(int j = 0; j<jj.size(); j++){
		if (a%10 == jj[j] && (j+1)*d<=a) {
			return true;
		}
	}
	return false;
}

void slv() {
	int n, d;
	cin >> n >> d;
	vector<int> jj;
	int d2 = (2*d)%10;
	jj.push_back(d);
	while(d2!=d){
		jj.push_back(d2);
		d2=(d2+d)%10;
	}
	for(int i = 0; i<n; i++){
		cout << (f(d, jj)?"YES":"NO") << '\n';
	}
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
