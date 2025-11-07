package models;

public class Flight {
    private String flightNumber;
    private String destination;
    private String departureTime;

    public Flight(String flightNumber, String destination, String departureTime) {
        this.flightNumber = flightNumber;
        this.destination = destination;
        this.departureTime = departureTime;
    }

    public String getFlightNumber() {
        return flightNumber;
    }

    public String getDestination() {
        return destination;
    }

    public String getDepartureTime() {
        return departureTime;
    }

    public String getDetails() {
        return "Flight " + flightNumber + " to " + destination + " departs at " + departureTime;
    }
}
