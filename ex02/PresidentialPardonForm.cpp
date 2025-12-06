#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), _grade("Default Grade")
{
    std::cout << "Default constructor of PresidentialPardonForm called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Default", 25, 5), _target(target)
{
    std::cout << "Constructor of PresidentialPardonForm called." << std::endl;
	if (grade > 150)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (grade < 1)
		throw PresidentialPardonForm::GradeTooHighException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "Copy constructor of PresidentialPardonForm called." << std::endl;

    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "Copy assignment operator of PresidentialPardonForm called." << std::endl;

    if (this != src)
        _target = src.target;

    AForm::=operator(src);

    return *this;
}


std::string &PresidentialPardonForm::getGrade()
{
    return _grade;
}




const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	const char *ex = "Grade is too low.";
    return ex;
}

