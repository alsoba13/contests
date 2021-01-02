#include <bits/stdc++.h>
using namespace std;

string f() {
	int n;
	cin >> n;
	string r, b;
	cin >> r >> b;
	int c = 0;
	for(int i = 0; i<n; i++){
		if(r[i]>b[i]) c++;
		else if (r[i]<b[i]) c--;
	}
	if (c>0) return "RED";
	if (c<0) return "BLUE";
	return "EQUAL";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << f() << endl;
	}
	return 0;
}
