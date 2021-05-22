#include <iostream>
#include <algorithm>
#include <cstring>
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
    return query(b)-query(a-1);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        memset(tree,0,sizeof tree);
        int n,x,a,b;
        char opr[10];
        printf("Case %d:\n",i);
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            add(j,x);
        }
        while(scanf("%s",opr),opr[0]!='E'){
            switch (opr[0]){
                case 'A':
                    scanf("%d%d",&a,&b);
                    add(a,b);
                    break;
                case 'S':
                    scanf("%d%d",&a,&b);
                    add(a,-b);
                    break;
                case 'Q':
                    scanf("%d%d",&a,&b);
                    printf("%d\n",query(a,b));
            }
        }
        
    }

    return 0;
}