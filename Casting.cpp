#include<bits/stdc++.h>
using namespace std;

class Base
{ 
	virtual void func(){}
};

class Derived1 : public Base
{ 
public:
	int d1_data; 
	Derived1(){
		d1_data = 10;
	}
};

class Derived2 : public Base
{
public:
	int d2_data; 
	Derived2(){
		d2_data = 20;
	}
};

int main(){

	Derived1 d1;
	Base * ptr_Base = &d1;

	/*
	- No run-time check is made to check the safety of the conversion
	- Any conversions which compiler performs implicitly can be made explicit using static_cast
	*/
	Derived2 * ptr_Derived2 = static_cast<Derived2*>(ptr_Base);
	cout << ptr_Derived2->d2_data << endl;  // <= prints 10, which is the incorrect value

	/* The dynamic_cast is used for safe casting from a base class pointer to a derived class. 
	- If is often refered to as safe down-casting
	- Failure of a dynamic_cast results in value NULL which gets assigned to ptr_Derived2
	*/
	ptr_Derived2 = dynamic_cast<Derived2*>(ptr_Base);
	if(ptr_Derived2){
		cout << ptr_Derived2->d2_data << endl;
	} else {
		cout << "ptr_Derived2 is null" << endl;
	}
	
	return 0;
}
