/*

Edit Distance
Minimum Edits required to convert string 1 to string 2

The problem statement is like if we are given two string str1 and str2 then how many minimum number of
operations can be performed on the str1 that it gets converted to str2.The Operations can be:

1. Insert
2. Remove
3. Replace

For Example

Input: str1 = "geek", str2 = "gesek"
Output: 1
We only need to insert s in first string

Input: str1 = "march", str2 = "cart"
Output: 3
We need to replace m with c and remove character c and then replace h with t

*/

#include <string>
#include <math.h>
#include <type_traits>

using namespace std;

template<typename T>
class EditDistance {

    static_assert(
        !is_same<T, string>::value
        && !is_same<T, bool>::value
        && !is_same<T, char>::value,
        "Error data type."
    );

    public:
        static T getMinConversions(string, string);
};

template<typename T>
T EditDistance<T>::getMinConversions(string str1, string str2) {
    T table[str1.length() + 1][str2.length() + 1];
    for (T i = 0; i <= str1.length(); i++) {
        for (T j = 0; j <= str2.length(); j++) {
            if (i == 0) {
                table[i][j] = j;
            } else if (j == 0) {
                table[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = 1 + min(table[i - 1][j], min(table[i][j - 1], table[i - 1][j - 1]));
            }
        }
    }
    return table[str1.length()][str2.length()];
}