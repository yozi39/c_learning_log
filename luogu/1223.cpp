#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int n;
struct P1223
{
    int t,id;
}a[N];


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t;
        a[i].id=i;
    }
    
    auto cmp=[](P1223& a,P1223& b){
        return a.t<b.t;
    };
    sort(a+1,a+1+n,cmp);

    double ret=0;
    for(int i=1;i<n;i++){
        cout<<a[i].id<<' ';
        ret+=a[i].t*(n-i);
    } 
    
    cout<<a[n].id<<'\n';
    printf("%.2lf",ret/n);
}