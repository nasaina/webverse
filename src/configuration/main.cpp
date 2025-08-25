/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:52:36 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>
#include <Location.hpp>
#include <configServer.hpp>
#include <Config.hpp>

int main(int ac, char **av)
{
	(void)ac;

	try
	{
		Config	src(av);

		std::cout << src;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
