import java.util.* ; 
import java.math.* ; 

public class Main{
	public static void main(String args[]){
		BigInteger a , sum  = BigInteger.ZERO ; 
		Scanner cin = new Scanner(System.in) ;
		while(cin.hasNext()){
			a = cin.nextBigInteger() ; 
			if(a.equals(BigInteger.valueOf(0)))
				break ;
			sum = sum.add(a) ; 
		}
		System.out.println(sum) ; 
	}
}
