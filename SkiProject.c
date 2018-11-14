#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char schedule[5][20], name1[20], phone[5][8];
int groups[5], i;
int on = 1;
int count = 0;



void schedule_a_time(void)
{
  char phone_number[8];
  int i, j, group_size, flag;
  flag =1;
  if(count == 5)
    {
      printf("Sorry no times available. Please try again on a later date.\n");
  
    }

  else
  {
    printf("What is your name?\n");
    scanf(" %s", &name1);
    
    for(i = 0;  i < 5; i++)
    {
      if(strcmp (schedule[i], name1) == 0)
      { 
        flag = 0;
        printf("The name %s has already been scheduled.\n", name1);
        break;
      }
    }
    
    if(flag == 1)
    {
      printf("How many? No more than 4\n");
      scanf(" %d", &group_size);
      if(group_size > 0 && group_size < 5)
      {
        printf("Phone Number?\n");
        scanf(" %s", &phone_number);
        //Copies Over Input Phone String to Phone Array 
        for(j = 0; j < strlen(phone_number); j++)
        {
          phone[count][j] = phone_number[j];
        }
        
        // Copies Group Size to Group Array
        groups[count] = group_size;
        
        //Copies Over Input Name String to Schedule Array 
        for(j = 0; j < strlen(name1); j++)
        {
          schedule[count][j] = name1[j];
        }
        printf("%s, you are scheduled for %d pm.\n", schedule[count], count + 1);
        count += 1;
      }
      else 
      {
        printf("Invalid Party Size.\n");

      }
    }
  }
  return;
}

void cancel_a_time(void)
{
  char temp;
  int i, j, k,flag;
  flag = 0;
  temp = phone[4];
  printf("Which name would you like to cancel?\n");
  scanf(" %s",&name1);
  printf("Looking for %s\n", name1);
    for(i = 0;  i < 5; i++)
    {
      if(strcmp (schedule[i], name1) == 0)
      {
        printf("%s, Your %d pm is canceled. Phone number is %s\n", name1, i + 1, phone[i]);
        count -= 1;
        flag = 1;
        
        if(i == 4)
        {
          for(j = 0; j < 20; j++)
              schedule[4][j]='\0';
          
          for(j = 0; j < 8; j++)
              phone[4][j]='\0';

          groups[4] = 0;
        }
        else
        {
          for(j = i; j < 4; j++)
          {
            //Change Name
            for(k = 0; k < 20; k++)
            {
              schedule[j][k] = schedule[j+1][k];
            }
            
               //Change Phone
            for(k = 0; k <8; k++)
            {
              phone[j][k] = phone[j+1][k];
            }
              //Change Group
              groups[j] = groups[j+1];
              if(schedule[j][0] != '\0')
              {
                printf("%s has been changed to %d pm. Phone number is %s. Group size is %d\n", schedule[j], j + 1, phone[j], groups[j]);
              }
          }
          
            for(j = 0; j < 20; j++)
                schedule[4][j]='\0';
            
            for(j = 0; j < 8; j++)
                phone[4][j]='\0';
           
            groups[4] = 0;
        }
        
       

        break;
      }
    }
      if(flag == 0)
        printf("Sorry that name has not scheduled a time. Please enter a different name.\n");
   return; 
}

void list_time(void)
{
  int i;
  if(count == 0)
  {
  printf("All classes are Available\n");

  }
  else
  {
  for(i = 0; i < 5; i++)
    {
      if(strcmp (schedule[i], "\0") == 0)
      {
        printf("The %d pm is Available\n", i + 1);
      }
      else
      {
        printf("The %d pm is booked by %s. Phone Number is %s. Group size is %d \n", i + 1, schedule[i], phone[i], groups[i]);
      }
    }
  }
  return;
}

void letter_search(void)
{
  char letter;
  int flag, i;
  if(count == 0)
  {
    printf("No classes have been scheduled.\n");

  }
  else
  {
    printf("Input a letter to show names starting with that letter.\n");
    scanf(" %c",&letter);
    flag = 0;
    for(i = 0; i < 5; i++)
      {
        if(schedule[i][0] == letter)
        {
          printf("%s is scheduled.\n", schedule[i]);
          flag = 1;
        }
        
      }
    if(flag == 0)
      {
        printf("No names found starting with the letter %c.\n",letter);
      }

  }
  return;
}

