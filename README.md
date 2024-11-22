 README for "Movie Ticket Reservation System"

 Movie Ticket Reservation System

 Overview
This project is a C++ implementation of a movie ticket reservation system, designed to manage multiple cinema screens and the reservation of seats within those screens. The system supports different types of commands such as adding a screen, reserving seats, checking unreserved seats, and suggesting contiguous unreserved seats based on user input.

 Features:
- Add Screen: Allows adding a new screen to the system with a set number of rows, columns, and aisle seats.
- Reserve Seat: Reserves specific seats in a screen for a given row.
- Get Unreserved Seats: Displays unreserved seats for a specific row in a screen.
- Suggest Contiguous Seats: Suggests a set of contiguous unreserved seats, considering aisle seats and a user's preferred seat.

 Installation

1. Clone the repository:
   ```
   git clone <repository_url>
   cd movie-ticket-res
   ```

2.Compile the program:
   ```
   g++ -o movie_ticket_reservation main.cpp
   ```

3. Run the program:
   ```
   ./movie_ticket_reservation
   ```

## Usage
To interact with the system, input the following commands as per the example:

1. Add Screen:
   ```
   add-screen <name-of-screen> <number-of-rows> <number-of-columns> <space-separated-aisle-seats>
   ```

2. Reserve Seat:
   ```
   reserve-seat <name-of-screen> <row-number> <space-separated-seats-to-be-reserved>
   ```

3. Get Unreserved Seats:
   ```
   get-unreserved-seats <name-of-screen> <row-number>
   ```

4. Suggest Contiguous Seats:
   ```
   suggest-contiguous-seats <name-of-screen> <number-of-seats> <row-number> <choice-of-seat>
   ```

Example
Input:
```
7
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen2 4 13 4
```

Output:
```
success
success
success
failure
3 4 5 6 7 8
4 5 6
```

 Contributing
1. Fork this repository.
2. Create a new branch for your feature.
3. Submit a pull request with a detailed description of the feature/bug.

