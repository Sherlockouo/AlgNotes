/**
并查集
    应用场景:
        元素分组问题.
    
    基本操作:
        1. init 初始化元素组数
        2. find 查询两个元素是否在同一个集合
        3. union 将两个不相交元素合并在一个集合
        
 **/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e6;
int fa[MAXN],rak[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        rak[i]=1;
    }
}

int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
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

int main(){

    return 0;
}
