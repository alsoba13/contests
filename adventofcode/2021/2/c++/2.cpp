#include <bits/stdc++.h>
using namespace std;

int slv(vector<pair<string, int> > a, int n) {
    int d, h;
    d = h = 0;
    for(int i = 0; i<n; i++) {
        switch (a[i].first[0]) {
            case 'u': d -= a[i].second; break;
            case 'd': d += a[i].second; break;
            case 'f': h += a[i].second; break;
        }
    }
    return d*h;
}

int slv2(vector<pair<string, int> > a, int n) {
    int d, h, aim;
    d = h = aim = 0;
    for(int i = 0; i<n; i++) {
        switch (a[i].first[0]) {
            case 'u': aim -= a[i].second; break;
            case 'd': aim += a[i].second; break;
            case 'f': h += a[i].second; d += aim * a[i].second; break;
        }
    }
    return d*h;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int> > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    cout << "Problem1: " << slv(a, n) << endl;
    cout << "Problem2: " << slv2(a, n) << endl;
}