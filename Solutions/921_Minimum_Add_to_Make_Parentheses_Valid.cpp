// 921 : Minimum Add to Make Parentheses Valid

/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.
 

*/

/*
Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3

 

*/

/*
Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.


*/

/*
- This can be solved using a stack
- If we encounter a '(' then we push it onto the stack in hope that it will be cancelled out by a ')'

- If we have a direct ')', then we add it to the count
- In the end, the total number of unmatched '(' & direct ')' is the solution

- Otherwise we can simply do this using counts of '(' & direct ')'
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char> st;
      int count = 0;
      for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                count++;
            }
        }
      }
       return count + st.size();
    }
};

// OR

class Solution {
public:
    int minAddToMakeValid(string s) {
       int open = 0;
       int close = 0;
       for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            open++;
        }
        else{
            if(open > 0){
                open--;
            }else{
                close++;
            }
        }
       }
       return (open + close);
    }
};