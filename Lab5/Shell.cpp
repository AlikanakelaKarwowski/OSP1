//shell.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

//command interpreter
bool cmdInterpreter(std::string, std::string);

//portable sleep function for non-OS dependent sleep functionality
void sleep(double);

int main()
{
    int control = 0;
    std::string input;
    while(true){

        std::cout << "~(__^> ";
        std::getline(std::cin, input);

        /* boot */
        if (cmdInterpreter(input, "boot")){
            std::cout <<"Rebooting... " <<std::endl;
            sleep(1);
            std::cout << "\033[2J\033[1;1H";
        }

        /* clrs */
        else if (cmdInterpreter(input, "clrs")){
            std::cout << "\033[2J\033[1;1H";
        }

        /* echo */
        else if (cmdInterpreter(input, "echo")){
            std::string echo = input.substr(4);
            std::cout << echo << std::endl;
        }

        /* copy */
        else if (cmdInterpreter(input, "copy")){
            std::stringstream ss;
            std::string File1, File2;
            ss << input.substr(4);
            ss >> File1 >> File2;
            std::cout << File2 << " has been copied to " << File1 << std::endl;

        }

        /* ddir */
        else if (cmdInterpreter(input, "ddir" )){
            std::cout <<"d directory ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* exec */
        else if (cmdInterpreter(input, "exec" )){
            std::cout <<"execute ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* help */
        else if (cmdInterpreter(input, "help" )){
            std::cout <<"\tboot:\tReboots the shell."<<std::endl;
            std::cout <<"\tclrs:\tClears the screen of text."<<std::endl;
            std::cout <<"\techo:\tPrints out all text after the command."<<std::endl;
            std::cout <<"\tcopy:\tTakes 2 arguments as files, and copys file 2 into file 1."<<std::endl;
            std::cout <<"\tddir:\t*Insert Help Text Here*."<<std::endl;
            std::cout <<"\texec:\tTakes 1 argument as a file and runs the file."<<std::endl;
            std::cout <<"\thelp:\tDisplays This Message."<<std::endl;
            std::cout <<"\tprnt:\tTakes 1 argument as a file and prints the content to the shell."<<std::endl;
            std::cout <<"\tremv:\tTakes 1 argument as a file and deletes the file."<<std::endl;
            std::cout <<"\tsenv:\t*Insert Help Message Here*."<<std::endl;
            std::cout <<"\tshow:\tTakes 1 argument as a file and displays the file."<<std::endl;
            std::cout <<"\ttwet:\t*Insert Help Message Here*."<<std::endl;
            std::cout <<"\texit:\tExit the shell and return to console."<<std::endl;

        }

        /* prnt */
        else if (cmdInterpreter(input, "prnt")){
            std::cout <<"Printing ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* remv */
        else if (cmdInterpreter(input, "remv")){
            std::cout <<"remove ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* senv */
        else if (cmdInterpreter(input, "senv")){
            std::cout <<"senv??? ... ";
            std::cout << std::endl;
        }

        /* show */
        else if (cmdInterpreter(input, "show")){
            std::cout <<"show ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* twet */
        else if (cmdInterpreter(input, "twet")){
            std::cout <<"twet ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }
        else if (cmdInterpreter(input, "exit"))
            return 0;
        else
            std::cout << "Command Not Found" << std::endl;
    }

};

bool cmdInterpreter(std::string input, std::string check){
    if (input.substr(0,4) == check)
        return true;
    else
        return false;

};
void sleep(double seconds){
    clock_t startClock = clock();
    double secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
};
