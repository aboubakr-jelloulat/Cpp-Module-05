#pragma once

#include <iostream>

// #include"Bureaucrat.h"
class Bureaucrat;

class AForm
{
	const std::string	_name;
	bool				_is_signed;
	const int			_grade_required_to_sign;
	const int			_grade_required_to_execute;

public:
	AForm();
	AForm(const std::string &name, int gd_required_to_sign, int gd_required_to_execute);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

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

	struct FormNotSignedException : public std::exception
	{
		const char *what() const throw();
	};


	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getGradeRequiredToSign() const;
	int					getGradeRequiredToExecute() const;


	void	beSigned(const Bureaucrat &bureaucrat);

	void check(int excutor_grade) const;

    virtual void execute(const Bureaucrat &executor) const = 0;
	virtual const std::string &getTarget() const = 0;

};


std::ostream &operator<<(std::ostream &ss, const AForm &frm);
