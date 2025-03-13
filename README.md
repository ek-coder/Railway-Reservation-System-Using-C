# Railway Reservation System Using C

## 📌 Overview
The **Railway Reservation System** is a simple C-based console application that allows users to book train tickets, view reservations, and cancel bookings. The system manages seat availability and assigns unique PNR numbers to each reservation.

## 🛠 Features
- **Display Available Trains**: View the list of trains with available seats.
- **Book a Ticket**: Reserve a seat in a selected train.
- **View All Reservations**: Check all booked tickets.
- **View Reservations for a Specific Train**: Display reservations for a particular train.
- **Cancel a Ticket**: Cancel a reservation using the PNR number.

## 🏗 Technologies Used
- **Programming Language**: C
- **Standard Libraries**: `stdio.h`, `stdlib.h`, `string.h`, `time.h`

## 🚆 Available Trains
The system includes 10 trains, each with a maximum of 50 seats:
1. NDLS Express
2. Chennai Express
3. UP EXPRESS
4. Bangalore Express
5. Haryana Express
6. Noida Express
7. Mumbai Express
8. Vande Bharat
9. Dehradun Express
10. Jammu Express

## 🏗 How It Works
1. **Run the program** and choose an option from the menu:
- Reserve a seat
- View reservations
- View reservations for a specific train
- Cancel a ticket
- Exit
2. **Book a Ticket**:
- Select a train.
- Enter passenger details (name, gender, food preference).
- Get assigned a **seat number** and a **PNR number**.
3. **View Reservations**:
- See all reservations or filter by a specific train.
4. **Cancel a Ticket**:
- Enter the **PNR number** to cancel a booking.
- The seat is freed up for new reservations.

### 📌 Example Output
-- Available Trains --
1. NDLS Express (Available Seats: 50)
2. Chennai Express (Available Seats: 50)
...
Enter the number of the train: 3
Enter passenger name: Rahul
Enter gender (M/F): M
Enter food preference (1 for vegetarian, 2 for non-vegetarian): 1
Reservation successful. Train: UP EXPRESS, Seat number: 1, PNR: 1234

### 📜 License
This project is open-source and free to use for learning purposes.  
