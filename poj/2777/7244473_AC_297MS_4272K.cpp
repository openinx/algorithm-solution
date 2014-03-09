#include<iostream>
using namespace std;
const int maxn = 100005;
struct node {
       int l,r,c;
       bool tot;
};
node tree[3*maxn] ;
int status;

bool unique(int x) {  return x & (x - 1) == 0 ; }

void build(int root,int l,int r)
{   
     tree[root].l = l ; tree[root].r = r;
     tree[root].c = 1<<1; tree[root].tot = true;
     if(l + 1 == r) return ;
     int mid = (l + r) >> 1;
     build(2*root,l,mid);   
     build(2*root+1,mid,r);
}

void ins(int root,int l,int r,int color)
{    
     if(tree[root].l == l && tree[root].r == r)
     {    
          tree[root].c = 1<<color; tree[root].tot = true;  return ;
     }
     if(tree[root].tot ==true)
     {  
          tree[2*root].c = tree[2*root+1].c = tree[root].c;
          tree[2*root].tot = tree[2*root+1].tot = true;
     }
     int mid =(tree[root].l + tree[root].r) >>1;
     if(r<=mid)  
            ins(2*root,l,r,color);
     else   if(mid<=l) 
            ins(2*root+1,l,r,color);
     else   
     {  
            ins(2*root,l,mid,color); 
            ins(2*root+1,mid,r,color); 
     }
     tree[root].c = tree[2*root].c | tree[2*root+1].c;
     tree[root].tot = unique(tree[root].c);
     return ;
}

void query(int root,int l,int r)
{    
     if(l==tree[root].l && tree[root].r ==r)
     {      
            status = status | tree[root].c;   return ;
     }
      if(tree[root].tot) 
     {   
          status = status | tree[root].c ; 
          tree[2*root].c = tree[2*root+1].c = tree[root].c;
          tree[2*root].tot = tree[2*root+1].tot = true; 
          return;
     }
     int mid = (tree[root].l + tree[root].r) >>1 ;
     if(r<=mid) query(2*root,l,r);
     else if(mid <= l) query(2*root+1,l,r);
     else  {  
              query(2*root,l,mid);
              query(2*root+1,mid,r);
     }
}

int main()
{    
     int L,T,O,A,B,C,ans,i;
     char cmd[5];
     scanf("%d%d%d",&L,&T,&O);
     build(1,1,L+3);
     while(O--)
     {       
             scanf("%s",cmd);
             if(cmd[0]=='C')
             {    
                    scanf("%d%d%d",&A,&B,&C);
                    if(A>B) swap(A,B);
                    ins(1,A,B+1,C);
             }
             else  
             {   
                    scanf("%d%d",&A,&B);
                    if(A>B) swap(A,B);
                    status = ans = 0;
                    query(1,A,B+1);
                    for(i=1;i<=T;++i)
                       if((1<<i) & status ) ++ans;
                    printf("%d\n",ans);
             }
     }
     return 0;
}
                    
     
     
     
     
     
     
     
     
     
     
     
     
     
     
           
