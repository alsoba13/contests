#include <bits/stdc++.h>
using namespace std;

bool is_permutation(vector<int> &v){
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

bool good(vector<int> &a, int k) {
	set<int> b;
	int max_v = 0;
	for(int i = 0; i<a.size()-k+1; i++){
		int min_ = a[i];
		for(int j = 0; j<k; j++){
			min_ = min(min_, a[i+j]);
		}
		max_v = max(max_v, min_);
		if (b.find(min_) != b.end()) return false;
		b.insert(min_);
	}
	return max_v == b.size();
}

void slv() {
	int n;
	vector<int> a;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int a_;
		cin >> a_;
		a.push_back(a_);
	}
	if(is_permutation(a)) {
		cout << 1;
	} else {
		cout << 0;
	}
	int lo = 2, hi = 2, sol = -1, mid;
	while(!good(a, hi) && hi < n){
		lo = hi+1;
		hi *= 2;
		hi = min(hi, n);
	}
	
	while (lo <= hi) {
		mid=lo+(hi-lo)/2;
		if (good(a, mid)) {
			sol = mid;
			hi = mid-1;
		} else {
			lo = mid + 1;
		}
	}
	if (sol == -1) {
		for(int i = 0; i < n-1; i++){
			cout << 0;
		}
	} else {
		for(int i = 2; i<sol; i++){
			cout << 0;
		}
		for(int i = sol; i <= n; i++){
			cout << 1;
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}