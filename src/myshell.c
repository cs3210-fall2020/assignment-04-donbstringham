#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define CMD_BUF_SIZE 1024
#define CMD_EXIT_STR "exit"
#define CMD_HELP_STR "help"
#define CMD_LS_STR "ls"
#define CMD_CP_STR "cp"
#define CMD_RM_STR "rm"
#define CMD_CAT_STR "cat"
#define CMD_GSTATUS_STR "gstat"

void init()
{
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

  printf(">>>> Are you sure (Y/N)? ");
  ch = fgetc(stdin);

  if (ch == 'Y' || ch == 'y')
  {
    exit(0);
  }
}
/**
 * Built-in Command: HELP 
 */
void showHelp()
{
  printf("+======================+\n");
  printf("|       mysh help      |\n");
  printf("+======================+");
  puts(
      "\nList of supported commands:"
      "\n> cd"
      "\n> ls"
      "\n> help"
      "\n> exit");

  return;
}

int readStdin(char *str)
{
  char *buf;

  buf = readline("\n>>>> ");

  if (strlen(buf) != 0)
  {
    add_history(buf);
    strcpy(str, buf);

    return 0;
  }

  return 1;
}

int parseStdin(char *cmd)
{
  printf("\ncmd> %s\n", cmd);

  return 1;
}

void printDir()
{
  char cwd[CMD_BUF_SIZE];
  getcwd(cwd, sizeof(cwd));
  printf("\ndir> %s", cwd);
}

/**
 * main(): applications entry point
 */
int main()
{
  char cmd[CMD_BUF_SIZE];

  init();

  while (1)
  {
    printDir();
    if (readStdin(cmd))
    {
      continue;
    }

    // Parse the user's input
    int execFlg = parseStdin(cmd);

    if (strcmp(cmd, CMD_HELP_STR) == 0)
    {
      showHelp();
    }

    if (strcmp(cmd, CMD_EXIT_STR) == 0)
    {
      quit();
    }
    // TODO Search for built-in command
    // TODO Pass in arguments from input to the command function
    // TODO Execute the command function. NOTE: Inform the user via output to stdout/stderr
  }
}
