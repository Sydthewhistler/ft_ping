#include "ft_ping.h"

static int	parse_int_arg(const char *opt_name, const char *value)
{
	char	*end;
	long	result;

	errno = 0;
	result = strtol(value, &end, 10);
	if (end == value || *end != '\0' || errno == ERANGE || result < 0)
	{
		fprintf(stderr, "ft_ping: invalid value for %s: '%s'\n",
			opt_name, value);
		exit(EXIT_FAILURE);
	}
	return ((int)result);
}

void	parse_args(int argc, char **argv, t_ping *ping)
{
	int	opt;

	ping->opts.verbose = 0;
	ping->opts.quiet = 0;
	ping->opts.help = 0;
	ping->opts.ttl = DEFAULT_TTL;
	ping->opts.count = 0;
	ping->opts.interval = DEFAULT_INTERVAL;
	ping->opts.timeout = DEFAULT_TIMEOUT;
	ping->target_raw = NULL;
	while ((opt = getopt(argc, argv, "vqht:c:i:W:")) != -1)
	{
		if (opt == 'v')
			ping->opts.verbose = 1;
		else if (opt == 'q')
			ping->opts.quiet = 1;
		else if (opt == 'h')
		{
			ping->opts.help = 1;
			return ;
		}
		else if (opt == 't')
			ping->opts.ttl = parse_int_arg("-t", optarg);
		else if (opt == 'c')
			ping->opts.count = parse_int_arg("-c", optarg);
		else if (opt == 'i')
			ping->opts.interval = parse_int_arg("-i", optarg);
		else if (opt == 'W')
			ping->opts.timeout = parse_int_arg("-W", optarg);
		else
		{
			usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (optind >= argc)
	{
		fprintf(stderr, "ft_ping: missing destination operand\n");
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	ping->target_raw = argv[optind];
}
