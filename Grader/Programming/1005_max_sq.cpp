#include <bits/stdc++.h>
#define forr(i, a, n) for (int i = a; i < n; i++)
#define coutf(n, m) cout << fixed << setprecision(n) << m << endl
#define endll "\n"
#define space " "
typedef long long ll;
using namespace std;
int main(){

    int n, temp, mx = INT_MIN, sum, first, last;
    cin >> n;
    vector<int> A;
    forr(i,0,n){
        cin >> temp;
        A.push_back(temp);
    }
    forr(i, 0, n){
        sum = 0;
            forr(j, i, n) {
                sum += A[j];
                if (sum > mx) {
                mx = sum;
                first = i;
                last = j;
            }
        }
    }
    if(mx<1){
        cout << "Empty sequence";
    }else{
        forr(i,first,last+1){
            cout << A[i] << space;
        }
        cout << endll << mx;
    }
    return 0;
}	