import java.util.* ;
import java.math.* ;

public class Main{
    public static int a[][] = new int[5][5] ;
    public static int vis[][] = new int[5][5] ;
    public static final int xStart = 0 , yStart = 0 , xEnd = 4 , yEnd = 4 ;
    public static int dx[] = {1 , 0 , -1 , 0} ;
    public static int dy[] = {0 , 1 , 0  , -1} ;


    public static void main(String args[]){
           Scanner cin = new Scanner(System.in);
           for(int i = 0 ; i < 5 ; ++ i)
              for(int j = 0 ; j < 5 ; ++ j)
                  a[i][j] = cin.nextInt();
           calc();
    }

    public static void calc(){
          int Q[] = new int[60] ;
          int f = 0 , r = 0 ;
          for(int i = 0 ; i < 5 ; ++ i)
             for(int j = 0 ; j < 5 ; ++ j)
               vis[i][j] = -1 ;
          Q[r++] = xStart ; Q[r++] = yStart ;
          vis[xStart][yStart] = 0 ; 
          while(f!=r){
              int xCur = Q[f++] , yCur = Q[f++] ;
              for(int drt = 0 ; drt < 4 ; drt ++ ){
                    int xNext =  dx[drt] + xCur ;
                    int yNext =  dy[drt] + yCur ; 
                    if(isOut(xNext ,yNext)||a[xNext][yNext]== 1||vis[xNext][yNext]!=-1) 
                         continue ;
                    vis[xNext][yNext] = vis[xCur][yCur] + 1 ;
                    Q[r++] = xNext ; Q[r++] = yNext ;
              }
              if(vis[xEnd][yEnd] !=-1 )  break ;
          }
         makeSolution(xEnd , yEnd);  
    }    

    public static boolean isOut(int xP , int yP){
           return xP<0 || yP < 0 || xP >4 || yP > 4 ;             
    }
 
    /*
    public static void show(){
           System.out.println("The Visit Board Is :");
           for(int i = 0 ; i < 5 ;++ i){
                for(int j = 0 ; j < 5 ; ++ j)
                        System.out.print("  " + vis[i][j]);
                        System.out.println();   
           }


    }
    */
    
   public static void makeSolution(int x , int y){
       if(!(x == xStart && y == yStart)){   
          for(int i = 0 ; i < 4  ; ++ i){
                  int nx = x + dx[i] ;
                  int ny = y + dy[i] ; 
                  if(isOut(nx,ny) || vis[nx][ny] == -1)  
                         continue ;
                  if(vis[nx][ny] == vis[x][y] - 1){
                           makeSolution(nx , ny);  break ;
                  } 
          }
       }
       System.out.println("("+x+", "+y+")");
   } 
   
}


















