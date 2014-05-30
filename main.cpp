/*
 INVESTIGATING QUADRATIC FUNCTIONS
 by Anna Cristina Karingal
 CSCI 135 Assignment 1
 
 Takes a quadratic equation given by the user and:
 
 1. Evaluates the equation at any given point.
 2. Finds the root(s) of the equation, if any.
 3. Finds the point(s) of intersection between the equation and another quadratic equation.
 4. Finds the minimum/maximum of the equation, if any.
 
 Last edited: February 27, 2014
 */

#include <iostream>
#include <math.h>
#include <string>
using namespace std;



//Initialization and command functions
void set(float &a, float &b, float &c);
string command ();

//Math Functions
float eval(float a, float b, float c, float x);
float discrim(float a, float b, float c);
void roots(float a, float b, float c, float &r1, float &r2);
void intersect (float a, float b, float c);
void extreme (float a, float b, float c);



/* MAIN FUNCTION */
int main(){
    
	float a, b, c; //coefficients of f(x)
    
	set(a, b, c); //initial setting of coefficients
    
	string cmd;
	cmd = command(); //receives initial command from user
    
	do {
        
		if (cmd =="set") {
			set(a, b, c);
			cmd = command();
            
		}
		else if (cmd =="eval"){
			float x;
			cout << "Please enter the value of x: ";
			cin >> x;
			cout << "The value of the function at x = " << x << " is " << eval (a,b,c,x) << ".\n";
			cmd = command();
            
		}
		else if (cmd =="roots"){
           float root1, root2;
			roots(a,b,c, root1, root2);
            float d = discrim(a,b,c);
            if (a==0){
                cout << "Your function is linear. Its x-intercept is at x = " << root1 << ".\n";
            }
            else {
                if (d>0){
                    cout << "The function has two real roots.\n";
                    cout << "The roots of your function are at x = " << root1 << " and x = " << root2 << ".\n";
                }
                else if (d==0){
                    cout << "The function has only one real root.\n";
                    cout << "The root of your function is at x = " << root1 << endl;
                }
                else {
                    cout << "Your function has no real roots.\n";
                }
            }
			
            cmd = command();
		}
		else if (cmd =="intersect"){
			intersect(a,b,c);
			cmd = command();
		}
		else if (cmd =="extreme"){
			extreme(a,b,c);
			cmd = command();
		}
		else {
			//In case of unacceptable command
			cout << "Sorry, I did not understand your command.\nPlease enter a new command.\n" << endl;
			cmd = command();
		}
        
	}
	while (cmd != "exit");
    
	
	return 0;
}




/*IMPLEMENTATION OF FUNCTIONS */

//Sets coefficients of the quadratic equation f(x)
void set(float &a, float &b, float &c){
	cout << "Enter the coefficients a, b, and c: ";
	cin >> a >> b >> c;
	cout << "f(x) = " << a << "(x^2) + " << b << "x + " << c << ".\n";
    
}

//Gets command from user
string command(){
	string cmd;
	cout << "\nCOMMAND: ";
	cin >> cmd;
    
	return cmd;
}

//Evaluates quadratic equation f(x) at a point x
float eval(float a, float b, float c, float x){
	float y, xsq;
	xsq = x*x;
	y = (a*xsq) + (b*x) + c;
    
	return y;
    
}

// Calcuates the value of the discriminant
float discrim(float a, float b, float c){
	float d;
	d = (b*b)-(4*a*c);
    
	return d;
}

//Evaluates the roots of the quadratic equation f(x)
void roots(float a, float b, float c, float &r1, float &r2){
    
    r1 = 0;
    r2 = 0;
	
	if (a == 0){ //if the equation f(x) is linear
		r1 = (-c)/b;
	}
	else { //if the equation f(x) is not linear, i.e. a != 0
        
		float d;
		d = discrim(a,b,c);
        
		//Determine whether the function f(x) has 0, 1, or 2 roots using the discriminant
		if (d > 0){
			//Finds the two roots of f(x)
            r1 = (-b + sqrt(d))/(2*a);
			r2 = (-b - sqrt(d))/(2*a);
		}
		else if (d == 0){
			//Finds the single root of f(x)
			r1 = (-b)/(2*a);
		}
		else { }
	}
}

//Evaluates intersection between the supplied quadratic equation f(x) & another quadratic equation g(x)
void intersect (float a, float b, float c){
    
	//Gets the coefficient of the second polynomial g(x)
	float a2,b2,c2;
	cout << "Enter the coefficients a, b and c of the second function: ";
	cin >> a2 >> b2 >> c2;
    
	//Finds the coefficients of h(x), the result of the difference between f(x) and g(x)
	float a3,b3,c3;
	a3 = a-a2;
	b3 = b-b2;
	c3 = c-c2;
    
	float d;
	d = discrim(a3,b3,c3); //Finds the discriminant of h(x)
    
	//Finds the roots of h(x) using the discriminant
	//The roots of h(x) are the same points where f(x) and g(x) intersect
    float x1, x2;
	roots(a3,b3,c3, x1, x2);
    if (a3==0){
        cout << "The two functions intersect at x = " << x1 << ".\n";
    }
    else {
        if (d>0){
            cout << "The two functions intersect at x = " << x1 << " and x = " << x2 << ".\n";
        }
        else if (d==0){
            cout << "The two functions intersect at" << x1 << endl;
        }
        else {
            cout << "The two functions do not intersect.\n";
        }
    }
}

void extreme (float a, float b, float c){
    
	float v;
	v = (-b)/(2*a); //Calculates the value of x at the vertex
    
	//Determines whether vertex is a minimum or maximum depending on the value of a
	if (a > 0){
		cout << "The function has a minimum.\n";
		cout << "Its located at x = " << v << ". The value of the function at this point is " << eval(a,b,c,v) << ".\n";
	}
	else if (a < 0){
		cout << "The function has a maximum.\n";
		cout << "Its located at x = " << v << ". The value of the function at this point is " << eval(a,b,c,v) << ".\n";
	}
	else {
		cout << "There is no extreme value for this function.\n";
	}
    
}





