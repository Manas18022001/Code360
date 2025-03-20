//check if string is palindrome

#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] - 'A' + 'a';
    }

    int st = 0;
    int e  = s.length()-1;
    
    while(st<e)
    {

        if ( !((s[st]>='a' && s[st]<='z') || (s[st]>='0' && s[st]<='9')) )
            st++;
      
        else if( !((s[e]>='a' && s[e]<='z') || (s[e]>='0' && s[e]<='9')) )
            e--;   

        else if(s[st] != s[e])
        {
            return false;
        }
        
        else
        {
            st++;
            e--;
        }
    } 
        return true;
}


//if (s[st] == '@' || s[st] == '?' || s[st] == '&' || s[st] =='$' || s[st] == '')