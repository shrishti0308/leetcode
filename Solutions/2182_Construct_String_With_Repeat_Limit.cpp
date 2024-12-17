// 2182 : Construct String With Repeat Limit

/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
Return the lexicographically largest repeatLimitedString possible.
A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
 

*/

/*
Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.

Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.

 

*/

/*
Constraints:

1 <= repeatLimit <= s.length <= 105
s consists of lowercase English letters.


*/

/*
Use the max heap to store all the alphabets along with their frequencies
extract the top element append it to the string upto the repeat limit and the change the frequency to the remaining no of characters
if the frequency is more than 0 and heap is empty break otherwise append the next char once to res string and decrement the frequency count
if next char frequency is greater than 0 push it in heap again 
also push curr to the heap
repeat the same until the heap becomes empty
return the res string
*/

class Solution {
    #define pii pair<int,int>
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        priority_queue<pii> maxheap;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                maxheap.push(make_pair(i,freq[i]));
        }

        string res;
        while(!maxheap.empty()){
            pii curr = maxheap.top();
            maxheap.pop();

            char curr_char = 'a' + curr.first;
            int count = min(curr.second,repeatLimit);
            curr.second -= count;
            res.append(count,curr_char);

            if(curr.second>0){
                if(maxheap.empty())break;

                pii next = maxheap.top();
                maxheap.pop();

                char next_char = 'a' + next.first;
                res.push_back(next_char);
                next.second--;

                if(next.second > 0)
                    maxheap.push(next);
                maxheap.push(curr);
            }
        }
        return res;
    }
};