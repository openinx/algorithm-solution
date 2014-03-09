import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	 
	 public static BigInteger sqrt(BigInteger a){
		    BigInteger  v0 = new BigInteger("1") ;
		    BigInteger  v1 = new BigInteger("1");
		    BigInteger  v2 = new BigInteger("2");
		    BigInteger l = v1 , r = a.add(v1) , mid , x ;
		    
		    //System.out.println(a.toString());
		    
		    
	        while((l.add(v1)).compareTo(r)<0){
	        	  mid = (l.add(r)).divide(v2) ;
	        	  x = mid.add(v1);
	        	  int tr1 = (mid.multiply(mid)).compareTo(a) ;
	        	  int tr2 = (x.multiply(x)).compareTo(a)     ; 
	        	  if(tr1 <=0 && tr2 > 0 )  return mid ;
	        	  if(tr1 < 0 )  
	        		    l = mid ; 
	        	  else  
	        		    r = mid.subtract(v1);
	        	  //System.out.println(l.toString() + "  and  " + r.toString());
	        }
	        if((r.multiply(r)).compareTo(a)<=0)  
	        	    return r ; 
	        else    
	        	    return l ;
	 }
	
	 public static void main(String args[]){
		    Scanner cin = new  Scanner(System.in);
		    BigInteger P , Q , n ,k , low , up ,tp ; 
		    BigInteger v10  = new BigInteger("100000");
		    BigInteger v100 = new BigInteger("10000000000");
		    BigInteger v4   = new BigInteger("4");
		    BigInteger v2   = new BigInteger("2");
		    BigInteger v1   = new BigInteger("1");
		    BigInteger v0   = new BigInteger("0");
		    
		    while(cin.hasNext()){
		         n = cin.nextBigInteger() ; k = cin.nextBigInteger();
		         tp =sqrt(v100.add(v4.multiply(k.multiply(n)))) ;
		         low = (tp.subtract(v10)).divide(v2) ; 
		         if((low.compareTo(v2))<0)  
		        	        low = v2 ;
		         up  = (tp.add(v10)).divide(v2)      ; 
		         for(Q = low ; Q.compareTo(up)<=0 ; Q=Q.add(v1)) 
		        	   if( (n.mod(Q)).compareTo(v0) == 0 )  break ;
		         P = n.divide(Q); 
		         if(Q.compareTo(P)<0){
		        	 tp = Q ; Q = P ; P = tp ;
		         }
		         System.out.println(P.toString()+" * " + Q.toString());
		    }
	 }

}

