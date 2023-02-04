#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int ara[n];
        long long int tempara[n]; //ABSOLUTE VALUES
        int negative=0;
        long long int sum=0;
        for(int i=0;i<n;i++)  //ARRAY INPUT
        {
           cin>>ara[i];
           if(ara[i]<0)
           {
               negative++;
               tempara[i]=(-1)*ara[i];
           }
           else tempara[i]=ara[i];

           sum+=ara[i];
        }

        if(negative==0) cout<<sum<<endl;  //number of negative value are 0


        else if(negative%2==0) //NUMBER OF NEGATIVE VALUES ARE EVEN
        {
           long long int sum=0;
           for(int i=0;i<n;i++)
           {
             sum+=tempara[i];
           }

           cout<<sum<<endl;
        }


        else  //NUMBER OF NEGATIVE VALUES ARE ODD
        {
           //FIND THE MINIMUM VALUE IN TEMPARA[] , ALL THE VALUES IN TEMPARA[] ARE POSITIVE
           int mini=tempara[0],indx=0;

           for(int i=1;i<n;i++)
           {
               if(tempara[i]<mini) {mini=tempara[i]; indx=i;}
           }

           tempara[indx]=(-1)*tempara[indx]; //MAKE THE MINIMUM NEGATIVE

           //SUM OF TEMPARA[]
           long long int sum=0;
           for(int i=0;i<n;i++)
           {
               sum+=tempara[i];
           }

           cout<<sum<<endl;
        }


    } //end of test

    return 0;
}

