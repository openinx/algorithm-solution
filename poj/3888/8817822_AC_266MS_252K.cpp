#include<iostream>
#include<algorithm>
using namespace std ;

const  int  MaxSize = 15   ; 
const  int  MaxRow  = 1005 ;

struct node{
       int x[MaxSize] , t , id;
}; 
node  ch[MaxRow] ;
int   ch_cnt     ;

bool cmp(node a , node b){
     if(a.t != b.t)
        return a.t < b.t   ;
     return  a.id < b.id   ;
}

int  choose[MaxSize][MaxSize] ;
int  ed[MaxSize] , st[MaxSize] , val[MaxSize] ;
int  mat[MaxSize][MaxSize] , row , col , mat2[MaxSize][MaxSize] ; 

//将mat[st..row-1 , st..col-1 ]的一个非零数初等行列变换到mat[st,st]  
void adjust( int st ){
     if(mat[st][st])  return  ;
     int x , y , i , j , k , chk = 0 ;
     for(x = st ; x < row ; ++ x){
           for(y = st ; y < col ; ++ y)
              if(mat[x][y]) { chk = 1 ; break ; }
           if(chk)  break ;
     } 
     if(!chk)  return ; 
     for(j = st ; j < col ; ++ j)  swap(mat[st][j] , mat[x][j]) ;
     for(i = 0  ; i < row ; ++ i)  swap(mat[i][st] , mat[i][y]) ;
}

//用高斯消元求矩阵的秩 
int order(){
    int i , j , k , del ; 
    if(!row || !col )  return 0 ;  
    // 转置运算，使矩阵的 row < col  
    if( row > col ){
          for(i = 0 ; i < row ; ++ i)  
              for(j = 0 ; j < col ; ++ j)  
              mat2[j][i] = mat[i][j] ; 
          swap(row , col) ;
          for(i = 0 ; i < row ; ++ i)
              for(j = 0 ; j < col ; ++ j)
              mat[i][j] = mat2[i][j] ;
    }
    //此处特别注意，当矩阵是一个向量时，若是零向量，则秩为0,否则为1  
    if(row == 1){
        for(i = 0 ; i < col ; ++ i) 
            if(mat[0][i])  return 1 ;
        return  0 ;
    }
    // 消元过程 
    for(i = 0 ; i < row ; ++ i){ 
           adjust(i);
           if(mat[i][i]%11 == 0 )  return i ;
           for(k = i + 1 ; k < row ; ++ k)
             if(mat[k][i]){
                //增量的选择 
                del = choose[ mat[i][i] ][ mat[k][i] ];
                for(j = i ; j < col ; ++ j)
                  mat[k][j] = (mat[k][j] + del * mat[i][j])%11 ;
           }
    }
    return row ; 
}

void InitChoose(){
     int i , j , k ; 
     for(i = 0 ; i < 11 ; ++ i)
        for(j = 0 ; j < 11 ; ++ j)
           for(k = 0 ; k < 11 ;++ k) 
              if((i*k+j)%11 == 0){
                  choose[i][j] = k ;  break ;
              }  
}

void read(){
     scanf("%d" , &ch_cnt);
     for(int i = 0 ; i < 11 ; ++ i)   scanf("%d" ,&st[i]);
     for(int i = 0 ; i < 11 ; ++ i)   scanf("%d" ,&ed[i]);
     for(int i = 0 ; i < 11 ; ++ i)   val[i] = (ed[i]-st[i] + 22)%11 ;
     for(int i = 0 ; i < ch_cnt ; ++ i){
            for(int j = 0 ; j < 11 ; ++ j)
                scanf("%d" , &ch[i].x[j]);
            scanf("%d" , &ch[i].t);
            ch[i].id = i ;
     }
     
     //注意按年份排序 
     sort(ch , ch + ch_cnt , cmp);
}

int indep[MaxSize][MaxSize] , ids  ; // linear independence 线性无关组 

int work(){
    int i , j , u , ans1 , ans2 ;
    ids = 0 ; 
    for(u = 0 ; u < ch_cnt ; ++ u){
           
           // 添加一个向量 
           for(i = 0 ; i < 11 ; ++ i) 
                indep[ids][i] = ch[u].x[i];
           ++ ids ;  
           
           // 判断刚添加的向量与前面是否线性相关 
           row = ids ;  col = 11 ;
           for(i = 0 ; i < ids ; ++ i )
              for(j = 0 ; j < 11 ; ++ j) 
              mat[i][j] =  indep[i][j] ;
           ans1 = order() ;
           if(ans1 < ids ){
              -- ids ;  continue ;
           }
           
           //判断矩阵的秩与其增广矩阵的秩是否相等 
           row = ids + 1  ; col = 11 ; 
           for(i = 0 ; i < ids ; ++ i)
              for(j = 0 ; j < 11 ; ++ j)
              mat[i][j] = indep[i][j] ;
           for(i = 0 ; i < 11 ; ++ i) mat[ids][i] = val[i] ;
           ans2 = order() ;
           if(ans1 == ans2 )  
                return ch[u].t ;
    }    
    return -1 ;
}

int main(){
    int tst , res ;
    InitChoose();
    scanf("%d" , &tst );
    while(tst--){
           read();
           res = work();
           if(res !=-1 )  
                 printf("%d\n",res);
           else 
                 printf("unreachable\n");
    }
    return 0 ;
} 

