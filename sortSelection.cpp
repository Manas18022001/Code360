//Selection sort

#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    
for(int i=0;i<arr.size()-1;i++){
  int minIndex = i;
  for(int j=i+1;j<arr.size();j++){
        if(arr[j]<arr[minIndex])
          minIndex = j;
  }
  swap(arr[i], arr[minIndex]);
}
}