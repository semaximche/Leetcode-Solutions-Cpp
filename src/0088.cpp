#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* This is the expected optimal solution specifically for LeetCode's problem.
    The optimal solution relies on the fact nums1 array has n zeroes at the end 
    which allows for O(1) space complexity, no needing to reserve any more memory
    and runs at O(n+m) time complexity. In real-world practice rare are the cases
    where you'd want an array merge sort function to rely on extra zeroes at the
    end of the first argument. */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1,      // Start from the end of nums1 and nums2
            j = n - 1,
            k = m + n - 1;  // Additional index for the end of the extra zeroes in nums1

        while(j >= 0) {
            /* From the end of the extra zeroes, we know the solved array will have
            the bigger of the two ends of nums1 and nums2. So we simply insert the larger of the two.
            There's an additional edge case for i<0 where no elements are left in the original nums1. */
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
    /* This is the sub-optimal solution but more practical in practice.
    This solution does not rely on n zeroes at the end of nums1. 
    It takes O(n+m) additional space complexity but still runs at O(n+m)
    time complexity. This solution is more similar to real world problems,
    where the function would return nums3 instead of copying into nums1. */
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(n+m);
        int i = 0, j = 0, k = 0;

        // Merge sort into nums3
        while(j < n) {
             if(i < m && nums1[i] < nums2[j]) {
                nums3[k] = nums1[i];
                i++;
            } else {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        }

        // Edge case for no elements in nums2 which skips putting nums1 elements into nums3.
        while(i < m) {
            nums3[k] = nums1[i];
            i++;
        }

        // Copy nums3 into nums1
        copy(nums3.begin(), nums3.end(), nums1.begin());
    }
};

/* =======================
        TESTS RUNNER
========================== */
int main() {
    Solution sol;

    // Test Case 1
    {
        cout << "Test Case 1" << endl;
        int m = 3, n = 3;
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        sol.merge2(nums1, m, nums2, n);
        for(int e : nums1) {
            cout << e << ", ";
            cout << endl;
        }
    }

    // Test Case 2
    {
        cout << "Test Case 2" << endl;
        int m = 1, n = 0;
        vector<int> nums1 = {1};
        vector<int> nums2 = {};
        sol.merge2(nums1, m, nums2, n);
        for(int e : nums1) {
            cout << e << ", ";
            cout << endl;
        }
    }

    // Test Case 3
    {
        cout << "Test Case 3" << endl;
        int m = 0, n = 1;
        vector<int> nums1 = {0};
        vector<int> nums2 = {1};
        sol.merge2(nums1, m, nums2, n);
        for(int e : nums1) {
            cout << e << ", ";
            cout << endl;
        }
    }

    return 0;
}