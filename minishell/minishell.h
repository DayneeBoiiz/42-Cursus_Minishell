/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:02:44 by zkasmi            #+#    #+#             */
/*   Updated: 2022/04/14 00:03:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CLEAR_SCREEN "\033[?1049h\033[H"
# define BUFF_SIZE 4096

# include <dirent.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <dlfcn.h>
# include "./Libft/libft.h"
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./ft_perror/ft_perror.h"

typedef struct s_data
{
	char				**path;
	int					ipath;
	char				**av;
	char				**line;
	char				**pline;
	int					*fd;
	char				*inpt;
	char				*check;
	char				**pdir;
	char				*dir;
	char				*pwd;
	char				*direction;
	char				*direction2;
	int					i;
	char				*tocheck;
	int					fdq;
	char				**sline;
	char				**env;
	char				*val;
	char				*name;
	struct s_export		*exp;
	struct s_env		*enva;
	int					redi;
	int					y;
	int					len;
	char				*fpath;
	char				*msg;
	char				*npwd;
	char				*fecho;
	char				*str1;
	char				*sx;
	char				*sx1;
	char				*sx2;
	char				*sx3;
	char				*sx4;
	char				**xplit;
	char				*xss;
	char				*nanox;
	char				*fullx;
	char				*strx1;
	int					ix;
	int					jx;
	int					lenx;
	int					blenx;
	int					lx;
	char				*strx;
	char				**rtabx;
	char				*tmpx;
	char				**plinex;
	char				*xxr;
	char				*linex;
	char				*stockx;
	char				**hx;
	char				*trimx;
	char				**nex;
	char				*namex;
	char				*svalx;
	char				*s;
	char				*s2;
	char				*s3;
	char				*line1;
	char				*home;
	int					filefd;
	char				**dex;
	char				*fpathx;
	char				*tpathx;
	char				**pathx;
	char				**fpathx1;
	char				*tmpx1;
	char				**xtpath;
	char				**xpath;
	char				*xfpath;
	char				*xtmp;
	char				**xdouple;
	int					xfilefd;
	char				*xxfpath;
	int					fdd;
	char				*xsx;
	char				*xsx1;
	char				**phx;
	pid_t				*pid;
	int					elock;
	int					lock;
	int					lock2;
	int					plock;
	int					lenls;
	int					len_nex;
	char				**lline;
	int					k;
	char				**plit;
	struct s_token		*start;
	int					exlock;
	int					hered;
	int					echohere;

}	t_data;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_export
{
	char			*data;
	struct s_export	*next;
}	t_export;

typedef struct s_cmd
{
	char			*new_arg;
	int				i;
	int				j;
}				t_cmd;

struct s_v
{
	int	codestatus;
	int	wstatus;
	int	plock;
	int	dlock;
} t_v;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

t_data				*getpath(int ac, char **av);
void				exec(char *input, t_data *data);
void				setall(char *input, t_data *data);
void				cdfun(char *input, t_data *data);
void				signalinit(void);
void				handler(int arg);
char				*getdir(t_data *data);
void				ft_export(t_data *data, t_env *env);
void				ft_env(t_data *data);
char				*findpath(t_data *data, char *line);
int					ft_tocheck(t_data *data, char c);
int					ft_tocheckv2(char *str);
int					pipecheck(char *input);
void				pwd(t_data *data);
int					ft_tocheckv3(char *str);
struct s_env		*set_env(t_data *data, char **envp);
void				all_export(char *input, t_data *data);
struct s_export		*set_export(t_data *data);
void				get_val(t_data *data, char *str);
int					check_eq(t_data *data);
int					get_eq(char *str);
void				all_env(t_data *data);
void				print_env(t_data *data);
void				heredoc(t_data *data, int *fd);
void				ft_unset(char *input, t_data *data);
void				delete_lst(t_data *data, char *name);
int					checkquotes(char *str);
int					check_redi(char *str);
void				ft_change(char *str);
void				ft_strerror(t_data *data, int check);
void				free_env(t_data *data);
int					ft_space(char *input);
int					booler(t_data *data, char *str);
int					booler2(t_data *data, char *str);
void				free_all(t_data *data);
int					check_doc(char *str);
char				*quotesremove(char *str);
char				*quotesremove_mini(char *str);
int					ft_get_error(char *str);
void				print_export(t_data *data);
int					boolerv3(char *name, char *str);
int					boolerv4(char *name, char *str);
void				ft_set_pwd(t_data *data);
void				ft_set_pwd_export(t_data *data);
void				ft_shlvl(t_data *data);
int					ft_exit(t_data *data);
void				find_directionb_beta2(char *input, t_data *data, int k);
void				first_if(t_export *tmp, t_data *data, char *pwd);
void				secondif(t_export *tmp, t_data *data, char *pwd);
void				ft_set_pwd_firstif(t_env *tmp, char *s, char *pwd);
void				ft_change_pwd_firstif(t_export *tmp,
						t_export *tmp2, t_data *data);
void				ft_change_pwd_fsecondif(t_export *tmp, t_data *data,
						char *pwd);
void				ft_change_pwd_first_if(t_env *tmp, t_env *tmp2,
						t_data *data);
void				ft_change_pwd_second_if(t_env *tmp, t_data *data,
						char *pwd);
void				cdfun_utils(t_data *data, DIR *dir);
void				free_dbl(t_data *data);
void				ft_change_pwd(t_data *data);
void				ft_change_pwd_export(t_data *data);
void				ft_change_pwd_hello(t_env *tmp, t_data *data, char *pwd);
int					ft_get_str(char *str, int i, int j, int k);
int					str_check(char *str, int i);
int					ft_llol(int k, int j, char *str, int i);
void				free_pdir(char **pdir);
int					geti(char *input1);
void				find_directionb_beta(char *input, t_data *data, int k);
void				cleaner(char *tmp, t_data *data, int k, int i);
char				*direction_check_beta(char *str);
int					check_list2(t_data *data);
void				get_val2(t_data *data, int i, int j, char *str);
int					check_list(t_data *data);
char				*get_line(t_data *data, char *line);
char				*free_path(t_data *data);
void				find_path2(t_data *data, int l, char *line);
void				ft_get_direction2(t_data *data, int k, int *fd);
void				ft_get_direction(t_data *data, int k);
void				ft_if_direction(t_data *data, int k);
void				ft_if_heredoc(t_data *data, int k, int *fd);
void				ft_execve(t_data *data);
void				ft_parent(t_data *data, int *fd);
void				free_execve(t_data *data);
int					ft_fork(t_data *data, int k, int *fd);
int					checkmoney(char *str);
char				*dollar_line(char *input, t_data *data);
void				ft_set_fun(char *input, t_data *data);
void				setall2(char *input, t_data *data);
void				freethis(t_data *data);
int					ft_parsingcheck(char *str);
void				ft_init(t_data *data);
char				*ft_get_env(t_data *data, char *name);
void				to_be_continued(t_data *data);
void				print_pwd(t_data *data);
int					expo_checker(char *str);
void				ft_handle_error(t_data *data);
char				*quotesremove_mini2(char *str);
void				ft_change_parsing(char **str);
t_token				*get_tokens(char *line);
int					if_char(int c);
char				*ft_big_dollar(char *str, t_data *data);
char				*space_line(char *line);
int					ft_echo(char *line, t_data *data);
char				*ft_environment(char *arg, t_data *data, int ret);
char				**cmd_tab(t_token *start);
int					ft_str_len(const char *arg, int pos, t_data *data, int ret);
void				*ft_memdel(void *ptr);
t_export			*expo_delt(t_export *xtmp, t_export *delete);
t_env				*env_delt(t_env *etmp, t_env *edelete);
void				type_arg(t_token *token, int separator);
char				**ft_echo1(char *line, t_data *data);
void				set_here(char **str, t_data *data);
void				get_val2(t_data *data, int i, int j, char *str);
char				*val_change(char *str, t_data *data);
char				*ft_split_join(char **cmd);
void				get_val(t_data *data, char *str);
int					expo_checker(char *str);
void				echo_free(t_data *data, char *line1, char *line);
char				*clean_space(char *str);
void				do_magic(char *str);
int					do_magic_utils(char *str);

#endif