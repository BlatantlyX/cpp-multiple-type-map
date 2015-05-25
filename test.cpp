#include <string>
#include <iostream>
#include "mtypemap.hpp"

int main(){
	bx::mtypemap m;

	m.set<int>("num1", 1);
	m.set<float>("num2", 2);
	m.set<std::string>("str", "yay");

	std::cout << "num1: " << m.get<int>("num1") << std::endl;
	std::cout << "num2: " << m.get<float>("num2") << std::endl;
	std::cout << "str: " << m.get<std::string>("str") << std::endl;



	return 0;
}
