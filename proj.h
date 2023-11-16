#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
extern char **environ;

/**
 * struct textstore - this is the structure of the project
 * @countin: this is the project
 * @uses: this is the uses and func of the project
 * @link: links to the following node
 */
typedef struct textstore
{
	int countin;
	char *uses;
	struct textstore *link;
} proj_link;

/**
 * struct fct- structure for the shell project
 * @exec: this executes the project
 * @readings: this reads the simple shell project
 * @typed: this is a type command in the project
 * @num_e: this is the no of executed code
 * @narrates: this narrates the code
 * @codes: this points to the code to be executed
 * @sur: this shows the surrounding of the code
 * @environ: locates the codes from LL sur
 * @bio: the is the codes theory
 * @align: this points to the alternate code.
 * @loc_sur: this is the surrounding change of the code
 * @stand: this is the stand of the code
 * @project: this defines the project of the cmd
 * @proj_line: this is the project line of the code
 * @memo: this the memorizing of the code
 * @bio_memo: this the history of memory code
 * @mist: this is the mistake in the code
 * @red_code: shows a bad code
 */
typedef struct fct
{
	char *exec;
	char **readings;
	char *typed;
	int num_e;
	unsigned int narrates;
	int mist;
	int red_code;
	char *codes;
	proj_link *sur;
	proj_link *bio;
	proj_link *align;
	char **environ;
	int loc_sur;
	int stand;
	char **project;
	int proj_line;
	int memo;
	int bio_memo;
} code_proj;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct core - this is the core function
 * @variant: the various core function
 * @routine: this is the rountine of the code
 */
typedef struct core
{
	char *variant;
	int (*routine)(code_proj *);
} core_repo;

/* prototype customize.c */
int loged(code_proj *);
int customize(code_proj *);

/*capture.c */
ssize_t capture(code_proj *);
int pre_read(code_proj *, char **, size_t *);
void interrupt(int);

/* function prototypes in fetch_data.c */
void plain(code_proj *);
void fix(code_proj *, char **);
void gratis(code_proj *, int);

/*prototype for chunk.c*/
int cut(char *);
int fragment(char *, char *);
char *prefix_match(const char *, const char *);
char *combine(char *, char *);

/*protype for program.c*/
char *run_program(char *, char *);
char *two_(const char *);
void print_str(char *);
int output(char);

/*prototype for handle_data.c*/
char *handle_data(char *, char *, int);
char *plus_data(char *, char *, int);
char *find_data(char *, char);

/*prototype for split_data.c*/
char **split_data(char *, char *);
char **locate(char *, char);

/* prototype for terminal.c*/
int foo(code_proj *, char **);
int setup_program(code_proj *);
void show_prompt(code_proj *);
void exec_task(code_proj *);

/*prototype for input.c */
int input(code_proj *, char *);
char *foo_bar(char *, int, int);
char *locate_dir(code_proj *, char *, char *);

/* prrototype for msh.c */
int msh(char **);

/*prototype for plus.c*/
void subst_vals(char *);
int swap(char);
int append_str(char dest, int prt);
int write_to(char *uses, int prt);

/* prototype for resize.c */
char *set(char *, char, unsigned int);
void release(char **);
void *resize(void *, unsigned int, unsigned int);

/* prototype for dyn_ops.c */
int _dynops(void **);

/* info_ops.c*/
int _check(code_proj *);
int process(char, char *);
int handleInfo(int);
int infoops(char *);

/* strint.c */
int strint(char *);
void show(code_proj *, char *);
int disp(int, int);
char *fmt(long int, int, int);
void strip(char *);

/* terminate.c */
int terminate(code_proj *);
int navigate(code_proj *);
int assist(code_proj *);

/* function prototypes in config_envi.c */
char *bring(code_proj *, const char *);
int circles(code_proj *);
int n_sur(code_proj *);
int not_b(code_proj *);
int expand(code_proj *);

/* verify.c */
int verify(code_proj *, char *, size_t *);
void validate(code_proj *, char *, size_t *, size_t, size_t);
int substitute(code_proj *);
int anod(code_proj *);
int modify(char **, char *);

/* function prototypes in fetch_env_var.c*/
char **catch_r(code_proj *);
int relive(code_proj *, char *);
int views(code_proj *, char *, char *);

/* prototypes in command_trace.c */
char *cmd_trace(code_proj *codep);
int text_h(code_proj *codep);
int learn_(code_proj *codep);
int constru(code_proj *codep, char *bre, int draws);
int memo_trace(code_proj *codep);

/* data_stru.c */
proj_link *data_stru(proj_link **, const char *, int);
proj_link *put_n(proj_link **, const char *, int);
size_t out(const proj_link *);
int remove_n(proj_link **, unsigned int);
void lib_n(proj_link **);

/* elements.c */
size_t elements(const proj_link *);
char **convert(proj_link *);
size_t display(const proj_link *);
proj_link *find(proj_link *, char *, char);
ssize_t position(proj_link *, proj_link *);

#endif
