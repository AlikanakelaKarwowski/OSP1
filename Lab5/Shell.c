#define PRINTS(x)  interrupt(33,0,x,0,0)
#define PRINTN(x)  interrupt(33,13,x,0,0)
#define LPRINTS(x) interrupt(33,0,x,1,0)
#define LPRINTN(x) interrupt(33,13,x,1,0)
#define SCANS(x)   interrupt(33,1,x,0,0)
#define SCANN(x)   interrupt(33,14,&x,0,0)
#define END        interrupt(33,5,0,0,0)

/*void boot(){
    interrupt(25,0,0,0,0);
}

void clrs(){
    interrupt(33,12,0,0,0);
}

void echo(){
    SCANS(x);
}
*/

void main()
{
    int True = 1;
    char input[55];
    while (True);
    {
        PRINTS("~(__^> ");
        SCANS(input);

    }
}
