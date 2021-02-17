#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n;
	cin >> n;
	int num_partidos = n*(n-1)/2;
	int partidos_equipo = num_partidos*2/n;
	if(partidos_equipo%2==0){
		for(int i = 0; i<n-1; i++){
			for(int j = 0; j<n-i-1; j++){
				if(j<partidos_equipo/2) cout << "1 ";
				else cout << "-1 ";
			}
		}
	}else{
		for(int i = 0; i<n-1; i++){
			for(int j = 0; j<n-i-1; j++){
				if(j<partidos_equipo/2) cout << "1 ";
				else if (j==partidos_equipo/2) cout << "0 ";
				else cout << "-1 ";
			}
		}
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
