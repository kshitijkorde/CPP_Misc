#include<bits/stdc++.h>
using namespace std;

// lvalue: - An object that occupies some identifiable location in memory
// rvalue: - Any object that is not lvalue

int square(int & x)  { cout << "lvalue reference" << endl; return x*x; }  
int square(int && x) { cout << "rvalue reference" << endl; return x*x; } // Since C++ 11

class String{
private:
public:
	int m_len;
	char * m_pbuff;

	String(){
		m_pbuff = NULL;
	}

	String(const String & sobj){
		cout << "Invoking Copy Constructor Lvalue ref" << endl;
		m_len = sobj.m_len;
		m_pbuff = new char[m_len+1];
		strcpy(m_pbuff, sobj.m_pbuff);
		m_pbuff[m_len] = '\0'; 
	}
	// Move constructor
	String(String && sobj) : m_len(0), m_pbuff(nullptr){ 
		cout << "Invoking Copy Constructor for Rvalue Referencing" << endl;
		swap(sobj);
	}

	void swap(String & sobj){
		std::swap(m_pbuff, sobj.m_pbuff);
		std::swap(m_len, sobj.m_len);
	}

	// Instead of writing the below 2 assignment operators we can write a unified assignment operator
    // that takes the parameter by value and makes use of "copy and swap" idiom
	// String& operator=(const String& sobj)
	// String& operator=(String && sobj)

	// 'Copy and Swap' idiom based assignment operator //
	String& operator=(String sobj){
		cout << "Invoking overloaded assignment operator" << endl;
		swap(sobj);
		return *this;
	}

	~String(){
		cout << "Invoking Destructor ..." << endl;
		delete [] m_pbuff;
	}
};

String create_string(int && x){

	String S;
	S.m_len = x;
	S.m_pbuff = new char[S.m_len+1];
	for(int i=0; i<S.m_len; i++){
		S.m_pbuff[i] = 'A'+i;
	}
	S.m_pbuff[S.m_len] = '\0';
	cout << "Created string " << S.m_pbuff << endl;
	return S;
}

void display_string(String & S){

	cout << "[" << S.m_pbuff << "]" << endl;
}

int main(){

	int x = 10;
	cout << square(x) << endl;  			   // LVALUE : square(int & x)
	cout << square(20) << endl; 			   // RVALUE : square(int && x)
	
	String reusable = move(create_string(8));  // RVALUE : String(String && sobj)

	String next(reusable); 					   // LVALUE : String(const String & sobj) 

	display_string(reusable);
	display_string(next);

	String tmp(move(create_string(4))); 	   // RVALUE : String(String && sobj)

	String latest(move(tmp)); 				   // RVALUE : String(String && sobj) 

	display_string(latest);
	// display_string(tmp);   // << Note tmp shouldn't be refered again after move(tmp) which has converted LValue tmp into RValue
                           // Doing so can cause inexplicable behavior

	String xyz;
	xyz = reusable;
	cout << "XYZ:";
	display_string(xyz);

	return 0;
}
