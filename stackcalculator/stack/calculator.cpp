#include"calculator.h"
#include<string>

int calculator() {
	ListStack<double> number;
	ListStack<char> numb;
	ListStack<char> stack_operator;
	system("cls");
	char input = 0;
	int digit = 0;
	bool power = false;
	bool errer = false;
	bool size = true;
	bool point = false;
	number.push_front(0);
	std::cout << "输入中缀表达式，输入e结束输入" << std::endl;
	std::cin >> input;
	char befo = 0;
	while (input != 'e') {
		if (size&&input == '-') {
			stack_operator.push_front('-');
			befo = input;
			std::cin >> input;
			continue;
		}
		size = false;
		if (input >= '0'&&input <= '9') {
			numb.push_front(input);
			digit++;
		}
		else {
			if (befo == '.' || befo == '^' || befo == '+' || befo == '-' || befo == '*' || befo == '/' || befo == '%') {
				if (input == '.' || input == '^' || input == '+' || input == '-' || input == '*' || input == '/' || input == '%' || input == ')') {
					errer = true;
				}
			}
			else if (befo == '(') {
				if (input == '.' || input == '^' || input == '*' || input == '/' || input == '%') {
					errer = true;
				}
			}
			else if (befo == ')') {
				if (input == '.' || input == '^' || input == '(') {
					errer = true;
				}
			}
				if (!numb.empty()) {
					double numbr = 0;
					numbr = 0;
					for (int i = 0; i < digit; i++) {
						char get;
						numb.front(get);
						numbr += (get - '0')*pow(10, i);
						numb.pop_front();
					}
					if (power) {
						double a = 0, b = 1;
						number.front(a);
						number.pop_front();
						b = pow(a, numbr);
						number.push_front(b);
						power = false;
					}
					else if (point) {
						numbr = numbr * pow(10, -digit);
						double a = 0;
						number.front(a);
						number.pop_front();
						number.push_front(a + numbr);
						point = false;
					}
					else {
						number.push_front(numbr);
					}
					digit = 0;
				}
				if (input == '(') {
					number.push_front(0);
					stack_operator.push_front(input);
				}
				else if (input == ')') {
					char temp = 0;
					stack_operator.front(temp);
					while (temp != '(') {
						double a, b;
						number.front(a);
						number.pop_front();
						number.front(b);
						number.pop_front();
						switch (temp) {
						case '+': number.push_front(a + b); break;
						case '-': number.push_front(b - a); break;
						case '*': number.push_front(a * b); break;
						case '/': number.push_front(b / a); break;
						case '%': number.push_front((int)b % (int)a);
						}
						stack_operator.pop_front();
						stack_operator.front(temp);
					}
					stack_operator.pop_front();
				}
				else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '%') {
					char top;
					if (stack_operator.front(top)) {
						if (input == '+' || input == '-') {
							while (stack_operator.size() != 0 && top != '(') {
								double a, b;
								number.front(a);
								number.pop_front();
								number.front(b);
								number.pop_front();
								switch (top) {
								case '+': number.push_front(a + b); break;
								case '-': number.push_front(b - a); break;
								case '*': number.push_front(a * b); break;
								case '/': number.push_front(b / a); break;
								case '%': number.push_front((int)b % (int)a);
								}
								stack_operator.pop_front();
								stack_operator.front(top);
							}
							stack_operator.push_front(input);
						}
						else {
							while (stack_operator.size() != 0 && top != '+' && top != '-'&&top != '(') {
								double a, b;
								number.front(a);
								number.pop_front();
								number.front(b);
								number.pop_front();
								switch (top) {
								case '*': number.push_front(a * b); break;
								case '/': number.push_front(b / a); break;
								case '%': number.push_front((int)b % (int)a);
								}
								stack_operator.front(top);
								stack_operator.pop_front();
							}
							stack_operator.push_front(input);
						}
					}
					else {
						stack_operator.push_front(input);
					}
				}
				else if (input == '^') {
					if (power || point) {
						errer = true;
					}
					power = true;
				}
				else if (input == '.') {
					if (power || point) {
						errer = true;
					}
					point = true;

				}
				else if (input == ' ' || input == 'e') {
					continue;
				}
				else {
					errer = true;
				}
		}
		befo = input;
		std::cin >> input;
	}
	if (!numb.empty()) {
		double numbr = 0;
		numbr = 0;
		for (int i = 0; i < digit; i++) {
			char get;
			numb.front(get);
			numbr += (get - '0')*pow(10, i);
			numb.pop_front();
		}
		if (power) {
			double a = 0, b = 1;
			number.front(a);
			number.pop_front();
			b = pow(a, numbr);
			number.push_front(b);
			power = false;
		}
		else if (point) {
			numbr = numbr * pow(10, -digit);
			double a = 0;
			number.front(a);
			number.pop_front();
			number.push_front(a + numbr);
			point = false;
		}
		else {
			number.push_front(numbr);
		}
	}
	char w = 0;
	if (stack_operator.front(w)) {
		while (stack_operator.size() != 0) {
			if (w == '(') {
				errer == true;
			}
			double a, b;
			number.front(a);
			number.pop_front();
			number.front(b);
			number.pop_front();
			switch (w) {
			case '+': number.push_front(a + b); break;
			case '-': number.push_front(b - a); break;
			case '*': number.push_front(a * b); break;
			case '/': number.push_front(b / a); break;
			case '%': number.push_front((int)b % (int)a);
			}
			stack_operator.front(w);
			stack_operator.pop_front();
		}
	}
	if (errer) {
		return -1;
	}
	else {
		double end = 0;
		number.front(end);
		std::cout << end << std::endl;
		system("pause");
		return 0;
	}
}
