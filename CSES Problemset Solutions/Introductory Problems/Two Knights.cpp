#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++) {
        //ans=(i*i)C2=((i*i)!)/(2!*((i*i)-2)!)=((i*i)*((i*i)-1)/2)
        //knight can move in 8 position
        ll ans=(i*i)*((i*i)-1)/2;
        if(i==3)
            ans-=8;
        else if(i>3)
            ans-=(max(i-2,0ll)*4+max(i-2,0ll)*6+max(i-2,0ll)*max(i-4,0ll)*4+max(i-4,0ll)*2+4);
        cout<<ans<<'\n';
    }
 
    return 0;
}
 
/*
attack in grid 3*3
2 2 2
1 0 1
0 0 0
attack in grid 4*4
2 3 3 2  
2 3 3 2
1 1 1 1
0 0 0 0
attack in grid 5*5
2 3 4 3 2  
2 3 4 3 2  
2 3 4 3 2
1 1 2 1 1
0 0 0 0 0
attack in grid 6*6
2 3 4 4 3 2  
2 3 4 4 3 2  
2 3 4 4 3 2
2 3 4 4 3 2
1 1 2 2 1 1
0 0 0 0 0 0
each number in grid represent 
how many anther cell will attack this cell from
the cells that let in down rows where this
 cell let in it
 ex: in grid 6*6:
 cell(3,3) is attacked 
 by the cells (4,1),(4,5),(5,2),(5,4)
*/
