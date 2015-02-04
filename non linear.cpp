#include "iostream"
#include <stdio.h>
#include "conio.h"
#include "math.h"

# define f(x,y,z) 10*x+sin(x+y)-1
# define g(x,y,z) 8*y-pow(cos(z-y),2)-1
# define h(x,y,z) 12*z+sin(z)-1

# define diff_f_x(x,y,z) 10+cos(x+y)
# define diff_f_y(x,y,z) cos(x+y)
# define diff_f_z(x,y,z) 0

# define diff_g_x(x,y,z) 0
# define diff_g_y(x,y,z) 8-sin(2*(z-y))
# define diff_g_z(x,y,z) sin(2*(z-y))

# define diff_h_x(x,y,z) 0
# define diff_h_y(x,y,z) 0
# define diff_h_z(x,y,z) 12+cos(z)



using namespace std;

main()
{    char g[50];

      double tol,i,j , ;
      double x0,y0,h = 0.000001,x_h,y_h, z0 ;
      
      float x1, y1, z1;
      float Jac[3][3],F[3][1],x_k1[3][1],Jac_inv[3][3],inv_det, sum[3][1];
      
       cout<<"Enter the initial points x0, y0 and z0  : \n \t \t";
      cin>>x0>>y0>>z0;
       cout<<"\nEnter the Tolerance limit : ";
        cin>>tol;
      
  
     while(fabs(f(x0,y0,z0))>tol && fabs(g(x0,y0,z0))>tol && fabs(h(x0,y0,z0))>tol)
      {
      
      Jac[0][0] = diff_f_x(x0,y0,z0);
      Jac[0][1] = diff_f_y(x0,y0,z0);
      Jac[0][2] = diff_f_z(x0,y0,z0);
      
      Jac[1][0] = diff_g_x(x0,y0,z0);
      Jac[1][1] = diff_g_y(x0,y0,z0);
      Jac[1][2] = diff_g_z(x0,y0,z0);
      
      Jac[2][0] = diff_h_x(x0,y0,z0);
      Jac[2][1] = diff_h_y(x0,y0,z0);
      Jac[2][2] = diff_h_z(x0,y0,z0);
      
      double det = Jac[0][0] * (Jac[1][1] * Jac[2][2] - Jac[2][1] * Jac[1][2]) -
             Jac[0][1] * (Jac[1][0] * Jac[2][2] - Jac[1][2] * Jac[2][0]) +
             Jac[0][2] * (Jac[1][0] * Jac[2][1] - Jac[1][1] * Jac[2][0]);
             inv_det = 1/det;
    


   
    
Jac_inv[0][0] = (Jac[1][1] * Jac[2][2] - Jac[2][1] * Jac[1][2]) * inv_det;
Jac_inv[0][1] = (Jac[0][2] * Jac[2][1] - Jac[0][1] * Jac[2][2]) * inv_det;
Jac_inv[0][2] = (Jac[0][1] * Jac[1][2] - Jac[0][2] * Jac[1][1]) * inv_det;
Jac_inv[1][0] = (Jac[1][0] * Jac[2][2] - Jac[1][2] * Jac[2][0]) * inv_det;
Jac_inv[1][1] = (Jac[0][0] * Jac[2][2] - Jac[0][2] * Jac[2][0]) * inv_det;
Jac_inv[1][2] = (Jac[0][0] * Jac[1][2] - Jac[1][0] * Jac[0][2]) * inv_det;
Jac_inv[2][0] = (Jac[1][0] * Jac[2][1] - Jac[2][0] * Jac[1][1]) * inv_det;
Jac_inv[2][1] = (Jac[0][0] * Jac[2][1] - Jac[2][0] * Jac[0][1]) * inv_det;
Jac_inv[2][2] = (Jac[0][0] * Jac[1][1] - Jac[1][0] * Jac[0][1]) * inv_det;

F[0][0] = f(x0,y0,z0);
F[1][0] = g(x0,y0,z0);
F[2][0] = h(x0,y0,z0);

cout<<"\n";
 
 
          for(int i=0;i<3;i++)
      {for(int j=0;j<1;j++)
      {sum[i][j] = 0;
      for(int k=0;k<3;k++)
      {
               
            sum[i][j] = sum[i][j]+Jac_inv[i][k]*F[i][j]; }
               }
               }
              
               
      
     x_k1[0][0] = x0 - sum[0][0] ;  
     x_k1[1][0] = y0 - sum[1][0];
     x_k1[2][0] = z0 - sum[2][0] ;
     
    x1 = x_k1[0][0];
     y1 = x_k1[1][0];
    z1 = x_k1[2][0];
     
     cout<<"\n"<<x1<<"\t"<<y1<<"\t"<<z1;
     
   x0 = x1;
     y0 = y1;
     z0 = z1;
     }  
                 
            getch();
            
} 
