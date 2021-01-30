#include <bits/stdc++.h>
using namespace std;

/*
I didn't manage to solve this during the contest. But I proposed 3 solutions.
	- First solution is my reimplementation of the winner of the round: https://codeforces.com/contest/1476/submission/105872560
	- Second is a "greedy" dfs.
	- Third is a dsu with bipartite graph
*/

void slv_best() {
	int n; 
	cin >> n;
	string d;
	cin >> d;
	vector<int> ll(n), lr(n);
	ll[0] = 1;
	for(int i = 1; i<n; i++){
		if (d[i]==d[i-1]) ll[i] = 1;
		else ll[i]=ll[i-1]+1;
	}
	lr[n-1] = 1;
	for(int i = n-2; i>=0; i--){
		if(d[i]==d[i+1]) lr[i] = 1;
		else lr[i]=lr[i+1]+1;
	}
	for(int i = 0; i<=n; i++){
		int ans = 1;
		if(i>0 && d[i-1]=='L') ans += ll[i-1];
		if(i<n && d[i]=='R') ans += lr[i];
		cout << ans << " ";
	}
	cout << endl;
}

vector<int> sols;
int dfs(int node, int cum, string &d, int steps) {
	cum++;
	if(steps%2==0){
		if(node<d.size() && d[node]=='R'){
			return sols[node] = dfs(node+1, cum, d, steps+1);
		}else{
			return sols[node] = cum;
		}
	}else{
		if(d[node]=='L'){
			return dfs(node+1, cum, d, steps+1);
		}else{
			return cum;
		}
	}
}
void slv_dfs() {
	int n; string d;
	cin >> n >> d;
	sols=vector<int>(n+1);
	for(int i = 0; i<=n; i++){
		if(sols[i] != 0){
			cout << sols[i] << " ";
			continue;
		}
		int left = 0;
		if(i>0 && d[i-1]=='L') left++;
		cout << dfs(i, left, d, 0) << " ";
	}
	cout << '\n';
}

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
void slv_dsu() {
	int n; string d;
	cin >> n >> d;
	p = vector<int>(2*(n+1));
	iota(p.begin(), p.end(), 0);
	for(int i = 0; i<=n; i++) {
		if(i>0) {
			if(d[i-1]=='L') union_(2*i, 2*(i-1)+1);
		}
		if(i<n) {
			if(d[i]=='R') union_(2*i, 2*(i+1)+1);
		}
	}
	map<int, int> sols;
	for(int i = 0; i<2*(n+1); i++){
		sols[get(p[i])]++;
	}
	for(int i = 0; i<=n; i++){
		cout << sols[get(p[i*2])] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		slv_dsu();
	}
	return 0;
}
