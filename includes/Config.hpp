/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:17:43 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/25 08:43:22 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

# include "includes.hpp"
# include "configServer.hpp"
# include <vector>

class Config
{
	private:
		std::vector<configServer>	_server;
	public:
		Config(char **av);
		std::vector<configServer>	getServer(void) const;
		~Config();
};

#endif