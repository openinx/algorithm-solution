/*这个自动机自我感觉比上一个好，而且在构造矩阵时更加方便。
但是，提交后，时间居然还要多20多ms-_-\\*/
#include<iostream>
using namespace std;
const int Mod = 100000;
const int size =110;
const int kind = 4;
__int64 g[size][size];

struct Node
{
       int fail,son[kind],end;
       void Init()
       {
            fail = -1;
            memset(son, -1, sizeof(son));
            end = 0;
       }
}node[size];

int node_Num = 0;
int q[size], head, tail;

int Index(char a)
{
    switch (a)   
    {   
           case 'A':return 0;   
           case 'G':return 1;   
           case 'C':return 2;   
           case 'T':return 3;   
    }   
}

void Insert(char *s)
{    
     int p=0;
     for (int i=0; s[i]; i++)
     {
         if (node[p].end) break;
         if (node[p].son[Index(s[i])] == -1)
         {
            node_Num++;
            node[p].son[Index(s[i])] = node_Num;
            node[node_Num].Init();
         }
         p = node[p].son[Index(s[i])];
     }
     node[p].end++;
}

void Build_Ac()
{
     head = tail = 0;
     int temp = 0, p = 0, i; 
     q[tail++] = 0;
     while (head < tail)
     {
           temp = q[head++];         
           for (i = 0; i < kind; i++)
           {
               p = node[temp].son[i];
           if (p != -1)
           {  
              if  (temp == 0) node[p].fail = 0;
              else 
              {
                   node[p].fail = node[node[temp].fail].son[i];
                   if (node[node[p].fail].end)
                   node[p].end++;
              }
              q[tail++] = node[temp].son[i];
           }
           else 
           {
             if (temp == 0) node[temp].son[i] = 0;
             else node[temp].son[i] = node[node[temp].fail].son[i];
           }
           }
     }
}

void MatrixMul(__int64 b[][size], __int64 c[][size], int sz)
{
     int i, j, k;
     __int64 temp[size][size] = {0};
     for (i = 0; i < sz; i++)
     for (j = 0; j < sz; j++)
     for (k = 0; k < sz; k++)
     {
     temp[i][j] += b[i][k]*c[k][j];
     if (temp[i][j] >= Mod)
     temp[i][j] %= Mod;
     }
     
     for (i = 0; i < sz; i++)
     for (j = 0; j < sz; j++)
     b[i][j] = temp[i][j];
}

void MatrixPow(__int64 tot[][size], __int64 a[][size], int sz, int n)
{
     while (n > 0)
     {
           if (n&1) MatrixMul(tot,a, sz);
           MatrixMul(a, a, sz);
           n >>= 1;
     }
}
int N;
int M;
char word[14];
__int64 tot[size][size], Ans, ans;
int main()
{
    int i, j;
    while (scanf("%d%d", &M, &N) != EOF)
    {
            node_Num = 0; 
            Ans = ans = 0;
            node[0].Init();
            memset(g, 0, sizeof(g));
            for (i = 0; i < M; i++)  
            {
                scanf("%s", word);
                Insert(word);
            }
            Build_Ac();
            
            node_Num++;
            for (i = 0; i < node_Num; i++)
            if(!node[i].end)
            for (j = 0; j < kind; j++)
            {
                if (node[node[i].son[j]].end==0)
                   g[i][node[i].son[j]]++;
                
            }            
            memset(tot, 0, sizeof(tot));
            for (i = 0; i < node_Num; i++)
            tot[i][i] = 1;
            MatrixPow(tot, g, node_Num, N);
            for (i = 0; i < node_Num; i++)
            if (node[i].end==0)
            {
                ans += tot[0][i];
                if (ans>=Mod) ans %= Mod;
            }
            printf("%I64d\n",ans);            
    }
    return 0;
}
