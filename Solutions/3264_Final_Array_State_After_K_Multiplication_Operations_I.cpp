// 3264 : Final Array State After K Multiplication Operations I

/*
You are given an integer array nums, an integer k, and an integer multiplier.
You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.

Return an integer array denoting the final state of nums after performing all k operations.
 

*/

/*
Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]
Explanation:



Operation
Result


After operation 1
[2, 2, 3, 5, 6]


After operation 2
[4, 2, 3, 5, 6]


After operation 3
[4, 4, 3, 5, 6]


After operation 4
[4, 4, 6, 5, 6]


After operation 5
[8, 4, 6, 5, 6]




Example 2:

Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]
Explanation:



Operation
Result


After operation 1
[4, 2]


After operation 2
[4, 8]


After operation 3
[16, 8]




 

*/

/*
Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5


*/

/*
First build the min heap 
Iterate through the array push the elements in min heap
run the loop k operations extract the top of the heap and remove it 
multiply the value of the heap element with the multiplier also the nums array element of the index of the current element
push the current in the heap
return the new nums array
*/

class Solution {
    #define pii pair<int,int>
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii,vector<pii>,greater<pii>> minheap;
        int n = nums.size();
        for(int i =0; i < n; i++)
            minheap.push(make_pair(nums[i],i));

            while(k--){
                pii curr = minheap.top();
                minheap.pop();

                curr.first *= multiplier;
                nums[curr.second] *= multiplier;
                minheap.push(curr);
            }
        return nums;
    }
};