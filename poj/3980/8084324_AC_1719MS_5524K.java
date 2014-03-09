import java.util.* ;
import java.math.* ;

public class Main{
   public static void main(String args[]){
           Scanner cin = new Scanner(System.in);
           while(cin.hasNext()){
                int a = cin.nextInt();
                int b = cin.nextInt();
                int c = a % b ;
                System.out.println(c);
           }
   }
}