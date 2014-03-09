#include<iostream>
#include<string>
using namespace std ;

const int maxn = 120 ;
const int maxe = 81000 ;
const double DOUBLE_INF = 1e300 ;
const double EPS  = 1e-18;
const double LIMIT = 1e-8 ;

struct node{
       int x ,y , next ;
       double c ;
};

node e[maxe] ; 
int  es , hd[maxn] , S , T ;
int  n , m , dgr[maxn] , wgt[maxn];
int  st[maxe] , ed[maxe] , cost[maxe];
int  TotalCount ; 

void ins(int x, int y , double c){
     e[es].x = x ,e[es].y = y ,e[es].c = c ,e[es].next = hd[x] , hd[x] = es ++ ;
     e[es].x = y ,e[es].y = x ,e[es].c = 0 ,e[es].next = hd[y] , hd[y] = es ++ ;
}

int dep[maxn] , cur[maxn] , ps[maxn] ;

double MaxFlow(){
       int  f , r ,i ,j , k , x ,y , top ;
       double tr , maxf = 0.0  ; 
       
       while(1){
               
               memset(dep , -1 ,sizeof(dep)); dep[S] = 0 ; f = r = 0 ; ps[r++] = S ;
               while(f!=r && dep[T] == -1){
                       for(i = hd[x=ps[f++]] ; i!=-1 ; i=e[i].next)
                           if(e[i].c > EPS && dep[y=e[i].y] == -1)  ps[r++] = y , dep[y] = dep[x] + 1 ;
                        
               }
               if(dep[T] == -1) break ;
               i = S , top = 0 ;  memcpy(cur , hd ,sizeof(hd));
               while(1){
                    if(i == T){
                         for(tr = DOUBLE_INF , k = 0 ; k < top ; ++ k)
                            if(e[ps[k]].c  < tr )  tr = e[ps[f = k]].c ;
                         for(k = 0 ; k < top ; ++ k)
                            e[ps[k]].c -= tr , e[ps[k]^1].c += tr ;
                         maxf += tr ,  i = e[ps[top = f]].x ;
                    }
                    for(j = cur[i] ; j!=-1 ; j=cur[i]=e[j].next)
                       if(e[j].c > EPS && dep[e[j].y] == dep[i] + 1)   break ;
                    
                    if(j!=-1){
                        ps[top++] = j ;  i = e[j].y ; 
                    }else{
                        //printf("LOOP\n");
                        if(0 == top) break ;
                        dep[i] = -1 ;   i = e[ps[--top]].x ; 
                    }
                    
                    //printf("LOOP\n");
               }
               
               // cout<<"LOOP"<<endl;
       }
       return maxf ;
}

/*
int vis[maxn] ;

void dfs(int x ){
     int i , y ;
     vis[x] = 1 ;
     for(i = hd[x] ; i!=-1 ; i=e[i].next)
        if(e[i].c > EPS && !vis[y = e[i].y])
           dfs(y);

}

void MakeSolution(){
     int i , x , y ,edgeSum = 0  , vertexSum = 0 ;   
     memset(vis , 0 ,sizeof(vis));  dfs(S);
     printf("\n\n Show The Point :\n");
     for(i = 1 ; i <= n ; ++ i) 
        if(vis[i]) printf("%d\n" ,i ) , vertexSum += wgt[i] ;
       
     for(i = 1 ; i<= m ; ++ i)
       if(vis[st[i]] && vis[ed[i]])  edgeSum += cost[i] ; 
       
     cout<<edgeSum<<" -- "<<vertexSum<<endl;
     
     double sol = edgeSum /(double)vertexSum ;
     printf("Real Answer Is :%0.3lf\n" , sol);
     
}
*/

double calc(double g){
       int i , j ; 
       es = 0 ; memset(hd , -1 ,sizeof(hd));  S = n + 1 ; T = n + 2 ;
       for(i = 1 ; i <= m ; ++i){
            ins(st[i] , ed[i] , cost[i]);
            ins(ed[i] , st[i] , cost[i]);
       }
       for(i = 1 ; i <= n ; ++i){
            ins(S , i , TotalCount);
            ins(i , T , TotalCount + 2*g*wgt[i] - dgr[i] );
       } 
       
       //printf("%0.8lf\n" , MaxFlow());
       
       return  (TotalCount*n - MaxFlow())/2.0 ; 
}

void work(){
     double l = 0  , r = TotalCount , mid ; 
     while(l + LIMIT < r){
           mid = (l + r) / 2.0  ;
           if(calc(mid) > LIMIT ) 
                  l = mid ; 
           else 
                  r = mid ;
            //cout<<"LOOP"<<endl;
           ///cout<<mid<<endl;   printf("recoed : %0.3lf\n" , calc(l));
     }
     
     //calc(l); 
     //MakeSolution();
     
     printf("%0.3lf\n" , l);  //cout<<"calc : " <<calc(l)<<endl;
}

int main(){
    
    //freopen("1.std.in" ,"r" , stdin); freopen("1.std.out" ,"w" ,stdout);
    
    int testCase , i ;
    scanf("%d" , &testCase);
   
    string my = "xxxx" ; 
    while(1){
           freopen("xxxx.out","w",stdout);
    }

    while(testCase--){
          TotalCount = 0 ;
          scanf("%d%d" , &n , &m);  
          for(i = 1 ; i<= n;  ++ i)  scanf("%d" , &wgt[i]);
          memset(dgr , 0 , sizeof(dgr));
          for(i = 1 ; i<= m ; ++ i){
                scanf("%d%d%d" , &st[i] , &ed[i] , &cost[i]);
                dgr[st[i]] += cost[i] , dgr[ed[i]] += cost[i] ;  
                TotalCount += cost[i] ;
          }
          work();
    }
    
    //fclose(stdin) ;  fclose(stdout);
    
    //while(getchar());
    return 0 ;
    
}
