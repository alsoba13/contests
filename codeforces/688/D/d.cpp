#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &sol, int n) {
	sol.push_back(1);
	for(int i = 0; i<n; i++) sol.push_back(0);
}

void slv(vector<long long> a) {
	long long k;
	cin >> k;
	if(k%2 == 1) {
		cout << -1 << endl;
		return;
	}
	vector<int> sol;
	int i = a.size()-1;
	while(i>=0){
		while(a[i]<=k) {
			k-=a[i];
			f(sol, i);
		}
		i--;
	}
	if (k > 0 || sol.size() > 2000) {
		cout << -1 << endl;
		return;
	}
	cout << sol.size() << endl;
	for(int i = 0; i<sol.size(); i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<long long> a;
	long long e = 2;
	long long s = 2;
	while(e < 2000000000000000000) {
		a.push_back(s);
		e*=2;
		s+=e;
	}
	int t = 0; 
	cin >> t;
	while (t--) {
		slv(a);
	}
	return 0;
}