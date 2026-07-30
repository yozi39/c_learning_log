#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

int n,up;
int cost,amount;
vector<PII> a;

int main(){
    cin>>n;
    cin>>cost>>amount;
    int x,y;
    while(cin>>x>>y,x!=-1 && y!=-1){
        a.push_back({x,y});
    }
    cin>>up;

}