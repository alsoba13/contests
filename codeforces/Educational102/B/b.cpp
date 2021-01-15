#include <bits/stdc++.h>
using namespace std;

bool divisible(string a, string b){
	if(a.size()%b.size()!=0) return false;
	for(int i = 0; i<a.size(); i++){
		if(a[i]!=b[i%b.size()]) return false;
	}
	return true;
}

string f() {
	string s, t;
	cin >> s >> t;
	string aux = "";
	for(int i = 0; i<400; i++) {
		aux += s;
		if (divisible(aux, t)) return aux;
	}	
	return "-1";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << endl;
	}
	return 0;
}
