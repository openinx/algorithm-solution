#include<iostream>
using namespace std ;
const int dx[] = {0,-1,0,1} ;
const int dy[] = {1,0,-1,0} ;
const int maxn = 20 ;
char  ch[maxn][maxn]  ;
int   vis[maxn][maxn] , r , c;
int   dir[300] ;

bool IsOut(int cx ,int cy){
     return cx<0||cy<0||cx>=r||cy>=c ; 
}

int main(){
    dir['E'] = 0 ; dir['N'] = 1 ; dir['W'] = 2 ; dir['S'] = 3 ;
    int cx ,cy , cmd , i , step;
    while(scanf("%d%d%d",&r,&c,&cy)!=EOF && (r+c+cy)){
         cx = 0 ; --cy ;   memset(vis,-1,sizeof(vis)); step = 0 ;
         for(i = 0 ;i<r ;++i)  
              scanf("%s",ch[i]);
         while(!IsOut(cx,cy) && vis[cx][cy]==-1){
             cmd = dir[ch[cx][cy]] ;  vis[cx][cy] = ++step ;
             cx += dx[cmd] ;
             cy += dy[cmd] ;
         }
         if(IsOut(cx,cy))
              printf("%d step(s) to exit\n",step);
         else 
              printf("%d step(s) before a loop of %d step(s)\n",vis[cx][cy]-1,step-vis[cx][cy]+1);
    }
    //while(getchar());
    return 0;
}


