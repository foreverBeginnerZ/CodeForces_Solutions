#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char s[n+1];
    cin>>s;  //string input

    int silver=0,gold,last_g=0;    //COUNTING SILVER,GOLD AND LAST POSITIONED G
    for(int i=0;i<n;i++)
    {
        if(s[i]=='S') silver++;
        else
        {
            if(i>last_g) last_g=i;
        }
    }
    gold=n-silver;


    //COUNTING VALID_S
    int valid_s=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G')  //Valid_s--> There is atleast one golden trophy before and after it.
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='S')
                {
                    if(j<last_g) valid_s++;
                }
            }
            break;
        }
    }




    int left[n],right[n];  //COUNTING LEFT[] RIGHT[] ARRAY
    int x=0;
    for(int i=0;i<n;i++) //LEFT
    {
       if(s[i]=='S') { x=0; left[i]=0; }
       else { x++; left[i]=x; }
    }
    x=0;
    for(int i=n-1;i>=0;i--) //RIGHT
    {
       if(s[i]=='S') { x=0; right[i]=0; }
       else { x++; right[i]=x; }
    }

    if(silver==0) cout<<gold<<endl;  //Applying LOGIC
    else if(valid_s==0) cout<<gold<<endl;
    else if(gold==0) cout<<"0"<<endl;
    else
    {
       int possible_ans[valid_s];
       int flag=0;
       int index=0;

       for(int i=0;i<n;i++)
       {
        if(s[i]=='G')
         {
            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='S' && j<last_g)
                {
                     if(left[j-1]+right[j+1]<gold) possible_ans[index++]=left[j-1]+right[j+1]+1;
                     else possible_ans[index++]=left[j-1]+right[j+1];
                }
                if(index>valid_s-1) break;
            }
            break;
         }

      }

      int maxi=possible_ans[0]; //FINDING MAXIMUM
      for(int i=1;i<valid_s;i++)
      {
          if(maxi<possible_ans[i]) maxi=possible_ans[i];
      }

      cout<<maxi<<endl;

    }


    return 0;
}
