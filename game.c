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

char getRand();
char getWidth(void);
char getHeight(void);
void shMatrix(char width, char height, char array[height][width], char figureNow);
char objParse(char num, char array[8][15])
{
  switch(num){
  {
      case 0:
          printf("0\n");
          return "sqr";
          break;
      case 1:
          printf("1\n");
          return "line";
          break;
      case 2:
          printf("2\n");
          return "tri";
          break;
      case 3:
          printf("3\n");
          return "tri-o";
          break;
      case 4:
          printf("4\n");
          return "z";
          break;
      case 5:
          printf("5\n");
          return "z-o";
          break;
      case 6:
          printf("6\n");
          return "pist";
          break;
      default:
          break;
    };
  return;
  }
}

void main(void)
{
  char width = 8,
       height = 15,
       array[8][15];
  memset(array, 0, height * width);
  char figureNow = objParse(getRand(), array[8][15]);
  shMatrix(width, height, array, figureNow);

  // while(1)
  //   if(kbhit())

  return;
}
char matrixFigure(char figure)
{
  if(figure == 0)
    return 11;
  else 
    printf("%s\n", figure);
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
  
void shMatrix(char width, char height, char array[height][width],char figureNow) 
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
        printf("|    %d\n", matrixFigure(figureNow));
      else if (i == 8)
        printf("|    1\n");
      else
        printf("| \n");
      
  }
}
char getRand()
{
  srand(time(NULL));
  int r = rand() % 7;
  return r;
}