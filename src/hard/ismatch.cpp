//
// Created by shyamnath on 6/7/21.
//
#include <string>

bool isMatch(const std::string& s, const std::string p)
{
if(p[0] == '*')
    return false;

int curP, curS;
for(curP=0, curS=0; curP<p.size(); ++curP)
{
    if(p[curP]==s[curS] or p[curP]=='.')
    {
        ++curS;
    }
    else if (p[curP] == '*')
    {
        if(curS==(s.size()-1))
            return true;

        char left = p[curP-1];
        if(left == '.')
        {
            while (s[curS-1] == s[curS])
                ++curS;
        }

        while(s[curS] == left)
        {
            ++curS;
        }
    }
    else if (curP==0 and p[curP+1] == '*')
    {
        ++curP;
    }
    else
        return false;
}

if((curP !=(p.size())) or (curS!=(s.size())))
    return false;

return true;

}


int main()
{
    std::string s = "aab", p = "c*aab";
    bool match = isMatch(s, p);
}
