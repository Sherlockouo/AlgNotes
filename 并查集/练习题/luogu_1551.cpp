#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 50010;
int fa[MAXN],rak[MAXN];

inline void init(int n){
    for(int i=0;i<=n;i++)
        fa[i]=i,rak[i]=0;
}

int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

inline void merge(int i,int j){
    int x = find(i),y=find(j);
    if(rak[x]<=rak[y])
        fa[x]=y;
    else 
        fa[y]=x;
    if(rak[x]==rak[y]&&x!=y)
        rak[y]++;

}
int n,m,p;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    init(n);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    for(int i=0;i<p;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(find(a)==find(b))
            printf("Yes\n");
        else  
            printf("No\n");
    }
    return 0;
}