# ft_irc

## Project Overview

`ft_irc` is a custom IRC (Internet Relay Chat) server implemented in C++98, designed to handle real-time text messaging both in public channels and private messages. This project adheres to the strict protocols that govern internet communications, creating a server that can be connected to via any standard IRC client for testing and interaction.

## Features

- **Multi-client Handling**: Capable of managing multiple client connections simultaneously without blocking or hanging.
- **Command Handling**: Supports basic IRC commands including setting nicknames, joining channels, sending/receiving messages, and channel operations (KICK, INVITE, TOPIC, MODE).
- **Operator and User Roles**: Differentiates between operator commands and regular user activities.
- **TCP/IP Communication**: Utilizes TCP/IP protocols for client-server communication
- **No External Libraries**: Developed without the use of external or Boost libraries, adhering strictly to C++98 standards.

## Installation

To compile the server, ensure you have a C++ compiler that supports the C++98 standard. Clone this repository and navigate to the project directory.

```bash
make
```

This command compiles the source files using the flags `-Wall -Wextra -Werror` and produces an executable named `ircserv`.

## Running the Server

To start the IRC server, run:

```bash
./ircserv <port> <password>
```

- `port`: The port number on which the server will listen for incoming connections.
- `password`: A password required by clients to establish a connection.

## Testing

Although the server is designed to work with any IRC client, specific clients used during development should be noted for testing consistency. It's recommended to test using the `nc` (Netcat) tool for sending commands directly to the server for initial validation.

## Deployment

The server is designed to run macOS. Deployment involves running the compiled executable on a machine accessible by clients.
