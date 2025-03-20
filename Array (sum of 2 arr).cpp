//Sum of two arrays

#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int>ans;
	int val;
	int carry=0;
	int i = n-1;
	int j = m-1;
	while(i>=0 && j>=0){
		int val = a[i--]+b[j--] + carry;
		if(val>9){
			val=val%10;
			carry=1;
		}
		else
			carry=0;

		ans.push_back(val);
	}

	while(i>=0){
		if(carry == 1){
			ans.push_back(a[i--]+1);
			carry = 0;
		}
		else{
			ans.push_back(a[i--]);
		}
	}

	while(j>=0){
		if(carry == 1){
			ans.push_back(b[j--]+1);
			carry = 0;
		}
		else{
			ans.push_back(b[j--]);
		}
	}
	if(carry == 1){
			ans.push_back(1);
	}

	int s=0;
	int e=ans.size()-1;
	while(s<e){
		swap(ans[s++], ans[e--]);
	}
	return ans;
}