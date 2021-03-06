/*
merge 3 arrays

TODO: should implement with vector
	
*/

#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
// Main function for the program
int main( )
{
	/********************************simple array example************************/
	int a[] = {3,10,0,16,33};
	int asize = sizeof(a)/sizeof(a[0]);
	
	int b[] = {4,5,7,10};
	int bsize = sizeof(b)/sizeof(b[0]);
	
	int c[] = {22,11,678};
	int csize = sizeof(c)/sizeof(c[0]);
	
	int newsize = asize + bsize + csize;
	int d[newsize];
	
	unsigned int i;
	for(i = 0; i<asize; i++){
		d[i] = a[i];
		cout << a[i] << ",";	
	}
	cout << "\n";	
	unsigned int x = i;
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
	
	/*******************************STL vector example**************************/
		
	vector<int> V;
	V.insert(V.begin(), 3);
	assert(V.size() == 1 && V.capacity() >= 1 && V[0] == 3);
	
	vector<int> firstVect;                                // empty vector of ints
	vector<int> secondVect (4,100);                       // four ints with value 100
	vector<int> thirdVect (secondVect.begin(),secondVect.end());  // iterating through second
	vector<int> fourthVect (thirdVect);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	vector<int> fifthVect (myints, myints + sizeof(myints) / sizeof(int) );

	cout << "The contents of fifthVect are:";
	for (vector<int>::iterator it = fifthVect.begin(); it != fifthVect.end(); ++it)
	cout << ' ' << *it;
	cout << '\n';
	
	cout << "woof!" << endl;
	cout << "woof!" << endl;
	cout << "woof!" << endl;
	cout << "woof! and Meow!" << endl;
        cout << "I don't know why I have all these couts here..." << endl;
	
   return 0;
}
