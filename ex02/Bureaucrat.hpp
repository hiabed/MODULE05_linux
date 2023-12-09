#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <fstream>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
    void signForm(AForm &Aform);
    void executeForm(AForm const & form);
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &output, Bureaucrat &obj);

#endif