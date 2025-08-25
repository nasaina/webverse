/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configServer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:02 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:50:13 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGSERVER_HPP
# define CONFIGSERVER_HPP

# include <includes.hpp>
#include <Location.hpp>

class configServer
{
	private:
		std::vector<vectorString>	_config;
		std::string					_port;
		size_t						_bodyLimit;
		mapString					_uploadPath;
		mapString					_cgi;
		std::vector<Location>		_location;
	public:
		configServer(std::vector<vectorString>::iterator it);
		void					getElement(std::vector<vectorString>::iterator it);
		std::string				getPort(void) const;
		size_t					getLimit(void) const;
		mapString				getPath(void) const;
		mapString				getCgi(void) const;
		std::vector<Location>	getLocation(void) const;
		void					printMap(std::ostream &os) const;
		void					printLocation(std::ostream &os) const;
		~configServer();
};

std::ostream	&operator<<(std::ostream &o, const configServer &other);

#endif