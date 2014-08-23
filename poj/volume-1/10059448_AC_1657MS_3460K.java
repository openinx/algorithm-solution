import java.util.* ; 

class Stack{
	public static final int MAXN = 101 ;
	int top ; 
	String space[] = new String[MAXN] ;
	Stack(){ top = 0 ; }
	boolean isEmpty(){
		return top == 0 ;
	}
	void push(String url){
		 space[top++] = url ;
	}
	String pop(){
		String url = space[--top] ;
		return url ;
	}
	void clear(){top = 0 ; }
}

public class Main{
	public static void main(String args[]){
		String cmd , url , current = "http://www.acm.org/";
		Scanner cin = new Scanner(System.in) ;
		Stack backward = new Stack() ;
		Stack forward  = new Stack() ;
		while(cin.hasNext()){
			cmd = cin.next() ;
			if(cmd.equals("QUIT"))
				break ;
			if(cmd.equals("VISIT")){
				url = cin.next() ;
				backward.push(current) ;
				current = url ;
				System.out.println(current);
				forward.clear() ;
			}else if(cmd.equals("BACK")){
				if(!backward.isEmpty()){
				     forward.push(current) ;
				     current = backward.pop() ;
				     System.out.println(current);
				}else{
					 System.out.println("Ignored");
				}
			}else if(cmd.equals("FORWARD")){
				if(!forward.isEmpty()){
					  backward.push(current) ; 
					  current = forward.pop() ;
					  System.out.println(current);
				}else{
					  System.out.println("Ignored");
				}
			}	
		}
	}
}
