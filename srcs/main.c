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
	resolve_target(&ping);
	create_socket(&ping);
	ping.pid = getpid() & 0xFFFF;
	ping.seq = 0;
	ping.sent = 0;
	printf("target: %s (%s)\n", ping.target_raw, ping.target_ip);
	printf("ttl=%d count=%d interval=%d timeout=%d verbose=%d quiet=%d\n",
		ping.opts.ttl, ping.opts.count, ping.opts.interval,
		ping.opts.timeout, ping.opts.verbose, ping.opts.quiet);
	send_ping(&ping);
	close(ping.sockfd);
	return (EXIT_SUCCESS);
}
