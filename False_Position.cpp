#include <iostream>
#include<conio.h>
#include <cmath>

using namespace std;
double f(int n,double p[20],float x)
{ double z=0;
       for(int i=1;i<=n;i++)
       { z=z+p[i]*pow(x,i-1);
       }
       return z;
}

void falpos()
{
float a,b,c,n,etol;
int count = 0;

cout<<"Enter the degree of polynomial : ";
cin>>n;
n=n+1;   
cout<<"Enter all the coefficients : ";
double p[20];
for(int i=1;i<=n;i++)
{
cin>>p[i];
}
cout<<"Hence the polynomial is :";          
for(int i=1;i<=n;i++)
 { 
        cout<<" "<<p[i]<<"*x^"<<(i-1)<<" "<<"+";                 
 }
 
cout<<"\n\ninput initial root interval a, b : ";
cin>>a>>b;
cout<<"input the error tolerance : ";
cin>>etol;
if ((f(n,p,a)*f(n,p,b))<0)
{
count = 0;
do
{c=(a*f(n,p,b)-b*f(n,p,a))/(f(n,p,b)-f(n,p,a));
if (f(n,p,a)*f(n,p,c)<0)
b=c;
else 
a=c;
count = count + 1;
cout<<"\nValue of c is : "<<c;
}
while (fabs(f(n,p,c))>etol);
cout<<"\n\nroot= "<<c<<endl;
cout<<"f(root)= "<<f(n,p,c)<<endl;
cout<<"iterations= "<<count<<endl;
}
else
cout<<"initial interval incorrect\n";
}
main()
{
falpos();
getch();
return 0;
}
