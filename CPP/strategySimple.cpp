#include <cstdio>
class P { 
public: 
// without 'virtual', this won't 
virtual void doit(){ printf("parent :^p\n");} 
};
class CHILD1: public P { 
public: 
void doit(){ printf("child 1\n");} 
};
class CHILD1a: public CHILD1 { // this is a grandchild of P
public: 
void doit(){ printf("child 1a\n");} 
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
	
	x = new X(new CHILD1a());
	printf("Print 'child 1a'\n");
	x->execDo();
}