/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/13 18:48:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/* Simplification aliases */
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;

/* Structs */
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_philo
{
	int			nbr;
	int			id;
	int			meals_eaten;
	int			feeded;
	t_time		last_meal;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
	t_table		*table;
};

struct s_table
{
	int			nbr_phs;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			meals_req;
	int			stop;
	int			feast_end;
	t_mutex		*forks;
	t_mutex		start_thds;
	t_mutex		life_check;
	t_mutex		print_m;
	t_mutex		data_m;
	t_philo		*philos;
	pthread_t	*thds;
	long long	start_t;
};

/************* philo **************/
long long		t_ms(t_table *table);
void			*routine(void *arg);
int				create_threads(t_table *table);

/************* ph_checkers **************/
long long int	ft_atol(const char *str);
int				ft_isdigit(char *str);
int				ft_arg_range(int argc, char **argv);
int				arg_is_int(int argc, char **argv);
int				arg_chck(int argc, char **argv);

/************ ph_init *************/
int				init_table(int argc, char **argv, t_table *table);
int				init_philos(t_table *table, int nbr_philo);
int				init_mutex(t_table *table);

/************ ph_routine ************/
void			think(t_table *table, int id);
void			pick_up_forks(t_table *table, int id, int l_fork, int r_fork);
void			eat(t_table *table, int id);
void			put_down_forks(t_table *table, /*int id,*/ int l_fork, int r_fork);
void			sleep_philo(t_table *table, int id);

/************ ph_utils ***************/
void			destroy_all(t_table *table);

/************ ph_destroy ***************/
void			destroy_mutexes(t_table *table);
void			destroy_forks(t_table *table);
void			free_threads(t_table *table);
void			free_forks(t_table *table);
void			free_philos(t_table *table);

/************* ph_print **************/
int				info(char c);
void			handling(void);
void			initfeast(int argc, char **argv);

/*********** color defines ************/
# define RD		"\033[1;31m"
# define GR		"\033[1;32m"
# define YL		"\033[1;33m"
# define BL		"\033[1;34m"
# define PK		"\033[0;35m"
# define PP		"\033[1;35m"
# define CY		"\033[1;36m"
# define F		"\033[0m"

#endif
