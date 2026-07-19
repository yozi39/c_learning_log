//https://codeforces.com/problemset/problem/25/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;cin>>x;
    string phone;cin>>phone;

    if(x%2==0){
        int cnt=0;
        for(auto ch:phone){
            if(cnt==2){
                cout<<'-';
                cnt=0;
            }
            cout<<ch;
            cnt++;
        }
    }
    else {
        for(int i = 0; i < 3; i++){
            cout << phone[i];
        }

        if(x > 3) cout << '-';

        int cnt = 0;
        for(int i = 3; i < (int)phone.size(); i++){
            if(cnt == 2){
                cout << '-';
                cnt = 0;
            }
            cout << phone[i];
            cnt++;
        }
    }
}