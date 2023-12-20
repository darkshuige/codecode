#include <bits/stdc++.h>
using namespace std;
struct date
{
    int name;
    int pri;
};
bool cmp(date a,date b)
{
    return a.pri > b.pri;
}
int main()
{
    int n;
    vector<date>s;
    while(cin>>n && n)
    {
        vector<date>::iterator it;
        date x;
        switch(n)
        {
        case 1:
            cin>>x.name>>x.pri;
            s.push_back(x);
            break;
        case 2:
            if(s.size())
            {
                sort(s.begin(),s.end(),cmp);
                it = s.begin();
                cout<<it->name<<endl;
                s.erase(it);
            }
            else
                cout<<"0"<<endl;
             break;
        case 3:
            if(s.size())
            {
                sort(s.begin(),s.end(),cmp);
                it = s.end()-1;
                cout<<it->name<<endl;
                s.erase(it);
            }
            else
                cout<<"0"<<endl;
             break;
        }
    }
    return 0;
}
