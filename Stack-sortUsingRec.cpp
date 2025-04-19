#include <bits/stdc++.h> 

void sort(stack<int> &stack, int num){
	if(stack.empty() || num >= stack.top()){
		stack.push(num);
		return;
	}

	int x = stack.top();
	stack.pop();

	sort(stack, num);
	stack.push(x);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);

	sort(stack, num);
}