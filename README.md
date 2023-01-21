# QQ Chat Room Based on Qt

### Module 1 Basic Chat Room

#### Component 1 Chat room server

```c++
QTcpServer *server;
QList<QTcpSockets*> sockets;

void start_server();							// Start when a new chat is on
void send_message();							// Send messages to clients
void slot_newConnection();				// When new client connects the server, newConnection() signal
void slot_disconnected();					// When a client is offline, disconnected() signal
void slot_read_message();					// When a client sends data, readyRead() signal

```

