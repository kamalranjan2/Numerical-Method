#include "iostream"
#include "conio.h"
#include "math.h"
using namespace std;
     
double f(int n,double *coeff,double x)       
{
       double f_ans=0;
       for(int k=0;k<=n;k++)
       {
               f_ans+=coeff[k]*pow(x,k); 
       }                             
        return f_ans;
}
main()
{    
      double etol,i=0, coeff[10], k,n,diff, diff2;
      double x0,x1,h = 0.000001,x0_val,x0_val_h, x2,x2val_h ;
      cout<<"Enter the degree of polynomial  : ";
      cin>>n;
     for(int k=0;k<=n;k++)
    {
            cout<<"\nEnter the Coefficients of polynomial at "<<k<<"th position"<<" : ";
            cin>>coeff[k];
    }      
            
   cout<<"\nEnter the guess point : ";
  cin>>x0;
 
  cout<<"\nEnter the Tolerance limit : ";
  cin>>etol;

  
  if(fabs(f(n,coeff,x0))>etol)
  {
  while(fabs(f(n,coeff,x0))>etol)
{
                                  
         ++i;    
       x1 = x0+h ;
       x2 = x0-h;
      
          x0_val = f(n,coeff,x0);
   x0_val_h = f(n,coeff,x1);
   x2val_h = f(n,coeff,x2);
   
       



    diff =(x0_val_h - x0_val )/h ;
    diff2 = (x0_val_h - 2*x0_val + x2val_h)/(h*h);
       x1 = x0 - 0.5*pow((x0_val/diff),2)*(diff2/diff) - (x0_val/diff) ;  
       x0 = x1;
       
         cout<<"\n"<<"Point    ["<<i<<"]      "<<x0;
      
                             }  
           cout<<"\n"<<"Total Number of Steps Involved  =   "<< i;
           }
           
             else
             
      cout<<"Initial guess incorrect";                                                                    
        getch();
        }                                   
