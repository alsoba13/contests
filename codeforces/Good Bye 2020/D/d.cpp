#include <bits/stdc++.h>
using namespace std;

void slv2() { // My submited solution
	int n;
	cin >> n;
	vector<pair<long long, int> > w(n);
	long long sum = 0;
	for(int i = 0; i<n; i++) {
		cin >> w[i].first;
		w[i].second = i;
		sum += w[i].first;
	}
	sort(w.begin(), w.end());
	map<int, int> adj;
	for(int i = 0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a-1]++;
		adj[b-1]++;
	}
	cout << sum << " ";
	for(int i = n-1; i>=0; i--) {
		while(adj[w[i].second] > 1){
			sum += w[i].first;
			adj[w[i].second]--;
			cout << sum << " ";
		}
	}
	cout << endl;
}

void slv() { // Better solution?
	int n;
	cin >> n;
	vector<int> w(n), adj(n), inc;
	long long sum = 0;
	for(int i = 0; i<n; i++) {
		cin >> w[i];
		sum += w[i];
	}
	for(int i = 0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a]++;
		adj[b]++;
	}
	for(int i = 0; i<n; i++) 
		for(int j = 1; j<adj[i]; j++)
			inc.push_back(w[i]);
	sort(inc.rbegin(), inc.rend());
	cout << sum << " ";
	for(int i = 0; i<inc.size(); i++) {
		sum += inc[i];
		cout << sum << " ";
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
