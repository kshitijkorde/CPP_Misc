#include<bits/stdc++.h>
using namespace std;

/* [] <- Capture List
   () <- ArgumentList
   {} <- Body of the function
*/

int main(){
	
	// A simple lambda 
	auto sayHi = [](){
		cout << "Hi there" << endl;
	};
	sayHi();

	// Lambda with function parameters, the return type specification "-> int" is optional
	auto addNum = [](int a, int b) -> int {
		return a+b;
	};
	cout << addNum(39, 25) << endl;

	/* By default, no outside variables can be used inside the body of the lambda, hence we have the capture list.
     * Variables can be caputred by their names in the comma seperated capture list */

	int x = 100;
	int y = 200;
    // Note 'x' is read only inside the body of the lambda since it is passed by value, to modify it
    // pass 'x' by reference in the capute list like &x
	auto addNum_WithXY = [x, &y](int a, int b) -> int {
		//x = x + 100;
		y = y + 200;
		return a + b + x + y;
	};
	cout << addNum_WithXY(200, 5) << endl;
		
	// [=] tells the compiler to add the variable non local to lambda from outside by value, they cannot be modified from inside
	// [&] tells the compiler to add the variable non local to lambda from outside by reference so that they can be modifited from inside
	/* Mix and Match 
       [&, y] capture all by reference but 'y' by value (so that y becomes non modifiable from inside.
	   [=, &y] caputre everything by value but 'y' by reference so that it is modifiable from inside.
	*/
	auto addNum_AllVar = [=](int a, int b) -> int {
		return a + b + x + y;
	};

	cout << addNum_AllVar(1,1) << endl;

	/* Real Life useful example with lambda funciton and for_each loop
	   Similary it can be used for the sort function
	 */ 
	vector<int> arr = {1, 2, 4, 5, 8};
	int total = 0;
	for_each(begin(arr), end(arr), [&](int x){
			total += x;
			}
	);
	cout << "Total:" << total << endl;
		
	return 0;
}
