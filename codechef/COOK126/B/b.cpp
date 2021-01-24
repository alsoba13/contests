#include <bits/stdc++.h>
using namespace std;

int f() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i<n; i++){
		cin >> g[i];
	}
	int islands_sol = 0;
	int sol = n*m+1;
	for(int k = 0; k<2; k++){
		int s = 0;
		int islands = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				if ((j+i)%2 == k){
					islands++;
					if(g[i][j] == '.')s++;
				}else{
					if(g[i][j] == '*')s++;
				}
			}
		}
		if(islands_sol <= islands) {
			islands_sol = islands;
			sol = min(sol,s);
		}
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
        //slv();
	}
	return 0;
}
