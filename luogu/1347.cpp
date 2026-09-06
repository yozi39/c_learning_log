#include<bits/stdc++.h>
using namespace std;

const int N=30;

int n,m,ret,cnt;
int in[N],tmp[N];
vector<int> edge[N];
bool flag;
char s[N];

bool topsort(){
    flag=true;
    cnt=0;

    queue<int> q;
    for(int i=0;i<n;i++){
        tmp[i]=in[i];
        if(!tmp[i]){
            q.push(i);
        }
    }

    while(q.size()){
        if(q.size()>1){
            flag=false;
        }

        int a=q.front();q.pop();
        s[cnt++]=a+'A';

        for(auto v:edge[a]){
            tmp[v]--;
            if(!tmp[v]){
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(tmp[i])return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        char a,b,c;
        cin>>a>>b>>c;
        int x=a-'A',y=c-'A';

        in[y]++;
        edge[x].push_back(y);

        if(topsort() == false){
            printf("Inconsistency found after %d relations.\n",i);
            return 0;
        }
        if(flag){
            ret=i;
            break;
        }
    }

    if(flag){
        printf("Sorted sequence determined after %d relations: ",ret);
        for(int i=0;i<n;i++) cout<<s[i];
        cout<<".\n";
    } else {
        cout<<"Sorted sequence cannot be determined.\n";
    }


}