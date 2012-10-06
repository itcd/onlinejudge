#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string current = "http://www.acm.org/";
    string cmd, address;
    stack<string> back, front;
    char c[260];

    while(true)
    {
        cin.getline(c, 260);
        cmd = string(c);
        if(cmd == "QUIT")
            break;
        else
        {
            if(cmd == "BACK")
            {
                if(back.size() > 0)
                {
                    front.push(current);
                    current = back.top();
                    back.pop();
                    cout<<current<<endl;
                }else
                    cout<<"Ignored"<<endl;
            }else
            {
                if(cmd == "FORWARD")
                {
                    if(front.size() > 0)
                    {
                        back.push(current);
                        current = front.top();
                        front.pop();
                        cout<<current<<endl;
                    }else
                        cout<<"Ignored"<<endl;
                }else
                {
                    // VISIT http://www.ibm.com/    
                    address = cmd.substr(6, cmd.length()-6);
                    back.push(current);
                    while(!front.empty())
                    {
                        front.pop();
                    }
                    current = address;
                    cout<<current<<endl;
                }
            }
        }
    }
}