#include <bits/stdc++.h>
using namespace std;

char findMaxChar(string s)
{
    int max = INT_MIN;
    char result;
    unordered_map<char, int> map;
    string :: iterator i;
    unordered_map<char,int> :: iterator it;
    for (i = s.begin() ; i != s.end() ; i++)
    {
        map[*i]++;
    }
    for(it = map.begin() ; it != map.end() ; it++)
    {
        if(it->second > max)
        {
            max = it->second;
            result = it->first;
        }
    }
    return result;
}


int main()
{
    string s;
    getline(cin,s);
    cout << findMaxChar(s);
}




