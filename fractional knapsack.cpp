#include "bits/stdc++.h"
using namespace std;
map<float, int> global_ratio;
void getRatios(vector<int> &values, vector<int> &weights, vector<float> &ratios)
{
    for (size_t i = 0; i < values.size(); i++)
    {
        float rat = (float)((float)values[i] / (float)weights[i]);
        ratios[i] = rat;
        global_ratio[rat] = i;
        // cout << "Global ratio :" << ratios[i] << " index : " << global_ratio[ratios[i]] << endl;
    }
    sort(ratios.begin(), ratios.end(), greater<float>());
}
int fractionalKnap(vector<int> &values, vector<int> &weights, vector<float> &ratios, int capacity)
{
    cout << "getRatios: " << endl;
    getRatios(values, weights, ratios);
    cout << "getRatios: " << endl;
    int profit = 0;
    for (size_t i = 0; i < ratios.size(); i++)
    {
        if (capacity > 0)
        {
            // cout << "Global ratio :" << ratios[i] << " index : " << global_ratio[ratios[i]] << endl;
            if (capacity >= weights[global_ratio[ratios[i]]])
            {
                profit += values[global_ratio[ratios[i]]];
                capacity -= weights[global_ratio[ratios[i]]];
                // cout << "Profit: " << profit << " weight: " << weights[global_ratio[ratios[i]]] << " capacity: " << capacity << endl;
            }
            else
            {
                float temp = (float)capacity / (float)weights[global_ratio[ratios[i]]];
                profit += values[global_ratio[ratios[i]]] * temp;
                capacity -= weights[global_ratio[ratios[i]]] * temp;
                // cout << "profit: " << profit << " weight: " << weights[global_ratio[ratios[i]]] << " capacity: " << capacity << endl;
            }
        }
    }
    return profit;
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
    int profit = fractionalKnap(values, weights, ratios, capacity);
    cout << "Profit: " << profit << endl;
    return 0;
}
