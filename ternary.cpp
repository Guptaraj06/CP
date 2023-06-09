#include<bits/stdc++.h>
using namespace std;  
int n;
double a[200005];
double arr[200005];   
double f(double x){
     for(int i=0;i<n;i++){
         arr[i]=a[i]-x;
     }      
     double neg=0;
     double pos=0;
     double ans=0;  
     for(int i=0;i<n;i++){
         if(neg>0)neg=0;
         if(pos<0)pos=0;
         neg+=arr[i];
         pos+=arr[i];
         ans=max(ans,max(-neg,pos));
     }       
     return ans;
}
int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];  
    double l=-1e5-9,r=1e5+9;
    for(int i=0;i<100;i++){
        double m1=l+(r-l)/3, m2=r-(r-l)/3;   
        if(f(m1)>f(m2))l=m1;   
        else r=m2;
    }    
    cout<<setprecision(6) << fixed <<f(l)<<endl;
    return 0;
}