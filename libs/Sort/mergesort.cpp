#include <bits/stdc++.h>
using namespace std;

//Cost O(N·log(N))

void inplace_mergesort(vector<int> &a, int first, int end) {
    if(end-first == 1){
        return;
    }
    inplace_mergesort(a, first, first+(end-first)/2);
    inplace_mergesort(a, first+(end-first)/2, end);
    int start1 = first;
    int start2 = first+(end-first)/2;
    while(start1 < start2 && start2 < end) {
        if(a[start2]<a[start1]){
            int value = a[start2];
            for(int i = start2; i>start1; i--){
                a[i] = a[i-1];
            }
            a[start1] = value;
            start2++;
        }
        start1++;
    }
}

vector<int> mergesort(vector<int> &a) {
    if(a.size() == 1) return a;
    vector<int> half1, half2;
    half1.insert(half1.end(), a.begin(), a.begin()+a.size()/2);
    half2.insert(half2.end(), a.begin()+a.size()/2, a.end());
    half1 = mergesort(half1);
    half2 = mergesort(half2);
    vector<int> result;
    int p1 = 0, p2 = 0;
    while(p1<half1.size() && p2<half2.size()) {
        if(half1[p1]<half2[p2]){
            result.push_back(half1[p1++]);
        }else{
            result.push_back(half2[p2++]);
        }
    }
    while(p1<half1.size()) {
        result.push_back(half1[p1++]);
    }
    while(p2<half2.size()) {
        result.push_back(half2[p2++]);
    }
    return result;
}

void testMergeSortInplace(){
    srand(100);
    for(int i = 0; i<1000; i++){
        vector<int> a;
        for(int j = 0; j<100; j++) a.push_back(rand()%50);
        inplace_mergesort(a, 0, 100);
        for(int j = 1; j<100; j++)
            assert(a[j]>=a[j-1]);
    }
}

void testMergeSort(){
    srand(100);
    for(int i = 0; i<1000; i++){
        vector<int> a;
        for(int j = 0; j<100; j++) a.push_back(rand()%50);
        a = mergesort(a);
        for(int j = 1; j<100; j++)
            assert(a[j]>=a[j-1]);
    }
}

int main() {
    vector<int> a(10);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    cout << "In place mergesort: \n";
    inplace_mergesort(a, 0, 10);
    for(int i = 0; i<10; i++) cout << a[i] << " "; cout << endl;
    testMergeSortInplace();

    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());
    cout << "Mergesort: \n";
    a = mergesort(a);
    for(int i = 0; i<10; i++) cout << a[i] << " "; cout << endl;
    testMergeSort();

}
