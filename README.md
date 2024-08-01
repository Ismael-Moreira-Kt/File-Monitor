# File-Monitor
File Monitor is a simple application that allows you to monitor and view the contents of files using a graphical interface built with GTK. The project demonstrates the integration of C code with Assembly system calls, specifically the read syscall, for reading files.

<br><br>

## Introduction
The goal of this project is to demonstrate how to combine Assembly code with C in a graphical application. The application allows the user to select a file and view its contents in real time in a simple graphical interface. It also includes a logging system to record events and possible errors during execution.

<br><br>

## Functionalities
- **File Reading:** Using the read syscall implemented in Assembly to read files.
- **Graphical Interface:** Built with GTK for a friendly user experience.
- **Logging System:** Records important events and errors, facilitating debugging.

<br><br>

## Requirements
Before compiling and running File Monitor, ensure that you have the following requirements installed on your system:

- **GCC**
- **NASM**
- **GTK+3**
- **Make**

<br><br>

## Installation
To compile and run File Monitor, follow the steps below:

#### Clone the repository:
```bash
git clone https://github.com/Ismael-Moreira-Kt/File-Monitor
cd File-Monitor
```

#### Compile the project using the Makefile:
```bash
make
```

#### Run the application
```bash
./build/monitor
```

<br><br>

## Use
After running the program, the main window will open. To use the application:

- **Open File:** Click the "Open File" button to open a file chooser.
- **Select File:** Choose a file you want to view.
- **View Content:** The content of the selected file will be displayed in the text area.