void group_search(void)
{
  int number;
  int flag, i;
  if(count == 0)
  {
    printf("No classes have been scheduled.\n");

  }
  else
  {
    printf("Input a number to find groups matching that size.\n");
    scanf(" %d",&number);
    flag = 0;
    for(i = 0; i < 5; i++)
      {
        if(groups[i] == number && schedule[i][0] != '\0' )
        {
          printf("%s has a party of %d at %d pm.\n", schedule[i], groups[i], i+1);
          flag = 1;
        }
        
      }
    if(flag == 0)
      {
        printf("No groups of %d found.\n",number);
      }
  }
  return;
}

int priority()
{
  char phone_number[8];
  int i, j, group_size, flag;
  flag =1;
  printf("What is your name?\n");
    scanf(" %s", &name1);
    
    for(i = 0;  i < 5; i++)
    {
      if(strcmp (schedule[i], name1) == 0)
      { 
        flag = 0;
        printf("The name %s has already been scheduled.\n", name1);
        break;
      }
    }
    
    if(flag == 1)
    {
      printf("How many? No more than 4\n");
      scanf(" %d", &group_size);
      if(group_size > 0 && group_size < 5)
      {
        printf("Phone Number?\n");
        scanf(" %s", &phone_number);

        if(schedule[4][0] != '\0')
        {
          printf("%s has been canceled. Phone number is %s. Group size is %d.\n", schedule[4], phone[4], groups[4]);
        }
        //Copies Over previous position of Phone Array to current position of Phone Array
        for(j = 0; j < 7; j++)
        {
          phone[4][j] = phone[3][j];
          phone[3][j] = phone[2][j];
          phone[2][j] = phone[1][j];
          phone[1][j] = phone[0][j];
          phone[0][j] = phone_number[j];
        }
        
        // Copies  Previous Group Size to  current Group Array
        groups[4] =  groups[3];
        groups[3] =  groups[2];
        groups[2] =  groups[1];
        groups[1] =  groups[0];
        groups[0] = group_size;

        //Copies Over previous position of Schedule Array to current position of schedule array
        for(j = 0; j < 19; j++)
        {
           schedule[4][j] = schedule[3][j];
           schedule[3][j] = schedule[2][j];
           schedule[2][j] = schedule[1][j];
           schedule[1][j] = schedule[0][j];
          schedule[0][j] = name1[j];
        }

        printf("%s, is scheduled for %d pm.\n", schedule[0], 1);
        i = 1;
        while(schedule[i][0] != '\0' && i < 5)
        {
          printf("%s has been changed to %d pm. Phone number is %s. Group size is %d.\n", schedule[i], i + 1, phone[i], groups[i]);
          i++;
        }

        if(count < 5)
        {
          count += 1;
        }
        return 1;
      }
      else 
      {
        printf("Invalid Party Size.\n");

      }
    }
  
}

void quit_system(void)
{
  printf("Come again!\n");
  on = 0;
  return;           
}

int main(void)
{
  int i, j, priority_flag;
  int input;
  input = 0;
  priority_flag = 0;

  for(i = 0; i < 5; i++)
  {
    for(j = 0; j < 20; j++)
      schedule[i][j]='\0';
  }

  for(i=0; i < 5; i++)
  {
    groups[i] = 0;
  }

  //Prompt
  printf("Welcome.\n Enter\n 1 for Scheduling,\n 2 for Canceling,\n 3 for Available times,\n 4 for Letter Search,\n 5 for Group Search,\n 6 for Priority,\n and 9 for Exiting Sysetm: \n ");
  while(on == 1)
  {
    input = 0;

    //Input
    printf("Choose an option: \n");
    scanf(" %d", &input);
    switch(input)
      {

        //Schedule a Time
        case 1:
          schedule_a_time(); 
        break;
        
        //Cancel a Time
        case 2:
          cancel_a_time();
        break;
        
        // List Times
        case 3:
          list_time();
        break;
          
        //Letter Search;
        case 4:
         letter_search();
        break;
        
        //Group Search
        case 5:
          group_search();
        break;

        //Priority 
        case 6:
          if(priority_flag == 0)
          {
            priority_flag =  priority();
            break;
          }
          else
          {
            printf("Priority already used.\n");
            break;
          }
        
        
        //Quit System
        case 9:
          quit_system();
        break;
        
        default:
          printf("Error. Invalid Keystroke. Please try again.\n");

        }
    }
}


