#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 25, 5) {
	this->target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : AForm("ShrubberyCreationForm", 25, 5) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& a) {
	if (this != &a) {
		this->target = a.target;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	else if (this->getSigned() == UNSIGNED) throw std::runtime_error("The form has not been signed yet.\n");
	std::string fileName = this->target + "_shrubbery";
	std::ofstream outFile(fileName);
	if (!outFile) throw std::runtime_error("Failed to open a file");
    outFile << "                                               ." << std::endl;
    outFile << "                                   .         ;  " << std::endl;
    outFile << "      .              .              ;%     ;;   " << std::endl;
    outFile << "        ,           ,                :;%  %;   " << std::endl;
    outFile << "         :         ;                   :;%;'     .,   " << std::endl;
    outFile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
    outFile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    outFile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;" << std::endl;
    outFile << "    ;%;      %;        ;%;        % ;%;  ,%;" << std::endl;
    outFile << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    outFile << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    outFile << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    outFile << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
    outFile << "             `@%.  `;@%.      ;@@%;" << std::endl;
    outFile << "               `@%%. `@%%    ;@@%;" << std::endl;
    outFile << "                 ;@%. :@%%  %@@%;" << std::endl;
    outFile << "                   %@bd%%%bd%%:;     " << std::endl;
    outFile << "                     #@%%%%%:;;" << std::endl;
    outFile << "                     %@@%%%::;" << std::endl;
    outFile << "                     %@@@%(o);  . '         " << std::endl;
    outFile << "                     %@@@o%;:(.,'         " << std::endl;
    outFile << "                 `.. %@@@o%::;         " << std::endl;
    outFile << "                    `)@@@o%::;         " << std::endl;
    outFile << "                     %@@(o)::;        " << std::endl;
    outFile << "                    .%@@@@%::;         " << std::endl;
    outFile << "                    ;%@@@@%::;.          " << std::endl;
    outFile << "                   ;%@@@@%%:;;;." << std::endl;
    outFile << "               ...;%@@@@@%%:;;;;,.." << std::endl;
	outFile.close();
}
