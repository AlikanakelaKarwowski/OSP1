#define PRINTS(x)  interrupt(33,0,x,0,0)
#define PRINTN(x)  interrupt(33,13,x,0,0)
#define LPRINTS(x) interrupt(33,0,x,1,0)
#define LPRINTN(x) interrupt(33,13,x,1,0)
#define SCANS(x)   interrupt(33,1,x,0,0)
#define SCANN(x)   interrupt(33,14,&x,0,0)
#define END        interrupt(33,5,0,0,0)



void main()
{
    int True = 1, control = 0;
    while(True == 1){
        char input[55];
        PRINTS("~(__^> ");
        SCANS(input);
        PRINTS("\r\n\0");

        /* boot */
        if (input[0] == 'b' && input[1] == 'o' && input[2] == 'o' && input[3] == 't'){
            PRINTS("Rebooting ...");
            PRINTS("\r\n\0");
            break;
        }

        /* clrs */
        if (input[0] == 'c' && input[1] == 'l' && input[2] == 'r' && input[3] == 's'){
            PRINTS("clear screen ...");
            PRINTS("\r\n\0");
            break;
        }

        /* echo */
        if (input[0] == 'e' && input[1] == 'c' && input[2] == 'h' && input[3] == 'o'){
            PRINTS("echo ...");
            PRINTS("\r\n\0");
            break;
        }

        /* copy */
        if (input[0] == 'c' && input[1] == 'o' && input[2] == 'p' && input[3] == 'y'){
            PRINTS("copy ...");
            PRINTS("\r\n\0");
            break;
        }

        /* ddir 
        else if (input[0] == 'd' && input[1] == 'd' && input[2] == 'i' && input[3] == 'r')
            {PRINTS("d directory ...");
            PRINTS("\r\n\0");
            break;
        }

        /* exec
        else if (input[0] == 'e' && input[1] == 'x' && input[2] == 'e' && input[3] == 'c')
            {PRINTS("execute ...");
            PRINTS("\r\n\0");
            break;
        }

        /* help
        else if (input[0] == 'h' && input[1] == 'e' && input[2] == 'l' && input[3] == 'p')
            {PRINTS("help me ...");
            PRINTS("\r\n\0");
            break;
        }

        /* prnt
        else if (input[0] == 'p' && input[1] == 'r' && input[2] == 'n' && input[3] == 't'){
            PRINTS("execute ...");
            PRINTS("\r\n\0");
            break;
        }

        /* remv
        else if (input[0] == 'r' && input[1] == 'e' && input[2] == 'm' && input[3] == 'v'){
            PRINTS("remove ...");
            PRINTS("\r\n\0");
            break;
        }

        /* senv
        else if (input[0] == 's' && input[1] == 'e' && input[2] == 'n' && input[3] == 'v'){
            PRINTS("senv??? ...");
            PRINTS("\r\n\0");
            break;
        }

        /* show
        else if (input[0] == 's' && input[1] == 'h' && input[2] == 'o' && input[3] == 'w'){
            PRINTS("show ...");
            PRINTS("\r\n\0");
            break;
        }

        /* twet
        else if (input[0] == 't' && input[1] == 'w' && input[2] == 'e' && input[3] == 't'){
            PRINTS("twat waffle ...");
            PRINTS("\r\n\0");
            break;
        }*/
    }

};
