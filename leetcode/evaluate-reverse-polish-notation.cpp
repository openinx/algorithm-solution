class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack ; 
        for(int i = 0 ; i < tokens.size() ; ++ i){
            if(tokens[i] == "*"){
                int b = stack.back() ; stack.pop_back() ; 
                int a = stack.back() ; stack.pop_back() ; 
                stack.push_back( a * b ) ; 
            }else if (tokens[i] == "/"){
                int b = stack.back() ; stack.pop_back() ; 
                int a = stack.back() ; stack.pop_back() ; 
                stack.push_back( a / b ) ; 
            }else if (tokens[i] == "+"){
                int b = stack.back() ; stack.pop_back() ; 
                int a = stack.back() ; stack.pop_back() ; 
                stack.push_back( a + b ) ; 
            }else if (tokens[i] == "-"){
                int b = stack.back() ; stack.pop_back() ; 
                int a = stack.back() ; stack.pop_back() ; 
                stack.push_back( a - b ) ; 
            }else{
                int value = 0, k = 0 , flag = 1 ; 
                if(tokens[i][0] == '-') { k ++ ; flag = -1 ;}
                for(; k < tokens[i].size() ; ++ k){
                    value = value * 10 + (tokens[i][k] - '0') ; 
                }
                stack.push_back( flag * value) ;
            }
        }
        return stack.back() ;
    }
};
