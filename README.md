#0x16. C - Simple Shell

Shellby functions as a straightforward interpreter for the UNIX command language. It processes commands from standard input or files and subsequently carries out their execution.


## Features
- Interactive command-line interface.
- Executes external commands using `execve()` system call.
- Supports basic built-in commands like `cd`, `help`, and `exit`.
- Implements simple process management with foreground and background execution.


### How to invoke

Usage: **shellby** [filename]

To invoke **shellby**, compile all .c files present in the repository, and execute the resultant executable:

```
gcc *.c -o shellby
./shellby
```

**Shellby** is capable of being activated in both interactive and non-interactive modes. In the event that **shellby** is triggered with standard input not linked to a terminal, it proceeds to read and execute the received commands sequentially.

Example:
```
$ echo "echo 'hello'" | ./shellby
'hello'
$
```

In case **shellby** is initiated with standard input linked to a terminal (which is ascertained using [isatty](https://linux.die.net/man/3/isatty)(3)), it initiates an *interactive* shell session. During interactive execution, **shellby** presents the `$ ` prompt to signal its readiness for command input.

Example:
```
$./shellby
$
```

Alternatively, in the event that command line arguments are provided during activation, the initial argument presented to **shellby** is treated as a file from which to retrieve commands. The designated file should encompass one command on each line. Subsequently, **shellby** proceeds to execute each command within the file sequentially before concluding its operation.

Example:
```
$ cat hello
echo 'hi there'
$ ./shellby hello
'hi there'
$
```

### Environment:

Upon being invoked, **shellby** acquires the copy of the environment from the parent process within which it was launched. This environment is structured as an array comprising *name-value* strings that define variables following the *NAME=VALUE* format. Several pivotal environmental variables include:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./shellby
root@0fc55635806f:/
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./shellby
root@0fc55635806f:/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$ echo "echo $OLDPWD" | ./shellby
root@0fc55635806f:/printf
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```
$ echo "echo $PATH" | ./shellby
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```

### Command Execution:

Upon receipt of a command, **shellby** proceeds to tokenize it into individual words using `" "` as the delimiter. The foremost word is recognized as the command itself, while all subsequent words are interpreted as arguments linked to that command. Subsequently, **shellby** initiates the ensuing actions:

1. If the initial character of the command doesn't comprise a forward slash (`\`) or a dot (`.`), the shell scans for it within the inventory of shell builtins. Should a builtin with that name exist, it is triggered.

2. If the first character of the command isn't a forward slash (`\`), a dot (`.`), or a recognized builtin, **shellby** examines each component of the **PATH** environmental variable to identify a directory that holds an executable file matching the command's name.

3. In case the initial character of the command is a forward slash (`\`), a dot (`.`), or if either of the above searches yields success, the shell proceeds to launch the specified program along with any remaining supplied arguments, within an isolated execution environment.


### Exit Status:
**Shellby** furnishes the exit status of the most recently executed command, where a value of zero signifies successful execution, while a non-zero value indicates failure.

In situations where a command cannot be located, the return status takes on the value `127`. When a command is discoverable but lacks executability, the return status is assigned as `126`.

Concerning builtins, they uniformly return a value of zero upon successful operation, but in the event of incorrect usage—prompted by an associated error message—the return values can be either one or two.

### Signals :exclamation:
During its operation within interactive mode, **shellby** disregards the keyboard input `Ctrl+c`. On the other hand, triggering an input for the end-of-file (`Ctrl+d`) will lead to the termination of the program.

User hits `Ctrl+d` in the third line.
```
$ ./shellby
$ ^C
$ ^C
$
```

### Variable Replacement:

**Shellby** interprets the `$` character for variable replacement.

#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.

Example:
```
$ echo "echo $PWD" | ./shellby
root@0fc55635806f:/simple_shell
```

#### $?
The symbol "`?`" is replaced with the return value of the most recently executed program.

Example:
```
$ echo "echo $?" | ./shellby
0
```

#### $$
The second `$` is substitued with the current process ID.

Example:
```
$ echo "echo $$" | ./shellby
6494
```

### Comments :hash:

**Shellby** ignores all texts preceeded by a `#` character on a line.

Example:
```
$ echo "echo 'hello' #this will be ignored!" | ./shellby
'hello'
```

### Operators:

**Shellby** specially interprets the following operator characters:

#### ; - Command separator
Commands separated by a `;` are executed sequentially.

Example:
```
$ echo "echo 'hello' ; echo 'world'" | ./shellby
'hello'
'world'
```

#### && - AND logical operator
`command1 && command2`: `command2` is executed if, and only if, `command1` returns an exit status of zero.

Example:
```
$ echo "error! && echo 'hello'" | ./shellby
./shellby: 1: error!: not found
$ echo "echo 'all good' && echo 'hello'" | ./shellby
'all good'
'hello'
```

#### || - OR logical operator
`command1 || command2`: `command2` is executed if, and only if, `command1` returns a non-zero exit status.

Example:
```
$ echo "error! || echo 'but still runs'" | ./shellby
./shellby: 1: error!: not found
'but still runs'
```

The operators `&&` and `||` have equal precedence, followed by `;`.


#### setenv
  * Usage: `setenv [VARIABLE] [VALUE]`
  * Initializes a new environment variable, or modifies an existing one.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./shellby
$ setenv NAME alx
$ echo $NAME
alx
```

#### unsetenv
  * Usage: `unsetenv [VARIABLE]`
  * Removes an environmental variable.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./shellby
$ setenv NAME alx
$ unsetenv NAME
$ echo $NAME

$
```

## Creator:

* Lynda Ndidiamaka and Asakwonye Collins onyekachi <[soloking44](https://github.com/soloking44)>
