#include <bits/stdc++.h>
using namespace std;

void move(int &x, int &y, char c, int value) {
    switch (c) {
        case 'E': x+=value; break;
        case 'S': y-=value; break;
        case 'W': x-=value; break;
        case 'N': y+=value; break;
    }
}

int main() {
    char dirs[4] = {'E', 'S', 'W', 'N'};
    int n, dir = 0, x = 0, y = 0, wx = 10, wy = 1, x2 = 0, y2 = 0;
    cin >> n; 
    for(int i = 0; i<n; i++) {
        string ins;
        cin >> ins;
        int value = stoi(ins.substr(1));
        switch (ins[0]){
            case 'F':
                move(x, y, dirs[dir], value);
                x2 += wx*value; y2 += wy*value;
                break;
            case 'R':
                dir = (dir + (value/90))%4;
                for(int i = 0; i<value/90; i++){ int t = wx; wx = wy; wy = -t; }
                break;
            case 'L':
                dir = (dir - (value/90) + 4)%4;
                for(int i = 0; i<4-value/90; i++){ int t = wx; wx = wy; wy = -t; }
                break;
            default:
                move(x, y, ins[0], value);
                move(wx, wy, ins[0], value);
                break;
        }
    }
    cout << "Problem1: " << abs(x) + abs(y) << endl << "Problem2: " << abs(x2) + abs(y2) << endl;
}