#include "ft_ping.h"

static void	socket_error(t_ping *ping, const char *msg)
{
	perror(msg);
	close(ping->sockfd);
	exit(EXIT_FAILURE);
}

void	create_socket(t_ping *ping)
{
	struct timeval	tv;

	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0)
	{
		perror("ft_ping: socket");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(ping->sockfd, IPPROTO_IP, IP_TTL,
			&ping->opts.ttl, sizeof(ping->opts.ttl)) < 0)
		socket_error(ping, "ft_ping: setsockopt IP_TTL");
	tv.tv_sec = DEFAULT_RECV_TIMEOUT;
	if (ping->opts.timeout > 0)
		tv.tv_sec = ping->opts.timeout;
	tv.tv_usec = 0;
	if (setsockopt(ping->sockfd, SOL_SOCKET, SO_RCVTIMEO,
			&tv, sizeof(tv)) < 0)
		socket_error(ping, "ft_ping: setsockopt SO_RCVTIMEO");
}
