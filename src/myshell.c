#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define CMD_BUF_SIZE 1024
#define CMD_EXIT_STR "exit\n"
#define CMD_LS_STR "ls\n"
#define CMD_CP_STR "cp\n"
#define CMD_RM_STR "rm\n"
#define CMD_CAT_STR "cat\n"
#define CMD_GSTATUS_STR "gstat\n"

void init()
{
  // clear();
  printf("+======================+\n");
  printf("|       04 - mysh      |\n");
  printf("+======================+\n");
  printf("User: %s\n\n", getenv("USER"));
}

/**
 * Built-in Command: QUIT
 */
void quit()
{
  char ch;

  printf("Are you sure (Y/N)? ");
  ch = fgetc(stdin);

  if (ch == 'Y' || ch == 'y')
  {
    exit(0);
  }
}

/**
 * eoi(): Get user's input from the keyboard
 */
int eoi()
{
  int ret;
  char buf[CMD_BUF_SIZE];

  printf("what> ");
  fgets(buf, CMD_BUF_SIZE - 1, stdin);
  printf("    > %s", buf);

  if (strcmp(buf, CMD_EXIT_STR) == 0)
  {
    quit();
  }

  // TODO Parse the user's input
  // TODO Search for built-in command
  // TODO Pass in arguments from input to the command function
  // TODO Execute the command function. NOTE: Inform the user via output to stdout/stderr

  return 0;
}

/**
 * main(): applications entry point
 */
int main()
{
  init();
  while (!eoi())
  {
    printf("    > thinking...\n");
  }
}
