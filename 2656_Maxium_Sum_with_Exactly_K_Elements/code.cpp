/* 
Runtime 39 ms Beats 20.12%
Memory 71 MB Beats 81.75% 
*/
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res = *max_element( nums.begin(), nums.end() );
        
        return ( res * k ) + ( ( ( k - 1 ) *  k ) / 2 ) ;
    }
};

/*
Runtime 21 ms Beats 87.80%
Memory 71.1 MB Beats 22.87%
*/
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res = *max_element( nums.begin(), nums.end() );
        int ans = res;
        int fin = 0;
        cout << res << endl;

        while( k-- != 0 )
        {
            fin += ans++;
        }

        return fin;
    }
};