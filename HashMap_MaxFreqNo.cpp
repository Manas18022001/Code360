#include <unordered_map>
int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int, int> mp;
    int maxFreq = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
        maxFreq = max(maxFreq, mp[arr[i]]);
    }

    for(int i=0; i<n; i++){
        if(mp[arr[i]] == maxFreq){
            ans = arr[i];
            break;
        }
    }

    return ans;

}