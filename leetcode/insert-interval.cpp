#include<iostream>
#include<algorithm>
#include<vector>
#include<assert.h>

using namespace std; 

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 struct Interval{
 	int start ; 
 	int end ; 
 	Interval(): start(0), end(0){}
 	Interval(int s, int e): start(s), end(e){}
 };

class Solution {
public:

	int prev(vector<Interval> &intervals, int x){
		for(int i = 0 ; i < intervals.size(); ++ i){
			if( (i == 0  && x < intervals[i].start ) || 
				(x < intervals[i].start && x > intervals[i-1].end))
				return i ;
		}
		if(intervals.size() && x > intervals[intervals.size()-1].end )
			return intervals.size();
		return -1;
	}

	int mid(vector<Interval> & intervals, int x){
		for(int i = 0 ; i < intervals.size(); ++ i){
			if(x >= intervals[i].start && x <= intervals[i].end ) return i ;
		}
		return -1 ;
	}

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	vector<Interval> res ; 
    	int spi , smi, epi, emi ; 
    	if(intervals.size() == 0 ){
    		res.push_back(newInterval);
    		return res;
    	}
    	spi = prev(intervals, newInterval.start );
    	smi = mid(intervals,  newInterval.start);
    	epi = prev(intervals, newInterval.end);
    	emi = mid(intervals, newInterval.end);
    	if( spi == -1){
    		if(epi == -1 ){
    			if(smi == emi){
    				// start in mid, end in mid  , in same interval.
    				for(int i = 0 ; i < intervals.size() ; ++i)
    					res.push_back(intervals[i]);
    			}else{
    				// start in mid , end in mid , in different interval.
    				for(int i = 0 ; i < smi ; ++ i)
    					res.push_back(intervals[i]);
    				res.push_back(Interval(intervals[smi].start, intervals[emi].end ));
    			    for(int i = emi+1; i < intervals.size() ; ++ i)
    			    	res.push_back(intervals[i]);
    			}
    		}else{
    			// start mid, end prev.
    			for(int i = 0 ; i < smi; ++ i)
    				res.push_back(intervals[i]);
    			assert ( epi > 0 );
    			res.push_back(Interval(intervals[smi].start, newInterval.end));
    			for(int i = epi ; i < intervals.size() ; ++ i)
    				res.push_back(intervals[i]);
    		} 
    	}else{
    		if(epi == -1 ){
    			// start prev, end mid 
    			assert ( spi < intervals.size() );
    			for(int i = 0 ; i < spi; ++ i) 
    				res.push_back(intervals[i]);
    			res.push_back(Interval(newInterval.start, intervals[emi].end));
    			for(int i = emi+1; i < intervals.size() ; ++ i)
    				res.push_back(intervals[i]);
    		}else{
    			// start prev, end prev
    			if( spi >= intervals.size() || epi >= intervals.size()){
    				if(spi > intervals.size() ){
    					for(int i = 0 ;i < intervals.size() ; ++ i)
    						res.push_back(intervals[i]);
    					res.push_back(newInterval);
    				}else{
    					for(int i = 0 ; i < spi ; ++ i)
    						res.push_back(intervals[i]);
    					res.push_back(newInterval);
    				}
    			}else{// spi < intervals.size() && epi < intervals.size()
    				if(spi == epi ){
    					for(int i = 0 ; i < spi ; ++ i )  res.push_back(intervals[i]);
    					res.push_back(newInterval);
    					for(int i = spi ; i < intervals.size() ; ++ i)
    						res.push_back(intervals[i]);
    				}else{
    					assert ( spi < epi );
    					for(int i = 0 ; i < spi ; ++ i) res.push_back(intervals[i]);
    					res.push_back(newInterval);
    					for(int i = epi; i < intervals.size() ; ++ i)
    						res.push_back(intervals[i]);
    				}
    			}
    		}
    	}
    	return res;
    }
};

int main(){
	int n , a , b , left, right; 
	while(cin >> n >> left >> right){
		Interval interval(left, right);
		vector<Interval> intervals; 
		for(int i = 0 ; i < n ; ++ i){
			cin >> a >> b ; 
			intervals.push_back(Interval(a,b));
		}
		Solution sol ;
		vector<Interval> gd = sol.insert(intervals, interval);
		for(int i = 0 ; i < gd.size() ; ++ i){
			cout << "[ " <<  gd[i].start << ", " << gd[i].end << " ]"<< endl ;
		}
	}
	return 0 ;
}