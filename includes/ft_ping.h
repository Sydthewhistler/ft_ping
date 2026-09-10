#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Valeurs par defaut, utilisees tant que l'utilisateur ne les
** ecrase pas avec une option (-t, -i, -c, -W).
*/
# define DEFAULT_TTL        64
# define DEFAULT_INTERVAL   1
# define DEFAULT_TIMEOUT    -1  /* -1 = pas de timeout / pas de limite */
# define DEFAULT_PKT_SIZE   56  /* taille du payload, comme le ping systeme */

/*
** Toutes les options passees en ligne de commande, remplies par
** parse_args() (prochaine etape).
*/
typedef struct s_options
{
	int		verbose;    /* -v */
	int		quiet;      /* -q */
	int		help;       /* -h */
	int		ttl;        /* -t <n> */
	int		count;      /* -c <n>, 0 = illimite */
	int		interval;   /* -i <n>, secondes entre deux paquets */
	int		timeout;    /* -W <n>, secondes d'attente d'une reponse */
}	t_options;

/*
** Contexte global du programme. Il s'enrichira au fil des prochaines
** etapes (adresse resolue, socket, statistiques...).
*/
typedef struct s_ping
{
	t_options	opts;
	const char	*target_raw;   /* argv de la cible, tel que donne par l'utilisateur */
}	t_ping;

#endif
