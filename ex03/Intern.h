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
	
	
	// factory design pattern
	// a technique used to create objects dynamically based on some input (a string in this case)
	struct FormType
	{
		std::string name;
		AForm* (*creator)(const std::string &);
	};

	/*
		AForm *	Function returns a pointer to AForm
		(*creator)	creator is a pointer to a function
		(const std::string &)	The function takes a reference to a string as parameter
	
	*/

};
