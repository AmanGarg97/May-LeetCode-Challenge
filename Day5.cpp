// Question -  First Unique Character in a String


/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

//Solution

class Solution {
public:
    int firstUniqChar(string s) {
        map<char , pair<int,int>> m;
        int ans = INT_MAX;

        for(int i = 0 ; i < s.length() ; i++) {
            if(m.count(s[i]) > 0) {
                m[s[i]].first++;
            }

            else{
                m[s[i]] = make_pair(1,i);
            }
        }

        map<char , pair<int,int>> :: iterator it;

        for(it = m.begin() ; it != m.end() ; it++) {
            if(it -> second.first == 1) {
                if(ans > it -> second.second) {
                    ans = it -> second.second;
                }
            }
        }

        if(ans < INT_MAX) {
            return ans;
        }

        else {
            return -1;
        }
    }
};

