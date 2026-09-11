#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

# define DEFAULT_TTL        64
# define DEFAULT_INTERVAL   1
# define DEFAULT_TIMEOUT    -1
# define DEFAULT_PKT_SIZE   56

typedef struct s_options
{
	int		verbose;    /* -v */
	int		quiet;      /* -q */
	int		help;       /* -h */
	int		ttl;        /* -t <n> */
	int		count;      /* -c <n>, 0 = illimite */
	int		interval;   /* -i <n> */
	int		timeout;    /* -W <n> */
}	t_options;

typedef struct s_ping
{
	t_options	opts;
	const char	*target_raw;
}	t_ping;

void	usage(const char *prog_name);
void	parse_args(int argc, char **argv, t_ping *ping);

#endif
