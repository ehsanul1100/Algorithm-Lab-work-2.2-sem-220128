#include "bits/stdc++.h"
using namespace std;
void bubble_sort(vector<int> &vec, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < ((size - i) - 1); j++)
        {
            if (vec[j + 1] < vec[j])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}
void selection_sort(vector<int> &vec, int size)
{
    int max, sort_size = size, i, j, swap_index = 0;
    for (i = 1; i <= size; i++)
    {
        max = vec[0];
        for (j = 0; j < sort_size; j++)
        {
            if (max < vec[j])
            {
                max = vec[j];
                swap_index = j;
            }
        }
        int temp = vec[j - 1];
        vec[j - 1] = vec[swap_index];
        vec[swap_index] = temp;
        sort_size--;
        swap_index = 0;
    }
}
void input(vector<int> &vec, int size)
{
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
}
void output(vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    vector<int> vec(size);
    input(vec, size);
    selection_sort(vec, size);
    bubble_sort(vec, size);
    cout << "Selection sort: ";
    output(vec, size);
    cout << "Bubble sort: ";
    output(vec, size);
    return 0;
}