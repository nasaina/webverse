/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:17:43 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 05:58:28 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <includes.hpp>
# include <configServer.hpp>

typedef std::vector<configServer>			vectorServer;

class Config
{
	private:
		vectorServer	_server;
	public:
		Config(char **av);
		vectorServer	getServer(void) const;
		configServer	checkPort(std::string input);
		~Config();
};

std::ostream	&operator<<(std::ostream &o, const Config &other);

#endif