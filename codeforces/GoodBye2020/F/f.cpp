#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int get(int v) {
	if (v == p[v]) return v;
	return p[v] = get(p[v]);
}

void union_(int a, int b){
	a = get(a);
	b = get(b);
	if (a != b) p[b] = a;
}

long long f(int s){
	long long sol = 1;
	while(s--) sol = sol*2 % 1000000007;
	return sol;
}

void slv() {
	int m, n;
	cin >> m >> n;
	p = vector<int>(n+1, 0);
	set<int> pintados;
	vector<int> solucion;
	for(int i = 0; i<m; i++) {
		int tipo;
		cin >> tipo;
		if (tipo == 1) {
			int nodo, padre;
			cin >> nodo;
			padre = get(nodo);
			if (padre == 0) {
				p[nodo] = nodo;
				solucion.push_back(i+1);
				pintados.insert(nodo);
			} else {
				if (pintados.find(padre) == pintados.end()) {
					solucion.push_back(i+1);
					pintados.insert(padre);
				}
			}
		} else {
			int a, b, pa, pb;
			cin >> a >> b;
			pa = get(a);
			pb = get(b);
			if (0 == pa && 0 == pb) {
				p[a] = b;
				p[b] = b;
				solucion.push_back(i+1);
			}else{
				if (pa != 0 && pb != 0) {
					if (pa != pb)
						if(pintados.find(pb) == pintados.end() || pintados.find(pa) == pintados.end()) {
							union_(a, b);
							solucion.push_back(i+1);
							if (pintados.find(pb) != pintados.end() || pintados.find(pa) != pintados.end()){
								pintados.insert(pa);
								pintados.insert(pb);
							}
						}
				}else{
					if (pb == 0) p[b] = pa;
					else p[a] = pb;
					solucion.push_back(i+1);
				}
			}
		}
	} 
	cout << f(solucion.size()) << " " << solucion.size() << endl;
	for(int i = 0; i<solucion.size(); i++){
		cout << solucion[i] << " "; 
	}
	cout << endl;
}

int main() {
	slv();
	return 0;
}