#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s, sol;
	cin >> s;
	sol = s;
	int K = 0;
	for(int i = 0; i<s.size(); i++){
		if(s[i] == '*') K = k;
		else if (K>0) sol[i] = '*', K--;
	}
	for(int i = s.size()-1; i>=0; i--){
		if(s[i] == '*') K = k;
		else if (K>0) sol[i] = '*', K--;
	}
	cout << sol << '\n';
	return 0;
}
