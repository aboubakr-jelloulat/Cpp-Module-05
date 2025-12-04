#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	std::cout << "\n\t**\t**\t**\n" << std::endl;

	try
	{
		Bureaucrat b1("ajelloul", 1);
		Form wati9a("Wati9at isti9lal", 1, 1);
		b1.signForm(wati9a);
	}
	catch (std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}
	
	std::cout << "\n\t**\t**\t**\n" << std::endl;
	
	try
	{
		Bureaucrat b2("borz", 100);
		Bureaucrat b3(b2);

		Form frm1("mo3ahadat soleh", 1, 2);
		frm1.beSigned(b2);
	}
	catch (std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}


	std::cout << "\n\t**\t**\t**\n" << std::endl;

	try
	{
		Bureaucrat b2("lbob", 1);
		Bureaucrat b3;

		b3 = b2;

		Form frm2("mo3ahadat lalla meghnia", 1, 1);
		frm2.beSigned(b3);
		
		b3.signForm(frm2);
		
	}
	catch (std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}


	return (0);
}