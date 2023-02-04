#include<iostream>
#include<set>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     set<char>s;
     cin>>n;
     char str[n+1];
     cin>>str; //string input

     int prefix[n-1],suffix[n-1];

     for(int i=0;i<n-1;i++)
     {
         s.insert(str[i]);
         prefix[i]=s.size();
     }
     s.clear();

     for(int i=n-1;i>0;i--)
     {
         s.insert(str[i]);
         suffix[i-1]=s.size();
     }
     //Finding maximum

     int maxi=0;

     for(int i=0;i<n-1;i++)
     {
         if(suffix[i]+prefix[i]>maxi) maxi=suffix[i]+prefix[i];
     }

     cout<<maxi<<endl;
     s.clear();


   }//end of test
}
