import java.util.* ;

class Point{
	int x , y ;
	Point(){}
	Point(int _x , int _y){
		x = _x ; y = _y ;
	}
}

public class Main{
	static int row , col , head , tail ;
	static Point queue[] = new Point[405] ;
	static int maze[][] = new int[25][25] ;
	static Point start , current , previous ;
	static int dx[] ={-1 , 0 , 1 , 0 } ;
	static int dy[] ={ 0 , 1 , 0 ,-1 } ;
	static boolean isOutOfBound(Point a){
		return a.x < 0 || a.y < 0 || a.x >= row || a.y >= col ;
	}
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			col = cin.nextInt() ;
			row = cin.nextInt() ; 
			if(row == 0 && col==0 ) break ;
		    char c[][] = new char[row][col] ;
		    for(int i = 0 ; i < row ; ++i){
		    	c[i] = cin.next().toCharArray() ;
		    	for(int j = 0 ; j < col ; ++ j)
		    		 if(c[i][j]=='@'){
		    			 start = new Point(i,j) ;
		    		 }
		    }
		    for(int i = 0 ; i < row ; ++i)
		    	for(int j = 0 ; j < col ; ++ j)
		    		maze[i][j] = -1 ; 
		    head = tail = 0 ; 
		    queue[tail ++ ] = start ;
		    maze[start.x][start.y] = 0 ;
		    while(head < tail){
		    	previous = queue[head++] ;
		    	for(int i = 0 ; i < 4 ; ++i){
		    		current = new Point(previous.x + dx[i] , previous.y + dy[i]) ; 
		    		if(isOutOfBound(current) || c[current.x][current.y]!='.' || maze[current.x][current.y]!=-1 )
		    			continue ;
		    		maze[current.x][current.y] = maze[previous.x][previous.y] + 1 ;
		    		queue[tail++] = current ; 
		    	}
		    }
		    System.out.println(tail) ;
		}
	}

}
