#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > process(vector<int> &a, int start, int end) {
	int sign = 1;
	int q = 0;
	for(int i = start; i<end; i++) {
		if(a[i]<0) sign *= -1;
		if(abs(a[i])==2) q++;
	}
	if(sign == 1) return make_pair(q, make_pair(0,0));
	int q1=0, q2=0;
	int t1, t2;
	for(int i = start; i<end; i++) {
		if(abs(a[i])==2) q1++;
		if(a[i]<0) {
			t1 = i-start+1;
			break;
		}
	}
	for(int i = end-1; i>=start; i--) {
		if(abs(a[i])==2) q2++;
		if(a[i]<0) {
			t2 = end-i;
			break;
		}
	}
	if(q1<q2) return make_pair(q-q1, make_pair(t1, 0));
	return make_pair(q-q2, make_pair(0,t2));
}

void slv() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	int best = 0;
	pair<int,int> sol = make_pair(0,n);
	for(int i = 0; i<n; i++) {
		int start = i;
		while(i<n && a[i]!=0) i++;
		if(start != i) {
			pair<int,pair<int,int> > b = process(a, start, i);
			if (b.first>best) {
				best = b.first;
				sol = make_pair(start+b.second.first, n-i+b.second.second);
			}
		}
	}
	cout << sol.first << " " << sol.second << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}
