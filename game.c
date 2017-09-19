#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>



#define AC_RED     "\x1b[31;1m"
#define AC_GREEN   "\x1b[32;1m"
#define AC_BLUE    "\x1b[34;1m"
#define AC_RESET   "\x1b[0m"


int kbhit(void);
int getch(void);


char getWidth(void);
char getHeight(void);
void shMatrix(char width, char height, char array[height][width]);
char objParse(char num, char array[8][15])
{
  if(num == 0)
    printf("0!!!!\n");
}
char getRand()
{
  srand(time(NULL));
  int r = rand() % 5;
  return r;
}

void main(void)
{
  char width = 8,
       height = 15,
       array[8][15];
  objParse(getRand(), array[8][15]);
  memset(array, 0, height * width);
  shMatrix(width, height, array);
  while(1)
  {
    if(kbhit())
    {
      switch (getch())
      {

      case  'w':

      break;
      case  'a':

      break;
      case  's':

      break;
      case  'd':

      break;
      case 27:
        return;
      break;
      default:
        printf(AC_BLUE"To play use: WASD\nTo exit: ESC\n%s", AC_RESET);
        break;
      }
    }
  }

  return;
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
  
void shMatrix(char width, char height, char array[height][width]) 
{
  system("clear");
  for(char i = 0;i < height;i++)
  {
    printf("| ");
      for(char j = 0;j < width;j++){
        if (array[i][j] == 1) {
          printf(AC_GREEN"1 %s", AC_RESET);
        } else {printf("0 ", array[i][j]);}
      }
      if(i == 3) 
        printf("| Score = %d\n", 55);
      else if (i == 5)
        printf("| Next part is:\n");
      else if (i == 7)
        printf("|    00\n");
      else if (i == 8)
        printf("|    0\n");
      else
        printf("| \n");
      
  }
}