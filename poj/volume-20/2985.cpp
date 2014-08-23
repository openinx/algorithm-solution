#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const static int maxn = 200005;

class DisjoinSet{
public:
    void init(int nsiz){
        n = nsiz;
        for(int i = 1;  i <= n ; ++ i){
            father[i] = i;
            rank[i] = 0 ;
            siz[i] = 1;
        }
    }
    int find(int x){
        if(x != father[x]){
            father[x] = find(father[x]);
        }
        return father[x];
    }
    int join(int x, int y){
        x = find(x);
        y = find(y);
        if(rank[x] > rank[y]){
            father[y] = x;
            siz[x] +=  siz[y];
        }else {
            if(rank[x] == rank[y]){
                rank[y] ++ ;
            }
            father[x] = y;
            siz[y] += siz[x];
        }
    }
    int size(int x){
        x = find(x);
        return siz[x];
    }
private:
    int n , father[maxn], rank[maxn], siz[maxn];
};

class BitTree{
public:
     int c[maxn] ; 
     void init(){
          memset(c , 0 ,sizeof(c));
     }
     int lowbit(int x){
         return x&(-x);
     }
     void add(int x ,int d){
          for( ; x < maxn ; x+=lowbit(x)) c[x]+=d ; 
     }
     int getsum(int x){ 
          int ans = 0 ;
          for( ; x>0 ; x-=lowbit(x))  ans +=c[x] ; 
          return ans ;
     }
     int getkth(int k){
          int ans = 0 , cnt = 0 , i ;
          for(i = 20 ; i>=0 ; --i){
                ans += 1<<i ;
                if(ans>=maxn||cnt+c[ans]>=k) ans-=1<<i ;
                else cnt +=c[ans] ;      
          }
          return ans+1 ; 
     }
};


int main(){
    int n, m , c, x, y, xsiz, ysiz;
    DisjoinSet d;
    BitTree bt;
    while(scanf("%d%d", &n, &m) !=EOF ){
        d.init(n);
        bt.init();
        for(int i = 1 ; i <=n ; ++ i){
            scanf("%d", &c);
            if(c == 0){
                scanf("%d%d", &x, &y);
                bt.add(d.size(x), -1);
                bt.add(d.size(y), -1);
                d.join(x, y);
                bt.add(d.size(x), +1);
            }else if(c == 1){
                scanf("%d", &x);
                printf("%d\n", bt.getkth(x));
            }
        }
    }
}
