package main;

import models.Passenger;
import utils.FileManager;

import javax.swing.JOptionPane;
import java.util.List;

public class Main {
    public static List<Passenger> passengers;

    public static void main(String[] args) {
        // Load saved data
        passengers = FileManager.loadPassengers();

        while (true) {
            String[] options = {"Register Passenger", "Login", "Exit"};
            int choice = JOptionPane.showOptionDialog(null, "Choose an option:", "Main Menu",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, null, options, options[0]);

            switch (choice) {
                case 0 -> registerPassenger();
                case 1 -> loginPassenger();
                case 2 -> {
                    JOptionPane.showMessageDialog(null, "Goodbye!");
                    System.exit(0);
                }
                default -> JOptionPane.showMessageDialog(null, "Invalid choice! Try again.");
            }
        }
    }

    private static void registerPassenger() {
        String name = JOptionPane.showInputDialog("Enter your name:");
        String email = JOptionPane.showInputDialog("Enter your email:");
        String password = JOptionPane.showInputDialog("Enter your password (at least 8 chars, including a number & special character):");
        String passportNumber = JOptionPane.showInputDialog("Enter your passport number:");

        try {
            passengers.add(new Passenger(name, email, password, passportNumber));
            JOptionPane.showMessageDialog(null, "Passenger registered successfully!");
            FileManager.savePassengers(passengers); // Save to file
        } catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(null, "Failed to register: " + e.getMessage());
        }
    }

    private static void loginPassenger() {
        String email = JOptionPane.showInputDialog("Enter your email:");
        String password = JOptionPane.showInputDialog("Enter your password:");

        for (Passenger passenger : passengers) {
            if (passenger.getEmail().equals(email) && passenger.authenticate(password)) {
                JOptionPane.showMessageDialog(null, "Login successful!");
                passenger.menu(passengers); // Pass passengers list
                return;
            }
        }
        JOptionPane.showMessageDialog(null, "Invalid email or password.");
    }
}
