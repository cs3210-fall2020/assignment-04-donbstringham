#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

void init()
{
  clear();
  printf("+======================+\n");
  printf("| 04 - Linux Shell     |\n");
  printf("+======================+\n\n");
}

int main()
{
  init();
  return 0;
}
