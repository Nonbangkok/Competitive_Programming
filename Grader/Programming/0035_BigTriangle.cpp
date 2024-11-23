#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    double x[n],y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];

    double mx = -1;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                mx = max(mx,abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i])/2.0);
            }
        }
    }
    
    cout << fixed << setprecision(3) << mx;

    return 0;
}