#include "ft_ping.h"

uint16_t	checksum(void *data, size_t len)
{
	uint16_t	*buf;
	uint32_t	sum;

	buf = data;
	sum = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(uint8_t *)buf;
	while (sum >> 16)
		sum = (sum & 0xFFFF) + (sum >> 16);
	return ((uint16_t)~sum);
}

static void	build_packet(t_ping *ping, uint8_t *packet)
{
	struct icmphdr	*icmp;
	struct timeval	now;
	size_t			i;

	memset(packet, 0, PACKET_SIZE);
	icmp = (struct icmphdr *)packet;
	icmp->type = ICMP_ECHO;
	icmp->code = 0;
	icmp->un.echo.id = htons(ping->pid);
	icmp->un.echo.sequence = htons(ping->seq);
	gettimeofday(&now, NULL);
	memcpy(packet + sizeof(*icmp), &now, sizeof(now));
	i = sizeof(*icmp) + sizeof(now);
	while (i < PACKET_SIZE)
	{
		packet[i] = (uint8_t)i;
		i++;
	}
	icmp->checksum = checksum(packet, PACKET_SIZE);
}

int	send_ping(t_ping *ping)
{
	uint8_t	packet[PACKET_SIZE];
	ssize_t	sent;

	build_packet(ping, packet);
	sent = sendto(ping->sockfd, packet, PACKET_SIZE, 0,
			(struct sockaddr *)&ping->dest, sizeof(ping->dest));
	if (sent < 0)
	{
		perror("ft_ping: sendto");
		return (-1);
	}
	ping->seq++;
	ping->sent++;
	return (0);
}
