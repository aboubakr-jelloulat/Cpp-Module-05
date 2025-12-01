#pragma once

#include <iostream>
#include <stdlib.h>

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;
   
    
public :
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    virtual ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void increment();
	void decrement();

    struct GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

};


std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);
