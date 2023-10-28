#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int>mp;
          for(char c='a';c<='z';c++)mp[c]=int(c);
           for(char c='A';c<='Z';c++)mp[c]=int(c);
           for(int k=0;k<n;k++){
               mp[x[k]]=b[k];
           }
         int ans=INT_MIN;
         int curr_max=0;
         int start=0,end=0,s=0;
         for(int i=0;i<w.size();i++){
             curr_max+=mp[w[i]];
             if(curr_max>ans){
                 ans=curr_max;
                 start=s;
                 end=i;
             }
             if(curr_max<0){
                curr_max=0;
                 s=i+1;
             }
         }
        string res;
        for(int i=start;i<=end;i++)res+=w[i];
        return res;
      }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
