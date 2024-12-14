// 2762 : Continuous Subarrays

/*
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.

Return the total number of continuous subarrays.
A subarray is a contiguous non-empty sequence of elements within an array.
 

*/

/*
Example 1:

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

 
Example 2:

Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.

 

*/

/*
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109


*/

/*
In this question sliding window (with two pointer)approach is used
we will keep on moving the right pointer until it goes out of bound (nums[right] - nums[left] > 2)
if it goes out of bound then we will upadte the count , also make the left and right pointer as same, then we will again start moving the left pointer backwards until (nums[right] - nums[left] > 2)
then we will stop and subtract the new count from that old count then again 
add subarrays from the last window
*/

class Solution {
    #define ll long long
    #define pii pair<int,int>
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right;
        int range_min = INT_MAX;
        int range_max = INT_MIN;

        ll count = 0;
        ll win_size;

        for(right = 0; right < n; right++){
            range_min = min(range_min, nums[right]);
            range_max = max(range_max, nums[right]);

            if(range_max - range_min > 2){
                win_size = right - left;
                count += (win_size*(win_size+1))/2;

                left = right;
                //expand curr window to as left as possible
                range_min = nums[right];
                range_max = nums[right];
                while(abs(nums[right]- nums[left-1]) <= 2){
                    left--;
                    range_min = min(range_min, nums[left]);
                    range_max = max(range_max, nums[left]);
                }

                //subtract overcounted subarrays
                if(left < right){
                    win_size = right - left;
                    count -= (win_size*(win_size+1))/2;
                }
            }
        }
        //add subarrays from last window;
        win_size = right - left;
        count += (win_size*(win_size+1))/2;
        return count;
    }
};