import java.util.* ;
import java.math.* ;

class node{
      int a , b ;
      public node(int a ,int b){
             int t = gcd(a>0 ? a : -a , b > 0 ? b : -b);
             this.a = a/t ;
             this.b = b/t ;
      }
      public int gcd(int x ,int y){
            if(y == 0 )  
                 return x ;
            else 
                 return gcd(y , x%y);
      }
      public node add(node that){
             int c , d , t ;
             c = a * that.b + b * that.a ;
             d = b * that.b ;
             t = gcd(c > 0 ? c : -c , d > 0 ? d : -d);
             return new node(c/t , d/t);
      }
      public node sub(node that){
             int c , d , t ;
             c = a * that.b - b * that.a ;
             d = b * that.b ;
             t = gcd(c > 0 ? c : -c , d > 0 ? d : -d);
             return new node(c/t , d/t);
      }
      public String toString(){
         if(a==0)
                return "0" ;
         else  
                return a+"/"+b ;
      }
}


public class Main{
    public static void main(String args[]){
           Scanner cin = new Scanner(System.in);
           while(cin.hasNext()){
                 String info = cin.next();
                 node u = new node(info.charAt(0)-'0' , info.charAt(2)-'0');
                 node v = new node(info.charAt(4)-'0' , info.charAt(6)-'0');
                 if(info.charAt(3)=='+'){
                       System.out.println(u.add(v));
                 }else{
                       System.out.println(u.sub(v));
                 }
           }       
    }
}