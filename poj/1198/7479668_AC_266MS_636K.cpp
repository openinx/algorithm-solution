#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

typedef __int64 i64;

const  i64  one = (i64)1;
const  int  maxn = 1<<17 ;
int dx[4] = { 1 , 0 ,-1 , 0  } ;
int dy[4] = { 0 , 1 , 0 , -1 };

struct node
{   
     i64  bd;
     int pos[4];
};

node st , ed ;

i64  stq[maxn] ,edq[maxn]  , sz ,ez ;
set<i64> win ;
set<i64>:: iterator it ;

void show(i64 bd )
{    
     int i,j;
     i64 t ;
     cout<<"current board is :"<<endl;
     for(i = 0 ; i<8 ; ++i)
     {    
          for(j = 0 ; j<8 ; ++j)
          {
              t = one<<( 8 * i + j);
              if( t & bd ) 
                      cout<<1;
              else 
                      cout<<0;  
          }
          cout<<endl;
     }
}




bool  IsOut( int cx,int cy)
{     
      return cx <0 || cy < 0 || cx >=8 || cy >=8 ;
}

bool  IsOn( i64 bd ,int cx, int cy)
{     
      return  bd & ( one<<(cx * 8 + cy) ) ;
}

void  clr( i64 &bd ,int i)
{     
      if( ! IsOn( bd , i/8 , i%8) ) return ;
      bd -= one<<i;
}

void  put( i64 &bd, int i )
{    
      if(IsOn(bd ,i/8 ,i%8) )   return ;
      bd += one <<i ;
}


bool next(node cur, int i,int j , node &son)
{    
     int t , tx , ty , nx , ny , cx , cy ;
     i64 bd = cur.bd;
     t = cur.pos[i] , tx = t / 8  , ty = t % 8 ;
     nx = tx + dx[j] , ny = ty + dy[j] ;
     if( IsOut(nx, ny) )  return false;
     if( IsOn (bd , nx, ny) )  
     {     
           cx = 2*nx - tx, cy = 2*ny - ty;
           if( IsOut(cx , cy) || IsOn(bd , cx , cy) )  return false;
           clr(cur.bd, tx*8 + ty);
           put(cur.bd, cx*8 + cy);
           cur.pos[i] = cx * 8 + cy;
           son = cur;
           return  true;
     }
     clr(cur.bd , tx * 8 + ty);  put(cur.bd , nx * 8 + ny);
     cur.pos[i] = nx * 8 + ny ;
     son =  cur;
     return true;
}

void  deal(node bgn )
{    
      int i , j  , dep = 0;
      node cur , son , tail;
      queue<node> q; 
         
      tail.bd = -1 ;
      win.clear();        win.insert(bgn.bd);
      q.push(tail);       q.push(bgn);
      while(!q.empty()) 
      {      
             if( dep > 4 ) return ;
             cur = q.front();  q.pop();
             if( cur.bd == -1 )
             {      
                    if(q.empty()) return ;
                    q.push(tail);  cur = q.front() ; q.pop();
                    ++ dep ;
             }
             for(i = 0 ; i < 4 ;++i)
                 for( j = 0 ;j < 4 ;++j )
                    if ( next( cur , i , j , son ) ) 
                         if( win.find(son.bd) ==win.end() ) 
                         {   
                             //show(son.bd);
                             q.push(son);
                             win.insert(son.bd);
                         }
      }
}

int bbs(i64  x)
{    
    int l , r ,mid;
    l = 0 , r = ez ;
    while(l <= r) 
    {    
         mid = ( l + r) / 2 ;
         if(edq[ mid ] == x)  return mid ;
         else  if ( x < edq[mid] ) r = mid - 1;
         else   l = mid + 1;
    }
    return -1;
}


          


bool can()
{    
     int i , x[4],y[4] ,check ;
     if(scanf("%d%d%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]) == EOF )
         return false;
     st.bd = 0 ;
     for(i = 0 ; i<4 ; ++i)
     {   
         -- x[i] , -- y[i] ;
         put(st.bd , x[i] * 8 + y[i]);
         st.pos[i] = x[i] * 8 + y[i];
     }    
     
     ed.bd = 0 ;
     for(i = 0 ; i<4 ; ++i)
     {    
         scanf("%d%d",&x[i],&y[i]);
         -- x[i] , -- y[i];
         put(ed.bd , x[i] * 8 + y[i]);
         ed.pos[i] = x[i] * 8 + y[i] ;
     }
     
     sz =  ez = 0 ;
     
     deal(st);
     for(it = win.begin() ; it!=win.end(); it ++ )
          stq[sz ++ ] = *it;
          
     deal(ed);
     for(it = win.begin() ; it!=win.end(); it++)
         edq[ez ++ ] =  *it ;
     
     sort(edq , edq + ez);
     
     //cout<<" sz :"<<sz<<endl;
     //cout<<" ez :"<<ez<<endl;
     
     check =  0 ;
     for(i = 0 ; i < sz && !check ; ++i)
       if( bbs(stq[i]) !=-1 )  
            check = 1;  
    
     if(check)
           cout<<"YES"<<endl;
     else 
           cout<<"NO"<<endl;
     return true;
}

int main()
{    
     while(can());
     return 0;
}

