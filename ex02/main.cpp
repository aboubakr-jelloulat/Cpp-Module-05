#include <iostream>
#include <fstream>
#include <sstream>


#include"AForm.h"
#include"Bureaucrat.h"
#include"PresidentialPardonForm.h"
#include"RobotomyRequestForm.h"
#include"ShrubberyCreationForm.h"



void	ShrubberyCreationForm_Test()
{
	try
	{
		ShrubberyCreationForm frm_sh("sh1");
		Bureaucrat b1("b1", 21);
		frm_sh.execute(b1);

		
	}
	catch(std::exception &ex)
	{
		assert(ex.what() == "Form not signed yet");
	}

}

int main()
{
	ShrubberyCreationForm_Test();


	return 0;
}


// void	RobotomyRequestForm_Test()
// {

// }


// void	PresidentialPardonForm_Test()
// {

// }






