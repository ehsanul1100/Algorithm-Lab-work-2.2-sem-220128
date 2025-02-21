#include "bits/stdc++.h"
using namespace std;
int lcs_dp(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    string dp_string;
    vector<vector<int>> dp_table(n + 1, vector<int>(n + 1, 0));
    vector<vector<char>> dp_direction(n + 1, vector<char>(n + 1, ' '));
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp_table[i][j] = 1 + dp_table[i - 1][j - 1];
                dp_direction[i][j] = 'D';
            }
            else
            {
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1]);
                (dp_table[i - 1][j] >= dp_table[i][j - 1]) ? dp_direction[i][j] = 'U' : dp_direction[i][j] = 'L';
            }
        }
    }
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (dp_direction[i][j] == 'D')
        {
            dp_string.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (dp_direction[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(dp_string.begin(), dp_string.end());
    cout << "LCS: " << dp_string << endl;

    return dp_table[n][m];
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int length = lcs_dp(str1, str2);
    cout << "Length of LCS: " << length << endl;
    return 0;
}
