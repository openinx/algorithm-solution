import java.util.* ;

public class Main{
	private static final Exception OUT = null;
	static int a[] = new int[15] ; 
	static int n = 0  , x ;
	static int count(){
		int i , j , answer = 0 ;
		for(i = 0 ; i < n ;++ i)
			 for(j = 0 ; j < i ; ++j)
				 if(a[i] == a[j]*2 || a[i]*2 == a[j])
					 ++ answer ;
		return answer ; 
	}
	public static void main(String args[]){
		n = 0 ; 
		Scanner cin = new Scanner(System.in);
		String line  ; 
		while(cin.hasNext()){
			line = cin.nextLine() ;
			if(line.equals("-1")) break ;
			String nub[] = line.split(" ") ; 
			n = nub.length-1 ;
			for(int i = 0 ; i < n ; ++i)
				a[i] = Integer.parseInt(nub[i]) ;
			System.out.println(count());
		}
	}
}
