//shell.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//command interpreter
bool cmdInterpreter(std::string, std::string, std::string, std::string);

//portable sleep function for non-OS dependent sleep functionality
void sleepy(double);

int main()
{
    int control = 0;
    std::string input;
    while(true){

        std::cout << "~(__^> ";
        std::getline(std::cin, input);

        /* boot */
        if (cmdInterpreter(input, "boot", " ", " ")){
            std::cout <<"Rebooting... " <<std::endl;
            sleepy(1);
            std::cout << "\033[2J\033[1;1H";
        }

        /* clrs */
        else if (cmdInterpreter(input, "clrs", "W", "w")){
            int pid;
            pid =fork();
            if (pid ==0)
            {
                int status =0;
                char* cmd[] = { "clear", NULL};
                execvp(cmd[0], cmd);
                status =1;
                std::cout << "~(__^> ";
            }


        }

        /* echo */
        else if (cmdInterpreter(input, "echo", "E", "e")){
            std::string echo = input.substr(4);
            std::cout << echo << std::endl;
        }

        /* copy */
        else if (cmdInterpreter(input, "copy" , "C", "c")){
            std::stringstream ss;
            std::string File1, File2;
            ss << input.substr(4);
            std::cout << File2 << " has been copied to " << File1 << std::endl;

        }

        /* ddir */
        else if (cmdInterpreter(input, "ddir", " ", " ")){
            std::cout <<"d directory ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;

        }

        /* exec */
        else if (cmdInterpreter(input, "exec", "X", "x")){
            std::cout <<"execute ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* help */
        else if (cmdInterpreter(input, "help", "H", "h" )){
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
        else if (cmdInterpreter(input, "prnt", "P", "p")){
            std::cout <<"Printing ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        else if (cmdInterpreter(input, "surf", "S", "s")){
            std::cout <<"surfing web ... " <<std::endl;

        }

        /* remv */
        else if (cmdInterpreter(input, "remv", "D", "d")){
            std::cout <<"removing file(s)... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            int pid;
            pid =fork();
            if (pid ==0)
            {
                int status;
                char* cmd = "rm";
                char* arg[3];
                arg[0]= "rm";
                char * argFile = new char[argument.size() + 1];
                std::copy(argument.begin(), argument.end(), argFile);
                argFile[argument.size()] = '\0';
                arg[1] = argFile;
                arg[2] = NULL;
                execvp(cmd, arg);

            }
            std::cout << argument << std::endl;

        }

        /* senv */
        else if (cmdInterpreter(input, "senv", " ", " ")){
            std::cout <<"senv??? ... ";
            std::cout << std::endl;
        }

        /* show */
        else if (cmdInterpreter(input, "show", " ", " ")){
            std::cout <<"show ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }

        /* twet */
        else if (cmdInterpreter(input, "twet", " ", " ")){
            std::cout <<"twet ... ";
            std::stringstream ss;
            std::string argument;
            ss << input.substr(4);
            ss >> argument;
            std::cout << argument << std::endl;

        }
        else if (cmdInterpreter(input, "exit", "Q", "q"))
            {std::cout << "Exiting"<<std::endl;
            sleepy(1);
            std::cout << "\033[2J\033[1;1H";
            return 0;}

        else if(cmdInterpreter(input, "list", "L", "l")){
            std::cout << "Listing content" <<std::endl;
        }
        else
            std::cout << "Command Not Found" << std::endl;
    }

};

bool cmdInterpreter(std::string input, std::string check, std::string altU, std::string altL){
    if (input.substr(0,4) == check)
        return true;
    if (input == altU || input == altL)
        return true;
    else
        return false;

};
void sleepy(double seconds){
    clock_t startClock = clock();
    double secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
};
