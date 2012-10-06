#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comparePrefix(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    int min = l1 < l2 ? l1 : l2;
    int i;
    for(i=0; i<min; i++)
    {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

int main()
{
    const string END = "9";
    string s;
    vector<string> sv;
    bool loop = true;
    int i;
    int count = 0;

    while(true)
    {
        count++;
        sv.clear();
        while((loop=(cin>>s)) && s!=END)
        {
            sv.push_back(s);
        }

        if(!loop)
            break;

        sort(sv.begin(), sv.end());

        //for(i=0; i<sv.size(); i++)
        //    cout<<sv[i]<<endl;

        for(i=1; i<sv.size(); i++)
        {
            if(comparePrefix(sv[i-1], sv[i]))
            {
                cout<<"Set "<<count<<" is not immediately decodable"<<endl;
                break;
            }
        }
        if(i >= sv.size())
            cout<<"Set "<<count<<" is immediately decodable"<<endl;
    }

    return 0;
}