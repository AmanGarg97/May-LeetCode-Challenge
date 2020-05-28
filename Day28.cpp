// Question -  Counting Bits

/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

// Solution
class Solution {
public:

    //Function to check whether the number is a power of 2 or now
    inline bool ispowerof2(int n){
        return (n & (n-1)) == 0;
    }

    vector<int> countBits(int num) {
        vector<int> dp(num+1);

        dp[0]=0;

        if(num>=1)
            dp[1]=1;

        int curr=2;
        int nearest=2;
        while(curr<=num)
        {
            //nearest stores the nearest power of 2 less than current element (nearest of 5 is 4, nearest of 13 is 8..)
            nearest = ispowerof2(curr) ? curr  : nearest;
            dp[curr] = 1 + dp[curr-nearest]; // 1 stands for dp[nearest]
            curr++;
        }

        return dp;
    }
};
