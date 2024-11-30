// binary search divide and conquire

#include<bits/stdc++.h>
using namespace std;
int binary_search_divide_and_conquier(vector<int> & vec, int element,int high,int low){
    int mid = (low + high/2);
    if(element == vec[mid]){
        return mid+1;
    }
    else if(element > vec[mid]){
        low = mid+1;
        return binary_search_divide_and_conquier(vec,element,high,low);
    }
    else{
        high = mid -1;
        return binary_search_divide_and_conquier(vec,element,high,low);
    }
    return -1;
}
int main(){
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
    int element_index = binary_search_divide_and_conquier(vec,element,n-1,0);
    cout << "index of element " << element << "is = " << element_index;
    return 0;
}