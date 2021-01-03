#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<long long, long long> m1, m2;
    long long zeros, ones, xs, sol1 = 0, sol2 = 0;
    vector<long long> offsets, offsets_aux; 
    for(int i = 0; i<n; i++){
        string instruction, value;
        cin >> instruction >> value >> value;
        if (instruction == "mask") {
            zeros = xs = (1L << 35)-1; ones = 0;
            offsets.clear(); offsets.push_back(0);
            for(int c = 0; c < value.size(); c++) {
                if (value[c] == '0') zeros = zeros ^ (1L << (35-c));
                if (value[c] == '1') ones = ones | (1L << (35-c));
                if (value[c] == 'X') {
                    xs = xs ^ (1L << (35-c));
                    offsets_aux = offsets;
                    for (int o = 0; o < offsets.size(); o++) offsets_aux.push_back(offsets[o] + (1L << (35-c)));
                    offsets = offsets_aux;
                }
            }
        } else {
            int pos = stoi(instruction.substr(4, instruction.size()-1));
            m1[pos] = stoi(value) & zeros | ones;
            for (int o = 0; o < offsets.size(); o++) { 
                m2[pos & xs | ones + offsets[o]] = stoi(value);
            }
        }
    }
    for (map<long long, long long>::iterator i = m1.begin(); i != m1.end(); i++) sol1 += i->second;
    for (map<long long, long long>::iterator i = m2.begin(); i != m2.end(); i++) sol2 += i->second;
    cout << "Problem1: " << sol1 << endl << "Problem2: " << sol2 << endl;
}