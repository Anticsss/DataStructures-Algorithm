/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        
        for (int i:nums){
            if (i == max1 || i == max2 || i == max3){ continue; }
            
            if(i > max1){
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if (i > max2){
                max3 = max2;
                max2 = i;
            }
            else if (i > max3){
                max3 = i;
            }
        }
        return max3 == LONG_MIN ? max1 : max3;
    }
};

int main(){
	Solution sol;
	
	vector<int> heights = {2,2,3,1};
	int max_third = sol.thirdMax(heights);

	cout << max_third << endl;
}
