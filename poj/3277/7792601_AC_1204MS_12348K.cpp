#include<iostream>
#include<set>
#include<algorithm>
using namespace std ;

const  int maxbuild = 80000; 
const  int maxn = 2*maxbuild;
typedef __int64  lld ;

struct node{
       lld l , r , w ;
};
node tree[3*maxn] ;
lld  n , ch[maxn] , chs ;
lld  lx[maxn] , rx[maxn] , h[maxn] ;
set<lld> win ;
set<lld>:: iterator it ; 

lld bbs(lld x){
    lld l = 1 , r = chs , mid ;
    while(l<=r){
          mid =(l+r)/2;
          if(x == ch[mid])  return mid ;
          if(x < ch[mid])  
               r = mid - 1 ;
          else  
               l = mid + 1 ;
    }
    return 0 ;
}

void build(lld l , lld r ,lld i){
     tree[i].l = l , tree[i].r = r , tree[i].w = 0 ;
     if(tree[i].l + 1 == tree[i].r ) return ;
     lld mid = (tree[i].l + tree[i].r) /2 ;
     build(l , mid , 2*i);
     build(mid ,r  , 2*i+1);
}

void ins(lld l , lld r ,lld h , int i){
     if(l == tree[i].l && tree[i].r == r){
           tree[i].w = max(tree[i].w , h ) ;  return ;
     }
     tree[2*i].w   = max( tree[i].w , tree[2*i].w ) ;
     tree[2*i+1].w = max(tree[i].w , tree[2*i+1].w); 
     lld mid = (tree[i].l + tree[i].r ) / 2 ; 
     if(r <= mid )
          ins(l , r , h , 2*i);
     else if(mid <= l)
          ins(l , r , h , 2*i+1);
     else {
          ins(l , mid , h , 2*i);
          ins(mid , r , h , 2*i+1);
     } 
}

lld Query(lld i){
    if(tree[i].l + 1 == tree[i].r )
           return  tree[i].w * (ch[tree[i].r] - ch[tree[i].l]) ;
    tree[2*i].w   = max(tree[i].w , tree[2*i].w   );
    tree[2*i+1].w = max(tree[i].w , tree[2*i+1].w ); 
    return Query(2*i) + Query(2*i+1);
}

int main(){
    lld i , j ;
    scanf("%I64d" , &n);
    win.clear();
    for(i = 1 ; i <=n ; ++ i){
          scanf("%I64d%I64d%I64d" , &lx[i] , &rx[i] , &h[i]);
          win.insert(lx[i]); win.insert(rx[i]);
    }
    for(it = win.begin() , chs = 0 ;it!=win.end() ; it++)
         ch[++chs] = *it ;
    build(1 , chs , 1) ;
    for(i = 1 ; i <=n ; ++ i){
           lld lp  = bbs(lx[i]) , rp = bbs(rx[i]);
           ins(lp , rp , h[i] , 1 );
    } 
    printf("%I64d\n" ,Query(1));
    return 0 ;
}
