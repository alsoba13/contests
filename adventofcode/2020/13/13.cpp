#include <bits/stdc++.h>
using namespace std;

long long inv(long long a, long long b) {
    long long b0 = b, x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        long long q = a/b;
        long long t = a;
        a = b;
        b = t%b;
        t = x0;
        x0 = x1 - q*x0;
        x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

long long crt(vector<pair<long long, long long> > a) {
    long long N = 1;
    for(int i = 0; i < a.size(); i++) {
        N *= a[i].first;
    }
    long long sum = 0;
    for(int i = 0; i< a.size(); i++) {
        sum += a[i].second * N/a[i].first * inv(N/a[i].first, a[i].first);
    }
    return sum % N;
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long> > a;
    string input;
    cin >> input;
    input += ",x";
    int init = -1, sol_min = n, sol1;
    for(int i = 0, c = 0; i<n; i++){
        if ('0' <= input[i] && input[i] <= '9')
            if (init == -1) init = i;
        if (input[i] == ',') {
            if (init != -1) {
                int v = stoi(input.substr(init, i));
                a.push_back(make_pair(v, ((v-c)%v+v)%v));
                if (v-n%v < sol_min) {
                    sol_min = v-n%v;
                    sol1 = (v-n%v) * v;
                }
                init = -1;
            }
            c++;
        }
    }
    cout << "Problem1: " << sol1 << endl << "Problem2: " << crt(a) << endl;
}