/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:56:39 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/26 07:59:25 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <includes.hpp>

class Location
{
	private:
		std::string	_root;
		mapString	_content;
		std::string	methods(std::string tmp);
	public:
		Location(vectorString::iterator *it);
		Location();
		std::string	getRoot(void) const;
		mapString	getContent(void) const;
		void		printMap(std::ostream &os) const;
		~Location();
};

std::ostream	&operator<<(std::ostream &o, const Location &other);

#endif