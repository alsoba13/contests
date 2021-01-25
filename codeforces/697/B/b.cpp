#include <bits/stdc++.h>
using namespace std;

set<int> sol;
void s() {
	for(int i = 0; i<500; i++){
		for(int j = 0; j<500; j++){
			sol.insert(2020*i+2021*j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	s();
	while (t--) {
		int n;
		cin >> n;
		cout << (sol.find(n)==sol.end()?"NO":"YES") << '\n';
	}
	return 0;
}
