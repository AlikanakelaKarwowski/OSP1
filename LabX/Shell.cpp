//shell.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//command interpreter
bool cmdInterpreter(std::string, char);

//portable sleep function for non-OS dependent sleep functionality
void sleepy(double);

int main()
{
    int pid;
    int status;
    std::string input;
    while(true)
    {
        pid =0;
        std::cout << "~(__^> ";
        std::getline(std::cin, input);

        //Clear screen command
        if (cmdInterpreter(input,'W'))
        {
            int pid;
            pid =fork();
            if (pid ==0)
            {
                char* cmd[] = { "clear", NULL};
                execvp(cmd[0], cmd);

            }
        waitpid(pid, &status, 0);

        }

        // echo command
        else if (cmdInterpreter(input, 'E'))
        {
            std::string echo = input.substr(2);
            int pid;
            pid = fork();

            if(pid ==0)
            {
                char* cmd = "echo";
                char* arg[3];
                arg[0]= cmd;

                char * argEcho = new char[echo.size() + 1];
                std::copy(echo.begin(), echo.end(), argEcho);
                argEcho[echo.size()] = '\0';

                arg[1] = argEcho;
                arg[2] = NULL;

                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
        }

        // Copy file command
        else if (cmdInterpreter(input, 'C'))
        {
            std::stringstream ss;
            std::string File1, File2;
            ss << input.substr(1);
            ss >> File1 >> File2;
            int pid;
            pid = fork();
            if(pid == 0){
                char* cmd = "cp";
                char* arg[4];

                arg[0] = cmd;

                char * argF1 = new char[File1.size() + 1];
                std::copy(File1.begin(), File1.end(), argF1);
                argF1[File1.size()] = '\0';

                char * argF2 = new char[File2.size() + 1];
                std::copy(File2.begin(), File2.end(), argF2);
                argF2[File2.size()] = '\0';

                arg[1] = argF1;
                arg[2] = argF2;
                arg[3] = NULL;
                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
            std::cout << File1 << " has been copied to " << File2<< std::endl;
        }
        // execute command
        else if (cmdInterpreter(input, 'X'))
        {
            std::stringstream ss;
            std::string argument;
            ss << input.substr(1);
            ss >> argument;

            int pid;
            pid = fork();

            if(pid ==0)
            {

                char* arg[2];
                char * argExec = new char[argument.size() + 1];
                std::copy(argument.begin(), argument.end(), argExec);
                argExec[argument.size()] = '\0';
                arg[0]= argExec;
                arg[1] = NULL;
                std::cout <<std::endl;

                execvp(arg[0], arg);
            }
            waitpid(pid, &status, 0);
        }

        // help command
        else if (cmdInterpreter(input, 'H'))
        {
            std::cout <<"\tW:\tClears the screen of text."<<std::endl;
            std::cout <<"\tE:\tPrints out all text after the command."<<std::endl;
            std::cout <<"\tC:\tTakes 2 arguments as files, and copys file 1 into file 2."<<std::endl;
            std::cout <<"\tX:\tTakes 1 argument as a program and runs the program."<<std::endl;
            std::cout <<"\tH:\tDisplays This Message."<<std::endl;
            std::cout <<"\tP:\tTakes 1 argument as a file and prints the content to the shell."<<std::endl;
            std::cout <<"\tS:\tTakes 1 argument and surfs the web." << std::endl;
            std::cout <<"\tD:\tTakes 1 argument as a file and deletes the file."<<std::endl;
            std::cout <<"\tQ:\tExit the shell and return to console."<<std::endl;

            std::cout <<"\tS:\tSurf the web, but not really."<<std::endl;
            std::cout <<"\tL:\tShow current working directory and files."<<std::endl;
            std::cout <<"\tM:\tMake a new file using nano."<<std::endl;
        }

        // print command
        else if (cmdInterpreter(input, 'P'))
        {
            std::stringstream ss;
            std::string argument;
            ss << input.substr(1);
            ss >> argument;

            int pid;
            pid = fork();
            if(pid == 0){
                char* cmd = "more";
                char* arg[3];

                arg[0] = cmd;

                char * argF1 = new char[argument.size() + 1];
                std::copy(argument.begin(), argument.end(), argF1);
                argF1[argument.size()] = '\0';

                arg[1] = argF1;
                arg[2] = NULL;
                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
        }

        /* surf the web*/ //works ?
        else if (cmdInterpreter(input, 'S'))
        {
            int pid;
            pid =fork();
            //firefox & does not work on my home system. use at your own risk
            if (pid ==0)
            {
                char* cmd = "firefox &";
                char* arg[2];
                arg[0] = cmd;
                arg[1] = NULL;
                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
            std::cout << "Surfing Dude..." << std::endl;
            pthread_exit(0);
            pthread_join(pid, NULL);
        }

        // delete
        else if (cmdInterpreter(input, 'D'))
        {
            std::stringstream ss;
            std::string buffer;
            ss << input.substr(2);
            ss >> buffer;
            int pid;
            pid =fork();
            if (pid ==0)
            {
                int status;
                char* cmd = "rm";
                char* arg[3];
                arg[0]= "rm";
                char * argFile = new char[buffer.size() + 1];
                std::copy(buffer.begin(), buffer.end(), argFile);
                argFile[buffer.size()] = '\0';
                arg[1] = argFile;
                arg[2] = NULL;
                execvp(cmd, arg);

            }
            waitpid(pid, &status, 0);

        }
        // exit command
        else if (cmdInterpreter(input, 'Q'))
        {
            std::cout << "Exiting"<<std::endl;
            sleepy(1);
            std::cout << "\033[2J\033[1;1H";
            exit(1);
        }
        // list directory command
        else if(cmdInterpreter(input, 'L'))
        {
            int pid;
            pid =fork();
            if (pid ==0)
            {
                char* cmd = "pwd";
                char* arg[2];
                arg[0] = cmd;
                arg[1] = NULL;
                execvp(cmd, arg);
            }
            pid =fork();
            if (pid ==0)
            {
                char* cmd = "ls";
                char* arg[3];
                arg[0] = cmd;
                arg[1] = "-l";
                arg[2] = NULL;
                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
        }
        // make command
        else if(cmdInterpreter(input, 'M'))
        {

            std::stringstream ss;
            std::string argument;
            ss << input.substr(1);
            ss >> argument;

            int pid;
            pid = fork();
            if(pid == 0){
                char* cmd = "nano";
                char* arg[3];

                arg[0] = cmd;

                char * argF1 = new char[argument.size() + 1];
                std::copy(argument.begin(), argument.end(), argF1);
                argF1[argument.size()] = '\0';

                arg[1] = argF1;
                arg[2] = NULL;
                execvp(cmd, arg);
            }
            waitpid(pid, &status, 0);
        }
        else
            std::cout << "Command Not Found" << std::endl;
    }

};


bool cmdInterpreter(std::string input, char cmd){

    char tmp = input[0];

    if (tmp == cmd)
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
