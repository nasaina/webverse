/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/22 17:36:48 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>
#include <Location.hpp>
#include <configServer.hpp>

std::vector<vectorString>	getArg(char *av)
{
	std::fstream				fs;
	std::string					filename = (std::string)av;
	std::string					tmp;
	vectorString				cTmp;
	std::vector<vectorString>	config;

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: unable to open your file");
	std::string line;
	while (std::getline(fs, line))
	{
		tmp.append(line);
		if (line[line.length() - 1] == '{')
		{
			if (trimSpace(line) != "server" && trimSpace(line) != "location" && trimSpace(line) != "cgi")
				throw std::runtime_error("Error: config should start with \"server {\"");
		}
		cTmp.push_back(line);
		tmp.append("\n");
	}
	if (!checkBrace(tmp))
		throw std::runtime_error("Error: config should start with \"server {\"");
	config = getServer(cTmp);
	fs.close();
	return (config);
}

int main(int ac, char **av)
{
	(void)ac;
	std::vector<vectorString>	tmp;
	std::vector<configServer>	server;

	try
	{
		tmp = getArg(av[1]);
		for (std::vector<vectorString>::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			configServer	srv(it);
			server.push_back(srv);
		}
		for (std::vector<configServer>::iterator it = server.begin(); it != server.end(); it++)
		{
			std::cout << "****************" << std::endl;
			std::cout << *it;
			std::cout << "****************" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
