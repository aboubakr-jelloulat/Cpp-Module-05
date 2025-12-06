#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    PresidentialPardonForm();

    std::string _target;

public:

    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    virtual ~PresidentialPardonForm();

    std::string &getTarget();

    void execute(const Bureaucrat &executor) const;


    struct GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

};
