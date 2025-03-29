#include <bits/stdc++.h> 
void solve(string s,vector<string>&ans,int index,string str)
{
	if(index>=str.length())
	{
		if(!s.empty())
			ans.push_back(s);
		return;
	}
	//exclude
	solve(s,ans,index+1,str);
	//include
	s.push_back(str[index]);
	solve(s,ans,index+1,str);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
	string s="";
	int index=0;
	solve(s,ans,index,str);

	return ans;
	
}
