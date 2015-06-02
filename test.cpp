#include <string>
#include <iostream>
#include "mtypemap.hpp"

void add_str_2(bx::mtypemap<std::string> &m){
	std::string a;
	a = "woo!";
	m.set<std::string>("str2", a);
}

int main(){
	bx::mtypemap<std::string> m;

	m.set<int>("num1", 1);
	m.set<float>("num2", 2);
	m.set<std::string>("str1", "yay");
	add_str_2(m);

	std::cout << "num1: " << m.get<int>("num1") << std::endl;
	std::cout << "num2: " << m.get<float>("num2") << std::endl;
	std::cout << "str1: " << m.get<std::string>("str1") << std::endl;
	std::cout << "str2: " << m.get<std::string>("str2") << std::endl;


	return 0;
}
