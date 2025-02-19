
# Project Specification

## Due: Friday, March 14th 11:59pm

## Description
The project will be implemented as three separate programs:
- **Logger** – Responsible for logging all activity.
- **Encryption Program** – Responsible for encrypting and decrypting strings.
- **Driver Program** – Interacts with the user to use the encryption program.

The entire system will be run by executing the driver program, which will launch the other programs and communicate with them through pipes.

- **C/C++:** Use Linux system calls `fork`, `pipe`, and `dup2`.
- **Java:** Use the `Process` class.
- **Python:** Use the `Subprocess` module.

Examples for all these approaches will be provided in class. Details of each program are below.

## Details

### Logger
The logger will write log messages to a log file. The log messages follow this format:

```
YYYY-MM-DD HH:MM [ACTION] MESSAGE
```

For example, logging the message `"START Logging Started."` on March 2nd, 2025, at 11:32 AM would result in:

```
2025-03-02 11:32 [START] Logging Started.
```

- **Command-line argument:** The logger program accepts a single argument – the name of the log file.
- **Standard input:** It will accept log messages until receiving the command `QUIT`.

### Encryption Program
The encryption program processes commands given via standard input. The first word is treated as a command, and the rest of the line (after the first space) as the argument. The encryption program must maintain a passkey for encryption and decryption.

#### Commands:
- **`PASS`** – Sets the current passkey.
- **`ENCRYPT`** – Encrypts the argument using a Vigenère cipher with the current passkey.
  - If no passkey is set, an error is returned.
- **`DECRYPT`** – Decrypts the argument using a Vigenère cipher with the current passkey.
  - If no passkey is set, an error is returned.
- **`QUIT`** – Exits the program.

#### Response Types:
- **`RESULT`** – The command succeeded, and the result follows.
- **`ERROR`** – The command failed, and an error message follows.

More information on the Vigenère cipher can be found [here](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher).

##### Example Interaction:
```
Input: ENCRYPT HELLO
Output: ERROR Password not set

Input: PASSKEY HELLO
Output: RESULT

Input: ENCRYPT HELLO
Output: RESULT OIWWC
```

### Driver Program
The driver program accepts a single command-line argument – the name of the log file. It:
1. Creates two new processes: the logger and the encryption program.
2. Uses pipes to connect to their standard input and output.
3. Provides a user menu for interaction.

#### Commands:
- **`password`** – Allows the user to set a passkey, either by entering a new password or selecting from history.
- **`encrypt`** – Encrypts a string entered by the user or selected from history.
- **`decrypt`** – Decrypts a string entered by the user or selected from history.
- **`history`** – Displays the history of entered strings.
- **`quit`** – Sends `QUIT` to the encryption program and logger, then exits.

#### Additional Requirements:
- Commands must be logged.
- Results must be logged.
- Start and exit of the driver program must be logged.
- Strings for encryption and decryption should be stored in history but only for the duration of the program.
- Passwords should **never** be logged.
- Only letters should be accepted for encryption, decryption, and password commands.
- Input should be **case insensitive** (e.g., encrypting "Hello" and "hello" should yield the same result).

### Error Handling
- Input containing non-letter characters (e.g., `Hello World!`) should result in an error message.
- Users must have an option to exit history selection and enter a new string manually.
- Proper validation and error messages should be provided for incorrect inputs.

---

