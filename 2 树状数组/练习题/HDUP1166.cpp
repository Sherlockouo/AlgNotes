#include <iostream>
#include <algorithm>

using namespace std;

#define lowbit(x) ((x)&(-x))
const int N = 5*1e5+10;
int tree[N];

inline void add(int p,int x){
    for(int i=p;i<N;i+=lowbit(i)) tree[i]+=x;
}

inline int query(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i)) ans+=tree[i];
    return ans;
}

inline int query(int a,int b){
    return query(b)-query(a);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        memset(tree,0,sizeof tree);
    }

    return 0;
}