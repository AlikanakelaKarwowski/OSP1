//shell.cpp
#include <iostream>
#include <string>
#include <sstream>
bool CommandHandler(std::string, std::string);

int main()
{
    int control = 0;
    std::string input;
    while(true){

        std::cout << "~(__^> ";
        std::getline(std::cin, input);

        /* boot */
        if (CommandHandler(input, "boot")){
            std::cout <<"Rebooting... " <<std::endl;
        }

        /* clrs */
        else if (CommandHandler(input, "clrs")){
            std::cout << "\033[2J\033[1;1H";
        }

        /* echo */
        else if (CommandHandler(input, "echo")){
            std::string echo = input.substr(4);
            std::cout << echo << std::endl;
        }

        /* copy */
        else if (CommandHandler(input, "copy")){
            std::stringstream ss;
            std::string File1, File2;
            ss << input.substr(4);
            ss >> File1 >> File2;
            std::cout << File1 << " " << File2 << std::endl;

        }

        /* ddir */
        else if (CommandHandler(input, "ddir" )){
            std::cout <<"d directory ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* exec */
        else if (CommandHandler(input, "exec" )){
            std::cout <<"execute ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* help */
        else if (CommandHandler(input, "help" )){
            std::cout <<"help me ... ";
            std::cout << std::endl;
        }

        /* prnt */
        else if (CommandHandler(input, "prnt")){
            std::cout <<"Printing ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* remv */
        else if (CommandHandler(input, "remv")){
            std::cout <<"remove ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* senv */
        else if (CommandHandler(input, "senv")){
            std::cout <<"senv??? ... ";
            std::cout << std::endl;
        }

        /* show */
        else if (CommandHandler(input, "show")){
            std::cout <<"show ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* twet */
        else if (CommandHandler(input, "twet")){
            std::cout <<"twet ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }
        else if (CommandHandler(input, "exit"))
            return 0;
        else
            std::cout << "Command Not Found" << std::endl;
    }

};

bool CommandHandler(std::string input, std::string check){
    if (input.substr(0,4) == check)
        return true;
    else
        return false;

};
