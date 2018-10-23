#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
  int on, i, input, count, time1, n;
  int schedule[5]={0,0,0,0,0};
  on = 1;
  input = 0;
  time1 = 0;
  count = 0;
  printf("Welcome. Enter 1 for Scheduling, 2 for Canceling, 3 for Available times, and 9 for Exiting Sysetm: \n ");
  while(on == 1)
  {
    //Prompt
    input = 0;

    printf("Choose an option: \n");
    scanf(" %d", &input);

    switch(input)
        {

        //Schedule a Time

        case 1:
          if(count == 5)
            {
              printf("Sorry no times available. Please try again on a later date.\n");
              fflush(stdin);
            }

          else
          {
            for(i = 0; i < 5; i++)
            {
              if(schedule[i] == 0)
              {
                schedule[i] = 1;
                count += 1;
                printf("You are scheduled for %d pm.\n", i + 1);
                i = 6;
                input = 0;
              }
            }
          }
          input = 0;
        break;

        //Cancel a Time
        case 2:
          printf("What time would you like to cancel?\n");
          scanf(" %d",&time1);
          if(time1 >=0 && time1 <= 5)
          {
              if(schedule[time1 - 1] == 1)
              {
                schedule[time1 - 1] = 0;
                count -= 1;
                printf("Your %d pm is canceled.\n", time1);
              }
              else
                printf("Sorry that time has not been scheduled. Please enter a different time.\n");
          }
          else
          {
            printf("Sorry that time is not available to cancel. Please enter a different time.\n");
          }
        break;

        // List Times
        case 3:
          if(count == 0)
          {
            printf("All classes are Available\n");

          }
          else if(count == 5)
          {
            printf("No classes are Available\n");

          }
          else
          {
            for(i = 0; i < 5; i++)
              {
                if(schedule[i] == 0)
                {
                  printf("The %d pm is Available\n", i + 1);
                }
                else
                {
                  printf("The %d pm is Booked\n", i + 1);

                }
              }
            }
          break;

        //Quit System
        case 9:
          printf("Come again!\n");
          on = 0;
          break;


        default:
              return 0;
              printf("Error. Invalid Keystroke. Please try again.\n");



        }

    }

}
