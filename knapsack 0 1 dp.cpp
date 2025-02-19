#include "bits/stdc++.h"
using namespace std;

int knapsack_01(vector<int> &values, vector<int> &weights, int capacity)
{
    int n = values.size();
    vector<vector<int> > dp_table(n + 1, vector<int>(capacity + 1, 0));
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] > w)
            {
                dp_table[i][w] = dp_table[i - 1][w];
            }
            else
            {
                dp_table[i][w] = max(dp_table[i - 1][w], values[i - 1] + dp_table[i - 1][w - weights[i - 1]]);
            }
        }
    }
    return dp_table[n][capacity];
}
int main()
{
    int items;
    int capacity;
    cout << "Enter number of items: ";
    cin >> items;
    vector<int> values(items);
    vector<int> weights(items);
    vector<float> ratios(items);
    cout << "Enter values: ";
    for (size_t i = 0; i < items; i++)
    {
        cin >> values[i];
    }
    cout << "Enter weights: ";
    for (size_t i = 0; i < items; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    int profit = knapsack_01(values, weights, capacity);
    cout << "Profit: " << profit << endl;
    return 0;
}