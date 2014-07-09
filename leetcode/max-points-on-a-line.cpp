bool mycmp(const Point a , const Point b){
	if(a.x != b.x ) return a.x < b.x ;
	return a.y < b.y ; 
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	if(points.size() == 0) return 0 ;
    	vector< Point > ps ; 
    	vector< int > cnt ; 
    	int i, j = 0 , ans = 0 ; 
    	double INF = 1e100 ; 
    	sort(points.begin(), points.end(), mycmp);
    	ps.push_back(points[0]); 
    	for(i = 1, j = 0 ; i < points.size() ; ++ i)
    		if( !( points[i].x == points[j].x && points[i].y == points[j].y) ){
    			cnt.push_back(i-j);
    			ps.push_back(points[i]); 
    			j = i ;
    		}
    	cnt.push_back(i-j);
    	for(i = 0 ; i < ps.size() ; ++ i){
    		vector<Point> vp ; 
    		map<double, int> mp ;
    		ans = max(ans, cnt[i]);
    		for(j =  0 ; j < ps.size() ; ++ j)
    			if( i != j){
    				double y = ps[j].y - ps[i].y , x = ps[j].x - ps[i].x ;
    				double delta = (x == 0 ?  INF: y /x ) ;
    				int total = mp[delta]; 
    				total = total + cnt[j];
    				mp[delta] = total;
    				ans = max(ans, total + cnt[i]);
    			}
    	}
    	return ans;
    }
};
