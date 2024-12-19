// 769 : Max Chunks To Make Sorted

/*
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
 

*/

/*
Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

 

*/

/*
Constraints:

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
All the elements of arr are unique.


*/

/*
This question is similar to Anagrams just the frequency of is one
while finding the partition point it is observed that the max of the left part should be less than the min of the right part
also the max of the left is equal to the index of the partition point
we will maintain the max_seen first initialize it to 0 and also the count of the blocks
iterate through the array and upadte the max_seen to max of current max_seen and the current element
if max_seen is equal to the current index then increase the count 
return count
time complexity O(N)
space complexity O(1)
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max_seen = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            max_seen = max(max_seen, arr[i]);
            if(max_seen == i){
                count++;
            }
        }
        return count;    
    }
};