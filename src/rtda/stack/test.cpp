#include "local_vars.hpp"
#include <iostream>

int main(){
	LocalVars slot(7);

	slot.SetInt(0, 12345);
	std::cout << "int:" << slot.GetInt(0)<<std::endl;

	slot.SetFloat(1, 1.02345789f);
	std::cout << "Float:" << slot.GetFloat(1) << std::endl;

	Object obj;
	slot.SetRef(2, &obj);
	std::cout << "Ref:" << slot.GetRef(2) << std::endl;

	long long a = 0x1234567879013456;
	slot.SetLong(3, a);
	std::cout << "Long:" << slot.GetLong(3) << std::endl;

	double b = 1.223;
	slot.SetDouble(5, b);
	std::cout << "Double:" << slot.GetDouble(5) << std::endl;

	return 0;
}