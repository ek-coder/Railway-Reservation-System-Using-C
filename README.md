Railway Reservation System Using C

Introduction

The Railway Reservation System is a C-based console application that allows users to reserve train tickets, view reservations, and cancel tickets. This system manages train seat bookings, assigns seat numbers, generates unique PNR numbers, and keeps track of reservations.

Features

Display available trains with seat availability.

Reserve a seat by providing passenger details.

View all reservations across different trains.

View reservations for a specific train.

Cancel a ticket using the PNR number.

How It Works

The user selects an option from the menu:

Reserve a seat

View all reservations

View reservations for a specific train

Cancel a ticket

Exit the program

For reservation, the user provides details like name, gender, and food preference.

A unique PNR number is generated for each reservation.

Users can view or cancel their reservation using the PNR number.

Train seat availability updates dynamically.

Technologies Used

Programming Language: C

Data Structures: Arrays and Structs

Randomization: Used for generating unique PNR numbers

How to Compile and Run

# Save the code as railway_reservation.c
# Open a terminal and navigate to the directory containing the file

# Compile the program
gcc railway_reservation.c -o railway_reservation

# Run the program
./railway_reservation

Future Enhancements

Add file handling to store and retrieve reservation data.

Implement user authentication for secured booking.

Introduce a graphical user interface (GUI) for better user experience.

Enable online payment integration.

Author

Developed as a simple C programming project for learning and implementation of basic data structures and console-based application development.

License

This project is open-source and can be modified or distributed freely.

