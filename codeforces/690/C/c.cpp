#include <bits/stdc++.h>
using namespace std;

map<int, int> s;

int f(vector<int> a) {
	string sol = "0";
	for(int i = 0; i<a.size(); i++) sol+=('0'+a[i]);
	return stoi(sol);
}

int main() {
	int t;
	cin >> t;
	vector<int> a;
	for(int i=1; i<=9; i++)a.push_back(i);
	for(int i = 0; i<512; i++) {
		vector<int> b;
		for(int j = 0; j<9; j++)
			if (i & (1 << j)) 
				b.push_back(a[j]);
		int sum = 0;
		for(int j = 0; j<b.size(); j++)
			sum += b[j];
		if(s.find(sum) == s.end()) s[sum] = f(b);
		else s[sum] = min(s[sum], f(b));
	}
	while (t--) {
		int n;
		cin >> n;
		if(s[n] == 0) cout << -1 << endl;
		else cout << s[n] << endl;
	}
	return 0;
}