#pragma once

#include <iostream>

// #include"Bureaucrat.h"
class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_required_to_sign;
	const int			_grade_required_to_execute;

public:
	Form();
	Form(std::string &name, int gd_required_to_sign, int gd_required_to_execute);
	Form(const Form &src);
	Form &operator=(const Form &src);
	virtual ~Form();

	struct GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	struct FormAlreadySignedException : public std::exception
	{
		const char* what() const throw();
	};


	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getGradeRequiredToSign() const;
	int					getGradeRequiredToExecute() const;


	void	beSigned(const Bureaucrat &bureaucrat);

};


std::ostream &operator<<(std::ostream &ss, const Form &form);
