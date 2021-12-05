#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n; string s;
	cin >> n >> s; 
	vector<int> sol;
	int c0 = 0;
	for(int i = 0; i<n; i++) {
		if(s[i] == '0') c0++;
	}
	for(int i = 0; i<c0; i++){
		if(s[i] == '1') sol.push_back(i+1);
	}
	for(int i = c0; i<n; i++){
		if(s[i] == '0') sol.push_back(i+1);
	}
	if(sol.size() == 0) {
		cout << "0\n";
		return;
	} 
	cout << "1\n" << sol.size() << " ";
	for(int i = 0; i<sol.size(); i++) cout << sol[i] << " "; cout << "\n";
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
