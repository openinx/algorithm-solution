#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void print(int x){
    if (x == 0) printf("00");
    if (x == 1) printf("01");
    if (x == 2) printf("10");
    if (x == 3) printf("11");
}

int  main(){
    char s[3];
    int n, m, i, j, h[4], ans[1001][1001]; 
    while(scanf("%d%d", &n, &m)!=EOF){
        h[0] = h[1] = h[2] = h[3] = 0 ; 
        for(i = 0 ; i < n ; ++ i ) for(j = 0 ; j < m ; ++ j){
            scanf("%s",s);
            if(!strcmp(s, "00"))   h[0] ++ ;
            if(!strcmp(s, "01"))   h[1] ++ ; 
            if(!strcmp(s, "10"))   h[1] ++ ; 
            if(!strcmp(s, "11"))   h[3] ++ ;
        }
        memset(ans, 0 ,sizeof(ans));
        for(i = 0 ; i < n ; ++ i){
            int l11 = 0 ;
            for(j = 0;j < m ; ++ j){
                if(h[3] > 0 ){
                    ans[i][j] = 3 ; h[3]-- ;  l11 = 1;
                }else if(h[1] > 0){
                    if(i > 0 && ans[i-1][j] == 2 )
                    { 
                        ans[i][j] = 1 ;
                        h[1]--; 
                    }else if(i >0 && ans[i-1][j] == 1){
                        ans[i][j] = 2 ; 
                        h[1]--;
                    }else if(i > 0 && ans[i-1][j] == 3 && !l11) {
                        if(h[0] > 0)
                        {
                            ans[i][j] = 0 ; h[0] -- ; 
                        }else{
                            ans[i][j] = 1 ; h[1]-- ;
                        }
                    }else{
                        ans[i][j] = 1 ; 
                        h[1]--;
                    }
                }else break; 
                //printf("(%d,%d) = %d\n", i, j, ans[i][j]);
            }
        }
        for(i=0;i<n;++i) {
            int first = 1 ; 
            for(j = 0 ; j < m ; ++ j){
                if(first){
                    print(ans[i][j]);
                    first = 0 ;
                } else{
                    printf(" ") ; print(ans[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0 ; 
}
