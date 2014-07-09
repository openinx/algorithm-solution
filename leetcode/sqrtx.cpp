#include<iostream>
#include<stdio.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        long long l = 0 , r = x, mid = (l + r) >> 1 , ret = 1; 
        while(l <= r ){ 
            mid = (l + r) >> 1 ; 
            if(mid * mid == x){
                return mid; 
            }else if(mid * mid < x ){
                ret = mid ; 
                l = mid + 1; 
            }else{
                r = mid - 1; 
            }
        }
        return (int)ret ; 
    }
};

int main(){
    int n ; 
    while(cin >> n ){
        Solution sol ; 
        cout << sol.sqrt(n) << endl ;
    }
    return 0;
}