#include <bits/stdc++.h>
using namespace std;

void slv() {
	int n, k = 0;
	cin >> n;
	vector<string> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) k += (t[i][j] != '.' ? 1 : 0);
	pair<int, int> s[3];
	for(int i = 0; i<3; i++) s[i] = make_pair(0,0);
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if (t[i][j] == 'X') s[(i+j)%3].first++;
			if (t[i][j] == 'O') s[(i+j)%3].second++;
		}
	int min_ = k, min_x, min_o;
	for (int x = 0; x < 3; x++) {
		for(int o = 0; o < 3; o++) {
			if (x == o) continue;
			if (s[x].first + s[o].second < min_) {
				min_ = s[x].first + s[o].second;
				min_x = x; min_o = o;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 3 == min_x && t[i][j] == 'X') t[i][j] = 'O';
			else if ((i + j) % 3 == min_o && t[i][j] == 'O') t[i][j] = 'X';
	for (int i = 0; i < n; i++)
		cout << t[i] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		slv();
	}
	return 0;
}