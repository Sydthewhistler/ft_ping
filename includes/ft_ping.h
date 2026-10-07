#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <stdint.h>
# include <netinet/ip_icmp.h>

# define DEFAULT_TTL        64
# define DEFAULT_INTERVAL   1
# define DEFAULT_TIMEOUT    -1
# define DEFAULT_PKT_SIZE   56
# define DEFAULT_RECV_TIMEOUT 1
# define PACKET_SIZE        (sizeof(struct icmphdr) + DEFAULT_PKT_SIZE)

typedef struct s_options
{
	int		verbose;    // -v
	int		quiet;      // -q
	int		help;       // -h
	int		ttl;        //-t <n>
	int		count;      // -c <n>, 0 = illimite
	int		interval;   // -i <n>
	int		timeout;    // -W <n>
}	t_options;

typedef struct s_ping
{
	t_options			opts;
	const char			*target_raw;
	struct sockaddr_in	dest;
	char				target_ip[INET_ADDRSTRLEN];
	int					sockfd;
	uint16_t			pid;
	uint16_t			seq;
	long				sent;
}	t_ping;

void		usage(const char *prog_name);
void		parse_args(int argc, char **argv, t_ping *ping);
void		resolve_target(t_ping *ping);
void		create_socket(t_ping *ping);
uint16_t	checksum(void *data, size_t len);
int			send_ping(t_ping *ping);

#endif
