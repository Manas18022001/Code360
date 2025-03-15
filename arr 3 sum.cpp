You are given an array/list ARR consisting of N integers.
Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	set<vector<int>> hash;
	for(int i=0;i<n;i++){
		if(i!=0 && (arr[i] == arr[i-1]))
			continue;
		
		int j = i+1;
		int k = n-1;

		while(j<k){
			if(arr[i]+arr[j]+arr[k] < K){
				j++;
			}
			else if(arr[i]+arr[j]+arr[k] > K){
				k--;
			}
			else{
				vector<int> temp = {arr[i],arr[j],arr[k]};
				hash.insert(temp);
				j++;k--;
			}
		}
	}
	for(auto x:hash){
		ans.push_back(x);
	}
	return ans;
}