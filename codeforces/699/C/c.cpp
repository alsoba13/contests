#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	map<int, vector<int> > faltan;
	map<int, int> tengo;
	for(int i = 0; i<n; i++) cin >> a[i];
	long long f = 0;
	for(int i = 0; i<n; i++){
		cin >> b[i];
		if(a[i]==b[i]){
			tengo[b[i]] = i+1;
		}
		else {
			faltan[b[i]].push_back(i+1);
			f++;
		}
	}
	for(int i = 0; i<m; i++) cin >> c[i];
	vector<int> sol(m);
	for(int i = m-1; i>=0; i--) {
		if(faltan[c[i]].size()>0){
			sol[i] = faltan[c[i]][faltan[c[i]].size()-1];
			faltan[c[i]].pop_back();
			f--;
		}else{
			if (tengo.find(c[i])!=tengo.end()){
				sol[i] = tengo[c[i]];
			}else{
				if(i == m-1){
					cout << "NO\n";
					return;
				}else{
					sol[i] = sol[i+1];
				}
			}
		}
	}
	if(f>0){
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	for(int i = 0; i<m; i++) cout << sol[i] << " ";
	cout << '\n';
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
