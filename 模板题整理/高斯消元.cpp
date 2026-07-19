#include<bits/stdc++.h>
using namespace std;

const int N=105;
const double EPS=1e-7;

double a[N][N];
int n;

inline bool zero(double x){
    return fabs(x)<EPS;
}

int gauss(){
    for(int i=1;i<=n;i++){
        int aim=i;
        for(int j=1;j<=n;j++){
            if(j<i && !zero(a[j][j])){
                continue;
            }
            if(fabs(a[j][i])>fabs(a[aim][i])){
                aim=j;
            }
        }

        if(zero(a[aim][i]))continue;

        for(int j=1;j<=n+1;j++)swap(a[aim][j],a[i][j]);

        for(int j=n+1;j>=i;j--)a[i][j]/=a[i][i];

        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double t=a[j][i]/a[i][i];
            for(int k=i;k<=n+1;k++){
                a[j][k]-=a[i][k]*t;
            }
        }
    }

    int ret=1;
    for(int i=1;i<=n;i++){
        if(zero(a[i][i]) && !zero(a[i][n+1])){
            ret=0;
            return 0;
        }
        if(zero(a[i][i]))ret=2;
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }

    int ret = gauss();

    if(ret == 0|| ret == 2){
        cout<<"No Solution";
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            printf("%.2lf\n",a[i][n+1]);
        }
        return 0;
    }
}