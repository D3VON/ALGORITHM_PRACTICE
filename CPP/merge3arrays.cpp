/*
merge 3 arrays

TODO: should implement with vector
	
*/

#include <iostream>
 
using namespace std;
// Main function for the program
int main( )
{
	int a[] = {3,10,0,16,33};
	int asize = sizeof(a)/sizeof(a[0]);
	
	int b[] = {4,5,7,10};
	int bsize = sizeof(b)/sizeof(b[0]);
	
	int c[] = {22,11,678};
	int csize = sizeof(c)/sizeof(c[0]);
	
	int newsize = asize + bsize + csize;
	int d[newsize];
	
	int i;
	for(i = 0; i<asize; i++){
		d[i] = a[i];
		cout << a[i] << ",";	
	}
	cout << "\n";	
	int x = i;
	for(i = 0; i<bsize; i++){
		d[x++] = b[i];
		cout << b[i] << ",";	
	}
	cout << "\n";
	for(i = 0; i<csize; i++){
		d[x++] = c[i];
		cout << c[i] << ",";	
	}
	cout << "\n";
	for(i = 0; i<newsize; i++){
		cout << d[i] << ",";	
	}
	cout << "\n";
	

	
   return 0;
}