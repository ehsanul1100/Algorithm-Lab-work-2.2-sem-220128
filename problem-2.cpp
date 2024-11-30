#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void binary_search(vector<int> &vec, int element)
{
    int high = vec.size() - 1, low = 0;
    int mid;
    bool isFound = false;
    while (low <= high)
    {
        mid = (high + low) / 2, cnt++;
        if (element == vec[mid])
        {
            isFound = true;
            cnt++;
            break;
        }
        else if (element > vec[mid])
        {
            low = mid + 1;
            cnt++;
        }
        else
        {
            high = mid - 1;
            cnt++;
        }
    }
    if (isFound)
    {
        if (cnt == 2)
        {
            cout << "Element found. " << mid + 1 << " number index. " << endl;
            cout << "Theoritical Complexity for binary search best case = O(1)" << 1 << endl;
            cout << "Practical Complexity = " << cnt << endl;
        }
        else
        {
            cout << "Element found. " << mid + 1 << " number index. " << endl;
            cout << "Theoritical Complexity for binary search avarage case and worst case = log(n)" << ceil(log2f(vec.size())) << endl;
            cout << "Practical Complexity = " << cnt << endl;
        }
    }
}
int main()
{
    vector<int> vec;
    int n, element;
    cout << "Enter the size of the arry : ";
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> element;
        vec.push_back(element);
    }
    sort(vec.begin(), vec.end());
    cout << "Enter the element: ";
    cin >> element;
    binary_search(vec, element);
}