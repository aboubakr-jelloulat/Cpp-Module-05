#pragma once

#include<iostream>

class AForm;

class Intern
{
	Intern(const std::string force_Orthodox_Form);
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);

public:
	Intern();
	virtual ~Intern();

	AForm *makeForm(const std::string &frmName, const std::string &frmTarget) const;

	struct FormType
	{
		std::string name;
		AForm *(*creator)(const std::string &);
	};

};
