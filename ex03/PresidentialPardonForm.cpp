#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
    std::cout << "Default constructor of PresidentialPardonForm called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Constructor of PresidentialPardonForm called." << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "Copy constructor of PresidentialPardonForm called." << std::endl;

    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "Copy assignment operator of PresidentialPardonForm called." << std::endl;

    if (this != &src)
        _target = src._target;

    AForm::operator=(src);

    return *this;
}


const std::string &PresidentialPardonForm::getTarget() const
{
    return _target;
}


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	check(executor.getGrade());

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}




PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor of PresidentialPardonForm called." << std::endl;
}
