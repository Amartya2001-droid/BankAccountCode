# BankAccountCode
# Amartya's Bank Pvt Ltd. Internet Banking System

Welcome to the Internet Banking System of Amartya's Bank Pvt Ltd. This is a simple command-line program that allows users to create a bank account, log in, check their balance, transfer money, and log out.

## Features

- Create a bank account
- Log in to an existing account
- Check account balance
- Transfer money to another user
- Log out

## Usage

1. **Compile the program**:
   ```sh
   gcc -o bank bank.c
   ./bank
Functions

account()

	•	This function allows a new user to create a bank account by providing details such as name, address, date of birth, driver’s license number, phone number, username, and password.

accountcreated()

	•	This function simulates the account creation process and prompts the user to log in.

login()

	•	This function allows an existing user to log in by entering their username and password.

display(char* username)

	•	This function displays the account details of the logged-in user and provides options to check balance, transfer money, log out, or exit.

transfermoney()

	•	This function allows a user to transfer money to another user’s account.

checkbalance(char* username)

	•	This function displays the transaction history and total balance of the logged-in user.

logout()

	•	This function logs the user out of the system.

File Structure

	•	bank.c: The main program file containing all the functions.
	•	username.txt: The file where user account details are stored.
	•	mon.txt: The file where transaction details are stored.

Example

When you run the program, you will be presented with the following menu:
WELCOME TO AMARTYA'S BANK PVT LTD. INTERNET BANKING SYSTEM

******************************************************************************
1.... CREATE A BANK ACCOUNT
2.... ALREADY A USER? SIGN IN
3.... EXIT

ENTER YOUR CHOICE:
Follow the on-screen prompts to create an account, log in, check balance, or transfer money.

Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request.

License

This project is licensed under the MIT License.
