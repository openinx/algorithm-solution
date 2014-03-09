#include<iostream>
#include<queue>
int vis[300],n;
void back(int x){
    if(vis[x]==0){
        putchar('1');
        return;
    }
    back(vis[x]);
    if(vis[x]*10%n==x)putchar('0');
    else putchar('1');
}
void bfs(){
    memset(vis,-1,sizeof(vis));
    vis[1]=0;
    std::queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int s=Q.front();Q.pop();
        for(int i=0;i<=1;++i){
            int x=(s*10+i)%n;
            if(vis[x]>=0)continue;
            vis[x]=s;
            if(x==0)return;
            Q.push(x);
        }
    }
}
int main(){
    while(scanf("%d",&n),n){
        if(n==1)puts("1");
        else{
            bfs();
            back(0);
            putchar(10);
        }
    }
    return 0;
}

