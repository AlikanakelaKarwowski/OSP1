/* ACADEMIC INTEGRITY PLEDGE                                              */
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
/* Signed:Alex Karwowski, Chayton Hamric, Dominic Cumba Date: 1/27/20     */
/*                                                                        */
/*                                                                        */
/* 3460:4/526 BlackDOS2020 kernel, Version 1.03, Fall 2019.               */

void handleInterrupt21(int,int,int,int);
void printLogo();
void clearScreen(int, int);
void readString(char*, int);
int mod(int, int);
int div(int, int);
void readInt(int* n);
void writeInt(int, int);
void readSector(char* , int, int);
void writeSector(char* , int , int);


/* Mad Lib kernel.c - c. 2018 O'Neil */
void main()
{
    int i;
    char buffer[512];
    makeInterrupt21();
    for (i = 0; i < 512; i++)
        buffer[i] = 0;
    buffer[0] = 0;
    buffer[1] = 11;
    interrupt(33,6,buffer,258,1);
    interrupt(33,12,buffer[0]+1,buffer[1]+1,0);
    printLogo();
    interrupt(33,2,buffer,30,1);
    interrupt(33,0,buffer,0,0);
    while(1);
}

void printString(char* c, int d)
{
    char al, ah;
    int ax;
    if(d ==1)
        while(*c != '\0')
        {
            interrupt(23, *c, 0, 0, 0);
            c++;
        }
    else
        while(*c != '\0')
        {
            al = *c;
            ah = 14;
            ax = ah * 256 + al;
            interrupt(16, ax, 0, 0, 0);
            c++;
        }

    /*add new line and return carrage*/
        al = '\r';
        ah = 14;
        ax = ah * 256 + al;
        interrupt(16, ax, 0, 0, 0);
        al = '\n';
        ax = ah * 256 + al;
        interrupt(16, ax, 0, 0, 0);

    /*interrupt(16,'\r',0,0,0);
    interrupt(16,'\n',0,0,0);
     fill this in */
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

void clearScreen(int bx,int cx)
{
    int i = 0;
    while(i <=24)
    {
        interrupt(33,0,"\r",0,0);
        interrupt(33,0,"\n",0,0);
        ++i;
    }
    interrupt(16,512,0,0,0);
    if(bx >0 && cx > 0)
        if(bx >8 || cx >16)
            return;
        else
            interrupt(16, 1536, 4096 * (bx-1)+ 256 * (cx-1), 0, 6223);
}

int mod(int a, int b)
{
    int x = a;
    while (x >= b)
        x = x - b;
    return x;
}

int div(int a, int b)
{
    int q = 0;
    while (q * b <= a)
        ++q;
    return (q - 1);
}

void readString(char* c, int size)
{
    char temp, al, ah;
    int ax, index;

    while(temp != 0xd)
    {
        temp = interrupt(22,0,0,0);
        c[index] = temp;
        ++index;
        al = temp;
        ah = 14;
        ax = ah * 256 + al;
        interrupt(16,ax,0,0,0);

        if(temp == 0x8 && index >= 0)
        {
            --index;
        }
    }
    c[index-1] = 0x0;
    return;
}

void readInt(int* n)
{
    int i = 0, length = 0, num = 0, ax;
    char temp, al, ah;
    char *c;

    while(temp != 0xd)
    {
        temp = interrupt(22,0,0,0);
        c[i] = temp;
        ++i;
        al = temp;
        ah = 14;
        ax = ah * 256 + al;
        interrupt(16,ax,0,0,0);

        if(temp == 0x8 && i >= 0)
        {
            --i;
        }
    }
    c[i-1] = 0x0;

    while(length < (i-1))
    {
        num = num * 10;
        num = num + (c[length++] - '0');
    }

    *n = num;
    return;
}

void writeInt(int x, int print)
{
    int i = 0, k = 0;
    char temp[6], store[6];
    char p;

    if(x == 0)
    {
        store[0] = '0';
        store[1] = 0;
        interrupt(33, 0, store, 0, 0);
        return;
    }

    /*Fill buffer with digit characters in reverse order.*/
    while (x != 0)
    {
        temp[i++] = (char) (mod(x,10) + 48);
        x = div(x,10);
    }

    while(i > 0)
    {
        p = temp[--i];
        store[k++] = p;
    }

    store[k] = '\0';

    interrupt(33, 0, store, print, 0);
    return;
}

void readSector(char* buffer, int sector, int sectorCount)
{
    int AX = 512 + sectorCount;
    int CX = 256 * div(sector, 36) + (mod(sector, 18) + 1);
    int DX = mod(div(sector, 18), 2) * 256;
    interrupt(19,AX,buffer,CX,DX);

}

void writeSector(char* buffer, int sector, int sectorCount)
{
    int AX = 768 + sectorCount;
    int CX = 256 * div(sector, 36) + (mod(sector, 18) + 1);
    int DX = mod(div(sector, 18), 2) * 256;
    interrupt(19,AX,buffer,CX,DX);
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
        case 1:
            readString(bx, cx);
            break;
        case 2:
            readSector(bx, cx, dx);
            break;
        case 6:
            writeSector(bx, cx, dx);
            break;
        case 12:
            clearScreen(bx, cx);
            break;
        case 13:
            writeInt(bx, cx);
            break;
        case 14:
            readInt(bx);
            break;
        /*case 2: case 3: case 4: case 5: */
        /*      case 6: case 7: case 8: case 9: case 10: */
        /*      case 11: case 12: case 13: case 14: case 15: */
        default:
            interrupt(33,0,"General BlackDOS error.\r\n\0",0,0);
            break;
    }
}
