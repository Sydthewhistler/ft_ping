#include "ft_ping.h"

void	resolve_target(t_ping *ping)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	ret = getaddrinfo(ping->target_raw, NULL, &hints, &res);
	if (ret != 0)
	{
		fprintf(stderr, "ft_ping: unknown host\n");
		exit(EXIT_FAILURE);
	}
	memcpy(&ping->dest, res->ai_addr, sizeof(ping->dest));
	freeaddrinfo(res);
	if (!inet_ntop(AF_INET, &ping->dest.sin_addr,
			ping->target_ip, sizeof(ping->target_ip)))
	{
		perror("ft_ping: inet_ntop");
		exit(EXIT_FAILURE);
	}
}
