#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* Not difficult to solve, but edge cases took a little while to sort out. */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        vector<int>::iterator it = nums.begin();

        // Edge case for empty nums
        if(nums.size() == 0) {
            return result;
        }

        // Start first result string with first number
        result.emplace_back(to_string(*it));

        // Iterate over nums array
        while(++it != nums.end()) {
            // On the first occurrence of a non-sequential number 
            if(*(it - 1) != *it - 1) {
                // If it's different than the value already stored in the result string, add range notation
                if(stoi(result.back()) != *(it - 1)) {
                    result.back().append("->");
                    result.back().append(to_string(*(it-1)));
                }
                // Start new range string
                result.emplace_back(to_string(*it));
            }
        }

        // Append ending range if left incomplete after exiting loop
        if(stoi(result.back()) != *(it - 1)) {
            result.back().append("->");
            result.back().append(to_string(*(it-1)));
        }
        return result;
    }
};

/* =======================
        TESTS RUNNER
========================== */
int main() {
    Solution sol;

    // Test case 1
    {
        vector<int> nums = {0, 1, 2, 4, 5, 7};
        cout << "Test case 1" << endl;
        cout << "Expected:\t0->2, 4->5, 7, " << endl;
        cout << "Actual:\t\t";
        vector<string> results = sol.summaryRanges(nums);
        for(string str : results) {
            cout << str << ", ";
        }
        cout << endl;
    }

    // Test case 2 (Modified test case 1)
    {
        vector<int> nums = {0, 1, 2, 4, 5, 7, 9};
        cout << "Test case 2" << endl;
        cout << "Expected:\t0->2, 4->5, 7, 9, " << endl;
        cout << "Actual:\t\t";
        vector<string> results = sol.summaryRanges(nums);
        for(string str : results) {
            cout << str << ", ";
        }
        cout << endl;
    }

    // Test case 3
    {
        vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
        cout << "Test case 3" << endl;
        cout << "Expected:\t0, 2->4, 6, 8->9, " << endl;
        cout << "Actual:\t\t";
        vector<string> results = sol.summaryRanges(nums);
        for(string str : results) {
            cout << str << ", ";
        }
        cout << endl;
    }

    // Test case 4
    {
        vector<int> nums = {5};
        cout << "Test case 4" << endl;
        cout << "Expected:\t5, " << endl;
        cout << "Actual:\t\t";
        vector<string> results = sol.summaryRanges(nums);
        for(string str : results) {
            cout << str << ", ";
        }
        cout << endl;
    }

    // Test case 5
    {
        vector<int> nums = {};
        cout << "Test case 5" << endl;
        cout << "Expected:\t " << endl;
        cout << "Actual:\t\t";
        vector<string> results = sol.summaryRanges(nums);
        for(string str : results) {
            cout << str << ", ";
        }
        cout << endl;
    }
    return 0;
}

/* =======================
        SCRATCHPAD
==========================

nums =              [0,1,2,     4,5,        7,      9]
                                                    ^

result =            ["0->2", "4->5", "7->7", "9"]


expected_result =   ["0->2",    "4->5",     "7"]

*/