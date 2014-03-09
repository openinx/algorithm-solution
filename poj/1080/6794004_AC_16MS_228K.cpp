#include<iostream>
#include<stdlib.h>
using namespace std;
int GN[5][5]={
{5,-1,-2,-1,-3},
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1,0}
};
int Sw(char a)
{
	switch(a)
	{
	case 'A':return 0;break;
	case 'C':return 1;break;
	case 'G':return 2;break;
	case 'T':return 3;break;
	default:return 4;
	}
}
int main()
{
	char G[105];
	char N[105];
	int now[105];
	int pre[105];
	int i,j,t,n1,n2,t1,t2;
	cin>>t;
	while(t--)
	{
        memset(now,0,sizeof(now));
     	memset(pre,0,sizeof(pre));
		/*cin>>n1;
		for(i=1;i<=n1;i++)
			cin>>G[i];
		cin>>n2;
		for(i=1;i<=n2;i++)
			cin>>N[i];*/
		scanf("%ld%s",&n1,G+1);
		scanf("%ld%s",&n2,N+1);
		pre[0]=0;
		for(i=1;i<=n2;i++)
			pre[i]=pre[i-1]+GN[4][Sw(N[i])];
		for(i=1;i<=n1;i++)
		{
			now[0]=GN[Sw(G[i])][4]+pre[0];
			for(j=1;j<=n2;j++)
			{
				t1=Sw(G[i]);
				t2=Sw(N[j]);
				now[j]=pre[j-1]+GN[t1][t2];
				now[j]=now[j]>GN[t1][4]+pre[j]?now[j]:GN[t1][4]+pre[j];
				now[j]=now[j]>GN[4][t2]+now[j-1]?now[j]:GN[4][t2]+now[j-1];		
			}
			for(j=0;j<=n2;j++)
				pre[j]=now[j];
		}
		cout<<now[n2]<<endl;
	}
	//system("pause");
	return 0;
}
