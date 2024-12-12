# Movie Ticket Reservation System

## Overview

This project is a **C** implementation of a **Movie Ticket Reservation System**, designed to manage multiple cinema screens and the reservation of seats within those screens. The system supports various commands such as adding a screen, reserving seats, checking unreserved seats, and suggesting contiguous unreserved seats based on user input.

## Features

- **Add Screen**: Allows adding a new screen to the system with a set number of rows, columns, and aisle seats.
- **Reserve Seat**: Reserves specific seats in a screen for a given row.
- **Get Unreserved Seats**: Displays unreserved seats for a specific row in a screen.
- **Suggest Contiguous Seats**: Suggests a set of contiguous unreserved seats, considering aisle seats and a user's preferred seat.

## Installation

### Step 1: Clone the repository

Clone the repository to your local machine using the following command:

```bash
git clone <repository_url>
cd movie-ticket-reservation
```

### Step 2: Compile the program

To compile the program, use the following command:

```bash
gcc -o movie_ticket_reservation main.c
```

### Step 3: Run the program

To run the compiled program, use:

```bash
./movie_ticket_reservation
```

## Usage

To interact with the system, input the following commands as per the example:

### Add Screen

To add a new screen, use the following command:

```
add-screen <name-of-screen> <number-of-rows> <number-of-columns> <space-separated-aisle-seats>
```

Example:

```
add-screen Screen1 12 10 4 5 8 9
```

### Reserve Seat

To reserve specific seats for a given row, use:

```
reserve-seat <name-of-screen> <row-number> <space-separated-seats-to-be-reserved>
```

Example:

```
reserve-seat Screen1 4 5 6 7
```

### Get Unreserved Seats

To view unreserved seats for a specific row in a screen, use:

```
get-unreserved-seats <name-of-screen> <row-number>
```

Example:

```
get-unreserved-seats Screen2 13
```

### Suggest Contiguous Seats

To suggest contiguous unreserved seats, use:

```
suggest-contiguous-seats <name-of-screen> <number-of-seats> <row-number> <choice-of-seat>
```

Example:

```
suggest-contiguous-seats Screen2 4 13 4
```

## Example Input

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

## Example Output

```
success
success
success
failure
3 4 5 6 7 8
4 5 6
```


