#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* This solution is memory efficient(beating 97.62%) but not runtime efficient(only beating 38.24%).
    My own intuition tells me that a runtime efficient but not memory efficient solution would be to convert
    the whole string into only alpha-numeric without spaces and then splice in the middle comparing the two
    sides.*/
    bool isPalindrome(string s) {
        size_t i = 0, j = s.length() - 1;
        while(i < j) {
                while(!isalnum(s[i]) && i < j) {
                        i++;
                }
                while(!isalnum(s[j]) && j > i) {
                        j--;
                }
                if(isalnum(s[i]) && isalnum(s[j]) && (tolower(s[i]) != tolower(s[j]))) {
                        return false;
                }
                i++;
                j--;
        }
        return true;
    }
};

/* =======================
        TESTS RUNNER
========================== */
int main() {
    Solution sol;

    // Test Case 1
    {
        string input = "A man, a plan, a canal: Panama";
        cout << "Test Case 1: " << input << endl;
        cout << "Expected: 1" << endl;
        cout << sol.isPalindrome(input) << endl;
    }

    // Test Case 2
    {
        string input = "race a car";
        cout << "Test Case 2: " << input << endl;
        cout << "Expected: 0" << endl;
        cout << sol.isPalindrome(input) << endl;
    }

    // Test Case 3
    {
        string input = " ";
        cout << "Test Case 3: " << input << endl;
        cout << "Expected: 1" << endl;
        cout << sol.isPalindrome(input) << endl;
    }

    // Test Case 4 ".," my original solution failed at this string
    // Original mistake was not testing for is-alpha-numeric at the return false if statement(line 25)
    {
        string input = ".,";
        cout << "Test Case 3: " << input << endl;
        cout << "Expected: 1" << endl;
        cout << sol.isPalindrome(input) << endl;
    }

    // Test Case 5 "0P" my original solution failed at this string
    // Original mistake was testing for isalpha and not for alpha-numeric with isalnum
    {
        string input = "0P";
        cout << "Test Case 3: " << input << endl;
        cout << "Expected: 0" << endl;
        cout << sol.isPalindrome(input) << endl;
    }

    return 0;
}
