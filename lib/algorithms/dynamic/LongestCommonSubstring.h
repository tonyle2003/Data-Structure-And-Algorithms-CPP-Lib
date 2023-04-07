/*

Longest Common Substring

Given 2 string str1 and str2 we have to find the length of the longest common substring between them.

Examples

Input : X = "abcdxyz", y = "xyzabcd" Output : 4
The longest common substring is "abcd" and is of length 4.

Input : X = "zxabcdezy", y = "yzabcdezx" Output : 6
The longest common substring is "abcdez" and is of length 6.

*/

#include <string>
#include <values.h>

using namespace std;

class LongestCommonSubstring {
    public:
        static int getLongestCommonSubstring(string, string);
};

int LongestCommonSubstring::getLongestCommonSubstring(string str1, string str2) {
    int table[str2.length() + 1][str1.length() + 1];
    int max = INT_MIN;
    for (int i = 1; i <= str2.length(); i++) {
        for (int j = 1; j <= str1.length(); j++) {
            if (str1[j - 1] == str2[i - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > max) {
                    max = table[i][j];
                }
            } else {
                table[i][j] = 0;
            }
        }
    }
    return max;
}