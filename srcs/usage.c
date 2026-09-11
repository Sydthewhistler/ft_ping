#include "ft_ping.h"

void	usage(const char *prog_name)
{
	fprintf(stderr, "Usage: %s [-v] [-h] [-t ttl] [-c count] "
		"[-i interval] [-W timeout] <destination>\n", prog_name);
	fprintf(stderr, "  -v            verbose output\n");
	fprintf(stderr, "  -h            show this help and exit\n");
	fprintf(stderr, "  -t <ttl>      set the IP time to live\n");
	fprintf(stderr, "  -c <count>    stop after <count> replies\n");
	fprintf(stderr, "  -i <seconds>  wait <seconds> between packets\n");
	fprintf(stderr, "  -W <seconds>  time to wait for a reply\n");
}
