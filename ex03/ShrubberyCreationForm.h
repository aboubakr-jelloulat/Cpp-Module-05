#pragma once

#include "AForm.h"
#include "fstream"
class ShrubberyCreationForm : public AForm
{
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

};
