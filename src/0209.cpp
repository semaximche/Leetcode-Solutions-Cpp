#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* Initial O(nlogn) solution. Figured out I was going to need sums of the elements in the array, and subtraction
    between two elements of the sums represents one sliding window. Couldn't realize that the sums were in non-decreasing
    order and thus allowed for binary search, had to look it up to find the solution. */
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sums(nums.size() + 1);
        int min_length = numeric_limits<int>::max();
        sums[0] = 0;

        // Get sums array for nums, sums array is always sorted non-decreasing which gives us the option to binary search it
        for(int i = 1; i < sums.size(); ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }

        /* Find minimal length for all sliding window sequences at O(n log n)
        One loop iterates over the whole sums array for left side of sliding window */
        for(int i = 0; i < nums.size(); ++i) {

            // Binary search for the right side of sliding window, sums[j] - sums[i] represents one sliding window option
            int left_boundary = i;
            int right_boundary = nums.size();
            int j = (right_boundary - left_boundary) / 2 + left_boundary;

            while(left_boundary <= right_boundary) {
                if((sums[j] - sums[i] >= target)) {
                    // Search left half, target value was found
                    if (j - i <= min_length) {
                        min_length = j - i;
                    }
                    right_boundary = j - 1;
                    j = (right_boundary - left_boundary) / 2 + left_boundary;
                } else {
                    // Search right half, target value not found
                    left_boundary = j + 1;
                    j = (right_boundary - left_boundary) / 2 + left_boundary;
                }
            }
        }

        if(min_length == numeric_limits<int>::max()) {
            return 0;
        }
        return min_length;
    }

    /* Optimal solution using two pointers(iterators) sliding window. */
    int minSubArrayLen2(int target, vector<int>& nums) {
        int min_length = numeric_limits<int>::max();
        int sum = 0;
        int index_right = 0;
        int index_left = 0;
        vector<int>::iterator it_left = nums.begin();
        vector<int>::iterator it_right = nums.begin();

        while(it_right != nums.end()) {
            sum += *it_right;

            while(sum >= target) {
                if(index_right - index_left + 1 < min_length) {
                    min_length = index_right - index_left + 1;
                }
                sum -= *it_left;
                index_left++;
                it_left++;
            }

            index_right++;
            it_right++;
        }

        if(min_length == numeric_limits<int>::max()) {
            return 0;
        }
        return min_length;
    }
};

/* =======================
        TESTS RUNNER
========================== */
int main() {
    Solution sol;

    // Test Case 1
    {
        vector<int> nums = { 2,3,1,2,4,3 };
        int target = 7;
        cout << "Expected: 2" << endl;
        cout << "Got: " << sol.minSubArrayLen2(target, nums) << endl;
    }

    // Test Case 2
    {
        vector<int> nums = { 1,4,4 };
        int target = 4;
        cout << "Expected: 1" << endl;
        cout << "Got: " << sol.minSubArrayLen2(target, nums) << endl;
    }

    // Test Case 3
    {
        vector<int> nums = { 1,1,1,1,1,1,1,1 };
        int target = 11;
        cout << "Expected: 0" << endl;
        cout << "Got: " << sol.minSubArrayLen2(target, nums) << endl;
    }

    // Test Case 4, solution failed
    {
        vector<int> nums = { 1,2,3,4,5 };
        int target = 15;
        cout << "Expected: 5" << endl;
        cout << "Got: " << sol.minSubArrayLen2(target, nums) << endl;
    }

    // Test Case 5, solution failed
    {
        vector<int> nums = { 1,1,1,1,7 };
        int target = 7;
        cout << "Expected: 1" << endl;
        cout << "Got: " << sol.minSubArrayLen2(target, nums) << endl;
    }

    return 0;
}

/* =======================
        SCRATCH PAD
==========================

Target: 7
Nums:   2, 3, 1, 2, 4, 3
                       ^
                 ^

Current Sum: 9

*/