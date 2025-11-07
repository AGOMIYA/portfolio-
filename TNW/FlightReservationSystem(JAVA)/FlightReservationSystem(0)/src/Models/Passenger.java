package models;

import utils.FileManager;
import utils.Validation;
import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;

public class Passenger {
    private String name;
    private String email;
    private String password;
    private String passportNumber;
    private List<Flight> flights = new ArrayList<>();

    public Passenger(String name, String email, String password, String passportNumber) {
        if (!Validation.isValidPassword(password)) {
            throw new IllegalArgumentException("Password must be at least 8 characters, include a number & a special character.");
        }
        this.name = name;
        this.email = email;
        this.password = password;
        this.passportNumber = passportNumber;
    }

    public String getEmail() {
        return email;
    }

    public boolean authenticate(String inputPassword) {
        return this.password.equals(inputPassword);
    }

    // Menu method that takes a list of passengers
    public void menu(List<Passenger> passengers) {
        while (true) {
            String[] options = {"Add Flight", "Display Flights", "Cancel Flight", "Logout"};
            int choice = JOptionPane.showOptionDialog(null, "Choose an option:", "Passenger Menu",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, options, options[0]);

            switch (choice) {
                case 0 -> addFlight(passengers);
                case 1 -> displayFlights();
                case 2 -> cancelFlight(passengers);
                case 3 -> {
                    JOptionPane.showMessageDialog(null, "Logging out...");
                    return;
                }
                default -> JOptionPane.showMessageDialog(null, "Invalid choice! Try again.");
            }
        }
    }

    // Method to add a flight for the passenger
    public void addFlight(List<Passenger> passengers) {
        String flightNumber = JOptionPane.showInputDialog("Enter flight number:");
        String destination = JOptionPane.showInputDialog("Enter flight destination:");
        String departureTime = JOptionPane.showInputDialog("Enter departure time:");

        flights.add(new Flight(flightNumber, destination, departureTime));
        JOptionPane.showMessageDialog(null, "Flight added successfully!");

        // Save to file (pass passengers list)
        FileManager.savePassengers(passengers);
    }

    // Method to display all flights for the passenger
    public void displayFlights() {
        if (flights.isEmpty()) {
            JOptionPane.showMessageDialog(null, "You have no flights.");
            return;
        }

        StringBuilder flightDetails = new StringBuilder("--- Your Flights ---\n");
        for (Flight flight : flights) {
            flightDetails.append(flight.getDetails()).append("\n");
        }
        JOptionPane.showMessageDialog(null, flightDetails.toString());
    }

    // Method to cancel a flight for the passenger
    public void cancelFlight(List<Passenger> passengers) {
        String flightNumber = JOptionPane.showInputDialog("Enter flight number to cancel:");
        boolean removed = flights.removeIf(flight -> flight.getFlightNumber().equals(flightNumber));

        if (removed) {
            JOptionPane.showMessageDialog(null, "Flight " + flightNumber + " canceled successfully!");
            FileManager.savePassengers(passengers); // Save to file
        } else {
            JOptionPane.showMessageDialog(null, "Flight not found.");
        }
    }

    // Convert passenger data into a string to save to a file
    public String toFileString() {
        StringBuilder data = new StringBuilder(name + ";" + email + ";" + password + ";" + passportNumber + ";");
        for (Flight flight : flights) {
            data.append(flight.getFlightNumber()).append("-")
                .append(flight.getDestination()).append("-")
                .append(flight.getDepartureTime()).append(",");
        }
        return data.toString();
    }

    // Method to load flights from file
    public void addFlightFromFile(Flight flight) {
        flights.add(flight);
    }
}
