#include "inversion_count.h"
using namespace std;

const int N = 100;

struct Fenwick{
    int fw[N];

    Fenwick(){
        for(int i=0;i<N;i++)fw[i] = 0;
    }

    void update(int idx){
        for(int i=idx;i<N;i+=i&-i)fw[i]++;
    }

    int query(int idx){
        int sum = 0;
        for(int i=idx;i>0;i-=i&-i)sum += fw[i];
        return sum;
    }
}fw;

long long count_inversions(vector<int>& arr) {
    long long sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += fw.query(N-arr[i]);
        fw.update(N-arr[i]);
    }
    return sum;
}