	import java.util.*;
	import java.io.*;
	import java.math.BigDecimal;

	public class Main{
		  public static void main(String args[])
		  {
			  Scanner cin = new Scanner(System.in);
			  BigDecimal num;
			  int n;
			  String r;
			  while(cin.hasNextBigDecimal())
			  {
				  num = cin.nextBigDecimal();
				  n= cin.nextInt();
				  num = num.pow(n);
				  r = num.stripTrailingZeros().toPlainString();
				  if(r.startsWith("0.")) r= r.substring(1);
				  System.out.println(r);
			  }
		  }
}