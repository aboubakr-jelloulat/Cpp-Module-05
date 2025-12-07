#include "AForm.h"
#include"Bureaucrat.h"

AForm::AForm() : _name("wati9a"), _is_signed(false),
	_grade_required_to_sign(150), _grade_required_to_execute(150)
{
	std::cout << "Default constructor of AForm called." << std::endl;
}

AForm::AForm(const std::string &name, int gd_required_to_sign, int gd_required_to_execute)
	: _name(name), _is_signed(false), _grade_required_to_sign(gd_required_to_sign),
	_grade_required_to_execute(gd_required_to_execute)
{
	std::cout << "Constructor of AForm called." << std::endl;

	if (gd_required_to_sign > 150 || gd_required_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (gd_required_to_sign < 1 || gd_required_to_execute < 1)
		throw AForm::GradeTooHighException();

}

AForm::AForm(const AForm &src) : _name(src._name), _is_signed(src._is_signed),
	_grade_required_to_sign(src._grade_required_to_sign),
	_grade_required_to_execute(src._grade_required_to_execute)
{
	std::cout << "Copy constructor of AForm called." << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "Copy assignment operator of AForm called." << std::endl;

	if (this != &src)
		this->_is_signed = src._is_signed;
	
	return *this;
}



const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}


const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed yet";
}

const std::string	&AForm::getName() const
{
	return _name;
}

bool				AForm::getIsSigned() const
{
	return _is_signed;
}

int					AForm::getGradeRequiredToSign() const
{
	return _grade_required_to_sign;
}

int					AForm::getGradeRequiredToExecute() const
{
	return _grade_required_to_execute;
}


void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_is_signed)
		throw AForm::FormAlreadySignedException();

	if (bureaucrat.getGrade() > _grade_required_to_sign)
		throw AForm::GradeTooLowException();

	this->_is_signed = true;
}

void AForm::check(int excutor_grade) const
{
	if (excutor_grade > _grade_required_to_execute)
		throw AForm::GradeTooLowException();
	
	if (!_is_signed)
		throw AForm::FormNotSignedException();
}


AForm::~AForm()
{
	std::cout << "Destructor of AForm called." << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const AForm &frm)
{
	return ss << "Form : " << (frm.getIsSigned() ? "Signed " : "Unsigned ")
		<< "name " << frm.getName() << " required sign grade "
		<< frm.getGradeRequiredToSign() << " required execution grade "
		<< frm.getGradeRequiredToExecute() << "." << std::endl; 
}
