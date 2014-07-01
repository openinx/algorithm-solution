#include <cstdio>
#include <queue>
#include <climits>
#define MAXN 110
#define BASE 100
using namespace std;

int const M = INT_MAX;
int arr[MAXN][MAXN];
char crr[MAXN][MAXN];
bool used[MAXN][MAXN];
int krr[MAXN * MAXN];
int prr[MAXN * MAXN][2];

inline bool bfs(int x, int y, int n, int m, int k){
       queue<int> m_que;
       int cur_pos;
       int i, j;
       int kk = k;
       m_que.push(x * BASE + y);
       m_que.push(M);
       while(kk--){
                 while(m_que.front() != M){
                       cur_pos = m_que.front();
                       m_que.pop();
                       x = cur_pos / BASE;
                       y = cur_pos % BASE;
                       if(x + 1 < n){
                            if(!used[x + 1][y] && crr[x + 1][y] != '*'){
                                       arr[x + 1][y] = k -kk;
                                       used[x + 1][y] = true;
                                       if(x + 1 == prr[k - kk - 1][0] && y == prr[k -kk -1][1]) return true;
                                       m_que.push((x + 1) * BASE + y);
                            }
                       }
                       if(x - 1 >= 0){
                            if(!used[x - 1][y] && crr[x - 1][y] != '*'){
                                       arr[x - 1][y] = k - kk;
                                       used[x - 1][y] = true;
                                       if(x - 1 == prr[k - kk - 1][0] && y == prr[k -kk -1][1]) return true;
                                       m_que.push((x - 1) * BASE + y);
                            }
                       }
                       if(y + 1 < m){
                            if(!used[x][y + 1] && crr[x][y + 1] != '*'){
                                          arr[x][y + 1] = k -kk;
                                          used[x][y + 1] = true;
                                          if(x == prr[k - kk - 1][0] && y + 1 == prr[k -kk -1][1]) return true;
                                          m_que.push(x * BASE + y + 1);
                            }
                       }
                       if(y - 1 >= 0){
                            if(!used[x][y - 1] && crr[x][y - 1] != '*'){
                                          arr[x][y - 1] = k - kk;
                                          used[x][y - 1] = true;
                                          if(x == prr[k - kk - 1][0] && y - 1 == prr[k -kk -1][1]) return true;
                                          m_que.push(x * BASE + y - 1);
                            }
                       }
                 }
                 m_que.pop();
                 m_que.push(M);
       }
       return false;
}
                       
int main(){
    int i, j;
    int n, m, k;
    int t;
    int t_x, t_y;
    int j_x, j_y;
    bool is_can;
    int d_x, d_y;
    int time_j;
    scanf("%d", &t);
    while(t--){
               scanf("%d%d%d\n", &n, &m, &k);
               for(i = 0; i < n; ++i){
                     for(j = 0; j < m; ++j){
                           crr[i][j] = getchar();
                           used[i][j] = false;
                           arr[i][j] = M;
                           if(crr[i][j] == 'T'){
                                        t_x = i;
                                        t_y = j;
                           }
                           if(crr[i][j] == 'J'){
                                        j_x = i;
                                        j_y = j;
                           }
                     }
                     getchar();
               }
               for(i = 0; i < k; ++i){
                     scanf("%d", krr + i);
               }
               d_x = 0;
               d_y = 0;
               time_j = 1;
               if(arr[j_x][j_y] <= 0) is_can = true;
               for(i = 0; i < k; ++i){
                     if(krr[i] == 0){
                               d_x = 1;
                               d_y = 0;
                     } else if(krr[i] == 1){
                            d_x = 0;
                            d_y = 1;
                     } else if(krr[i] == 2){
                            d_x = -1;
                            d_y = 0;
                     } else if(krr[i] == 3){
                            d_x = 0;
                            d_y = -1;
                     }
                     prr[i][0] = j_x + d_x;
                     prr[i][1] = j_y + d_y;
                     j_x += d_x;
                     j_y += d_y;
               }
               is_can = bfs(t_x, t_y, n, m, k);
               printf("%s\n", is_can ? "Yes" : "No");
    }
    return 0;
}
