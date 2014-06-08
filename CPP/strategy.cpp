/* strategy.cpp
 *
 * strategy pattern example
 * This is swiped from wikipedia.  The original example was in Java, but
 * for practice I refactored it into C++.
 * 
 * To compile:
 * $ g++ strategy.cpp -o strategy
 * 
 * To run with valgrind:
 * $ valgrind --leak-check=full ./strategy
 * 
 * .....modify data inside program for other testing scenarios.
 * (no commandline arguments handled)
 */

#include <cstdio>

/*
 * Base class for concrete Strategies to be implemented.
 */
class  Strategy {
	public:
		Strategy(){}
		~Strategy(){
			printf("~Strategy is called\n");
		}
		virtual int execute(int a, int b){ 
			printf("Called the base class. :^(\n"); 
		}// = 0; // pure virtual when no body and = null. 
};
 
/* Implements the algorithm using the Strategy base class */
class Add: public Strategy {
    public: 
		Add(){}
		int execute(int a, int b) {
			printf("Called Add's execute()\n");
			return a + b;  // Do an addition with a and b
		}
		~Add(){
			printf("~Add is called\n");
		}
};
 
class Subtract: public Strategy {
    public: 
		Subtract(){}
		int execute(int a, int b) {
			printf("Called Subtract's execute()\n");
			return a - b;  // Do a subtraction with a and b
		}
		~Subtract(){
			printf("~Subtract is called\n");
		}
};
 
class Multiply: public Strategy {
    public: 
		Multiply(){}
		int execute(int a, int b) {
			printf("Called Multiply's execute()\n");
			return a * b;   // Do a multiplication with a and b
		}    
		~Multiply(){
			printf("~Multiply is called\n");
		}
};
 
class Context {
    private:
		Strategy * strategy;
 
    public: 
		Context(Strategy * s) {
			strategy = s;
		}
		~Context(){
			printf("~Context is called\n");
			delete strategy;
		}
		int executeStrategy(int a, int b) {
			return strategy->execute(a, b);
		}
};
 
/* Test run the strategy pattern */
int main() {
    Context * context;
	
	// use a strategy child object directly
	Strategy * a = new Add();
	int resultA = a->execute(3,4);//context->executeStrategy(3,4);
	delete a; // this did something good.
 
    // Two contexts following different strategies
    context = new Context(new Subtract());
    int resultB = context->executeStrategy(3,4);
	delete context; // this did something good.
	
    context = new Context(new Multiply());
    int resultC = context->executeStrategy(3,4);
	delete context; // this did something good.

    printf("Result A : %d\n", resultA);
    printf("Result B : %d\n", resultB);
    printf("Result C : %d\n", resultC);
    return 0;
}

/*
// a 'simpler' version of the above program
#include <cstdio>
class P { 
public: 
void doit(){ printf("parent :^p\n");} 
};
class CHILD1: public P { 
public: 
void doit(){ printf("child 1\n");} 
};
class CHILD2: public P { 
public: 
void doit(){ printf("child 2\n");} 
};
class X { 
public:
P * p;
X(P * p_in){ p = p_in;}
void execDo(){ p->doit(); }
};
int main(){
	X * x;
	x = new X(new CHILD1());
	printf("Print 'child 1'\n");
	x->execDo();
	
	x = new X(new CHILD2());
	printf("Print 'child 2'\n");
	x->execDo();
}
*/
