#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 
#include <sys/time.h>
#define AC_RED     "\x1b[31;1m"
#define AC_YELLOW  "\x1b[33;1m"
#define AC_GREEN   "\x1b[32;1m"
#define AC_BLUE    "\x1b[34;1m"
#define AC_RESET   "\x1b[0m"

char *foo = 0;


char setOne(void) 
{
  char one = 1;
  foo = &one;
  return;
  
}
char startGame(char array[15][8], char figure, char blc1hi, char blc2hi, char blc3hi, char blc4hi, char blc1we, char blc2we, char blc3we, char blc4we)
{
  char zero = 0;
  foo = &zero;
  signal (SIGALRM, setOne);
  alarm (1);
  char figureFlip = 0;
  char block1 = blc1hi,
       block2 = blc2hi,
       block3 = blc3hi,
       block4 = blc4hi,
       block5 = blc1hi,
       block6 = blc2hi,
       block7 = blc3hi,
       block8 = blc4hi;
  char blcwe1 = blc1we,
       blcwe2 = blc2we,
       blcwe3 = blc3we,
       blcwe4 = blc4we;
  while(1) 
  {
    if (*foo == 1)
    {
      if(array[block1 + 1][blc1we] == 2 || array[block2 + 1][blc2we] == 2 || array[block3 + 1][blc3we] == 2 || array[block4 + 1][blc4we] == 2 || block5 + 1 == 15 || block6 + 1 == 15 || block7 + 1 == 15 || block8 + 1 == 15)
        {
          for(char i = 0;i < 15;i++)
          {
              for(char j = 0;j < 8;j++){
                if (array[i][j] == 1) 
                  array[i][j] = 2;
              }
          }
          for(char i = 0; i < 15; i++)
          {
            char count = 0;
            for(char j = 0;j < 8;j++){
              if (array[i][j] == 2) 
              {
                count++;
                if(count == 8)
                {
                  for(char j = 0;j < 8;j++)
                    array[i][j] = 0;
                    char m = i;
                  for(char k = m - 1; k > 0; k--)
                  {
                    for(char h = 0; h < 8; h++)
                    {
                      char g = k;
                      if(array[k][h] == 2)
                      {
                        array[k][h] = 0;
                        array[g + 1][h] = 2;
                        shMatrix(8, 15, array, figure);

                      }
                    }
                  }
                }
              }
            }
          }
          


          for(char j = 0;j < 8;j++){
            if (array[0][j] == 2) 
              return 0;
            else
              return 1;
          }

          

          shMatrix(8, 15, array, figure);
        } else {
          block1 = blc1hi;
          block2 = blc2hi;
          block3 = blc3hi;
          block4 = blc4hi;
          block5 = blc1hi;
          block6 = blc2hi;
          block7 = blc3hi;
          block8 = blc4hi;
          if(array[block1 + 1][blc1we] != 2 || array[block2 + 1][blc2we] != 2 || array[block3 + 1][blc3we] != 2 || array[block4 + 1][blc4we] != 2 || block5 + 1 == 14 || block6 + 1 == 14 || block7 + 1 == 14 || block8 + 1 == 14) {
            array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
            array[++blc1hi][blc1we] = 1, array[++blc2hi][blc2we] = 1, array[++blc3hi][blc3we] = 1, array[++blc4hi][blc4we] = 1;
            shMatrix(8, 15, array, figure);
          }

        }
        shMatrix(8, 15, array, figure);
        foo = &zero;
        signal (SIGALRM, setOne);
        alarm (1);
        block1 = blc1hi,
        block2 = blc2hi,
        block3 = blc3hi,
        block4 = blc4hi,
        block5 = blc1hi,
        block6 = blc2hi,
        block7 = blc3hi,
        block8 = blc4hi;
      }
          if(kbhit())
          {
            switch (getch())
            {
            case  'w':
            if (figure == 1){
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                  array[blc1hi][blc1we] = 1, array[blc2hi = blc2hi + 1][blc2we = blc2we - 1] = 1, array[blc3hi = blc3hi + 2][blc3we = blc3we - 2] = 1, array[blc4hi = blc4hi + 3][blc4we = blc4we - 3] = 1;
                  figureFlip = 1;
              } else if (figureFlip == 1) {
                  array[blc1hi][blc1we] = 1, array[blc2hi = blc2hi - 1][blc2we = blc2we + 1] = 1, array[blc3hi = blc3hi - 2][blc3we = blc3we + 2] = 1, array[blc4hi = blc4hi - 3][blc4we = blc4we + 3] = 1;
                  figureFlip = 0;
              }
            shMatrix(8, 15, array, figure);
            } 
            else if (figure == 2){
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                  array[blc1hi][blc1we = blc1we + 1] = 1, array[--blc2hi][blc2we] = 1, array[blc3hi][--blc3we] = 1, array[++blc4hi][blc4we = blc4we - 2] = 1;
                  figureFlip = 1;
              } else if (figureFlip == 1) {
                  array[++blc1hi][++blc1we] = 1, array[blc2hi][blc2we = blc2we + 2] = 1, array[blc3hi][++blc3we] = 1, array[--blc4hi][blc4we] = 1;
                  figureFlip = 2;
              } else if (figureFlip == 2) {
                array[blc1hi = blc1hi + 1][--blc1we] = 1, array[blc2hi = blc2hi + 2][blc2we = blc2we - 2] = 1, array[blc3hi][--blc3we] = 1, array[--blc4hi][blc4we] = 1;
                figureFlip = 3;
              } else if (figureFlip == 3) {
                array[blc1hi = blc1hi - 2][--blc1we] = 1, array[--blc2hi][blc2we] = 1, array[blc3hi][++blc3we] = 1, array[++blc4hi][blc4we = blc4we + 2] = 1;
                figureFlip = 0;
              }
            shMatrix(8, 15, array, figure);
            } 
            else if (figure == 3){
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                array[++blc1hi][blc1we = blc1we - 2] = 1, array[blc2hi = blc2hi + 2][--blc2we] = 1, array[++blc3hi][blc3we] = 1, array[blc4hi][++blc4we] = 1;
                figureFlip = 1;
              } else if (figureFlip == 1) {
                array[--blc1hi][blc1we] = 1, array[blc2hi = blc2hi - 2][--blc2we] = 1, array[--blc3hi][blc3we] = 1, array[blc4hi][++blc4we] = 1;
                figureFlip = 2;
              } else if (figureFlip == 2) {
                array[++blc1hi][++blc1we] = 1, array[blc2hi = blc2hi + 1][blc2we] = 1, array[blc3hi][--blc3we] = 1, array[blc4hi = blc4hi + 2][blc4we = blc4we - 2] = 1;
                figureFlip = 3;
              } 
              else if (figureFlip == 3) {
                array[--blc1hi][++blc1we] = 1, array[--blc2hi][blc2we = blc2we + 2] = 1, array[blc3hi][++blc3we] = 1, array[blc4hi = blc4hi - 2][blc4we] = 1;
                figureFlip = 0;
              }
            shMatrix(8, 15, array, figure);
            } 
            else if (figure == 4){
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                  array[blc1hi][--blc1we] = 1, array[++blc2hi][blc2we = blc2we - 2] = 1, array[blc3hi][++blc3we] = 1, array[++blc4hi][blc4we] = 1;
                  figureFlip = 1;
              } else if (figureFlip == 1) {
                  array[blc1hi][++blc1we] = 1, array[--blc2hi][blc2we = blc2we + 2] = 1, array[blc3hi][--blc3we] = 1, array[--blc4hi][blc4we] = 1;
                  figureFlip = 0;
              }
            shMatrix(8, 15, array, figure);
            } 
            else if (figure == 5){
        
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                  array[blc1hi][++blc1we] = 1, array[++blc2hi][blc2we] = 1, array[blc3hi][--blc3we] = 1, array[++blc4hi][blc4we = blc4we - 2] = 1;
                  figureFlip = 1;
              } else if (figureFlip == 1) {
                  array[blc1hi][--blc1we] = 1, array[--blc2hi][blc2we] = 1, array[blc3hi][++blc3we] = 1, array[--blc4hi][blc4we = blc4we + 2] = 1;
                  figureFlip = 0;
              }
              shMatrix(8, 15, array, figure);
              
        
            } 
            else if (figure == 6){
              array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
              if(figureFlip == 0){
                array[++blc1hi][blc1we] = 1, array[--blc2hi][blc2we] = 1, array[blc3hi][--blc3we] = 1, array[++blc4hi][blc4we = blc4we - 2] = 1;
                figureFlip = 1;
              } else if (figureFlip == 1) {
                array[blc1hi][blc1we] = 1, array[blc2hi][blc2we = blc2we + 2] = 1, array[--blc3hi][++blc3we] = 1, array[blc4hi = blc4hi - 2][blc4we] = 1;
                figureFlip = 2;
              } else if (figureFlip == 2) {
                array[blc1hi][--blc1we] = 1, array[blc2hi = blc2hi + 2][--blc2we] = 1, array[++blc3hi][blc3we] = 1, array[blc4hi][++blc4we] = 1;
                figureFlip = 3;
              } 
              else if (figureFlip == 3) {
                array[--blc1hi][++blc1we] = 1, array[--blc2hi][--blc2we] = 1, array[blc3hi][blc3we] = 1, array[++blc4hi][++blc4we] = 1;
                figureFlip = 0;
              }
              shMatrix(8, 15, array, figure);
            } 
                break;
            case 'a':
            blcwe1 = blc1we,
            blcwe2 = blc2we,
            blcwe3 = blc3we,
            blcwe4 = blc4we;
            if(blc1we - 1 < 0 || blc2we - 1 < 0 || blc3we - 1 < 0 || blc4we - 1 < 0 )
            {
              shMatrix(8, 15, array, figure);
            } else {
              if(array[blc1hi][blcwe1 - 1] == 2 || array[blc2hi][blcwe2 - 1] == 2 || array[blc3hi][blcwe3 - 1] == 2 || array[blc4hi][blcwe4 - 1] == 2)
              {
                /* code */
              } else{
                array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
                array[blc1hi][--blc1we] = 1, array[blc2hi][--blc2we] = 1, array[blc3hi][--blc3we] = 1, array[blc4hi][--blc4we] = 1;
                shMatrix(8, 15, array, figure);
              }
            }
            break;
            case 'd':
            blcwe1 = blc1we,
            blcwe2 = blc2we,
            blcwe3 = blc3we,
            blcwe4 = blc4we;
            if(blc1we + 2 > 8 || blc2we + 2 > 8 || blc3we + 2 > 8 || blc4we + 2 > 8 )
            {
              shMatrix(8, 15, array, figure);
            } else {
              if(array[blc1hi][blcwe1 + 1] == 2 || array[blc2hi][blcwe2 + 1] == 2 || array[blc3hi][blcwe3 + 1] == 2 || array[blc4hi][blcwe4 + 1] == 2)
              {
                /* code */
              } else{
                array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
                array[blc1hi][++blc1we] = 1, array[blc2hi][++blc2we] = 1, array[blc3hi][++blc3we] = 1, array[blc4hi][++blc4we] = 1;
                shMatrix(8, 15, array, figure);
              }
            }
            break;
            case 's':
            block1 = blc1hi;
            block2 = blc2hi;
            block3 = blc3hi;
            block4 = blc4hi;
            if(array[blc1hi][blc1we] == 2 || array[blc2hi][blc2we] == 2 || array[blc3hi][blc3we] == 2 || array[blc4hi][blc4we] == 2 || blc1hi + 2 > 15 || blc2hi + 2 > 15 || blc3hi + 2 > 15 || blc4hi + 2 > 15 || array[block1 + 1][blc1we] == 2 || array[block2 + 1][blc2we] == 2 || array[block3 + 1][blc3we] == 2 || array[block4 + 1][blc4we] == 2) {
              for(char i = 0;i < 15;i++)
              {
                  for(char j = 0;j < 8;j++){
                    if (array[i][j] == 1) 
                      array[i][j] = 2;
                  }
              }
              for(char i = 0; i < 15; i++)
              {
                char count = 0;
                for(char j = 0;j < 8;j++){
                  if (array[i][j] == 2) 
                  {
                    count++;
                    if(count == 8)
                    {
                      for(char j = 0;j < 8;j++)
                        array[i][j] = 0;
                        char m = i;
                      for(char k = m - 1; k > 0; k--)
                      {
                        for(char h = 0; h < 8; h++)
                        {
                          char g = k;
                          if(array[k][h] == 2)
                          {
                            array[k][h] = 0;
                            array[g + 1][h] = 2;
                            shMatrix(8, 15, array, figure);
    
                          }
                        }
                      }
                    }
                  }
                }
              }
              
    
    
              for(char j = 0;j < 8;j++){
                if (array[0][j] == 2) 
                  return 0;
                else
                  return 1;
              }
    
              
    
              shMatrix(8, 15, array, figure);
            } else {
              block1 = blc1hi;
              block2 = blc2hi;
              block3 = blc3hi;
              block4 = blc4hi;
              if(array[block1 + 1][blc1we] != 2 || array[block2 + 1][blc2we] != 2 || array[block3 + 1][blc3we] != 2 || array[block4 + 1][blc4we] != 2) {
                array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
                array[++blc1hi][blc1we] = 1, array[++blc2hi][blc2we] = 1, array[++blc3hi][blc3we] = 1, array[++blc4hi][blc4we] = 1;
                shMatrix(8, 15, array, figure);
              }
    
            }
            break;
            }
          }
          

    
  }
}
      




  
char createFigure(char array[15][8], char figure)
{
  char blc1we,
  blc2we,
  blc3we,
  blc4we,
  blc1hi,
  blc2hi,
  blc3hi,
  blc4hi;

  if(figure == 0){
    blc1we = 0, blc2we = 1, blc3we = 0, blc4we = 1, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  }
  else if (figure == 1){
    blc1we = 0, blc2we = 1, blc3we = 2, blc4we = 3, blc1hi = 0, blc2hi = 0, blc3hi = 0, blc4hi = 0;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  else if (figure == 2){
    blc1we = 0, blc2we = 0, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 1, blc3hi = 1, blc4hi = 1;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  else if (figure == 3){
    blc1we = 2, blc2we = 2, blc3we = 1, blc4we = 0, blc1hi = 1, blc2hi = 0, blc3hi = 0, blc4hi = 0;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  else if (figure == 4){
    blc1we = 1, blc2we = 2, blc3we = 0, blc4we = 1, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  else if (figure == 5){
    blc1we = 0, blc2we = 1, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  else if (figure == 6){
    blc1we = 1, blc2we = 0, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 1, blc3hi = 1, blc4hi = 1;
    array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
  } 
  shMatrix(8, 15, array, figure);
  return startGame(array,figure,blc1hi,blc2hi,blc3hi,blc4hi, blc1we, blc2we, blc3we, blc4we);
}
int kbhit(void);
int getch(void);

char getRand();
char getWidth(void);
char getHeight(void);
void shMatrix(char width, char height, char array[height][width], char figureNow);



// Еще не готово!


void main(void)
{
  char width = 8,
       height = 15,
       array[8][15];
  memset(array, 0, height * width);
  char figureNow = getRand();
  while(1)
  {
    char g = createFigure(array, getRand());
    if (g == 1)
    {
      printf("New figure request\n");
    } else if (g == 0) return;
      else {
        // Only for debug (Later it will be deleted)
        printf("%d\n", g);
        return;
      }
  }
  



  return;
}






short * matrixFigure(char figure)
{
  if(figure == 0)
    return "11";
  else if (figure == 1)
    return "1111";
  else if (figure == 2)
    return "1";
  else if (figure == 3)
    return "  1";
  else if (figure == 4)
    return " 11";
  else if (figure == 5)
    return "11";
  else if (figure == 6)
    return " 1 ";
}
short * matrixFigure2(char figure) 
{
  if(figure == 0)
    return "11";
  else if (figure == 1)
    return "";
  else if (figure == 2)
    return "111";
  else if (figure == 3)
    return "111";
  else if (figure == 4)
    return "11";
  else if (figure == 5)
    return " 11";
  else if (figure == 6)
    return "111";
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
  char figure = figureNow;
  char * mat = matrixFigure(figure);
  char * mat2 = matrixFigure2(figure);
  system("clear");
  for(char i = 0;i < height;i++)
  {
    printf("| ");
      for(char j = 0;j < width;j++){
        if (array[i][j] == 1) {
          printf(AC_GREEN"1 %s", AC_RESET);
        } else if (array[i][j] == 2)
          printf(AC_YELLOW"2 %s", AC_RESET);
        
         else {printf("0 ", array[i][j]);}
      }
      if(i == 3)
        printf("| Score = %d\n", 55);
      else if (i == 5)
        printf("| Now part is:\n");
      else if (i == 7)
        printf("|    %s\n", mat);
      else if (i == 8)
        printf("|    %s\n", mat2);
      else
        printf("| \n");
      
  }
}
char getRand()
{
  srand(time(NULL));
  int r = rand() % 7; // 7
  return r;
}

// Почти готово!!!!
