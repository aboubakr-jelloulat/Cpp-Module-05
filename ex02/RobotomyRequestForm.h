#pragma once

#include "AForm.h"

class RobotomyRequestForm : public AForm
{
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

};
