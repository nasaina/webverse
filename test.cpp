/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:21:11 by nandrian          #+#    #+#             */
/*   Updated: 2025/08/19 13:18:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// void	clientSocket(void)
// {
// 	sockaddr_in	serverAddress;
// 	int			clientSocket;

// 	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
// 	serverAddress.sin_family = AF_INET;
// 	serverAddress.sin_port = htons(8080);
// 	serverAddress.sin_addr.s_addr = INADDR_ANY;
// 	connect(clientSocket, (sockaddr *)&serverAddress, sizeof(serverAddress));
// 	send(clientSocket, "test from nowhere", 18, 0);
// 	close(clientSocket);
// }

void	receiveClient(int clientSocket)
{
	char	buffer[1024] = {0};
	if (recv(clientSocket, buffer, sizeof(buffer), 0) != -1)
	{
		std::cout << "message from client : " << buffer << std::endl;
	}
}

void	serverSocket(void)
{
	sockaddr_in	serverAddress;
	pid_t		serverSocket;
	pid_t		clientSocket;

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress));
	listen(serverSocket, 5);
	clientSocket = accept(serverSocket, nullptr, nullptr);
	receiveClient(clientSocket);
	close(serverSocket);
}

int	main()
{
	while (1)
	{
		serverSocket();
	}
	return (0);
}
