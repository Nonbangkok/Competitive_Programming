#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;

struct Point{
    double x,y;
};

vector<Point> Points;
double a,b;

double dis(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Closest_Pair(vector<Point> Px, vector<Point> Py){
    int n = Px.size();
    if(n<=3){
        double mn = 1e9;
        forr(i,0,n)forr(j,i+1,n){
            mn = min(mn,dis(Px[i],Px[j]));
        }
        return mn;
    }

    int mid = n >> 1;

    vector<Point> Pxl(Px.begin(),Px.begin()+mid);
    vector<Point> Pxr(Px.begin()+mid,Px.end());

    vector<Point> Pyl, Pyr;

    int l = 0;
    for(auto p:Py){
        // if((p.x<Px[mid].x||(p.x==Px[mid].x&&p.y<Px[mid].y))&&l<mid)Pyl.push_back(p),l++;
        if(p.x<Px[mid].x)Pyl.push_back(p);
        else Pyr.push_back(p);
    }

    double d = min(Closest_Pair(Pxl,Pyl),Closest_Pair(Pxr,Pyr));

    vector<Point> strip;
    for(auto p:Py){
        if(abs(p.x-Px[mid].x)<d)strip.push_back(p);
    }

    forr(i,0,strip.size()){
        for(int j=i+1;j<strip.size()&&abs(strip[i].y-strip[i].y)<d;j++){
            d = min(d,dis(strip[i],strip[j]));
        }
    }

    return d;
}

int main(){macos;

    int n;
    cin >> n;
    forr(i,0,n){
        cin >> a >> b;
        Points.push_back({a,b});
    }

    vector<Point> Px = Points, Py = Points;

    sort(Px.begin(),Px.end(),[](const Point &a, const Point &b){return a.x < b.x;});
    sort(Py.begin(),Py.end(),[](const Point &a, const Point &b){return a.y < b.y;});

    cout << Closest_Pair(Px,Py);

    return 0;
}