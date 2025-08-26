/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:40:35 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 10:26:29 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes.hpp>

std::string	eraseSpace(std::string tmp)
{
	std::string	out = "";

	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == ' ' || tmp[i] == '\t')
			continue ;
		out.append(tmp, i, 1);
	}
	return (out);
}

void	countBrace(std::string tmp, int *brace)
{
	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == '{')
			*brace += 1;
		if (tmp[i] == '}')
			*brace -= 1;
	}
}

int	countServer(vectorString &tmp)
{
	vectorString::iterator	it;
	int									count = 0;

	it = tmp.begin();
	while (it != tmp.end())
	{
		if (eraseSpace(*it) == "server{")
			count++;
		it++;
	}
	return (count);
}

std::vector<vectorString>	getServer(vectorString &tmp)
{
	vectorString::iterator	it;
	std::vector<vectorString>	in;
	std::string							str;
	int									brace;
	size_t								count;
	
	it = tmp.begin();
	count = countServer(tmp);
	brace = 0;
	for (size_t i = 0; i < count; i++)
	{
		str = "";
		vectorString	out;
		while (it != tmp.end())
		{
			if (eraseSpace(*it).length() == 0)
			{
				it++;
				continue ;
			}
			countBrace(*it, &brace);
			out.push_back(*it);
			if (!brace)
			{
				it++;
				break ;
			}
			it++;
		}
		in.push_back(out);
	}
	return (in);
}
