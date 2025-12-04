#include "Form.h"
#include"Bureaucrat.h"

Form::Form() : _name("wati9a"), _is_signed(false),
	_grade_required_to_sign(150), _grade_required_to_execute(150)
{
	std::cout << "Default constructor of Form called." << std::endl;
}

Form::Form(const std::string &name, int gd_required_to_sign, int gd_required_to_execute)
	: _name(name), _is_signed(false), _grade_required_to_sign(gd_required_to_sign),
	_grade_required_to_execute(gd_required_to_execute)
{
	std::cout << "Constructor of Form called." << std::endl;

	if (gd_required_to_sign > 150 || gd_required_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (gd_required_to_sign < 1 || gd_required_to_execute < 1)
		throw Form::GradeTooHighException();

}

Form::Form(const Form &src) : _name(src._name), _is_signed(src._is_signed),
	_grade_required_to_sign(src._grade_required_to_sign),
	_grade_required_to_execute(src._grade_required_to_execute)
{
	std::cout << "Copy constructor of Form called." << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Copy assignment operator of Form called." << std::endl;

	if (this != &src)
		this->_is_signed = src._is_signed;
	
	return *this;
}



const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}


const char* Form::FormAlreadySignedException::what() const throw()
{
	return "Form already signed";
}


const std::string	&Form::getName() const
{
	return _name;
}

bool				Form::getIsSigned() const
{
	return _is_signed;
}

int					Form::getGradeRequiredToSign() const
{
	return _grade_required_to_sign;
}

int					Form::getGradeRequiredToExecute() const
{
	return _grade_required_to_execute;
}


void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
		throw Form::FormAlreadySignedException();

	if (bureaucrat.getGrade() > _grade_required_to_sign)
		throw Form::GradeTooLowException();

	this->_is_signed = true;
}


Form::~Form()
{
	std::cout << "Destructor of Form called." << std::endl;
}


std::ostream &operator<<(std::ostream &ss, const Form &form)
{
	return ss << "Form : " << (form.getIsSigned() ? "Signed " : "Unsigned ")
		<< "name " << form.getName() << " required sign grade "
		<< form.getGradeRequiredToSign() << " required execution grade "
		<< form.getGradeRequiredToExecute() << "." << std::endl; 
}
