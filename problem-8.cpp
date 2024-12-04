#include "bits/stdc++.h"
using namespace std;

void swapTwoNumbers(int * number1,int * number2){
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

int makePartation(int array[],int high,int low){
    int pivot = array[low];
    int64_t i = low,j = high;
    while (i < j)
    {
        while(array[i] <= pivot) i++;
        while (array[j] > pivot) j--;
       if(i < j)swapTwoNumbers(&array[i],&array[j]);
    }
    swapTwoNumbers(&array[j],&array[low]);
    return j;
}

void quickSortForList(int array[],int high, int low){
    if(low < high){
        int64_t j = makePartation(array,high,low);
        quickSortForList(array,j-1,low);
        quickSortForList(array,high,j+1);

    }
}
void output(int array[],int size){
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;   
}

int main(){
    int64_t size;
    cin >> size;
    int array[size];
    for (size_t i = 0; i < size; i++) cin >> array[i];
    quickSortForList(array,size-1,0);
    output(array,size);
    return 0;
}