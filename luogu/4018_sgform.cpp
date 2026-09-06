//用sg打表找规律的方法
#include<iostream>
#include<unordered_set>
using namespace std;

int a[]={1,2,3,4,5,7,8,9,11,13,16,17,19};

int sg(int x){
    unordered_set<int> mp;
    for(auto y:a){
        if(x-y<0)break;
        mp.insert(sg(x-y));
    }

    for(int i=0;;i++){
        if(!mp.count(i)){
            return i;
        }
    }
}

int main(){
    for(int i=0;i<=20;i++){
        cout<<i<<':'<<sg(i)<<endl;
    }
}