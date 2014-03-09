#include<iostream>
#include<bitset>
#include<queue>
using namespace std;
#define N (1<<24)+10
struct chess{
       int x;
       int y;
};
//int dir[8][2]={1,0,0,1,-1,0,0,-1,
//             2,0,0,2,-2,0,0,-2};
int dir1[4][2]={1,0,0,1,-1,0,0,-1,};
int dir2[4][2]={2,0,0,2,-2,0,0,-2};
struct Node{
    chess pos[4];
    int step;
    char map[9][9];
    Node()
    {
        int i,j;
        for(i=1;i<=8;i++)
        for(j=1;j<=8;j++){
            map[i][j]='a';
        }
        step=0;
    }
};
inline bool cmp(chess a,chess b)
{
    if(a.x==b.x)return a.y<b.y;
    else return a.x<b.x;
}
bitset<N>hash1;
bitset<N>hash2;
inline int Hash(Node node){
    int i;
    int num;
    int sum=0;
    for(i=0;i<4;i++){
        num=8*(node.pos[i].x-1)+node.pos[i].y;
        sum=sum*64+num;
    }
    return sum;
}
Node start,end;
void bbfs()
{
    queue<Node>q1;
    queue<Node>q2;
    q1.push(start);
    q2.push(end);
    Node now,next;
    hash1.reset();
    hash2.reset();
    hash1[Hash(start)]=true;
    hash2[Hash(end)]=true;
    int x,y;
    int i,j,k;
    int step;
    for(step=0;step<4;step++){
        while(!q1.empty()){
            now=q1.front();
            q1.pop();
            if(now.step>4)break;
            for(i=0;i<4;i++){
                next=now;
                for(j=0;j<4;j++){
                    next=now;
                    x=now.pos[i].x+dir1[j][0];
                    y=now.pos[i].y+dir1[j][1];
                    if(x>=1&&x<=8&&y>=1&&y<=8&&now.map[x][y]=='a'){
                        next.map[x][y]='d';
                        next.map[now.pos[i].x][now.pos[i].y]='a';
                        next.pos[i].x=x;
                        next.pos[i].y=y;
                        next.step=now.step+1;
                        sort(next.pos,next.pos+4,cmp); 
                        if(hash1[Hash(next)])continue;
                        if(hash2[Hash(next)]){
                            cout<<"YES"<<endl;
                            return ;
                        }
                        hash1[Hash(next)]=true;
                        q1.push(next);
                    }
                }
                for(j=0;j<4;j++){
                //for(j=0;j<4;j++){
                    next=now;
                    x=now.pos[i].x+dir2[j][0];
                    y=now.pos[i].y+dir2[j][1];
                    if(x>=1&&x<=8&&y>=1&&y<=8&&now.map[x][y]=='a'&&
                    now.map[now.pos[i].x+dir1[j][0]][now.pos[i].y+dir1[j][1]]=='d'){
                        next.map[x][y]='d';
                        next.map[now.pos[i].x][now.pos[i].y]='a';
                        next.pos[i].x=x;
                        next.pos[i].y=y;
                        next.step=now.step+1;
                        sort(next.pos,next.pos+4,cmp); 
                        if(hash1[Hash(next)])continue;
                        if(hash2[Hash(next)]){
                            cout<<"YES"<<endl;
                            return ;
                        }
                        hash1[Hash(next)]=true;
                        q1.push(next);
                    }
                }
            }
        }
        while(!q2.empty()){
            now=q2.front();
            q2.pop();
            //if(now.step>4)break;
            if(next.step == step + 1)   
                break;  
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    next=now;
                    x=now.pos[i].x+dir1[j][0];
                    y=now.pos[i].y+dir1[j][1];
                    if(x>=1&&x<=8&&y>=1&&y<=8&&now.map[x][y]!='d'){
                        next.map[x][y]='d';
                        next.map[now.pos[i].x][now.pos[i].y]='a';
                        next.pos[i].x=x;
                        next.pos[i].y=y;
                        next.step=now.step+1;
                        sort(next.pos,next.pos+4,cmp); 
                        if(hash2[Hash(next)])continue;
                        if(hash1[Hash(next)]){
                            cout<<"YES"<<endl;
                            return  ;
                        }
                        hash2[Hash(next)]=true;
                        q2.push(next);
                    }
                }
                for(j=0;j<4;j++){
                    next=now;
                    x=now.pos[i].x+dir2[j][0];
                    y=now.pos[i].y+dir2[j][1];
                    if(x>=1&&x<=8&&y>=1&&y<=8&&now.map[x][y]!='d'&&
                    now.map[now.pos[i].x+dir1[j][0]][now.pos[i].y+dir1[j][1]]=='d'){
                        next.map[x][y]='d';
                        next.map[now.pos[i].x][now.pos[i].y]='a';
                        next.pos[i].x=x;
                        next.pos[i].y=y;
                        next.step=now.step+1;
                        sort(next.pos,next.pos+4,cmp);  
                        if(hash2[Hash(next)])continue;
                        if(hash1[Hash(next)]){
                            cout<<"YES"<<endl;
                            return ;
                        }
                        hash2[Hash(next)]=true;
                        q2.push(next);
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return ;
}
int main(){
   // freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout); 
    int x,y;
    Node star,en;
    while(cin>>x>>y){
        int i,j;
        star.map[x][y]='d';
        star.pos[0].x=x;
        star.pos[0].y=y;
        for(i=1;i<=3;i++){
            cin>>x>>y;
            star.map[x][y]='d';
            star.pos[i].x=x;
            star.pos[i].y=y;
        }
        for(i=0;i<4;i++){
            cin>>x>>y;
            en.map[x][y]='d';
            en.pos[i].x=x;
            en.pos[i].y=y;
        }
        start=star;
        end=en;
        sort(start.pos,start.pos+4,cmp);
        sort(end.pos,end.pos+4,cmp);
        bbfs();
    }
    //while(1);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

