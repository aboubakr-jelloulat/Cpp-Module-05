#include "Bureaucrat.h"


int main()
{
    try
    {
        Bureaucrat b1("Hej", 2);
        std::cout << b1 << std::endl;
        
        b1.increment();
        std::cout << b1 << std::endl;
        
        b1.increment();
        std::cout << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---\n" << std::endl;

    try
    {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        
        b2.decrement();
        std::cout << b2 << std::endl;
        
        b2.decrement();
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---\n" << std::endl;

    try
    {
        Bureaucrat b3("Charlie", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---\n" << std::endl;

    try
    {
        Bureaucrat b4("David", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}