#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* Very similar to 0036 in the way that the actual most efficient way would be using fixed size arrays in pure C
    rather than hash maps in C++. Weird that this is under the category of hash map since it doesn't even require it. 
    Space complexity would be fixed to 26 letters of the alphabet at O(1). Time complexity is O(n) where n is the
    longest between the length of the magazine and length of ransomNote (Can add an additional return false condition
    at the very start for ransomNote.length() > magazine.length() in which case n would be the length of the magazine only). */
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazine_map;
        for(char letter : magazine) {
            magazine_map[letter]++;
        }
        for(char letter : ransomNote) {
            if(--magazine_map[letter] < 0) {
                return false;
            }
        }
        return true;
    }
};

/* =======================
        TESTS RUNNER
========================== */
int main() {
    Solution sol;

    // Test case 1
    {
        string ransomNote = "a";
        string magazine = "b";
        cout << "Expected: 0" << endl;
        cout << "Actual:" << sol.canConstruct(ransomNote, magazine) << endl;;
    }

    // Test case 2
    {
        string ransomNote = "aa";
        string magazine = "ab";
        cout << "Expected: 0" << endl;
        cout << "Actual:" << sol.canConstruct(ransomNote, magazine) << endl;;
    }

    // Test case 3
    {
        string ransomNote = "aa";
        string magazine = "aab";
        cout << "Expected: 1" << endl;
        cout << "Actual:" << sol.canConstruct(ransomNote, magazine) << endl;;
    }
    return 0;
}

/* =======================
        SCRATCHPAD
==========================

*/