/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:25:52 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:42:55 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Config.hpp>

std::vector<configServer>	Config::getServer(void) const
{
	return (_server);
}

Config::Config(char **av)
{
	std::vector<vectorString>	tmp;

	tmp = getArg(av[1]);
	for (std::vector<vectorString>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		configServer	srv(it);
		_server.push_back(srv);
	}
}

Config::~Config()
{
}