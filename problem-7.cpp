#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &vec,int high,int mid,int low){
    int n1 = mid - low + 1;
    int n2 = high - low;

    vector<int> L(n1),R(n2);

    for (size_t i = 0; i < n1; i++)
    {
        L[i] = vec[low + i];
    }
    for (size_t i = 0; i < n2; i++)
    {
        R[i] = vec[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i<n1 && j < n2)
    {
        if(L[i] <= R[j]){
            vec[k] = L[i];
            i++;
        }else{
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vec[k] = L[j];
        j++;
        k++;
    } 
    
}

void mergeSort(vector<int> vec,int high,int low){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(vec,mid,low);
        mergeSort(vec,high,mid+1);

        merge(vec,high,mid,low);
    }
}
int main(){
    vector<int> vec;
    int n, element;
    cout << "Enter the size of the array : ";
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> element;
        vec.push_back(element);
    }
    mergeSort(vec,n-1,0);
    cout << "Sorted array : ";
    for (size_t i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}