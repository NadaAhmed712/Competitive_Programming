struct FenwickTree {
    vector<ll>bit;
    int N;
    FenwickTree(int n) {
        N=n+5;
        bit=vector<ll>(N);
    }
    void add(int idx,ll val) {
        while(idx<N) {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }
    ll query(int idx) {
        ll ret=0;
        while(idx>0) {
            ret+=bit[idx];
            idx-=idx&-idx;
        }
        return ret;
    }
    ll rangeQuery(int l,int r) {
        if(l>r) return 0;
        return query(r)-query(l-1);
    }
};
