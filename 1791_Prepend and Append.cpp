#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,valid=0;
        cin>>n;
        char s[n+1];
        cin>>s;
        int last=n-1;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[last]) valid++;
            else break;

            last--;
        }

        cout<<n-(valid*2)<<endl;
    }
  return 0;
}



