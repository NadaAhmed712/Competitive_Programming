#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, c=0;
    cin>>n;
    stack<int>one, two, three;
    vector<pair<int, int>>v;
    for(int i=n; i>0; i--)
        one.push(i);
    while (one.size()||(two.size()&&three.size())) {
        if(!c) {
            if(one.size()&&two.size()) {
                if(one.top()<two.top())
                    two.push(one.top()), one.pop(), v.push_back({1,2});
                else
                    one.push(two.top()), two.pop(), v.push_back({2,1});
            }
            else if(one.size())
                two.push(one.top()), one.pop(), v.push_back({1,2});
            else
                one.push(two.top()), two.pop(), v.push_back({2,1});
        }
        else if(c==1) {
            if(one.size()&&three.size()) {
                if(one.top()<three.top())
                    three.push(one.top()), one.pop(), v.push_back({1,3});
                else
                    one.push(three.top()), three.pop(), v.push_back({3,1});
            }
            else if(one.size())
                three.push(one.top()), one.pop(), v.push_back({1,3});
            else
                one.push(three.top()), three.pop(), v.push_back({3,1});
        }
        else {
            if(three.size()&&two.size()) {
                if(three.top()<two.top())
                    two.push(three.top()), three.pop(), v.push_back({3,2});
                else
                    three.push(two.top()), two.pop(), v.push_back({2,3});
            }
            else if(two.size())
                three.push(two.top()), two.pop(), v.push_back({2,3});
            else
                two.push(three.top()), three.pop(), v.push_back({3,2});
        }
        c=(c+1)%3;
    }
    cout<<v.size()<<'\n';
    for(auto it:v) {
        if((n&1)&&min(it.first,it.second)==1)
            if(it.first!=1)
                cout<<((it.first==2)?3:2)<<' '<<it.second<<'\n';
            else
                cout<<it.first<<' '<<((it.second==2)?3:2)<<'\n';
        else if(n&1)
            cout<<it.second<<' '<<it.first<<'\n';
        else
            cout<<it.first<<' '<<it.second<<'\n';
    }
    return 0;
}
