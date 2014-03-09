#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int arr[6], sta, pos, step;
};

bool sign[10][6] = 
    {
        1, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0,
        1, 1, 1, 0, 0, 0,
        1, 1, 1, 1, 0, 0,
        1, 1, 1, 1, 1, 0,
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1,
        1, 1, 0, 0, 0, 1,
        1, 1, 1, 0, 0, 1,
        1, 1, 1, 1, 0, 1,
    };

int way[600][8], ind, Min;
bool flag[6][6][6][6][6][6][6][10];
queue<Node> Q;
Node a, b;

void bfs()
{
    int i;
    a.sta = a.pos = a.step = 0;
    for(i = 0; i < 6; ++i)
        a.arr[i] = i;
    Q.push(a);
    flag[a.arr[0]][a.arr[1]][a.arr[2]][a.arr[3]][a.arr[4]][a.arr[5]][a.pos][a.sta] = 1;
    ind = 0;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i < 6; ++i)
            way[ind][i] = a.arr[i];
        way[ind][6] = a.sta;
        way[ind][7] = a.step;
        ++ind;
        b = a;
        ++b.step;
        if(b.pos > 0)
        {
            swap(b.arr[0], b.arr[b.pos]);
            if(!flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta])
            {
                flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta] = 1;
                Q.push(b);
            }
            swap(b.arr[0], b.arr[b.pos]);
        }
        if(b.pos < 5)
        {
            ++b.pos;
            int temp = b.sta;
            if(b.pos > b.sta || (b.sta > 5 && b.pos > b.sta - 6))
            {
                if(b.sta == 9) b.sta = 5;
                else ++b.sta;
            }
            if(!flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta])
            {
                flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta] = 1;
                Q.push(b);
            }
            --b.pos;
            b.sta = temp;
            swap(b.arr[5], b.arr[b.pos]);
            if(b.sta < 5) b.sta += 6;
            if(!flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta])
            {
                flag[b.arr[0]][b.arr[1]][b.arr[2]][b.arr[3]][b.arr[4]][b.arr[5]][b.pos][b.sta] = 1;
                Q.push(b);
            }
        }
    }
}

int main()
{
    bfs();
    int ss, ee, aa[6], bb[6], step, i, j;
    while(scanf("%d %d", &ss, &ee)!=EOF)
    {
    Min = 100000;
    for(i = 5; i >= 0; --i)
    {
        aa[i] = ss % 10;
        ss /= 10;
    }
    for(i = 5; i >= 0; --i)
    {
        bb[i] = ee % 10;
        ee /= 10;
    }
    for(i = 0; i < ind; ++i)
    {
        step = way[i][7];
        for(j = 0; j < 6; ++j)
            if(aa[way[i][j]] != bb[j] && !sign[way[i][6]][j])
                break;
            else
                step += abs(aa[way[i][j]] - bb[j]);
        if(j == 6 && step < Min)
            Min = step;
    }
    printf("%d\n", Min);
   }
    return 0;
}
