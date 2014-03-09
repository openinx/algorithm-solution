#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_N = 10001;

int hash[2*MAX_N], str2[2*MAX_N] , hash2[2*MAX_N];
int len[2*MAX_N] , leftcover[2*MAX_N] , rightcover[2*MAX_N] , numcover[2*MAX_N];
struct In
{
       int start;
       int end;
       int pos;
       bool flag;       
}str[2*MAX_N];

struct Node
{
       int l;
       int r;
       int mid;   
       int sum; 
}node[3*MAX_N];
//建树
void B_Tree( int l , int r , int num){
          node[num].l = l;
          node[num].r = r;
          node[num].mid = (l+r)>>1;
          node[num].sum = 0;
          if( l+1 != r ){
              B_Tree( l , node[num].mid , num<<1 );
              B_Tree( node[num].mid , r , num<<1|1 );    
          }
}
//更新
void Updata( int l , int r , int num ){
     if( node[num].sum > 0 ){   //当它已被覆盖时
          len[num] = hash2[ node[num].r ] - hash2[ node[num].l ];  //并集区间的长度
          leftcover[num] = rightcover[num] = 1;    //表示左区间和右区间都被覆盖 
          numcover[num] = 1;    //并集的独立区间数目
     }else if( r > l+1 ){               //内结点
           len[num] = len[num<<1]+len[num<<1|1];
           leftcover[num] = leftcover[num<<1];
           rightcover[num] = rightcover[num<<1|1];
           numcover[num] = numcover[num<<1]+numcover[num<<1|1] - leftcover[num<<1|1]*rightcover[num<<1];
     }else{                            //叶结点
           len[num] = 0;
           leftcover[num] = rightcover[num] = 0;
           numcover[num] = 0;
     }
}
//插入
void Insert( int l , int r , int num ){
     if( node[num].l == l && r == node[num].r ){
         node[num].sum++; 
     }else{
         if( node[num].mid >= r ){
             Insert( l , r , num<<1 );    
         }else if( node[num].mid <= l ){
               Insert( l , r , num<<1|1 );      
         }else{
    Insert( l , node[num].mid , num<<1 );
    Insert( node[num].mid , r , num<<1|1 ); 
   }
     }  
     Updata( node[num].l , node[num].r , num );
}
//删除
void Delete( int l , int r , int num ){
     if( node[num].l == l && r == node[num].r ){
         node[num].sum--; 
     }else{
         if( node[num].mid >= r ){
             Delete( l , r , num<<1 );    
         }else if( node[num].mid <= l ){
               Delete( l , r , num<<1|1 );      
         }else{
    Delete( l , node[num].mid , num<<1 );
    Delete( node[num].mid , r , num<<1|1 );     
   }
     }
     Updata( node[num].l , node[num].r , num );
}

int cmp( const void *a , const void *b ){
    struct In *c = ( In *)a;
    struct In *d = ( In *)b;
    return c->pos - d->pos;    
} 

int intcmp( const void *a , const void *b ){
    return *( int *)a - *(int *)b;    
}
int main()
{   
    int i , j , x1 , x2 , y1 , y2 ,cas, k = 0;
    scanf("%d",&cas);
    while( cas-- ){
          scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
          str[k].start = y1 , str[k].end = y2 , str[k].flag = true , str[k].pos = x1 , str2[k] = y1;
          k++;
          str[k].start = y1 , str[k].end = y2 , str[k].flag = false , str[k].pos = x2 , str2[k]= y2;
          k++;
    }
    qsort( str , k , sizeof(In) , cmp );
    qsort( str2 , k , sizeof(int) , intcmp );
    int l = 1;
    hash[str2[0]] = l;
    hash2[1] = str2[0];
    for( i = 1 ; i < k ; i++ ){
         if( str2[i] != str2[i-1] ){
             l++;
             hash[str2[i]] = l;    
             hash2[l] = str2[i];
         } 
    }
    B_Tree( 1 , l , 1 );
    int sum = 0 , ans = 0 , value = 0;
    for( i = 0 ; i < k-1 ; i++ ){
         if( str[i].flag ){
             Insert( hash[str[i].start] , hash[str[i].end] , 1 );    
         }else{
              Delete( hash[str[i].start] , hash[str[i].end] , 1 );       
         }
         ans += 2*( str[i+1].pos - str[i].pos )*numcover[1];
         ans += abs( len[1] - value );
         value = len[1];
    }
    Delete( hash[str[i].start] , hash[str[i].end] , 1 );
    ans += abs( len[1] - value );
    printf("%d\n",ans);
    return 0;    
}


