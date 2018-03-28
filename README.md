# simple_shell

### Installation

compile with: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Documentation

- header.h - simple_shell's prototypes
- shell.c - shell main function
- type_prompt.c - prints "$ " prompt
- read_cmd.c - reads user input for command to execute, along with parameters
- location_check.c - looks if cmd exist in current directory
- find_cmd.c - searches the systems PATHs for a command
- child.c - searches for command and executes
- write_nope.c - error message if command is not found
- print_env.c - built-in command that prints environment variables
- _kill.c - exits process

Recreate some of string functions:
- _strcat.c - concatenates a string to another
- _strcmp.c - compares string to another
- _strncmp.c - compares n characters of one string to another
- _strlen.c - calculates and returns the length of a string
- _strcpy.c - copies a string to a buffer
- _itoa.c - convert int to string

Others:
- Authors - authors of simepl_shell
- man_1_simple_shell - man page for simple_shell
- test - folder for testing
### Usage

Run the following command to check if simple_shell works:

To launch simple shell:
```ShellSession
./hsh
```

Example: [command] [options]
```ShellSession
$ env
```
```ShellSession
$ ls -la
```

To exit simple_shell:
```ShellSession
$ exit
```

### Authors

Max Stuart, Adriel Tolentino, Michael Schechner
