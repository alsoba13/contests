#include <bits/stdc++.h>
using namespace std;
void slv() {
	vector<int> sol(4,1e7);
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<4; j++) {
			int v;
			cin >> v;
			sol[j] = min(sol[j],v);
		}
	}
	int ink_so_far = 0;
	for(int i = 0; i<4; i++) {
		sol[i] = min(1000000-ink_so_far, sol[i]);
		ink_so_far += sol[i];
	}
	if (ink_so_far != 1000000) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int i = 0; i<4; i++) cout << sol[i] << " "; cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		slv();
	}
	return 0;
}
