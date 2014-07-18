#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;


struct Interval{
	int start;
	int end; 
	Interval(): start(0), end(0){}
	Interval(int s, int e): start(s), end(e){}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool operator < (const Interval a, const Interval b){
	if(a.start != b.start )
		return a.start < b.start ;
	return a.end < b.end;
}

bool cross(Interval a, Interval b){
	return (a.start <= b.end && a.start >= b.start) || 
		   (a.end <= b.end && a.end >= b.start ) || 
		   (b.start <= a.end && b.start >= a.start ) || 
		   (b.end <= a.end && b.end >= a.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    	vector<Interval> result;
    	sort(intervals.begin(), intervals.end());
    	int i = 0, start, end; 
    	while(i < intervals.size()){
    		Interval interval(intervals[i].start, intervals[i].end);
    		++ i;
    		for(; i < intervals.size() ; ++ i)
    			if(cross(interval, intervals[i])){
    				start = min(intervals[i].start, interval.start);
    				end = max(intervals[i].end, interval.end);
    				interval = Interval(start, end);
    			}else break;
    		result.push_back(interval);
    	}
    	return result;
    }
};

int main(){
	Solution sol;
	Interval a(1,3), b(2,6), c(8,10), d(15,18);
	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	vector<Interval> ans =  sol.merge(intervals);
	for(int i = 0 ; i < ans.size(); ++ i){
		cout << "[ " << ans[i].start << "," << ans[i].end << "]" << endl;
	}
	return 0 ;
}