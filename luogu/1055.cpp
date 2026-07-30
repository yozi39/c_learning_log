#include<bits/stdc++.h>
using namespace std;

const int MOD=11;
string pin;

int main(){
    cin>>pin;
    int cmp;
    char ch=pin.back();
    if(ch == 'X') cmp=10;
    else cmp=pin.back()-'0';


    int ret=0;
    ret+=pin.front()-'0';

    int cnt=2;
    for(int i=2;i<=10;i++){
        if(pin[i]=='-')continue;
        ret+=pin[i]*cnt%MOD;
        cnt++;
    }

    ret%=MOD;
    if(ret==cmp){
        cout<<"Right";
    } else {
        cout<<pin.substr(0,pin.size()-1);
        if(ret==10){
            cout<<"X";
            return 0;
        }
        cout<<ret;
    }
}