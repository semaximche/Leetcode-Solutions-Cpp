# LeetCode Solutions in C++

## Usage with CMAKE
Build all solutions at once:
```
cmake -B build
cmake --build build
```

Build one solution (replace `0088` with any 4 digits problem number from LeetCode):
```
cmake -B build
cmake --build build --target 0088
```

The executable files will be located in `/build/<problem_number>`

## Solutions with Extras
 - `0088.cpp` contains both the optimal solution and a more practical solution for real world applications.
 - `0209.cpp` contains both O(nlogn) solution and O(n) solution.