#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_PASSENGERS = 1;

struct Train {
    string name;
    string startingStation;
    string endingStation;
    vector<string> stations;
    int baseFare;
    int farePerStation;
};

void displayMenu() {
    cout << "Main Menu" << endl;
    cout << "1. View Trains and Book Tickets" << endl;
    cout << "2. Show Booked Tickets" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Train> trains;
    Train generalTrain = {"General Train", "A", "H", {"A", "B", "C", "D", "E", "F", "G", "H"}, 50, 5};
    Train ac3Train = {"3 AC Train", "H", "P", {"H", "I", "J", "K", "L", "M", "N", "O", "P"}, 120, 15};
    Train seater2Train = {"2 Seater Train", "F", "Z", {"F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}, 80, 10};

    trains.push_back(generalTrain);
    trains.push_back(ac3Train);
    trains.push_back(seater2Train);

    vector<string> bookedTickets;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            // View Trains and Book Tickets
            cout << "Available Trains:" << endl;
            for (int i = 0; i < trains.size(); ++i) {
                cout << i + 1 << ". " << trains[i].name << " (" << trains[i].startingStation << " to " << trains[i].endingStation << ")" << endl;
            }

            int trainChoice;
            cout << "Choose a train: ";
            cin >> trainChoice;

            if (trainChoice >= 1 && trainChoice <= trains.size()) {
                Train selectedTrain = trains[trainChoice - 1];

                cout << "Enter starting station: ";
                string startStation;
                cin >> startStation;

                cout << "Enter ending station: ";
                string endStation;
                cin >> endStation;

                int passengers;
                cout << "Enter the number of passengers (max " << MAX_PASSENGERS << "): ";
                cin >> passengers;

                if (passengers < 1 || passengers > MAX_PASSENGERS) {
                    cout << "Invalid number of passengers." << endl;
                    continue;
                }

                vector<string> passengerNames(passengers);
                vector<int> passengerAges(passengers);

                for (int i = 0; i < passengers; ++i) {
                    cout << "Enter name of passenger " << i + 1 << ": ";
                    cin >> passengerNames[i];
                    cout << "Enter age of passenger " << i + 1 << ": ";
                    cin >> passengerAges[i];
                }

                int totalFare = selectedTrain.baseFare + (selectedTrain.farePerStation * (selectedTrain.stations.size() - 1));
int startIndex = -1, endIndex = -1;
for (int i = 0; i < selectedTrain.stations.size(); ++i) {
    if (selectedTrain.stations[i] == startStation) {
        startIndex = i;
    }
    if (selectedTrain.stations[i] == endStation) {
        endIndex = i;
        break;
    }
}

if (startIndex != -1 && endIndex != -1 && endIndex >= startIndex) {
    int stationsBetween = endIndex - startIndex;
    totalFare += selectedTrain.farePerStation * stationsBetween;
} else {
    cout << "Invalid stations or order." << endl;
    continue;
}
string proceed;
cout << "Total fare for " << selectedTrain.name << ": " << totalFare << " INR" << endl;
cout << "Do you want to proceed with the booking? (yes/no): ";
cin >> proceed;

if (proceed == "yes") {
    bookedTickets.push_back(selectedTrain.name);
    cout << "Ticket booked successfully!" << endl;
} else {
    cout << "Booking canceled." << endl;
}
                if (proceed == "yes") {
                    bookedTickets.push_back(selectedTrain.name);
                    cout << "Ticket booked successfully!" << endl;
                } else {
                    cout << "Booking canceled." << endl;
                }

            } else {
                cout << "Invalid train choice." << endl;
            }
        } else if (choice == 2) {
            // Show Booked Tickets
            if (bookedTickets.empty()) {
                cout << "No booked tickets found." << endl;
            } else {
                cout << "Booked Tickets:" << endl;
                for (const string& ticket : bookedTickets) {
                    cout << "- " << ticket << " ticket" << endl;
                }
            }
        } else if (choice == 3) {
            // Exit
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (true);

    return 0;
}
