// Question - Ransom Note

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

//Solution

// #include<map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char , int> m;

        for(int i = 0 ; i < magazine.length() ; i++) {
            if(m.count(magazine[i]) > 0) {
                m[magazine[i]]++;
            }

            else {
                m[magazine[i]] = 1;
            }
        }

        for(int i = 0 ; i < ransomNote.length() ; i++) {
            if(m.count(ransomNote[i]) > 0) {
                if(m[ransomNote[i]] <= 0) {
                    return false;
                }
                m[ransomNote[i]]--;
            }

            else{
                return false;
            }
        }

        return true;
    }
};
