// 2185 : Counting Words With a Given Prefix

/*
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
 

*/

/*
Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.

 

*/

/*
Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.


*/

/*
- We can use inbuilt functions to find whether a word is prefix or not i.e. find()
- The approach would be brute-force, where we would iterate over all possible words and determine if the condition satisfies or not
- find() returns the starting index of first occurence of a word, so in order to have a word as a prefix, we'd need to have return value = 0
*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(words[i].find(pref) == 0){
                count++;
            }
        }
        return count;
    }
};