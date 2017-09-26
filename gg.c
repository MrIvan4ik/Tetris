#include <stdio.h>
#include <sys/time.h>
#include <sys/poll.h>
#include <unistd.h>
int 
main(void) {
    while(1)
    {
      int retval = poll(NULL,NULL, 2000);
      if (retval)
      {
            printf("Данные доступны.\n%d", retval);
            
      }
      else
      {
            printf("Данные не появились в течение пяти секунд.\n%d", retval);
      }
      
    }

}
