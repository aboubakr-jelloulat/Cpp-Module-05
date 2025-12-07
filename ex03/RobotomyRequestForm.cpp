#include "Bureaucrat.h"
#include "RobotomyRequestForm.h"

#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "Default constructor of RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Constructor of RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	std::cout << "Copy constructor of RobotomyRequestForm called." << std::endl;

	*this = src;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "Copy assignment operator of RobotomyRequestForm called." << std::endl;

	AForm::operator=(src);
	if (this != &src)
		_target = src._target;

	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	check(executor.getGrade());

	std::cout << "VRRRRRRR VRRRRRR" << std::endl;

	std::cout << _target << ((rand() % 2 == 0) ? " robotomy succeeded." : " robotomy failed." );
	
	std::cout << std::endl;
	
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor of RobotomyRequestForm called." << std::endl;
}
