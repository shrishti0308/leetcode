// 1475 : Final Prices With a Special Discount in a Shop

/*
You are given an integer array prices where prices[i] is the price of the ith item in a shop.
There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.
 

*/

/*
Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.

Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.

Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]

 

*/

/*
Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 1000


*/

/*
Here we will use the concept of monotonic stack patterns (next smaller element)
we will create a stack , push the last index and the res vector and assign the last elememt as the last element of prices array
we will iterate from the alst second element of prices array and move backwards
push the index of the current if it is greater than the value of stack top otherwise pop the top of the stack
also if stack becomes empty res value of that index is same as the prices array value of the same index
otherwise we will reduce the stack top value from the prices index value which becomes the value of the res index 
at last return the res
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> dsc;//next smaller element (monotonically non- desc stack) 
        dsc.push(n-1);
        vector<int> res(n);
        res[n-1] = prices[n-1];

        for(int i = n-2; i>=0; i--){
            while(!dsc.empty() && prices[dsc.top()] > prices[i])
                dsc.pop();

            if(dsc.empty()){
                res[i]= prices[i];
            }else{
                res[i] = prices[i] - prices[dsc.top()];
            }
            dsc.push(i);      
        }
        return res;
    }
};