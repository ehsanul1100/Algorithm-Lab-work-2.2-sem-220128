#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int main(){
    vector<int> vec;
    int n,element;
    cout << "Enter the size of the arry : ";
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> element ;
        vec.push_back(element);
    }
    int max = vec[0],min = vec[0];
    cnt++;
    for (size_t i = 0; i < vec.size(); i++,cnt++)
    {
        if(vec[i] > max) max = vec[i],cnt++;
        if(vec[i] < min) min = vec[i],cnt++;
    }
    
    cout << "Maximum = " << max << endl << "Minimum = " << min << endl;
    cout << "Theoritical Complexity for maximum and minimum combined = O(n) + O(n) = " << 2*n << endl;
    cout << "Practical Complexity = " << cnt << endl;
    
}