#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int N, int K){
    deque<int> q;
    int i;

    for(i,0,K){
        while((!q.empty()) && arr[i] >= arr[q.back()])q.pop_back();
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
    for(;i<N;i++){
        while ((!q.empty()) && q.front() <= i - K)q.pop_front();
        while ((!q.empty()) && arr[i] >= arr[q.back()])q.pop_back();
        q.push_back(i);
        cout << arr[q.front()] << " ";
    }
}

int main(){
    int arr[]={12,1,78,0,90,57,89,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    printKMax(arr,n,k);
    
    return 0;
}