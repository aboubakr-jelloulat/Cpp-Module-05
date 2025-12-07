#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"



ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "Default constructor of ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target)
{
	std::cout << "Constructor of ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cout << "Copy constructor of ShrubberyCreationForm called." << std::endl;

	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "Copy assignment operator of ShrubberyCreationForm called." << std::endl;

	if (this != &src)
		_target = src._target;
	
	AForm::operator=(src);

	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{

	check(executor.getGrade());

	std::string filename = _target + "_shrubbery";
	std::ofstream output_file(filename.c_str());

	if (!output_file.is_open())
	{
		std::cerr << "Error: Could not create file" << std::endl;
		return;
	}

	output_file << "^" << std::endl;
	output_file << "*" << std::endl;

	output_file.close();
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor of ShrubberyCreationForm called." << std::endl;
}
