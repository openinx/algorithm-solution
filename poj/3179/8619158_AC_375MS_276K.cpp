#include<iostream>
#include<algorithm>
#include<set>
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)|1)
#define maxn  505 
using namespace std ;

struct seg_node{
      int l , r , mxs , sum ;
}; 

struct Point{
      int x , y ;
};

struct segtree{
      seg_node t[8*maxn] ;
      void build(int x , int l , int r){
           t[x].l = l , t[x].r = r , t[x].mxs = t[x].sum = 0 ;
           if(l!=r){
                 int mid = (l+r)>>1 ;
                 build(L(x) , l , mid );
                 build(R(x) ,mid+1 ,r );
           }
      } 
      void insert(int x ,int leaf , int value){
           if(t[x].l == t[x].r){
                t[x].sum += value ; t[x].mxs = t[x].sum ;  
           }else{
                int mid = (t[x].l +t[x].r)>>1 ;
                if(leaf <= mid ){
                    insert(L(x) , leaf , value);
                }else{
                    insert(R(x) , leaf , value);
                }
                t[x].sum = t[L(x)].sum + t[R(x)].sum ; 
                t[x].mxs = max(t[L(x)].mxs , t[L(x)].sum + t[R(x)].mxs);
           }
      }
      int Ask(){
          return t[1].mxs ;
      }
};

set<int> fly ;
set<int>::iterator  it ;
Point P[maxn];
segtree tree ; 
int  C , N , dy[2*maxn] , b[2*maxn] , bsi ;

bool cmp(Point a , Point b){
     return a.x < b.x ;
}

int bs(int fuck){
    int l = 1 , r = bsi , mid ; 
    while(l<=r){
         mid = (l+r)>>1 ;
         if(fuck == b[mid]) return mid ;
         if(fuck <  b[mid]) r = mid - 1;
         if(fuck >  b[mid]) l = mid + 1;  
    }
    return 0 ;
}

int calc(int H ){
     int i , cur , cover;
     
     fly.clear();
     for(i = 1 ; i<=N ; ++ i){
           fly.insert(P[i].y);  fly.insert(P[i].y+H);
     }
     for(it = fly.begin() , bsi = 0 ; it!=fly.end() ; it++)  
          b[++bsi] = *it ;
     
     tree.build(1 , 1 , bsi);
     cur = 1 ;  cover = 0 ;   
     for(i = 1 ; i<=N ; ++i){
             while(cur<=N && (P[cur].x - P[i].x < H)){
                   tree.insert(1 , bs(P[cur].y) , +1) ;  
                   tree.insert(1 , bs(P[cur].y+H) , -1); 
                   ++ cur ;
                   cover = max(cover , tree.Ask());
             }
             tree.insert(1 , bs(P[i].y) , -1) ;
             tree.insert(1 , bs(P[i].y+H) , +1);    
     }
     return cover ;
}

int main(){
    int i , l , r ,mid ,  ans ; 
    scanf("%d%d" ,&C ,&N);
    for(i = 1 ; i<=N ; ++i){
           scanf("%d%d" , &P[i].x , &P[i].y) ;
    }
    sort(P+1 , P+N+1 , cmp);
    l = 1 , r = 10005 ; 
    while(l<=r){
          mid = (l+r)>>1 ; 
          ///printf("test_value : mid = %d   ==================  ans = %d\n"  , mid , calc(mid));
          if(calc(mid)>=C){
               ans = mid  ;  r = mid - 1 ;
          }else{
               l = mid + 1;
          }
    }
    printf("%d\n" , ans);
    //system("pause");
    return 0 ;
}
