// You are given an integer array 'ARR' of size 'N' and an integer 'S'.
// Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
// Note:
// Each pair should be sorted i.e the first value should be less than or equals to the second value. 
// Return the list of pairs sorted in non-decreasing order of their first value.
// In case if two pairs have the same first value, the pair with a smaller second value should come first.
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<arr.size()-1;i++)
    {
        for(int j = i+1;j<arr.size();j++)
        {
            if ((arr[i]+arr[j]) == s)
            {
                vector<int> v(2,0);
                v[0]=arr[i];
                v[1]=arr[j];
                ans.push_back(v);
            }
        }

    }
        return ans;
}