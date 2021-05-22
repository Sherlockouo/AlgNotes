/*
树状数组
    应用场景:
        1. 单点修改
        2. 区间查询
    时间复杂度
        O(logn)
*/
const int N= 1e5;
int st[N];
int n;

int lowbit(int x){
    return x&-x;
}

inline void add(int p,int x){
    for(int i=p;i<=n;i+=lowbit(x)) st[i]+=x;
}

inline int query(int x){
    int ans=0;
    for(int pos=n;pos;pos-=lowbit(pos))
        ans+=st[pos];
    return ans;
}

inline int query(int a,int b){
    return query(b)-query(a);
}