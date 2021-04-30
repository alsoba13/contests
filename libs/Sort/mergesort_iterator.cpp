#include <bits/stdc++.h>
using namespace std;

//Cost O(N·log(N))

void inplace_mergesort(vector<int>::iterator first, vector<int>::iterator end) {
    if(end-first == 1){
        return;
    }
    inplace_mergesort(first, first+(end-first)/2);
    inplace_mergesort(first+(end-first)/2, end);
    vector<int>::iterator start1 = first;
    vector<int>::iterator start2 = first+(end-first)/2;
    while(start1 < start2 && start2 < end) {
        if(*start2<*start1){
            int value = *start2;
            for(vector<int>::iterator i = start2; i>start1; i--){
                *i = *(i-1);
            }
            *start1 = value;
            start2++;
        }
        start1++;
    }
}

void testMergeSortInplace(){
    srand(100);
    for(int i = 0; i<1000; i++){
        vector<int> a;
        for(int j = 0; j<100; j++) a.push_back(rand()%50);
        inplace_mergesort(a.begin(), a.end());
        for(int j = 1; j<100; j++)
            assert(a[j]>=a[j-1]);
    }
}

int main() {
    vector<int> a(10);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    cout << "In place mergesort: \n";
    inplace_mergesort(a.begin(), a.end());
    for(int i = 0; i<10; i++) cout << a[i] << " "; cout << endl;
    testMergeSortInplace();

}
