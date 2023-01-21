# QQ Chat Room Based on Qt

### Module 1 Basic Chat Room

#### Component 1 Chat room server

```c++
QTcpServer *server;
QList<QTcpSockets*> sockets;

void start_server();							// Start when a new chat is on
void close_server();							// Close the server when the chat is over
void send_message();							// Send messages to clients
void slot_newConnection();				// When new client connects the server, newConnection() signal
void slot_disconnected();					// When a client is offline, disconnected() signal
void slot_readyRead();						// When a client sends message, readyRead() signal
```

#### Component 2 Chat room clients

```c++
QTcpSocket *socket;
QString username;

void connectToHost(ui->ipEdit->text(),ui->portEdit->text().toInt());	// Connect to the host

```

