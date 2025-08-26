/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 11:41:01 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>
#include <Location.hpp>
#include <configServer.hpp>
#include <Config.hpp>

int main(int ac, char **av)
{
	std::string	port = "localhost:8081";
	if (ac == 2)
	{
		try
		{
			checkConf((std::string)av[1]);
			std::string	root = "/";
			Config	src(av);
			configServer tmp = src.checkPort(port);
			mapString	example = tmp.getCgi();
			mapString::iterator search = example.find("exec_cg");
			std::cout << search->first << " " << search->second << std::endl;
			Location	none = tmp.getLocation(root);
			// std::cout << "##############" << none << "##############\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cerr << "No valid configuration file found" << std::endl;
}
