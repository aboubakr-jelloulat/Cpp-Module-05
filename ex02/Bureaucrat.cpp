#include "Bureaucrat.h"
#include "AForm.h"


Bureaucrat::Bureaucrat() : _name("Borz"), _grade(150)
{
    std::cout << "Default constructor of Bureaucrat called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade)
{
    std::cout << "Constructor of Bureaucrat called." << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Copy constructor of Bureaucrat called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Copy assignment operator of Bureaucrat called." << std::endl;

    if (this != &src)
	{
        this->_grade = src._grade;
	}
    
    return *this; 
}


const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}


void Bureaucrat::increment() // ++
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrement() // --
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	const char *ex = "Grade is too low.";
    return ex;
} 


void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << ex.what() << "." << std::endl;
	}

}




Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor of Bureaucrat called." << std::endl;
}


std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	return ostream << "Bureaucrat "
		<< bureaucrat.getName()
		<< " grade " << bureaucrat.getGrade() << ".";
}

