#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* =======================
        SOLUTION CLASS
========================== */
class Solution {
public:
    /* First intuitive solution. Fits most other solutions on LeetCode but less efficient due to
    dynamically increasing in size data structures with unordered_maps instead of fixed arrays of size 9. 
    The actual most efficient solution would be written in C without using any C++ standard library data structures.
    I.E arrays of booleans for each column/row/sub_box. */
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> sub_boxes(9);
        vector<unordered_map<char, int>> columns(9);
        int row_index = 0;
        int sub_box_index = 0;

        for(vector<char> row : board) {
            int column_index = 0;
            unordered_map<char, int> current_row;
            for(char element : row) {
                if(element != '.') {
                    // Add to row counter
                    current_row[element]++;
                    if(current_row[element] > 1) {
                        return false;
                    }
                    // Add to column counters according to the correct column index
                    columns[column_index][element]++;
                    if(columns[column_index][element] > 1) {
                        return false;
                    }
                    /* Add to sub boxes counters according to correct column and row indices.
                    The exact correct box is the floored division by 3 of the column index
                    plus 3 multiplied by the floored division by 3 of the row index */
                    sub_box_index = (column_index / 3) + ((row_index / 3) * 3);
                    sub_boxes[sub_box_index][element]++;
                    if(sub_boxes[sub_box_index][element] > 1) {
                        return false;
                    }
                }
                column_index++;
            }
            row_index++;
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
        vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        cout << "Expected: 1" << endl;
        cout << "Actual: " << sol.isValidSudoku(board) << endl;
    }

    // Test case 2
    { 
        vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        cout << "Expected: 0" << endl;
        cout << "Actual: " << sol.isValidSudoku(board) << endl;
    }
    return 0;
}

/* =======================
        SCRATCHPAD
==========================

    columns:    col / 3         +     
    row:        row / 3 * 3

    . . .|. . .|. . .
    . . .|. . .|. . .
    ._._.|._._.|._._.
    . . .|. . .|. . .
    . . .|. x .|. . .
    ._._.|._._.|._._.
    . . .|. . .|. . .
    . . .|. . .|. . .
    . . .|. . .|. . .
    

*/