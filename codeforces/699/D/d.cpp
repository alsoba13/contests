#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, m;
	string g[1000];
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> g[i]; 
	}
	vector<int> sol;
	if(m%2==1){
		sol.push_back(1);
		sol.push_back(2);
	}else{
		for(int i = 0; i<n&&!sol.size(); i++)
			for(int j = i+1; j<n&&!sol.size(); j++)
				if(g[i][j] == g[j][i]){
					sol.push_back(i+1);
					sol.push_back(j+1);
				}
		if(!sol.size() && n>2)
			for(int i = 0; i<n&&!sol.size(); i++)
				for(int j = 0; j<n&&!sol.size(); j++)
					for(int k = 0; k<n&&!sol.size(); k++)
						if(i!=j && j!=k && i!=k && g[i][j]==g[j][k]){
							if(m%4==0){
								sol.push_back(j+1);
								sol.push_back(k+1);
								sol.push_back(j+1);
								sol.push_back(i+1);
							}else{
								sol.push_back(i+1);
								sol.push_back(j+1);
								sol.push_back(k+1);
								sol.push_back(j+1);
							}
						}
	}
	if(!sol.size()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 0; i<=m; i++){
		cout << sol[i%sol.size()] << " ";
	}
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
