// 2593 : Find Score of an Array After Marking All Elements

/*
You are given an array nums consisting of positive integers.
Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.

Return the score you get after applying the above algorithm.
 

*/

/*
Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

 

*/

/*
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106


*/

/*
use a min heap push all the elements in the min heap , O(logN)
maintain a unordered_set to keep all the indices of marked elements , O(1)
add the elements which are not marked to the sum 
return sum.
total complexity = O(NlogN)
*/

class Solution {
    #define ll long long
    #define pii pair<int,int>
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pii,vector<pii>,greater<pii>> minheap;
        for(int i =0; i<n; i++)
            minheap.push(make_pair(nums[i],i));

            unordered_set<int> marked_index;
            ll sum = 0;
            while(!minheap.empty()){
                pii curr = minheap.top();
                minheap.pop();

                int val = curr.first;
                int index = curr.second;
                if(marked_index.count(index))
                continue;

                sum+= val;

                marked_index.insert(index);
                marked_index.insert(index - 1);
                marked_index.insert(index + 1);
            }
            return sum;
    }
};