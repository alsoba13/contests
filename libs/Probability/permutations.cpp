#include <bits/stdc++.h>
using namespace std;

const int n = 4;

void permutations_stl(vector<int> &a) {
    do {
        for(int i = 0; i<n; i++) cout << a[i] << " "; cout << endl;
    } while(next_permutation(a.begin(), a.end()));
}

template <typename T>
bool next_permutation_custom(T begin, T end) {
    T rightmost_element_with_higher_neighbour = end;
    for(T i = begin; i!=end; i++) {
        if((i+1)!=end && *i < *(i+1)) rightmost_element_with_higher_neighbour = i;
    }
    if(rightmost_element_with_higher_neighbour == end) return false;
    T rightmost_element_after = end;
    for(T i = rightmost_element_with_higher_neighbour+1; i!=end; i++){
        if(*i > *rightmost_element_with_higher_neighbour) rightmost_element_after = i;
    }
    swap(*rightmost_element_with_higher_neighbour, *rightmost_element_after);
    reverse(rightmost_element_with_higher_neighbour+1, end);
    return true;
}

void permutations_next_permutation_custom(vector<int> &a) {
    do {
        for(int i = 0; i<n; i++) cout << a[i] << " "; cout << endl;
    } while(next_permutation_custom(a.begin(), a.end()));
}

void permutations_backtracking(vector<int> &a, int next) {
    if(next == n){
        for(int i = 0; i<n; i++) cout << a[i] << " "; cout << endl;
    }
    for(int i = next; i<n; i++){
        swap(a[i], a[next]);
        permutations_backtracking(a, next+1);
        swap(a[i], a[next]);
    }
}

int main() {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    cout << "Permutations from STL:" << endl;
    permutations_stl(a);
    cout << endl << "Permutations with custom next_permutation:" << endl;
    permutations_next_permutation_custom(a);
    cout << endl << "Permutations backtracking: " << endl;
    permutations_backtracking(a, 0);
	return 0;
}
