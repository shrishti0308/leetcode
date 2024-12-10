// 2981 : Find Longest Special Substring That Occurs Thrice I

/*
You are given a string s that consists of lowercase English letters.
A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
A substring is a contiguous non-empty sequence of characters within a string.
 

*/

/*
Example 1:

Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.

Example 2:

Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.

Example 3:

Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.

 

*/

/*
Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters.


*/

/*
The solution tracks the top three longest consecutive substring lengths for each character ('a' to 'z') using a 2D array.
 As the string is traversed, it calculates the current window length for identical characters and updates the smallest value
 in the top 3 for the corresponding character if the current length is larger. Finally, it returns the maximum of the smallest
 values among the top 3 lists for all characters
*/

class Solution {
    int &getMin(int &a, int &b, int &c){
        if(a<=b and a<=c) return a;
        if(b<=a and b<=c) return b;
        return c;
    }
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> top3Freq(26,vector<int>(3,-1));
        

        char last_seen = '*';
        int win_len =  0;
        for(char& curr: s){
            int index = curr - 'a';
            win_len = curr==last_seen ? win_len+1 : 1;
            last_seen = curr;
            int &minimum = getMin(top3Freq[index][0],top3Freq[index][1],top3Freq[index][2]);
            if(win_len > minimum){
                minimum = win_len;
            }
        } 

        int maxLen = -1;
        for(int i = 0; i < 26; i++)
            maxLen = max(maxLen, min({top3Freq[i][0],top3Freq[i][1],top3Freq[i][2]}));
            return maxLen;
    }     
    
};