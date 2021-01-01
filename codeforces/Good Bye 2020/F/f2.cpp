#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int get(int v) {
	if (v == p[v]) return v;
	return p[v] = get(p[v]);
}

bool union_(int a, int b){
	a = get(a);
	b = get(b);
	if (a != b) {
		p[b] = a;
		return true;
	}
	return false;
}

int main() { // Simpler solution
	int m, n; long long ans = 1;
	cin >> m >> n;
	p = vector<int>(n+1);
	iota(p.begin(), p.end(), 0);
	vector<int> solucion;
	for(int i = 0; i<m; i++) {
		int tipo, a, b;
		cin >> tipo;
		if (tipo == 1) {
			cin >> a;
			b = 0;
		} else 
			cin >> a >> b;
		if (union_(a,b)) {
			solucion.push_back(i+1);
			ans = (ans * 2)%1000000007;
		}
	} 
	cout << ans << " " << solucion.size() << endl;
	for(int i = 0; i<solucion.size(); i++) cout << solucion[i] << " ";  cout << endl;
}
