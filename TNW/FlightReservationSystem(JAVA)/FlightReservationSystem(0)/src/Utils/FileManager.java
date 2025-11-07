package utils;

import models.Passenger;
import models.Flight;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileManager {
    private static final String FILE_NAME = "passengers.txt";

    public static void savePassengers(List<Passenger> passengers) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME))) {
            for (Passenger passenger : passengers) {
                writer.write(passenger.toFileString() + "\n");
            }
        } catch (IOException e) {
            System.out.println("Error saving passengers: " + e.getMessage());
        }
    }

    public static List<Passenger> loadPassengers() {
        List<Passenger> passengers = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                Passenger passenger = new Passenger(parts[0], parts[1], parts[2], parts[3]);
                
                if (parts.length > 4) {
                    String[] flights = parts[4].split(",");
                    for (String flightData : flights) {
                        if (!flightData.isEmpty()) {
                            String[] flightParts = flightData.split("-");
                            passenger.addFlightFromFile(new Flight(flightParts[0], flightParts[1], flightParts[2]));
                        }
                    }
                }
                passengers.add(passenger);
            }
        } catch (IOException e) {
            System.out.println("No previous data found. Starting fresh.");
        }
        return passengers;
    }
}
