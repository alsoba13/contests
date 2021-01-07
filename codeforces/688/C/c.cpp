#include <bits/stdc++.h>
using namespace std;

string m[2000];
int n; 

int f(char d){
	int max_b = 0, max_t = n-1, max_l = n-1, max_r = 0;
	vector<pair<int, int> > p;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(m[i][j] == d){
				p.push_back(make_pair(i, j));
				if (i < max_t) max_t = i;
				if (i > max_b) max_b = i;
				if (j > max_r) max_r = j;
				if (j < max_l) max_l = j;
			}
		}
	}
	int maxx = 0;
	for (int pp = 0; pp < p.size(); pp++) {
		maxx = max(maxx, max(abs(0-p[pp].first), abs(n-1-p[pp].first)) * max(abs(max_r-p[pp].second), abs(max_l-p[pp].second)));
		maxx = max(maxx, max(abs(0-p[pp].second), abs(n-1-p[pp].second)) * max(abs(max_t-p[pp].first), abs(max_b-p[pp].first)));
	}
	return maxx;
}

void slv() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	for (int d = '0'; d <= '9'; d++) {
		cout << f(d) << " ";
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