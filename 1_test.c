#include<stdio.h>

# define swap(a,b) temp=a; a=b; b=temp;
main( )
{
int i, j, temp;
i=5;
j=10;
temp=0;
if( i > j)
swap( i, j );
printf( "%d %d %d", i, j, temp);
}
