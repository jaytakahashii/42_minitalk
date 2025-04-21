<h1 align="center">
	MINITALK(Projects at 42tokyo)
</h1>

<p align="center">
	<b><i>Final Score 125/100</i></b><br>
</p>

# 💡 About the project
> The purpose of this project is to code a small data exchange program using UNIX signals. (Reference: 42Tokyo minitalk project PDF)

## Overview
minitalk is a project from the 42 curriculum that involves implementing inter-process communication (IPC) using UNIX signals.
The objective is to gain a deeper understanding of how signals work in UNIX systems and to develop skills in managing and utilizing signals for IPC.
This project provides an opportunity to explore various aspects of signal handling, data transmission, and bitwise operations.

### Key Features
- **Signal-Based Communication**: The application supports sending and receiving data between processes using UNIX signals.
- **Bitwise Data Reconstruction**: Converting strings sent through signals into bits and reconstructing the original data accurately.
- **Signal Handling**: Managing the sending and receiving of signals, including handling interrupts and ensuring reliable communication.
- **Error Management**: Implementing robust error handling to deal with potential issues during signal transmission and data reconstruction.
- **Command-Line Interface**: Providing a user-friendly command-line interface for initiating communication and monitoring progress.

### Objectives
- **Understanding Signals**: Gain insights into how UNIX signals work and how to use them for inter-process communication.
- **System Programming**: Enhance skills in system-level programming using C, focusing on signal handling and bitwise operations.
- **Error Handling**: Implement robust error handling to ensure the application operates smoothly under various conditions.
- **Data Reconstruction**: Develop techniques to accurately reconstruct data sent via signals from bitwise representation.

# 🚀 Algorithm
The communication between processes in the minitalk project is achieved using UNIX signals (SIGUSR1 and SIGUSR2) to send and receive data. Here is a simplified explanation of the algorithm:

1. **Client Side**:
   - Convert each character of the message into its binary representation.
   - For each bit of the character, send a signal to the server: SIGUSR1 for bit 1 and SIGUSR2 for bit 0.
   - Wait briefly between sending each signal to ensure proper handling.

2. **Server Side**:
   - Set up a signal handler to receive SIGUSR1 and SIGUSR2.
   - For each received signal, reconstruct the character bit by bit.
   - Once all bits of a character are received, print the character and reset the bit counter.

# 🛠️ Usage

### Requirements

- The library is written in C language and needs the **`cc` compiler**.

### Instructions

**1. Compiling the code**

To compile the [libft library](https://github.com/jayjayjay-hub/libft) and this project code, go to its path and run:

```shell
$ make
```

**2. Run**
After creating the executable file `server` and `client`, you must do it file.
Running `server` will display the process ID.
```shell
./server
# Server PID: [PID]
```
Start another shell, and run the client using the server's process ID.
```shell
./client [PID] [message]
```
Then a message is displayed on the server side.

**+α. Cleaning all binary (.o) and executable files**

To clean all files generated while doing a make, go to the path and run:

```shell
$ make fclean
```
