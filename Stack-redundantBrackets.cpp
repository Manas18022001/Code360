#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '*' || ch == '-' || ch == '/' || ch == '+')
            st.push(ch);
        else if (ch == ')')
        {
            if(st.top() == '(')
                return true;
            else
            {
                while(st.top() == '*' || st.top() == '-' || st.top() == '/' || st.top() == '+')
                    st.pop();
                st.pop();
            }
        }
    }
    return false;
}
