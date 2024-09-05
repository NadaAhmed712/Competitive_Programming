struct dsu {
    int n;
    vector<int>parent, groupSize;
    dsu(int sz) {
        n=sz;
        parent = groupSize = vector<int>(n);
        for(int i=0; i<n; i++)
            parent[i]=i, groupSize[i]=1;
    }
    int findLeader(int node) {
        if(node==parent[node])
            return node;
        return parent[node]=findLeader(parent[node]);
    }
    bool samegroup(int node1,int node2) {
        int leader1 =findLeader(node1);
        int leader2 =findLeader(node2);
        return leader1==leader2;
    }
    void margeGroup(int node1,int node2) {
        int leader1 =findLeader(node1);
        int leader2 =findLeader(node2);
        if(leader1==leader2) return;
        if(groupSize[leader1]>groupSize[leader2]) {
            parent[leader2]=leader1;
            groupSize[leader1]+=groupSize[leader2];
        }
        else {
            parent[leader1]=leader2;
            groupSize[leader2]+=groupSize[leader1];
        }
    }
};
