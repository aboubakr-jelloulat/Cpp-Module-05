#include <iostream>
#include <cassert>

#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"

int main(void)
{
	{
		try
		{
			Intern it;

			AForm *frm1 = it.makeForm("PresidentialPardonForm", "ajelloul");

			std::cout << "Name : " << frm1->getName() << std::endl;
			std::cout << "Target : " << frm1->getTarget() << std::endl;

			Bureaucrat b1("b1", 1);

			b1.signForm(*frm1);
			b1.executeForm(*frm1);

			delete frm1;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n\n";

	{
		try
		{
			Intern it;
			AForm *frm = it.makeForm("ShrubberyCreationForm", "hej");

			assert(frm->getName() == "ShrubberyCreationForm");
			assert(frm->getTarget() == "hej");

			Bureaucrat b("lmodir", 5);

			b.signForm(*frm);
			frm->execute(b);

			delete frm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

	}

	system("leaks -q intern");

	return 0;
}
