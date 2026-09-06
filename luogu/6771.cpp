#include<bits/stdc++.h>
using namespace std;

const int N=410;

int n;
int f[N][40005];
struct P6771
{
    int h,a,c;
}a[N];

bool cmp(P6771& a,P6771& b){
    return a.a<b.a;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].a>>a[i].c;
    }

    sort(a+1,a+1+n,cmp);

    f[0][0]=true;

    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i].a;j++){
            for(int k=0;k<=a[i].c && k*a[i].h<=j;k++){
                if(f[i-1][j-k*a[i].h]){
                    f[i][j]=true;
                    break;
                }
            }

            if(f[i][j]){
                ret=max(ret,j);
            }
        }
    }
    
    cout<<ret;
}