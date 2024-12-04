// maximum and minimum in devide and conquier method 

#include <bits/stdc++.h>
using namespace std;
struct MaxMin {
    int max,min;
};
int cnt1=0;
int cnt2=0;
int findMaxMinNormal(vector<int> &vec){
    int max = vec[0],min = vec[0];
    cnt1++;
    for (size_t i = 0; i < vec.size(); i++,cnt1++)
    {
        if(vec[i] > max) max = vec[i],cnt1++;
        if(vec[i] < min) min = vec[i],cnt1++;
    }
    
    cout << "Maximum = " << max << endl << "Minimum = " << min << endl;
    cout << "Practical Complexity Normal method = " << cnt1 << endl;
}

MaxMin findMaxMinDaC(vector<int>&vec,int first,int last){
    if(vec[first] == vec[last]){
        cnt2++;
        return {vec[first],vec[last]};
    }
    if(first == last-1){
        cnt2++;
        return{
            max(vec[first],vec[last]),
            min(vec[first],vec[last])
        };
    }
    int mid = (last + first) / 2; 
    MaxMin maxmin1 = findMaxMinDaC(vec,first,mid);
    MaxMin maxmin2 = findMaxMinDaC(vec,mid+1,last);
    cnt2+=4;

    return {
        max(maxmin1.max,maxmin2.max),
        min(maxmin1.min,maxmin2.min)
    };
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
    findMaxMinNormal(vec);
    MaxMin maxmin = findMaxMinDaC(vec,n-1,0);
    cout << "Maximum = " << maxmin.max << endl << "Minimum = " << maxmin.min << endl;
    cout << "Practical Complexity DaC method = " << cnt2 << endl;
    return 0;
}