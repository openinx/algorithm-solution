#include <iostream>
#include <string>

const int MAX_N = 20010;

struct In
{ 
       int left;
       int right;
}str[8*MAX_N];

struct Node
{
       int left;
       int right;
       int mid;
       int color;          //该节点中被覆盖的元线段数 

}node[8*MAX_N];            //树节点

int d[8*MAX_N];            //离散化前的元素记录

bool flag[10000003];        //标志str数组的元素是否被处理

int hash[10000003];        //离散化后的元素记录


//建树，以数组的方式存储树节点

void BuildTree( int left , int right , int num )
{ 
    node[num].left = left;
    node[num].right = right;
    node[num].mid = (left+right)/2;
    node[num].color = 0;
    if( left + 1 != right )
    {
        BuildTree( left , node[num].mid , 2*num );
        BuildTree( node[num].mid , right , 2*num+1 ); 
    }
}

//插入

void insert( int left , int right , int num , int &sum )
{ 
    if( node[num].color >= node[num].right - node[num].left ) //区间是否全部被覆盖

    {
        return ; 
    }
    if( left == node[num].left && right == node[num].right )
    {
        sum++;
        node[num].color = node[num].right - node[num].left;
        return ;
    }
    if( right <= node[num].mid )
    {
        insert(left, right, 2*num , sum );
    }
    else if( left >= node[num].mid )
    {
        insert( left , right , 2*num+1 , sum ); 
    }
    else
    {
        insert( left , node[num].mid , 2*num , sum );
        insert( node[num].mid , right , 2*num+1 , sum ); 
    }
    node[num].color = node[2*num].color + node[2*num+1].color;
}

//用快速排序方法数组元素data[low..high]作排序

void quicksort(int data[], int low,int high) 
{ 
    int i,j,pivot; 
    if(low<high)
    { 
        pivot=data[low];
        i=low; 
        j=high; 
         
        while(i<j)
        { 
            while(i<j&&data[j]>=pivot) 
            j--; 
            if(i<j) 
                data[i++]=data[j];
            while(i<j&&data[i]<=pivot) 
                i++; 
            if(i<j) 
                data[j--]=data[i];
        } 
         
        data[i]=pivot;
        quicksort(data,low,i-1);
        quicksort(data,i+1,high); 
    } 
} 

int main()
{ 
    int c , n , i , j ,m;
    scanf("%d",&c);

//由于涉及到多轮的数据，所以要初始化为false

    for(long i =0;i<10000003;i++)
    {
        flag[i] = false;
    }
    while( c-- ){
        scanf("%d",&n);
        m = 0;
        for( i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d",&str[i].left,&str[i].right);
            str[i].right++;
            if( !flag[str[i].left] )
            {
                d[m++] = str[i].left;
                flag[str[i].left] = true;
            }
            if( !flag[str[i].right] )
            {
                d[m++] = str[i].right; 
                flag[str[i].right] = true; 
            } 
        }
        quicksort(d, 0,m-1) ;

        j = 1; 
        //离散化过程

        for( i = 0 ; i < m ; i++ )
        { 
            flag[d[i]] = false;            //由于涉及到多轮的数据，所以要初始化为false

            hash[d[i]] = j++; 
        }
        int sum = 0;
        BuildTree( 1 , j , 1 );
        for( i = n ; i >= 1 ; i-- )
        {
            int k = 0;
            insert( hash[str[i].left] , hash[str[i].right] , 1 , k );
            if( k > 0 )
            {
            sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0; 
}

