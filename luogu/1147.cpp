#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int M=2e6,N=1e6+5;

int m;
unordered_map<LL,int> mp;

int main(){
    cin>>m;
    int n=(m+1)/2;

    mp[0]=0;
    LL sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;

        if(mp.count(sum-m)){
            cout<<mp[sum-m]+1<<' '<<i<<endl;
        }

        mp[sum]=i;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1, r = 2;
    int sum = 1 + 2;

    while (l < r && l <= n / 2) {
        if (sum < n) {
            r++;
            sum += r;
        } 
        else if (sum > n) {
            sum -= l;
            l++;
        } 
        else {
            cout << l << ' ' << r << '\n';

            sum -= l;
            l++;
        }
    }

    return 0;
}
*/