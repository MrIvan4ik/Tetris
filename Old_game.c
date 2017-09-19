#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>

// Colors(Цвета)

#define AC_RED     "\x1b[31;1m"
#define AC_GREEN   "\x1b[32;1m"
#define AC_BLUE    "\x1b[34;1m"
#define AC_RESET   "\x1b[0m"

// Functions to get char without Enter for Linux(Функции чтобы получить знак без Ентера для Линукса) Только декларация

int kbhit(void);
int getch(void);


char getWidth(void);
char getHeight(void);
void shMatrix(char width, char height, char array[height][width]);

void main(void)
{
  char width = getWidth(),
     height = getHeight(),
     array[height][width],
                    i = 1,
                    j = 0;
  // Задать массиву 0                  
  memset(array, 0, height * width);
  // Создать 1
  array[i][j] = 1;

  shMatrix(width, height, array);
// Бесконечный массив
  while(1)
  {
    // Если нажата любая кнопка сработает If
    if(kbhit())
    {
      // Получение и сравнение символа
      switch (getch())
      {

      case  'w':
        if(i - 1 < 0) {
          shMatrix(width, height, array);
          printf(AC_RED"You go beyond\n%s", AC_RESET);
        } else {
          memset(array, 0, height * width);
          array[--i][j] = 1;
          shMatrix(width, height, array);
        }
        break;

      case  'a':
        if(j - 1 < 0 ) {
          shMatrix(width, height, array);
          printf(AC_RED"You go beyond\n%s", AC_RESET);
        } else {
          memset(array, 0, height * width);
          array[i][--j] = 1;
          shMatrix(width, height, array);
        }
      break;

      case  's':
        if(i > height - 2 ) {
          shMatrix(width, height, array);
          printf(AC_RED"You go beyond\n%s", AC_RESET);
        } else {
          memset(array, 0, height * width);
          array[++i][j] = 1;
          shMatrix(width, height, array);
          
        }
      break;

      case  'd':
        if(j > width - 2 ) {
          shMatrix(width, height, array);
          printf(AC_RED"You go beyond\n%s", AC_RESET);
        } else {
          memset(array, 0, height * width);
          array[i][++j] = 1;
          shMatrix(width, height, array);
        }
      break;
      // Если номер символа = 27 Выход из игры
      case 27:
        return;
      break;
      // Если любой символ кроме WASD 
      default:
        shMatrix(width, height, array);
        printf(AC_BLUE"To play use: WASD\nTo exit: ESC\n%s", AC_RESET);
        break;
      }
    }
  }
  // Ничего не возвращаем потому что main - void
  return;
}
// Далее функции которые задекларированые 
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
char getWidth(void)
{
  char width[30] = {0};

  do
  {
    printf("Print here width(Max 15): ");
    scanf("%s", width);
  } while ( atoi(width) >= 16 );

  return atoi(width);
}

char getHeight(void)
{
  char height[30] = {0};

  do
  {
    printf("Print here height(Max 15): ");
    scanf("%s", height);
  } while ( atoi(height) >= 16 );

  return atoi(height);
}
  
void shMatrix(char width, char height, char array[height][width]) 
{
  system("clear");
  for(char i = 0;i < height;i++)
  {
      for(char j = 0;j < width;j++){
        if (array[i][j] == 1) {
          printf(AC_GREEN"1 %s", AC_RESET);
        } else {printf("0 ", array[i][j]);}
      }
      printf("\n");
  }
}

