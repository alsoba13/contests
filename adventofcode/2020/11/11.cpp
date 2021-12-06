#include <bits/stdc++.h>
using namespace std;

int n, m;

bool occupied(vector<string> &a, int i, int j, int di, int dj, bool direct_neighbour) {
    if (di == dj && di == 0) return false;
    for (i+=di, j+=dj; i>=0 && j>=0 && i<n && j<m; i+=di, j+=dj) 
        if (direct_neighbour || a[i][j] != '.') return a[i][j] == '#';
    return false;
}

int slv(vector<string> a, bool direct_neighbour, int neighbours) {
    while (1) {
        vector<pair<int, int> > changes;
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++) {
                if (a[i][j] == '.') continue;
                int c = 0;
                for (int di = -1; di<=1; di++) for (int dj = -1; dj<=1; dj++) c += occupied(a, i, j, di, dj, direct_neighbour);
                if ((a[i][j] == '#' && c >= neighbours) || (a[i][j] == 'L' && c == 0)) 
                    changes.push_back(make_pair(i, j));
            }
        if (changes.size() == 0) break;
        for (int i = 0; i<changes.size(); i++)
            a[changes[i].first][changes[i].second] = (a[changes[i].first][changes[i].second] == '#' ? 'L' : '#');
    }
    int sol1 = 0;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if (a[i][j] == '#') sol1++;
    return sol1;
}

int main() {
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Problem1: " << slv(a, true, 4) << endl << "Problem2: " << slv(a, false, 5) << endl;
}