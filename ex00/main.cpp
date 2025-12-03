#include "Bureaucrat.h"


int main()
{
	try
	{
		Bureaucrat b1("ajelloul", 2);
		std::cout << b1 << std::endl;

		b1.increment();
		std::cout << b1 << std::endl;

		b1.increment();
		std::cout << b1 << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}

	std::cout << "\n\t**\t**\t**\n" << std::endl;

	try
	{
		Bureaucrat b2("maddou", 149);
		Bureaucrat b3(b2);
		std::cout << b3 << std::endl;

		b3.decrement();
		std::cout << b3 << std::endl;
		
		b3.decrement();
		std::cout << b3 << std::endl;
	}
	catch(std::exception& ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}
	
    return 0;
}
