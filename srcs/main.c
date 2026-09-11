#include "ft_ping.h"

int	main(int argc, char **argv)
{
	t_ping	ping;

	parse_args(argc, argv, &ping);
	if (ping.opts.help)
	{
		usage(argv[0]);
		return (EXIT_SUCCESS);
	}
	printf("target: %s\n", ping.target_raw);
	printf("ttl=%d count=%d interval=%d timeout=%d verbose=%d quiet=%d\n",
		ping.opts.ttl, ping.opts.count, ping.opts.interval,
		ping.opts.timeout, ping.opts.verbose, ping.opts.quiet);
	return (EXIT_SUCCESS);
}
