// Maths Expression Evaluation Example
// Alex Healion

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char* getExpression(int &length)
{
	string exp, expression;
	cout<<"Please enter a mathematical expression (valid characters are "
	<<"unsigned integers, parentheses and the operators +,-,*,/): ";
	
	getline(cin,exp);												// Take in expression
	int len = exp.length();
	int brCount = 0;
	for(int i = 0; i < len; i++)									// Cycle through characters
	{
		if(isspace(exp[i]))
		{
			// Do nothing
		}
		else if((exp[i]>='0'&&exp[i]<='9') ||exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')	// Checks for valid tokens other than brackets
		{
			expression.insert(expression.end(),exp[i]);
		}
		else if(exp[i]=='('||exp[i]==')')							// Checks for even number of brackets
		{
			expression.insert(expression.end(),exp[i]);
			if(exp[i] == '(')
				brCount++;
			else if(exp[i] == ')')
				brCount--;
		}
		else														// Returns error if an invalid character
		{
			cout<<"Error - Invalid character...\n";
			while(1){};
		}
	}
	if(brCount != 0)												// Returns error if uneven number of brackets
	{
		cout<<"Error - Uneven parentheses";
		while(1){};
	}
	
	length = expression.length();
	return &expression[0];											// Returns address of first element of character array holding the expression
}

int getResult()														// Gets expected result from user
{
	int result;
	cout<<"\nPlease enter expression result to evaluate: ";
	cin>>result;
	return result;
}

int calcExpression(const char *expression, const int len)			// Calculates result of expression
{
	int res{0}, temp{0};
	char op = '+';
	for(int i = 0; i < len; i++)									// Evaluates from left to right
	{
		if(expression[i] >= '0' && expression[i] <= '9')			// If number value
		{
			if(expression[i+1] >= '0' && expression[i+1] <= '9')	// Check if two digit value
			{
				temp = 10*(expression[i] - '0')+(expression[i+1] - '0');
				i++;
			}
			else
			{
				temp = (expression[i] - '0');						// Set temp to value
			}
			
			switch(op)												// Carry out operation on above operand and set as result
			{
				case '+':
					res = res + temp;
					break;
				case '-':
					res = res - temp;
					break;
				case '*':
					res = res * temp;
					break;
				case '/':
					res = res / temp;
					break;				
			}
		}
		else if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/')
		{															// If operator, update op char 
			op = expression[i];
		}
		else if(expression[i] == '(')								// If open bracket, pass contents of bracket to recursive calc for calculation
		{
			string e;
			int l = len-i;
			int bCount = 0;
			for(int j = 0; j < l; j++)								// Creation of new expression containing only bracket contents
			{
				e[j] = expression[i+j+1];
				if(e[j] == '(')										// Ensures that right bracket is correct right bracket
					bCount++;
				if(e[j] == ')')
				{
					bCount--;
					if(bCount == -1)
					{
						l = j;										// Sets length of new expression
						break;
					}
				}
			}
			temp = calcExpression(&e[0],l);							// Passing to calc
			i = i+l+1;												// Moving forward to end of brackets
			
			switch(op)												// Carries out operation with new temp value from brackets
			{
				case '+':
					res = res + temp;
					break;
				case '-':
					res = res - temp;
					break;
				case '*':
					res = res * temp;
					break;
				case '/':
					res = res / temp;
					break;				
			}
		}
		else if(expression[i] == ')')								// Closing brackets are handled by opening bracket handler
		{
			break;
		}
	}
	return res;
}

bool evaluate(const char *expression, int result, const int length)	// Evaluate function which takes in an expression, the expected result, and the length
{
	int res = calcExpression(expression,length);					// Calls calculation function
	return (res == result);
}


int main()
{
	int length{0}, result{0};
	char *expression = getExpression(length);						// Gets expression
	for(int i = 0; i < length; i++)									// Prints expression (with spaces removed)
	{
		cout<<expression[i];
	}
	
	result = getResult();											// Asks for the result
	
	bool ans = evaluate(expression, result, length);				// Calls the evaluation function and is returned true or false
	if(ans == 1)
		cout<<"Result is correct";
	else if(ans == 0)
		cout<<"Result is incorrect";
	
	return 0;
}



