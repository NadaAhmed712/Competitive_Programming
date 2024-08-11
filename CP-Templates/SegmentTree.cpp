struct SegmentTree {
private:
    vector<ll>tree;
    int sz, base=0;
    ll merge(int a,int b) {
        return max(a,b);
    }
    void update(int p, int s, int e, int idx, ll val) {
        if(s==e) {
            tree[p]=val;
            return;
        }
        int mid=(s+e)/2;
        if(idx<=mid)
            update(2*p,s,mid,idx,val);
        else
            update(2*p+1,mid+1,e,idx,val);
        tree[p]=merge(tree[2*p], tree[2*p+1]);
    }
    ll query(int idx,int s,int e,int l,int r) {
        if(s>=l&&e<=r) {
            return tree[idx];
        }
        int mid=(s+e)>>1;
        if(l<=mid&&r>mid)
            return merge(query(idx * 2, s, mid, l, r), query(idx * 2+1, mid + 1, e, l, r));
        else if(r<=mid) {
            return query(idx * 2, s, mid, l, r);
        }
        else {
            return query(idx * 2+1, mid + 1, e, l, r);
        }
    }
public:
    SegmentTree(int n) {
        sz=1;
        while(sz<=n) sz<<=1;
        tree=vector<ll>(sz<<1, base);
    }
    void update(int idx,int val) {
        update(1,0,sz-1,idx,val);
    }
    ll query(int l,int r) {
        return query(1,0,sz-1,l,r);
    }
};
