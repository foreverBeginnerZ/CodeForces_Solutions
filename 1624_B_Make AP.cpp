#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
      int a,b,c;
      cin>>a>>b>>c;

      if( b-a==c-b ) cout<<"Yes"<<endl;
      else if((c+a)%(2*b)==0  ||  ((2*b-c)>0 && (2*b-c)%a ==0) ||  ((2*b-a)>0 && (2*b-a)%c ==0) ) cout<<"Yes"<<endl; //2b=c+a so c+a % 2b must be equal to zero...

      else cout<<"No"<<endl;
    }

    return 0;
}

