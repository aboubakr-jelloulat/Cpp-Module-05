#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"


Intern::Intern()
{
	std::cout << "Default constructor of Intern called." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor of Intern called." << std::endl;
}

static AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &frmName, const std::string &frmTarget) const
{
	FormType formTypes[3] = 
	{
		{"ShrubberyCreationForm", &createShrubbery},
		{"RobotomyRequestForm", &createRobotomy},
		{"PresidentialPardonForm", &createPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i].name == frmName)
		{
			std::cout << "Intern creates " << frmName << std::endl;
			return formTypes[i].creator(frmTarget);
		}
	}

	std::cerr << "Error: Form ** " << frmName << " ** does not exist" << std::endl;
	return NULL;
}
