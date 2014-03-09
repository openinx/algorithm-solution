public class Main{
	public static final int MAXN = 10001 ;
	public static int Next(int c){
		String str = Integer.valueOf(c).toString() ; 
		for(int i = 0 ; i < str.length() ; ++ i)
			c += str.charAt(i)-'0' ; 
		return c;
	}
	public static void main(String args[]){
		int count[]  = new int[MAXN] ;
		int next ;  
		for(int i = 1 ; i < MAXN ; ++ i){
			count[i] = 0 ;
		}
		for(int i = 1 ; i < MAXN ; ++ i){
			next = Next(i) ;
			if(next < MAXN )
			      count[next] ++  ;
		}
		for(int i = 1 ; i < MAXN ; ++ i)
			if(count[i] == 0)
				System.out.println(i) ;
	}
}
