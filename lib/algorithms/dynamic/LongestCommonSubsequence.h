#include <string>
#include <cmath>

using namespace std;

class LongestCommonSubsequence {

    public:

        static int length(string str1, string str2) {
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

        static int length(string str1, string str2, int size1, int size2) {
            if (size1 == 0 || size2 == 0) {
                return 0;
            }
            if (str1[size1 - 1] == str2[size2 - 1]) {
                return 1 + length(str1, str2, size1 - 1, size2 - 1);
            } else {
                return max(
                    length(str1, str2, size1 - 1, size2),
                    length(str1, str2, size1, size2 - 1)
                );
            }
        }
};