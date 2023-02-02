#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,counter=0;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++) //User input
    {
       int s;
       cin>>s;
       if(s==4) counter++;
       else v.push_back(s);
    }

    sort(v.begin(),v.end()); //SORTING

    for(int i=0; v.size()-(i+1)!=0;i++ )
    {   int x=*v.end();
        if(v[i]+x<=4)
        {
            counter++;
            v.erase(v.begin()+*v.end());
            cout<<"$";
        }
        else
        {
            while(v[i] + *(v.end()-1) > 4)
            {
                counter++;
                if(v.size()-(i+1)==0) break;
                v.erase(v.begin()+*v.end());
                cout<<"$";
            }
            cout<<"$";
        }

    }

    cout<<counter<<endl;

}
