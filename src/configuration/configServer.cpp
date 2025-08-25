/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configServer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:31:09 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:42:45 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <configServer.hpp>

void	configServer::getElement(std::vector<vectorString>::iterator it)
{
	for (vectorString::iterator strIt = (*it).begin(); strIt != (*it).end(); strIt++)
	{
		std::string	second = Word(*strIt, 1);
		if (Word(*strIt, 0) == "listen")
			_port = second;
		else if (Word(*strIt, 0) == "body_limit")
			_bodyLimit = std::atoi(second.c_str());
		else if (Word(*strIt, 0) == "upload_path")
			_uploadPath.insert(std::make_pair(second, Word(*strIt, 2)));
		else if (Word(*strIt, 0) == "cgi" && Word(*strIt, 1) == "{")
			_cgi = checkCgi(&strIt);
		else if (Word(*strIt, 0) == "location" && Word(*strIt, 2) == "{")
		{
			Location tmp(&strIt);
			_location.push_back(tmp);
		}
	}
}

configServer::configServer(std::vector<vectorString>::iterator it)
{
	getElement(it);
}

std::string	configServer::getPort(void) const
{
	return (_port);
}

size_t	configServer::getLimit(void) const
{
	return (_bodyLimit);
}

mapString	configServer::getPath(void) const
{
	return (_uploadPath);
}

mapString	configServer::getCgi(void) const
{
	return (_cgi);
}

std::vector<Location>	configServer::getLocation(void) const
{
	return (_location);
}

void	configServer::printLocation(std::ostream &os) const
{
	for (std::vector<Location>::const_iterator it = _location.begin(); it != _location.end(); it++)
	{
		os << *it;
	}
}

void	configServer::printMap(std::ostream &os) const
{
	os << std::endl << "upload_path : ";
	for (mapString::const_iterator it = _uploadPath.begin(); it != _uploadPath.end(); it++)
	{
		os << it->first << " " << it->second;
	}
	os << std::endl;
	os << "cgi : {" << std::endl;
	for (mapString::const_iterator it = _cgi.begin(); it != _cgi.end(); it++)
	{
		os << it->first << " : " << it->second << std::endl;
	}
	os << "}" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, const configServer &other)
{
	o << "port : " << other.getPort();
	o << ", body limit : " << other.getLimit();
	other.printMap(o);
	other.printLocation(o);
	return (o);
}

configServer::~configServer()
{
}
