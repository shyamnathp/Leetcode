/*
 Imagine a dictionary of mapping each letter to a number:
 a=1, b=2,..,z=26

 Given a number. Find the number of possible words formed.
 2223
 2 2 2 3
 22 2 3
 222 3
 2 22 3
 22 23

 2 = 1
 2 2, 22 = 2
 2 2 2 , 22 2, 2 22 = 3
2 2 2 3, 22 2 3, 2 22 3, 22 23 = 4

 */

#include <iostream>
#include <vector>
#include <string>

int findCount(int num) {
    auto s = std::to_string(num);

    std::vector<int> dp(s.size()+1, 0);
    dp[0]=1;
    dp[1]=(s[0]-'0'>0)?1:0;

    for(int i=2; i<=s.size();++i)
    {
        int valuePrev=(s[i-2]-'0')*10 + (s[i-1]-'0');

        if((s[i-1]-'0')>0 and (s[i-1]-'0')<=9)
            dp[i] += dp[i-1];

        if(valuePrev>=10 and valuePrev<=26)
            dp[i] += dp[i-2];
    }
    return dp[s.size()];
}

int main()
{
    int num = 1;
    int count = findCount(num);
    int test = 1;
}