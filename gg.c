#include <stdio.h>   //Для puts
#include <unistd.h>   //Для alarm
#include <signal.h>   //Для signal
void MyAlarm (int var)
{     puts ("End work");
      _Exit (0); //Завершение работы программы
}

int main (void)
{ 
      puts ("Start work");
      //Привязка функции MyAlarm к сигналу SIGALRM
      signal (SIGALRM, MyAlarm);
      //Установка будильника на 10 секунд
      alarm (2);
      //Бесконечный цикл
      while (1) {printf("Le\n");}
      return 0;
}