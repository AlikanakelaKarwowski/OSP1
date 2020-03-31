#define PRINTS(x)  interrupt(33,0,x,0,0)
#define PRINTN(x)  interrupt(33,13,x,0,0)
#define LPRINTS(x) interrupt(33,0,x,1,0)
#define LPRINTN(x) interrupt(33,13,x,1,0)
#define SCANS(x)   interrupt(33,1,x,0,0)
#define SCANN(x)   interrupt(33,14,&x,0,0)
#define END        interrupt(33,5,0,0,0)

int CommandHandler(char *c ){
    /* boot */
    if (input[0] == 'b' && input[1] == 'o' && input[2] == 'o' && input[3] == 't')
        {return 1;}

    /* clrs */
    if (input[0] == 'c' && input[1] == 'l' && input[2] == 'r' && input[3] == 's')
        {return 2;}

    /* echo */
    if (input[0] == 'e' && input[1] == 'c' && input[2] == 'h' && input[3] == 'o')
        {return 3;}

    /* copy */
    if (input[0] == 'c' && input[1] == 'o' && input[2] == 'p' && input[3] == 'y')
        {return 4;}

    /* ddir */
    if (input[0] == 'd' && input[1] == 'd' && input[2] == 'i' && input[3] == 'r')
        {return 5;}

    /* exec */
    if (input[0] == 'e' && input[1] == 'x' && input[2] == 'e' && input[3] == 'c')
        {return 6;}

    /* help */
    if (input[0] == 'h' && input[1] == 'e' && input[2] == 'l' && input[3] == 'p')
        {return 7;}

    /* prnt */
    if (input[0] == 'p' && input[1] == 'r' && input[2] == 'n' && input[3] == 't')
        {return 8;}

    /* remv */
    if (input[0] == 'r' && input[1] == 'e' && input[2] == 'm' && input[3] == 'v')
        {return 9;}

    /* senv */
    if (input[0] == 's' && input[1] == 'e' && input[2] == 'n' && input[3] == 'v')
        {return 10;}

    /* show */
    if (input[0] == 's' && input[1] == 'h' && input[2] == 'o' && input[3] == 'w')
        {return 11;}

    /* twet */
    if (input[0] == 't' && input[1] == 'w' && input[2] == 'e' && input[3] == 't')
        {return 12;}

}


void main()
{
    int True = 1;
    while(True == 1){
        char input[55];
        PRINTS("~(__^> ");
        SCANS(input);
        PRINTS("\r\n\0");
        int cmd = Command(input);
        switch(cmd)
        {
            case 1:
                PRINTS("Rebooting ...");
                PRINTS("\r\n\0");
                break;
            case 2:
                PRINTS("clear screen ...");
                PRINTS("\r\n\0");
                break;
            case 3:
                PRINTS("echo ...");
                PRINTS("\r\n\0");
                break;
            case 4:
                PRINTS("copy ...");
                PRINTS("\r\n\0");
                break;
            case 5:
                PRINTS("d directory ...");
                PRINTS("\r\n\0");
                break;
            case 6:
                PRINTS("execute ...");
                PRINTS("\r\n\0");
                break;
            case 7:
                PRINTS("help me ...");
                PRINTS("\r\n\0");
                break;
            case 8:
                PRINTS("print ...");
                PRINTS("\r\n\0");
                break;
            case 9:
                PRINTS("remove ...");
                PRINTS("\r\n\0");
                break;
            case 10:
                PRINTS("senv??? ...");
                PRINTS("\r\n\0");
                break;
            case 11:
                PRINTS("show ...");
                PRINTS("\r\n\0");
                break;
            case 12:
                PRINTS("twat ...");
                PRINTS("\r\n\0");
                break;
            case default:
                PRINTS("twat waffle ...");
                PRINTS("\r\n\0");
                break;

        }

    }
}
