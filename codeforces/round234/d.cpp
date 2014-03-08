#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std ;
#define MAXN 100001


typedef struct node{
    int e, v, next ;
}node;

int n , m , k , c[MAXN], part[MAXN], dist[505][505];
int sz , visit[MAXN], gh[MAXN];
node edge[4 * MAXN];

void add_edge(int u, int v, int x){
    edge[sz].e = v ;  edge[sz].v = x ; edge[sz].next = gh[u]; 
    gh[u] = sz; sz ++ ; 

    edge[sz].e = u ;  edge[sz].v = x ; edge[sz].next = gh[v];
    gh[v] = sz; sz ++ ;
}

void dfs(int s, int part_id){
    part[s] = part_id ;
    visit[s] = 1 ;
    for(int i = gh[s]; i != -1 ; i = edge[i].next ){
        int e = edge[i].e ; 
        if(visit[e] == 0 && edge[i].v == 0 )
            dfs(e, part_id);
    }
}

int main(){
    int correct;
    while(scanf("%d%d%d", &n , &m , &k) !=EOF ){
        sz = 0 ;
        memset(gh, -1, sizeof(gh));
        for(int i = 0 ; i < k ; ++ i) scanf("%d", &c[i])  ;

        for(int i = 0 ; i < m ; ++ i){
            int u, v, x; 
            scanf("%d%d%d", &u, &v, &x) ;
            add_edge(u, v , x);
        }

        int part_id = 0  ;
        memset(visit, 0 , sizeof(visit));
        for(int i = 1 ; i <= n; ++ i )
            if(visit[i] == 0){
                dfs(i,  ++part_id);
            }

        correct = (part_id <= k) ; 

        int sum = 0 ;
        for(int i = 0 ; i < k && correct; ++ i){
            sum += c[i];
            int part_j = part[ sum - c[i] + 1 ];
            for(int j = sum - c[i] + 1 ; j <= sum; ++ j)
                correct = part[j] == part_j;
        }

        if(!correct){
            printf("No\n");
            continue ;
        }

        memset(dist, -1, sizeof(dist));
        for(int i = 1; i <=n ; ++ i) dist[i][i] = 0 ; 
        for(int i = 1; i <= n ; ++ i){
            for(int t = gh[i]; t != -1; t = edge[t].next ){
                int s = part[i] , e = part[edge[t].e] , val = edge[t].v; 
                if(dist[s][e] == -1 || dist[e][s] == -1){
                    dist[s][e] = dist[e][s] = val ; 
                }else{
                    dist[s][e] = dist[e][s] = min(dist[s][e], val);
                }
            }
        }

        for(int t = 1 ; t <= k ; ++ t){
            for(int i = 1 ; i <= k; ++ i )
                for(int j = 1; j <= k ; ++ j){
                    if(dist[i][j] == -1){
                        if(dist[i][t] != -1 && dist[t][j] != -1)
                            dist[i][j] = dist[i][t]  + dist[t][j] ;
                    }else{
                        if(dist[i][t] != -1 && dist[t][j] != -1 && dist[i][j] > dist[i][t] + dist[t][j])
                            dist[i][j] = dist[i][t] + dist[t][j];
                    }
                }
        }

        printf("Yes\n");
        for(int i = 1 ; i <=k ; ++ i){
            printf("%d", dist[i][1]);
            for(int j = 2; j <=k ; ++ j)
                printf(" %d", dist[i][j]);
            printf("\n");
        }
    }
    return 0 ;
}
