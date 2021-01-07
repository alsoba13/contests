#include <bits/stdc++.h>
using namespace std;

bool is_permutation(vector<int> v){
	int max_ = v[0], min_ = v[0];
	set<int> s;
	for(int i = 0; i<v.size(); i++) {
		max_ = max(max_, v[i]);
		min_ = min(min_, v[i]);
		s.insert(v[i]);
	}
	if (min_ == 1 && max_ == v.size() && v.size() == s.size()) return true;
	return false;
	
}

void slv() {
	vector<int> a;
	int kkk;
	cin >> kkk;
	for(int i = 1; i<=5; i++) a.push_back(i);
	do{
		vector<int> b;
		for(int i = 0; i<6-kkk; i++){
			int min_ = a[i];
			for(int j = 0; j<kkk; j++){
				min_ = min(min_, a[i+j]);
			}
			b.push_back(min_);
		}
		if(is_permutation(b)){
			for(int i = 0; i<5; i++){
				cout << a[i] << " ";
			}
			cout << "<< ";
			for(int i = 0; i<6-kkk; i++){
				cout << b[i] << " ";
			}
			cout << endl;
		}
	}while(next_permutation(a.begin(), a.end()));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}