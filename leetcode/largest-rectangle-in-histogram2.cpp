class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        int *l = new int[n+1] , *r = new int[n+1] ; 
        l[0] = 
        for(int i = 1; i <=n ; ++ i)
            while(height[ l[i] ] <= height[ l[i-1] - 1 ] ) l[]
        for()
    	stack<int> s ; 
    	height.push_back(0);
    	int i = 0, maxArea = 0 ;
    	while( i < height.size() ){
    		if(s.empty() || height[s.top()] <= height[i]){
    			s.push(i++);
    		}else{
    			int t = s.top(); s.pop();
    			maxArea = max(maxArea, height[t] * (s.empty() ? i: i-s.top()-1));
    			cout << "index: " << t << "  maxArea: " << maxArea << endl; 
    		}
    	}
    	return maxArea;
    }
};