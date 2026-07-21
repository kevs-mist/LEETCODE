#include <string>
using namespace std;

class Solution { 
public: 
    bool isPalindrome(int x) { 
        // Negative numbers are not palindromes (e.g., -121 reversed is 121-)
        if (x < 0) return false;

        string str = to_string(x); 
        int Start = 0; 
        int End = str.size() - 1; // Fixed: Used str.size() instead of x.size()

        // Loop to compare characters from both ends moving inward
        while (Start < End) {
            if (str[Start] != str[End]) {
                return false; // Characters mismatch
            }
            Start++;
            End--;
        }
        return true; // All characters matched
    } 
};
