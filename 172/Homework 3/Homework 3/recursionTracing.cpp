#include <iostream>
#include <string>
using namespace std;


int GCD( int m, int n );

int main(void)
{

  GCD(212,-371);


  return 0;
}




int GCD( int m, int n )
{
  cout<<"M: " <<m<<endl;
  cout<<"N: " <<n<<endl;
  if ( m == 0 )
    return 0 ;
  else if ( m < 0 )
    return GCD( -m, n ) ;
  else if ( m > n )
    return GCD( n, m ) ;
  else if ( m == n )
    return m ;
  else
    return GCD( n - m, m ) ;
}



/* ------------ OUTPUT ---------------
M: 212
N: -371
M: -371
N: 212
M: 371
N: 212
M: 212
N: 371
M: 159
N: 212
M: 53
N: 159
M: 106
N: 53
M: 53
N: 106
M: 53
N: 53
 -----------------------------------*/
