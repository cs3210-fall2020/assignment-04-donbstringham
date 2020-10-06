# Assignment 04 - Coding a Linux Shell

Everyone use the built-in terminal in Linux distributions.  In this assignment we are going to code our own Linux shell.  Albeit a simple shell!  You will be handling some features and algorithms that actually exist in shells like sh, bash, zsh, etc.  Assignment is worth **200** points.

## Last name, first name

`Github username`

## Information For Assignment

- Must be written in C.
- Must compile and run on Linux (ie. class server or Darwin).
- All code (*.c) files must be in the `src/` folder.
- All binary files must be in the `bin/` folder.
- Use a Makefile with targets.
- Don't forget to put your name and Github user name in the `README.md` file.

## Programming a Basic Shell

- A shell REPL application (**R**ead, **E**valuate, **P**rint, **L**oop).
  - **Read**: gather inputs from a user, usually the keyboard.
  - **Evaluate**: parse and execute the input, if possible.
  - **Print**: write to `stdout` the results of evaluate.
  - **Loop**: start over again by prompting the user for more input.
- Basic execution flow:
  - Command is entered and if length is non-null, keep it in history.
  - Parse the command string into the command and it's arguments.
  - Check for built-in commands.
  - Check for special characters like pipes, etc.
  - If pipes are present, handle them.
  - Execute the built-in command.
  - Print the current directory name and ask for next input.
- **Requirements**:
  - Use the **Arrow** keys for navigating and recovering command history.
  - Use the **TAB** key for autocomplete.
  - On application start write to `stdout` who the user is.
  - On application start after the user is written to `stdout` write the current directory and prompt to `stdout`.
- **Suggestions**:
  - Use **getcwd()** for the directory name.
  - Obtain the username from the environment with `getenv("USERS")`.
  - Parsing can be done using `strsep("")`.
  - Checking the list of built-in commands can be done using `strcmp()`.
