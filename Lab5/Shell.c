#define PRINTS(x)  interrupt(33,0,x,0,0)
#define PRINTN(x)  interrupt(33,13,x,0,0)
#define LPRINTS(x) interrupt(33,0,x,1,0)
#define LPRINTN(x) interrupt(33,13,x,1,0)
#define SCANS(x)   interrupt(33,1,x,0,0)
#define SCANN(x)   interrupt(33,14,&x,0,0)
#define END        interrupt(33,5,0,0,0)

int CommandHandler(char *c );

void main()
{
    int True = 1, control;
    while(True == 1){
        char input[55];
        PRINTS("~(__^> ");
        SCANS(input);
        PRINTS("\r\n\0");

        control = CommandHandler(input);
        switch(control)
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
            default:
                PRINTS("twat waffle ...");
                PRINTS("\r\n\0");
                break;

        }

    }
}

int CommandHandler(char *c ){
    /* boot */
    if (c[0] == 'b' && c[1] == 'o' && c[2] == 'o' && c[3] == 't')
        {return 1;}

    /* clrs */
    else if (c[0] == 'c' && c[1] == 'l' && c[2] == 'r' && c[3] == 's')
        {return 2;}

    /* echo */
    else if (c[0] == 'e' && c[1] == 'c' && c[2] == 'h' && c[3] == 'o')
        {return 3;}

    /* copy */
    else if (c[0] == 'c' && c[1] == 'o' && c[2] == 'p' && c[3] == 'y')
        {return 4;}

    /* ddir */
    else if (c[0] == 'd' && c[1] == 'd' && c[2] == 'i' && c[3] == 'r')
        {return 5;}

    /* exec */
    else if (c[0] == 'e' && c[1] == 'x' && c[2] == 'e' && c[3] == 'c')
        {return 6;}

    /* help */
    else if (c[0] == 'h' && c[1] == 'e' && c[2] == 'l' && c[3] == 'p')
        {return 7;}

    /* prnt */
    else if (c[0] == 'p' && c[1] == 'r' && c[2] == 'n' && c[3] == 't')
        {return 8;}

    /* remv */
    else if (c[0] == 'r' && c[1] == 'e' && c[2] == 'm' && c[3] == 'v')
        {return 9;}

    /* senv */
    else if (c[0] == 's' && c[1] == 'e' && c[2] == 'n' && c[3] == 'v')
        {return 10;}

    /* show */
    else if (c[0] == 's' && c[1] == 'h' && c[2] == 'o' && c[3] == 'w')
        {return 11;}

    /* twet */
    else if (c[0] == 't' && c[1] == 'w' && c[2] == 'e' && c[3] == 't')
        {return 12;}

}
