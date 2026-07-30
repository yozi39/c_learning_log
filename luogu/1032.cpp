#include<bits/stdc++.h>
using namespace std;

const int N=10;
string a,b;
unordered_map<string,int> dist;
int n;
string x[N],y[N];

int bfs(){
    if(a==b)return 0;

    queue<string> q;
    q.push(a);
    dist[a]=0;

    while (q.size())
    {
        string s=q.front();q.pop();

        if(dist[s]>=10)return-1;

        //变
        for(int i=0;i<n;i++){
            int pos=0;
            while(s.find(x[i],pos)!=-1){
                pos=s.find(x[i],pos);
                string tmp=s.substr(0,pos)+y[i]+s.substr(pos+x[i].size());
                pos++;
                if(dist.count(tmp))continue;//如果有了那么就是之前已经统计过了这次肯定不是最短的直接跳过
                dist[tmp]=dist[s]+1;
                q.push(tmp);

                if(tmp==b)return dist[tmp];
            }
        }
    }
    return -1;
}

int main(){
    cin>>a>>b;
    while(cin>>x[n]>>y[n])n++;

    int ret=bfs();
    if(ret==-1)cout<<"NO ANSWER!";
    else{
        cout<<ret;
    }
}