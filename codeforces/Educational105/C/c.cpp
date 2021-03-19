#include <bits/stdc++.h>
using namespace std;

int g(vector<long long> a, vector<long long> b) {
	int n, m;
	n = a.size();
	m = b.size();
	if (m == 0 || n == 0) return 0;
	vector<int> prehits(m);
	set<int> as;
	for(int i = 0; i<n; i++) as.insert(a[i]);
	prehits[m-1] = (as.find(b[m-1])==as.end()?0:1);
	for(int i = m-2; i>=0; i--) prehits[i] = prehits[i+1] + (as.find(b[i])==as.end()?0:1);
	int pa, pb;
	int ans = 0;
	pa = pb = 0;
	for(int k = 0; k<m; k++){
		while(pa<n && a[pa]<b[k]+pa) pa++;
		while(pb<m && b[k]+pa>b[pb]) pb++;
		if(pb<m) ans = max(ans, pb-k+prehits[pb]);
		else ans =  max(ans, pb-k);
	}
	return ans;
}

int f() {
	int n, m;
	cin >> n >> m;
	vector<long long> a1, a2, b1, b2;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		if(a<0) a1.push_back(-a);
		else a2.push_back(a);
	}
	for(int i = 0; i<m; i++){
		int a;
		cin >> a;
		if(a<0) b1.push_back(-a);
		else b2.push_back(a);
	}
	reverse(a1.begin(), a1.end());
	reverse(b1.begin(), b1.end());
	return g(a1, b1)+g(a2, b2);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
