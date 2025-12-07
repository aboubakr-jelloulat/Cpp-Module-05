#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>


#include"AForm.h"
#include"Bureaucrat.h"
#include"PresidentialPardonForm.h"
#include"RobotomyRequestForm.h"
#include"ShrubberyCreationForm.h"



void	ShrubberyCreationForm_Test()
{
	std::cout <<"\n\t*** not signed ***\n" << std::endl;
	try
	{
		ShrubberyCreationForm frm_sh("sh1");
		Bureaucrat b1("b1", 21);
		frm_sh.execute(b1);
	}
	catch(std::exception &ex)
	{
		assert(std::string(ex.what()) == "Form not signed yet");
	}

	std::cout <<"\n\t*** couldn't sign ShrubberyCreationForm  ***\n" << std::endl;
	try
	{
		ShrubberyCreationForm frm_sh2("sh2");
		Bureaucrat b2("b2", 145);
		b2.signForm(frm_sh2);
		frm_sh2.execute(b2);
	}
	catch(std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}

	std::cout <<"\n\t*** LeRoi sign ShrubberyCreationForm  ***\n" << std::endl;
	try
	{
		ShrubberyCreationForm frm_sh3("le Roi");
		Bureaucrat LeRoi("LeRoi", 2);
		LeRoi.signForm(frm_sh3);
		frm_sh3.execute(LeRoi);
	}
	catch(std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}
}



void	RobotomyRequestForm_Test()
{
	std::cout <<"\n\t*** lmalik signed/exec RobotomyRequestForm  ***\n" << std::endl;
	try
	{
		RobotomyRequestForm frm_robo("robo_frm");
		Bureaucrat king("lmalik", 1);
		king.signForm(frm_robo);
		frm_robo.execute(king);
	}
	catch(std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}

}


void	PresidentialPardonForm_Test()
{
	std::cout <<"\n\t*** lmalik signed/exec RobotomyRequestForm  ***\n" << std::endl;
	try
	{
		PresidentialPardonForm President_frm("PRESIDENCE_FORM");
		Bureaucrat b1("ajelloul", 1);
		Bureaucrat b2(b1);

		assert(b2.getName() == "ajelloul");

		b2.signForm(President_frm);
		President_frm.execute(b2);
	}
	catch(std::exception &ex)
	{
		std::cerr << "\nException: " << ex.what() << std::endl;
	}


}




int main()
{
	srand(time(NULL));
	
	ShrubberyCreationForm_Test();

	RobotomyRequestForm_Test();

	PresidentialPardonForm_Test();

	return 0;
}


