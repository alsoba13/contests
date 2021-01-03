#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sol1 = 0, sol2;
    cin >> n;
    vector<int> s;
    for (int i = 0; i < n; i++) {
        string bp; cin >> bp;
        int seat_id = 0;
        for (int j = 0; j < bp.size(); j++) seat_id = seat_id * 2 + (bp[j] == 'B' || bp[j] == 'R' ? 1 : 0);
        sol1 = max(sol1, seat_id);
        s.push_back(seat_id);
    }
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++) {
        if (s[i] - 1 != s[i-1]) {
            sol2 = s[i] - 1;
            break;
        }
    }
	cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}