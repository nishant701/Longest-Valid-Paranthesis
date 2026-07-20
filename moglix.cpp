// #Write a program: Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
// Example 1:Input: s = "(()"Output: 2Explanation: The longest valid parentheses substring is "()".
// Example 2:Input: s = ")()())"Output: 4Explanation: The longest valid parentheses substring is "()()".
// Example 3:Input: s = ""Output: 0
// Constraints:
// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

                                        //    SOLUTION 1
#include <bits/stdc++.h>
using namespace std;

int longestValidParenthesesSubstring(string s) {
    stack<int> st;
    st.push(-1);  
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParenthesesSubstring(s);
    return 0;
}



                                        // SOLUTION 2
#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {

            if (s[i - 1] == '(') {
                dp[i] = 2;
                if (i >= 2)
                    dp[i] += dp[i - 2];
            }

            else {
                int j = i - dp[i - 1] - 1;

                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2;

                    if (j >= 1)
                        dp[i] += dp[j - 1];
                }
            }

            ans = max(ans, dp[i]);
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << longestValidParentheses(s);

    return 0;
}



