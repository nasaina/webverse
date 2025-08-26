/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 08:05:06 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>
#include <Location.hpp>
#include <configServer.hpp>
#include <Config.hpp>

int main(int ac, char **av)
{
	std::string	port = "localhost:8082";
	(void)ac;
	try
	{
		std::string	root = "/tube";
		Config	src(av);
		configServer tmp = src.checkPort(port);
		Location	none = tmp.getLocation(root);
		std::cout << "##############" << none << "##############\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
