#include <iostream>
#include <iomanip>


using namespace std;

double calcAvg( double array[ ], int N );

int main ()


{
    
    
   
    
    
    
    
    
    
    
    
    
    
  //  int AR[4] = {2, 4, 6, 8};
  //  int temp;
  //  temp = AR[0] ;
   // AR[0]=AR[3];
   // AR[3]=temp;
    
  //  for (int i = 0; i < 4; i++)
        
        
        
 //   {
       

 //       cout << AR[i] << endl;
  //  }
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

double calcAvg( double array[ ], int N )
{
double sum = 0.0;
for( int sub = 0; sub < N; sub++ )
{
sum = sum + array[sub];
}
return sum / N;
}
