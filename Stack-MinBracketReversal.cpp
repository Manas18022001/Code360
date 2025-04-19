#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    if(str.length()%2 == 1)
        return -1;
    
    stack<int> s;
    
    for(int i=0; i<str.length(); i++){
        if(s.empty())
          s.push(str[i]);

        else if (s.top() == '{' && str[i] == '}')
          s.pop();

        else
          s.push(str[i]);
    }
    int open = 0;
    int close = 0;

    while(!s.empty()){
      if(s.top() == '{'){
        open++;
        s.pop();
      }    
      else{
        close++;
        s.pop();
      }
    }
    return (open+1)/2 + (close+1)/2;
}