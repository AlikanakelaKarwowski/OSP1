﻿/* ACADEMIC INTEGRITY PLEDGE                                              */
/*                                                                        */
/* - I have not used source code obtained from another student nor        */
/*   any other unauthorized source, either modified or unmodified.        */
/*                                                                        */
/* - All source code and documentation used in my program is either       */
/*   my original work or was derived by me from the source code           */
/*   published in the textbook for this course or presented in            */
/*   class.                                                               */
/*                                                                        */
/* - I have not discussed coding details about this project with          */
/*   anyone other than my instructor. I understand that I may discuss     */
/*   the concepts of this program with other students and that another    */
/*   student may help me debug my program so long as neither of us        */
/*   writes anything during the discussion or modifies any computer       */
/*   file during the discussion.                                          */
/*                                                                        */
/* - I have violated neither the spirit nor letter of these restrictions. */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/* Signed:Alex Karwowski, Chayton Hamerick, Dominic *** Date: 1/27/20     */
/*                                                                        */
/*                                                                        */
/* 3460:4/526 BlackDOS2020 kernel, Version 1.03, Fall 2019.               */

void handleInterrupt21(int,int,int,int);
void printLogo();
void clearScreen();
//
void main()
{
  makeInterrupt21();
  printLogo();
  interrupt(33,0,"Hello world from Chayton, Dominic, and Alex.\r\n\0",1,0);
  while(1);
}

void printString(char* c, int d)
{
  if(d ==1)
    while(*c != '\0')
    {
      interrupt(23, *c, 0, 0, 0);
      c++;
    }
  else
    while(*c != '\0')
    {
      char al = *c;
      char ah = 14;
      int ax = ah * 256 + al;
      interrupt(16, ax, 0, 0, 0);
      c++;
    }
  /* fill this in */
  return;
}

void printLogo()
{
  interrupt(33,0,"       ___   `._   ____  _            _    _____   ____   _____ \r\n\0",0,0);
  interrupt(33,0,"      /   \\__/__> |  _ \\| |          | |  |  __ \\ / __ \\ / ____|\r\n\0",0,0);
  interrupt(33,0,"     /_  \\  _/    | |_) | | __ _  ___| | _| |  | | |  | | (___ \r\n\0",0,0);
  interrupt(33,0,"    // \\ /./      |  _ <| |/ _` |/ __| |/ / |  | | |  | |\\___ \\ \r\n\0",0,0);
  interrupt(33,0,"   //   \\\\        | |_) | | (_| | (__|   <| |__| | |__| |____) |\r\n\0",0,0);
  interrupt(33,0,"._/'     `\\.      |____/|_|\\__,_|\\___|_|\\_\\_____/ \\____/|_____/\r\n\0",0,0);
  interrupt(33,0," BlackDOS2020 v. 1.03, c. 2019. Based on a project by M. Black. \r\n\0",0,0);
  interrupt(33,0," Author(s): Chayton, Dominic, and Alex.\r\n\r\n\0",0,0);
}

void clearScreen()
{
  int i = 0;
  while(i <=24)
  {
    interrupt(33,0,"\r",0,0);
    interrupt(33,0,"\n",0,0);
    ++i;
  }
}
/* MAKE FUTURE UPDATES HERE */
/* VVVVVVVVVVVVVVVVVVVVVVVV */



/* ^^^^^^^^^^^^^^^^^^^^^^^^ */
/* MAKE FUTURE UPDATES HERE */

void handleInterrupt21(int ax, int bx, int cx, int dx)
{
  /* return;  */
  switch(ax)
  {
    case 0:
      printString(bx, cx);
      break;
  /*      case 1: case 2: case 3: case 4: case 5: */
  /*      case 6: case 7: case 8: case 9: case 10: */
  /*      case 11: case 12: case 13: case 14: case 15: */
    default:
      interrupt(33,0,"General BlackDOS error.\r\n\0",0,0);
      break;
  }
}
