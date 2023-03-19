#include "RPN.hpp"

#include <iostream>
#include <cstring>
#include <stack>

void	reversePolishNotation(char *expression)
{
	std::stack<int>	operand;
	char			c;
	int				a;
	int				b;
	int				result;
	bool			success = true;

	for(int i = 0; expression[i] && success == true; i++)
	{
		while (expression[i] && expression[i] == ' ')
			i++;
		if (expression[i] == '\0')
			break ;
		c = expression[i];
		
		if (isdigit(c))
			operand.push(c - '0');
		else
		{
			if (operand.size() < 2)
			{
				success = false;
				break ;
			}
			b = operand.top();
			operand.pop();
			a = operand.top();
			operand.pop();
			switch (c)
			{
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
			default:
				success = false;
				break;
			}
			if (success)
				operand.push(result);
		}
	}
	if (success)
		std::cout << "Result: " << operand.top() << "\n";
	else
		std::cout << "Error\n";
}