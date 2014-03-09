import java.util.* ;
import java.math.* ;

public class Main{
     public static void main(String args[]){
            Scanner cin = new Scanner(System.in);
            while(cin.hasNext()){
                 BigInteger a0 = cin.nextBigInteger();
                 BigInteger a1 = cin.nextBigInteger();
                 BigInteger a2 = cin.nextBigInteger();
                 for(int i = 3 ; i < 100 ; ++ i){
                           BigInteger t = a0.add(a1).add(a2) ;
                           a0 = a1 ;
                           a1 = a2 ; 
                           a2 = t  ;
                 }
                 System.out.println(a2);
            }
     }
}