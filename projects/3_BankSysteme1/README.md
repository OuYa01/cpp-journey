# Project: Client Management System

This project implements a **Client Management System** that allows you to store, manage, and retrieve client data. The data is saved in a text file, and you can perform various operations like adding, deleting, and viewing client information.

## Features
- **Add a New Client**: Add a new client with account number, pin code, name, phone number, and account balance.
- **Find a Client**: Search for a client by account number and view their details.
- **Show All Clients**: Display a list of all clients stored in the system.
- **Delete a Client**: Remove a client from the system using their account number.
- **Persistent Storage**: All client data is saved to a file (`ClientsData.txt`) for persistent storage.

## File Structure

```
/ClientManagementSystem
│── main.cpp               # Entry point of the application, handles user interaction.
│── client.cpp             # Contains the logic for adding, deleting, and displaying clients.
│── helpers.cpp            # Utility functions for data handling (e.g., converting data formats).
│── client.h               # Header file for client structure and function declarations.
│── ClientsData.txt        # File to store client data.
│── README.md              # Project documentation.
```

## How to Run

1. **Compile the program**:
   ```bash
   g++ main.cpp client.cpp helpers.cpp -o client_management
   ```

2. **Run the program**:
   ```bash
   ./client_management
   ```

## Functions Overview

### `AddClient()`
- Collects client information (Account number, Pin code, Name, Phone number, Account balance) and adds it to both the vector and file.

### `FindClient()`
- Allows you to search for a client by their account number. Displays client details if found.

### `ShowClientList()`
- Displays a list of all clients stored in the system, including their account number, pin code, name, phone number, and account balance.

### `DeletClient()`
- Deletes a client from the vector and updates the file accordingly.

### `LoadAllClientsDataFromFile()`
- Loads client data from the file into the vector when the program starts.

### `LoadAllDataFromVecToFile()`
- Saves the client data in the vector back to the file when the program exits or data is updated.

### `ConvertClientToRecordeLine()`
- Converts the client structure data into a formatted string for saving into the file.

### `ConvertClientRecordeToClient()`
- Converts a line from the file back into a client structure.

### `ClientFound()`
- Checks if a client with a given account number exists in the system.

## File Format

The client data is saved in the `ClientsData.txt` file with each record in the following format:

```
AccountNumber#//#PinCode#//#Name#//#PhoneNumber#//#AccountBalance
```

Example:

```
B01#//#0000#//#Oussama#//#+212608095577#//#20000
```

## Example Usage

1. **Add a new client**:  
   ```
   Entre Account Number: B01
   Entre Pin Code: 0000
   Entre Your Name: Oussama
   Entre Your Phone Number: +212608095577
   Entre Account Balance: 20000
   ```

2. **Find a client**:  
   ```
   Entre Account Number: B01
   ```

3. **Delete a client**:  
   ```
   Entre Client Account Number: B01
   Are you sure you want to delete this client? (Y/N): Y
   ```

## Requirements

- **C++ compiler** (e.g., `g++`).
- The program expects a text file `ClientsData.txt` to store and retrieve client data.

## Notes

- The system allows only one client to be added at a time, but you can keep adding multiple clients one after the other.
- The client data is stored permanently in `ClientsData.txt`, ensuring that information persists even after the program is closed.

---

Feel free to adjust the instructions or add more details as needed for your project!
