#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    PresidentialPardonForm();

    std::string _target;

public:

    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    virtual ~PresidentialPardonForm();

    const std::string &getTarget() const;

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
