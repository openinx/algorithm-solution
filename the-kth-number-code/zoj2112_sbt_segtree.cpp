#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int maxn = 50005 ; 
const int maxsize = 1000000 ;
const int INF  = 1000000010 ; 

struct node{
     int l , r ,  x ;
};
node tree[3*maxn] ;

struct sbt{
     int  l , r , s , v ;
};
sbt t[maxsize] ;
int  ts , a[maxn]; 

void sbt_init(){
     ts = 0 ; t[0].l = t[0].r = t[0].s = 0 ;
}

void zig(int &x){
     int y = t[x].l ;  if(x==0||y==0) return ;
     t[x].l = t[y].r ; t[y].r = x ;
     t[y].s = t[x].s ; t[x].s = t[t[x].r].s + t[t[x].l].s + 1;
     x = y ;
}

void zag(int &x){
     int y = t[x].r ; if(x==0||y==0) return ;
     t[x].r = t[y].l ; t[y].l = x ;
     t[y].s = t[x].s ; t[x].s = t[t[x].l].s + t[t[x].r].s + 1 ;
     x = y ;
}

void maintain(int &x , int flag){
     if(flag){
          if(t[t[t[x].l].l].s > t[t[x].r].s ){
              zig(x);
          }else if(t[t[t[x].l].r].s > t[t[x].r].s ){
              zag(t[x].l) ; zig(x);
          }else{
              return ;
          }
     }else{
          if(t[t[t[x].r].r].s > t[t[x].l].s ){
              zag(x);
          }else if(t[t[t[x].r].l].s > t[t[x].l].s ){
              zig(t[x].r) ; zag(x);
          }else{
             return ;
          }
     }
     maintain(t[x].l , true) ;  maintain(t[x].r , false);
     maintain(x , true) ;  maintain(x , false);
}

void ins(int &x , int v){
     if(x==0){
        x = ++ ts ;  t[x].l = t[x].r = 0 ; t[x].s = 1 ;  t[x].v = v ; return ;
     }else{
        t[x].s ++ ;  //  maintain the value of size .  do not forget again .
        if(v<=t[x].v)  
            ins(t[x].l , v );
        else 
            ins(t[x].r , v );
        maintain(x , v<=t[x].v);
     }
}

int del(int &x , int v){
     if(x == 0 )  return -1;
     t[x].s -- ; 
     if((t[x].l==0 && v < t[x].v )||(t[x].r==0 && v > t[x].v)||(v == t[x].v)){
        int temp = t[x].v ;   //  the element must be deleted .
        if(t[x].l==0 || t[x].r == 0 ){
             x = t[x].l + t[x].r ;   
        }else{
             t[x].v = del(t[x].l , t[x].v+1);
        }
        return temp ; 
     }else{
        if(v <= t[x].v )  return del(t[x].l ,  v);
        if(v >  t[x].v )  return del(t[x].r ,  v);
     }
}

int select(int x , int v){
    if(x == 0 )  return 0 ; 
    if(t[x].v < v )  
        return select(t[x].r , v ) + t[t[x].l].s + 1  ;
    else
        return select(t[x].l , v ) ;
}

void segtree_build(int root , int l , int r ){
     int i , mid = (l + r)>>1 ;
     tree[root].l = l ; tree[root].r = r ; tree[root].x = 0 ;
     for(i = l ; i<= r ;++ i )  ins(tree[root].x , a[i]);
     if(l == r ) return ;
     segtree_build(2*root , l , mid );
     segtree_build(2*root+1 ,mid+1 , r);
}

void segtree_update(int root , int pos , int val ){
     del(tree[root].x , a[pos]);   ins(tree[root].x ,  val );
     if(tree[root].l == tree[root].r )  return ; 
     int mid = (tree[root].l + tree[root].r)>>1 ;
     if(pos <= mid )
         segtree_update(2*root , pos , val);
     else  
         segtree_update(2*root+1 , pos , val);
}

int segtree_less(int root , int x , int y , int val ){  // count how many element is less than value 
    if(x == tree[root].l && tree[root].r == y){
           return select(tree[root].x , val);
    }
    int mid = (tree[root].l + tree[root].r)>>1 ;
    if(y <= mid ){
           return segtree_less(2*root , x , y , val );
    }else if(mid+1 <= x){
           return segtree_less(2*root+1 , x , y , val );
    }else{
           return segtree_less(2*root , x , mid , val ) + segtree_less(2*root+1 , mid+1 , y , val);
    }
}

int getkth(int x ,int y , int k){
    int l , r , mid , t0 , t1 ,  ans ;  
    l = 0  , r = INF  ; 
    while(l <= r ){
         mid = (l + r) >> 1 ; 
         t0 = segtree_less(1 , x , y , mid ) + 1 ;
         t1 = segtree_less(1 , x , y , mid+1) ;
         if(k < t0 ){
               r = mid - 1 ;
         }else if(k > t1){
               l = mid + 1 ; 
         }else{
             ans = mid  ;  break ;
         }
    }
    return ans ;
}

/*
void dfs(int x){
     if(x!=0){
          dfs(t[x].l);  printf("  %d" , t[x].v  , t[t[x].l].s );   dfs(t[x].r); 
     }
}

void test_sbt(){
     char cmd[10] ; 
     int  value , root = 0 ;   sbt_init();
     while(scanf("%s" , cmd)!=EOF){
           scanf("%d" ,&value) ; 
           if(!strcmp(cmd , "ins")) 
                ins(root , value);
           else if(!strcmp(cmd,"del"))
                del(root , value);   
           else if(!strcmp(cmd , "sel")){
                printf("there %d  ge number is smaller than %d" , select(root , value) , value);
           }
           printf("\nThe element is : "); 
            dfs(root);  printf("\n");  
     }
}

void test_range(){
     
}
*/
void work(){
    int i , n , q , x , y , k ;
    char cmd[10] ; 
    sbt_init();
    scanf("%d%d" , &n , &q);
    for(i = 1 ; i<=n ; ++ i)  scanf("%d" , &a[i]);
    segtree_build(1 , 1 , n );
    while(q--){
          scanf("%s" , cmd);
          if(!strcmp(cmd ,"Q")){
                 scanf("%d%d%d" ,&x , &y , &k); 
                 printf("%d\n" , getkth(x , y , k));
          }else if(!strcmp(cmd , "C")){
                 scanf("%d%d" , &x , &y );
                 segtree_update(1 , x , y);  
                 a[x] = y ; 
          }
    }
}

int main(){
    //test_sbt();
    
    int acase ;
    scanf("%d" , &acase);
    while(acase--){
        work();
    }
    //system("pause");
    return 0 ;
}
