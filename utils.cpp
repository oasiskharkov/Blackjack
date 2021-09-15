#include "utils.h"

#ifdef __linux__

#include <iostream>
#include <unistd.h>
#include <termios.h>

namespace Utils
{
   char getch(void)
   {
        char buf {0};
        termios old = {0};
        fflush(stdout);
        if(tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if(read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if(tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        printf("%c\n", buf);
        return buf;
    }

    void clearScreen(void)
    {
        std::system("clear");
    }
}

#elif defined (_WIN64) || defined (_WIN32)

#include <conio.h>

namespace Utils
{
    char getch(void)
    {
        char a;
        a = _getch();
        return a;
    }

    void clearScreen(void)
    {
        std::system("cls");
    }
}
#endif

