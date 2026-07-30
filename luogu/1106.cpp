#include <bits/stdc++.h>
using namespace std;

int main(){
    string num;
    int n;

    cin >> num >> n;

    string st;

    for(char ch : num){
        while(n > 0 && !st.empty() && st.back() > ch){
            st.pop_back();
            n--;
        }

        st.push_back(ch);
    }

    while(n > 0){
        st.pop_back();
        n--;
    }

    int pos = 0;
    while(pos < st.size() && st[pos] == '0'){
        pos++;
    }

    if(pos == st.size()){
        cout << 0;
    }else{
        cout << st.substr(pos);
    }
}