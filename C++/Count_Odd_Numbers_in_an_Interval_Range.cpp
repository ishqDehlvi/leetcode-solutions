// 1523. Count Odd Numbers in an Interval Range
// Date: 13 Feb, 2023


class Solution {
public:
    int countOdds(int low, int high) {
        int n;
       if(low%2==0)
       low=low+1;
       if(high%2==0)
       high=high-1;
        return (high-low)/2+1;
    }
};