#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    vector<string >ans;
    cin >> s;
    sort(s.begin(),s.end());
    do {
        ans.push_back(s);
    } while(next_permutation(s.begin(),s.end()));
    cout<<ans.size()<<'\n';
    for(auto it:ans)
        cout<<it<<'\n';
    return 0;
}
