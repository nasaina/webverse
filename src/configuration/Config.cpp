/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:25:52 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 07:00:50 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Config.hpp>

vectorServer	Config::getServer(void) const
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

configServer	Config::checkPort(std::string input)
{
	for (vectorServer::iterator it = _server.begin(); it != _server.end(); it++)
	{
		if (it->getPort() == input)
			return (*it);
	}
	throw std::runtime_error("Unable to connect to the port specified");
	return (*(_server.begin()));
}

std::ostream	&operator<<(std::ostream &o, const Config &other)
{
	vectorServer	server = other.getServer();
	for (vectorServer::iterator it = server.begin(); it != server.end(); it++)
	{
		std::cout << "****************" << std::endl;
		std::cout << *it;
		std::cout << "****************" << std::endl;
	}
	return (o);
}

Config::~Config()
{
}