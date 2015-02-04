#include "iostream"
#include <stdio.h>
#include "conio.h"
#include "math.h"
#include <string.h>
# define g(x) (pow(pow(x,3)+16*x-12,0.5))/7
using namespace std;

main()
{    char g[50];
      double tol,i=0, coeff[10],n,diff_g ;
      double x0,x1, len=0,h = 0.000001,act,l,x_h ;
      int t = 0, p=0;
      float r;
        
    cout<<"Enter the initial point  : ";
      cin>>x0;
      x_h = x0+h;
diff_g = (g(x_h)-g(x0))/h;
r = fabs(diff_g);

      if (r>0 && r<1)
      {    
       cout<<"\nEnter the Tolerance limit : ";
  cin>>tol;
  x1 = g(x0);
 cout<<"\n";
       while(fabs(x1-x0)>tol)
          { 
             ++i;
          cout<<x1<<"\n";
            x0 = x1;  
              x1 = g(x0);
              }  
     cout<<"\nThe Total Number Of Steps =  "<<i;
     cout<<"\nThe iterative process is converging to = "<<x0 ;             
              }  
   else
   cout<<"\n g(x) is tending to an infinite loop"  ; 
                       
            getch();
        }    
