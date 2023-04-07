/*
Longest Common Subsequence

If we are given with the two strings we have to find the longest common sub-sequence present in both of them.

Example

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

*/

#include <string>
#include <cmath>

using namespace std;

class LongestCommonSubsequence {
    public:
        static int getLongestCommonSubsequence(string, string);
        static int getLongestCommonSubsequence(string, string, int, int);
};

int LongestCommonSubsequence::getLongestCommonSubsequence(string str1, string str2) {
    int table[str1.length() + 1][str2.length() + 1];
    for (int i = 0; i <= (int) str1.length() + 1; i++) {
        for (int j = 0; j <= (int) str2.length() + 1; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]){
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[str1.length()][str2.length()];
}

int LongestCommonSubsequence::getLongestCommonSubsequence(string str1, string str2, int size1, int size2) {
    if (size1 == 0 || size2 == 0) {
        return 0;
    }
    if (str1[size1 - 1] == str2[size2 - 1]) {
        return 1 + getLongestCommonSubsequence(str1, str2, size1 - 1, size2 - 1);
    } else {
        return max(
            getLongestCommonSubsequence(str1, str2, size1 - 1, size2),
            getLongestCommonSubsequence(str1, str2, size1, size2 - 1)
        );
    }
}