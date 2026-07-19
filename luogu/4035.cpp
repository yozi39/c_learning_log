#include<bits/stdc++.h>
using namespace std;

const int N=15;
const double EPS=1e-7;

vector<double> num[N];
double a[N][N];
int n;

bool zero(double x){
    return fabs(x)<EPS;
}

void gauss(){
    for(int i=1;i<=n;i++){
        int aim=i;
        for(int j=1;j<=n;j++){
            if(j<i && !zero(a[j][j])){
                continue;
            }
            if(fabs(a[aim][i])<fabs(a[j][i]))aim=j;
        }

        if(zero(a[aim][i]))continue;

        for(int j=1;j<=n+1;j++)swap(a[aim][j],a[i][j]);
        for(int j=n+1;j>=i;j--){
            a[i][j]/=a[i][i];
        }

        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double t=a[j][i]/a[i][i];
            for(int k=i;k<=n+1;k++){
                a[j][k]-=a[i][k]*t;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n;j++){
            double tmp;cin>>tmp;
            num[i].push_back(tmp);
        }
    }

    for(int eq = 1; eq <= n; eq++){
        for(int j = 1; j <= n; j++){
            double x1 = num[1][j - 1];      // 第 1 个点的第 j 维
            double x2 = num[eq + 1][j - 1]; // 第 eq+1 个点的第 j 维

            a[eq][j] = 2 * (x2 - x1);
            a[eq][n + 1] += x2 * x2 - x1 * x1;
        }
    }

    gauss();

    for(int i=1;i<=n;i++){
        printf("%.3lf ",a[i][n+1]);
    }
}