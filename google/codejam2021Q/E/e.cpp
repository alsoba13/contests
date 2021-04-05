#include <bits/stdc++.h>
using namespace std;
const int n = 100;
const int Q = 10000;

double calculateSD(vector<double> data) {
    double sum = 0.0;
    for(int i = 0; i < data.size(); ++i)
        sum += data[i];
    double mean = sum/data.size();
	double standardDeviation = 0.0;
    for(int i = 0; i < data.size(); ++i)
        standardDeviation += pow(data[i] - mean, 2);
    return sqrt(standardDeviation / data.size());;
}

int f() {
	bool r[n][Q];
	vector<pair<int, int> > cnt_q(Q, make_pair(0,0));
	for(int i = 0; i<Q; i++) cnt_q[i].second = i;
	for(int i = 0; i<n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j<Q; j++){
			r[i][j] = s[j]-'0';
			cnt_q[j].first+=s[j]-'0';
		}
	}
	sort(cnt_q.begin(), cnt_q.end());
	vector<int> rank(Q);
	for(int i = 0; i<Q; i++) rank[cnt_q[i].second] = i;
	vector<pair<double, int> > deviations(n);
	for(int i = 0; i<n; i++){
		vector<double> difs;
		for(int j = 0; j<Q; j++) {
			if(r[i][j]==1) difs.push_back(rank[j]);
		}
		deviations[i].first = calculateSD(difs);
		deviations[i].second = i;
	}
	sort(deviations.rbegin(), deviations.rend());
	return deviations[0].second+1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, p;
	cin >> t >> p;
	for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		//slv();
		cout << f() << '\n';
	}
	return 0;
}
