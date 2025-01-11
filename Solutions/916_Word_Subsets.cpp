// 916 : Word Subsets

/*
You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.
 

*/

/*
Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]
Output: ["leetcode"]

Example 3:

Input: words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]
Output: ["facebook","google"]

 

*/

/*
Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.


*/

/*
we will create a freqeuncy map for each word in words2
also we will have one function which will return the freq map of each words which would be maximun occurence of each characters in word of words2
we will iterate through the words2 array and increment the count of each characters and update the max freqeuncy
we will iterate through the each word in words1 maintain the freqeuncy map of each each character in that word 
after  that we will check if the frequency count of each character is greater than or equal to max frequncy count in words2 of that character
return the universal words 

*/

class Solution {
    void setMaxFreq(vector<int>& freq_words2, vector<int>& freq){
        for(int i = 0; i < 26; i++)
           freq_words2[i] = max(freq_words2[i],freq[i]);
    }

    bool isUniversal(vector<int>& freq_word, vector<int> freq_words2){
        for(int i = 0; i < 26; i++){
            if(freq_word[i] < freq_words2[i])
              return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq_words2(26);
        for(string word: words2){
            vector<int> freq(26);
            for(char c : word){
                freq[c - 'a']++;
            }
            setMaxFreq(freq_words2,freq);
        }

        vector<string> universal_words;
        for(string word: words1){
            vector<int> freq_word(26);
            for(char c : word){
                freq_word[c - 'a']++;
            }
            if(isUniversal(freq_word, freq_words2))
                 universal_words.push_back(word);
        }
        return universal_words;
    }
};