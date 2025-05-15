/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:42:47 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/15 13:10:21 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(char *input)
{
	if (!validate_input(input))
		return (ERROR);
	return (SUCCESS);
	
}




// bool process_input_line(t_data *data, char *input_line)
// {
// 	t_cmd	*cmd;
	
// 	if (!input_line || !*input_line)
// 	{
// 		data->return_value = 0;
// 		return (false);
// 	}
// 	//printf("received input: %s\n", input_line);
// 	cmd = malloc(sizeof(t_cmd));
// 	if (!cmd)
// 	{
// 		ft_putstr_fd(ERR_MALLOC, STDERR_FILENO);
// 		return (false);
// 	}
// 	ft_memset(cmd, 0, sizeof(t_cmd));
// 	cmd->cmd = ft_strdup(input_line);
// 	cmd->type = CMD;
// 	data->cmd = cmd;
// 	return (true);
// }

/*
Créer le point de départ du traitement en récupérant l'entrée que 
utilisateur donnée au shell, par exemple "ls -l | grep txt".

Il vérifie la chaîne char *input_line reçue(pour voir si elle est vide ou valide).

Il associe cette entrée à la structure t_data qui contient l'état général du shell.
Par exemple : le champ cmd de data reçoit la première structure de commande.

Il prépare la base pour les étapes suivantes comme le tokenizer ou le parser.
Plus tard, l'entrée y sera divisée en parties.

ft_memset est utilisé pour réinitialiser les pointeurs, entiers et booléens,
afin de pouvoir les réutiliser correctement
et pour initialiser sans erreur les structures ou tableaux.

En résumé, c'est la fonction de démarrage utilisée 
pour commencer à traiter la chaîne d'entrée utilisateur
et l'intégrer correctement dans la structure de données t_data du shell.

*/
