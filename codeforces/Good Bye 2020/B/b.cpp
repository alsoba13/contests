#include <bits/stdc++.h>
using namespace std;

int f() {
	set<int> notes;
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int note;
		cin >> note;
		if (notes.find(note) == notes.end()) {
			notes.insert(note);
		} else {
			notes.insert(note+1);
		}
	}
	return notes.size();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
