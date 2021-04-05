#include <bits/stdc++.h>
using namespace std;

int n, q;

int ask(int a, int b, int c) {
	if(q==0) assert(false);
	cout << a << " " << b << " " << c << endl << flush;
	int m;
	cin >> m;
	q--;
	return m;
}

vector<int> slv_recursive(vector<int> v){
	if(v.size()<=1){
		return v;
	}
	vector<int> left, middle, right;
	int a = v[0], b = v[1];
	for(int i = 0; i<v.size(); i++) {
		if(v[i]==a || v[i]==b) continue;
		int m = ask(a, b, v[i]);
		if(m == a) left.push_back(v[i]);
		else if(m == b) right.push_back(v[i]);
		else middle.push_back(v[i]);
	}
	vector<int> sol1 = slv_recursive(left);
	if(sol1.size()>1 && ask(sol1[0], sol1[1], a) == sol1[0]) reverse(sol1.begin(), sol1.end());
	vector<int> sol2 = slv_recursive(middle);
	if(sol2.size()>1 && ask(sol2[0], sol2[1], a) == sol2[1]) reverse(sol2.begin(), sol2.end());
	vector<int> sol3 = slv_recursive(right);
	if(sol3.size()>1 && ask(sol3[0], sol3[1], b) == sol3[1]) reverse(sol3.begin(), sol3.end());
	sol1.push_back(a);
	sol2.push_back(b);
	sol1.insert(sol1.end(), sol2.begin(), sol2.end());
	sol1.insert(sol1.end(), sol3.begin(), sol3.end());
	return sol1;
}

void slv() {
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	vector<int> sol = slv_recursive(a);
	for(int i = 0; i<n; i++) cout << sol[i] << " "; cout << endl << flush;
	int correct;
	cin >> correct;
	if(!correct) assert(false);
}

int main() {
	int t;
	cin >> t >> n >> q;
	while(t--){
		slv();
	}
	return 0;
}
