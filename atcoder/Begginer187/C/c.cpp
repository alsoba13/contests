#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> a, b;
	for(int i = 0; i<n; i++) {
		string s;
		cin >> s;
		if (s[0] == '!') {
			s = s.substr(1);
			if (a.find(s) != a.end()){
				cout << s << endl;
				return 0;
			}
			b.insert(s);
		} else {
			if (b.find(s) != b.end()){
				cout << s << endl;
				return 0;
			}
			a.insert(s);
		}
	}
	cout << "satisfiable" << endl;
	return 0;
}