
// Question -   Find All Anagrams in a String

/**

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


// Solution

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
                vector<int> ans;

        if(s.length() < p.length()) {
            return ans;
        }
        int arr[26] = {0};
        int flag = 0;

        for(int i = 0 ; i < p.length() ; i++) {
            arr[p[i] - 'a']++;
        }

         for(int i = 0 ; i < p.length() ; i++) {
            arr[s[i] - 'a']--;
        }
         for(int i = 0 ; i < p.length() ; i++) {
            if(arr[p[i] - 'a'] != 0) {
                flag = 1;
            }
        }
         if(flag == 0) {
                ans.push_back(0);
            }

        for(int i = 1 ; i <= (s.size() - p.size()) ; i++) {
            flag = 0;


                arr[s[i - 1] - 'a']++;
                arr[s[i + p.size() - 1] - 'a']--;


            for(int j = 0 ; j < p.size() ;  j++) {
                if(arr[p[j] - 'a'] != 0) {
                    flag = 1;
                }
            }
            if(flag == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
