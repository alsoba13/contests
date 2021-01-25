#include <bits/stdc++.h>
using namespace std;
 
int m[1000010];
bool sol(int start, int couple, vector<int> &a) {
	for(int i = 0; i<1000010; i++){
		m[i] = 0;
	}
	for(int i = 0; i<a.size(); i++) {
		m[a[i]]++;
	}
	vector<pair<int, int> > sol;
	sol.push_back(make_pair(start, couple));
	m[start]--;
	m[couple]--;
	int x = start;
	int p = a.size()-2;
	for(int i = 0; i<a.size()/2-1; i++){
		while(m[a[p]] == 0) p--;
		if((x-a[p] != a[p] && m[x-a[p]]) || (x-a[p] == a[p] && m[x-a[p]]>1)){
			m[x-a[p]]--;
			m[a[p]]--;
			sol.push_back(make_pair(x-a[p], a[p]));
			x = a[p];
			p--;
		}else{
			return false;
		}
	}
	cout << "YES\n"; 
	cout << sol[0].first + sol[0].second << '\n';
	for(int i = 0; i<sol.size(); i++){
		cout << sol[i].first << " " << sol[i].second << '\n';
	}
	return true;
}
 
void slv() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	for(int i = 0; i<2*n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 2*n-2; i>=0; i--){
		if(sol(a[2*n-1], a[i], a)) {
			return;
		}
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