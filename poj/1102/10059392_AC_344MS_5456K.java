import java.util.* ;

public class Main{
	public static void rowUp(int s , char c[][]){
		for(int i = 1 ; i <= s ; ++ i) c[0][i] = '-' ;
	}
	public static void rowMiddle(int s , char c[][]){
		for(int i = 1 ; i <= s ; ++ i) c[s+1][i] = '-' ;
	}
	public static void rowDown(int s , char c[][]){
		for(int i = 1 ; i <= s ; ++ i) c[2*s+2][i] = '-' ;
	}
	public static void colLeftUp(int s , char c[][]){
		for(int i = 1 ; i <= s ; ++ i) c[i][0] = '|' ;
	}
	public static void colLeftDown(int s ,char c[][]){
		for(int i = s+2; i <= 2*s+1 ; ++i) c[i][0] = '|' ;
	}
	public static void colRightUp(int s , char c[][]){
		for(int i = 1 ; i <= s ; ++ i) c[i][s+1] = '|' ;
	}
	public static void colRightDown(int s , char c[][]){
		for(int i = s+2; i<= 2*s+1 ; ++i) c[i][s+1] = '|' ;
	}
	public static void zero (int s , char c[][]){
		rowUp(s , c);  rowDown(s , c) ; 
		colLeftUp(s , c) ; colLeftDown(s , c) ; colRightUp(s , c) ; colRightDown(s , c) ;
	}
	public static void one  (int s , char c[][]){
		colRightUp(s , c) ; colRightDown(s , c) ;
	}
	public static void two  (int s , char c[][]){
		rowUp(s , c); rowMiddle(s , c) ; rowDown(s , c) ;
		colRightUp(s , c) ; colLeftDown(s , c) ;
	}
	public static void three(int s , char c[][]){
		rowUp(s , c) ; rowMiddle(s , c) ; rowDown(s , c) ;
		colRightUp(s , c) ; colRightDown(s , c) ;
	}
	public static void four (int s , char c[][]){
		rowMiddle(s , c) ;
		colLeftUp(s , c) ; colRightUp(s , c) ;  colRightDown(s , c) ;
	}
	public static void five (int s , char c[][]){
		rowUp(s , c) ; rowMiddle(s , c) ; rowDown(s , c) ;
		colLeftUp(s , c) ; colRightDown(s , c) ; 
	}
	public static void six  (int s , char c[][]){
		rowUp(s , c) ; rowMiddle(s ,c ) ; rowDown(s , c) ; 
		colLeftUp(s , c) ; colLeftDown(s , c) ; colRightDown(s , c) ;
	}
	public static void seven(int s , char c[][]){
		rowUp(s , c) ;
		colRightUp(s , c) ; colRightDown(s , c) ;
	}
	public static void eight(int s , char c[][]){
		rowUp(s , c) ; rowMiddle(s , c) ; rowDown(s , c) ;
		colLeftUp(s , c) ; colLeftDown(s , c) ; colRightUp(s , c) ; colRightDown(s , c) ;
	}
	public static void nine (int s , char c[][]){
		rowUp(s , c) ; rowMiddle(s , c) ; rowDown(s , c) ; 
		colLeftUp(s , c) ; colRightUp(s , c) ; colRightDown(s , c) ;
	}
	
	public static void fillCharArray(char c[][][] ,int d , int row , int col ){
		for(int k = 0 ; k < d ; ++ k)
		  for(int i = 0 ; i < row ; ++ i)
			for(int j = 0 ; j < col ; ++ j)
				c[k][i][j] = ' ' ; 
	}
	
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in) ; 
		int row , col , s ;
		String strNumber = null ; 
		boolean isFirstCase = true ;
		while(cin.hasNext()){
			s = cin.nextInt() ; 
			strNumber = cin.next() ;
			if(s == 0 && strNumber.equals("0")) 
				break ;
			row = 2*s + 3 ; 
			col = s + 2 ;
			char c[][][] = new char[strNumber.length()][row][col] ; 
			fillCharArray(c , strNumber.length() , row , col ) ;
			for(int i = 0 ; i < strNumber.length() ; ++ i){
			      switch(strNumber.charAt(i) - '0'){
			         case 0 :  zero (s , c[i]) ; break ; 
			         case 1 :  one  (s , c[i]) ; break ; 
			         case 2 :  two  (s , c[i]) ; break ;
			         case 3 :  three(s , c[i]) ; break ;
			         case 4 :  four (s , c[i]) ; break ;
			         case 5 :  five (s , c[i]) ; break ;
			         case 6 :  six  (s , c[i]) ; break ;
			         case 7 :  seven(s , c[i]) ; break ;
			         case 8 :  eight(s , c[i]) ; break ;
			         case 9 :  nine (s , c[i]) ; break ;
			         default:  break ;
			       }
			}
			if(isFirstCase){
				isFirstCase = false ;
			}else{
				System.out.println();
			}
			for(int r = 0 ; r < row ; ++ r ){
				boolean isFirstNumber = true ; 
				for(int i = 0 ; i < col * strNumber.length(); ++ i){
					int index  = i / col , position = i % col ;
					if(position == 0){
						if(isFirstNumber){
							isFirstNumber = false ;
						}else{
							System.out.print(" ") ; 
						}
					}
					System.out.printf("%c", c[index][r][position])  ;
				}
				System.out.println();
			}
		}
	}	
}
