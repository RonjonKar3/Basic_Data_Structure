#include <iostream>
#include <ctime>

using namespace std;

class Train
{
public:
    int trainCode;
    string trainName;
    string sourceStation;
    string destinationStation;
    string journeyDate;
    string time;
    int totalTickets;

    Train(int code, string name, string source, string dest, string date, string t, int tickets)
    {
        trainCode = code;
        trainName = name;
        sourceStation = source;
        destinationStation = dest;
        journeyDate = date;
        time = t;
        totalTickets = tickets;
    }

    void displayTrainInfo()
    {
        cout << "Train Code: " << trainCode << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source Station: " << sourceStation << endl;
        cout << "Destination Station: " << destinationStation << endl;
        cout << "Journey Date: " << journeyDate << endl;
        cout << "Time: " << time << endl;
        cout << "Available Tickets: " << totalTickets << endl;
        cout << "----------------------------------" << endl;
    }

    bool reserveTickets(int numTickets)
    {
        if (numTickets <= totalTickets)
        {
            totalTickets -= numTickets;
            return true;
        }
        return false;
    }
};

class TrainNode
{
public:
    Train train;
    TrainNode* next;

    TrainNode(int code, string name, string source, string dest, string date, string t, int tickets)
        : train(code, name, source, dest, date, t, tickets), next(NULL) {}
};

class TrainList
{
public:
    TrainNode* head;

    TrainList()

    {
        head = NULL;
    }

    void insertTrain(int code, string name, string source, string dest, string date, string t, int tickets)
    {
        TrainNode* newNode = new TrainNode(code, name, source, dest, date, t, tickets);
        newNode->next = head;
        head = newNode;
    }

    void displayAllTrains()
    {
        TrainNode* current = head;
        while (current != NULL)
        {
            current->train.displayTrainInfo();
            current = current->next;
        }
    }

    void deleteTrain(int code)
    {
        TrainNode* current = head;
        TrainNode* prev = NULL;

        while (current != NULL && current->train.trainCode != code)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Train with code " << code << " not found." << endl;
            return;
        }

        if (prev == NULL)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        delete current;
        cout << "Train with code " << code << " has been deleted." << endl;
    }

    TrainNode* searchTrain(int code)
    {
        TrainNode* current = head;
        while (current != NULL)
        {
            if (current->train.trainCode == code)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    int getTotalAvailableTickets(int code)
    {
        TrainNode* trainNode = searchTrain(code);
        if (trainNode)
        {
            return trainNode->train.totalTickets;
        }
        return -1;
    }

    bool reserveTickets(int code, int numTickets)
    {
        TrainNode* trainNode = searchTrain(code);
        if (trainNode)
        {
            return trainNode->train.reserveTickets(numTickets);
        }
        return false;
    }
};

class Customer
{
public:
    string name;
    int trainCode;
    int numTickets;

    Customer(string n, int code, int tickets)
    {
        name = n;
        trainCode = code;
        numTickets = tickets;
    }
};

class CustomerQueue
{
public:
    class Node
    {
    public:
        Customer customer;
        Node* next;

        Node(Customer c) : customer(c), next(NULL) {}
    };

    Node* front;
    Node* rear;

public:
    CustomerQueue()
    {
        front =NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(Customer customer)
    {
        Node* newNode = new Node(customer);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    Customer getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.";
        }
        return front->customer;
    }
};

int main()
{
    TrainList trainlist;
    CustomerQueue customerQueue;
    int choice;

    cout << "********** Train Ticket Reservation **********"<<endl;

    while (true)
    {
        cout << "\n\t\tLOG IN AS ADMIN"<<endl;
        cout << "(Username: Admin\tPassword: 1234)"<<endl << endl;

        cout << "Enter Username: ";
        string user;
        cin >> user;

        cout << "Password: ";
        string password;
        cin >> password;

        if (user == "Admin" && password == "1234")
        {

        cout << "\nLogin Successfull!!!\n"<< endl;

            while(true)
            {
                cout << "Menu: " << endl;
                cout << "1. Add a Train" << endl;
                cout << "2. Display All Trains" << endl;
                cout << "3. Delete a Train" << endl;
                cout << "4. Reserve Tickets" << endl;
                cout << "5. Search a Train" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout << "----------------------------------" << endl << endl;

                switch (choice)
                {
                case 1:
                {
                    int code, tickets;
                    string name, source, dest, date, time;

                    cout << "Enter Train Code: ";
                    cin >> code;
                    cout << "Enter Train Name: ";
                    cin >> name;
                    cout << "Enter Source Station: ";
                    cin >> source;
                    cout << "Enter Destination Station: ";
                    cin >> dest;
                    cout << "Enter Journey Date: ";
                    cin >> date;
                    cout << "Enter Journey Time: ";
                    cin >> time;
                    cout << "Enter Total Tickets: ";
                    cin >> tickets;

                    trainlist.insertTrain(code, name, source, dest, date, time, tickets);
                    cout << "Train added successfully." << endl;
                    break;
                }
                case 2:
                {
                    cout << "All Trains in the List:" << endl;
                    trainlist.displayAllTrains();
                    break;
                }
                case 3:
                {
                    int codeToDelete;
                    cout << "Enter Train Code to delete: ";
                    cin >> codeToDelete;
                    trainlist.deleteTrain(codeToDelete);
                    break;
                }
                case 4:
                {
                    int reservationTrainCode, numReservedTickets;
                    string customerName;
                    time_t currentTime = time(NULL);
                    tm* timeInfo = localtime(&currentTime);

                    cout << "Enter Reservation Train Code: ";
                    cin >> reservationTrainCode;
                    cout << "Enter Number of Ticket Reservation: ";
                    cin >> numReservedTickets;
                    cout << "Enter Customer Name: ";
                    cin >> customerName;

                    if (trainlist.reserveTickets(reservationTrainCode, numReservedTickets))
                    {
                        cout << "Reservation successful for " << numReservedTickets << " tickets." << endl;
                        Customer customer(customerName, reservationTrainCode, numReservedTickets);
                        customerQueue.enqueue(customer);
                        cout << "Reservation Date and Time: "<<endl;
                        cout <<"Date:" <<(1900 + timeInfo->tm_year) << "-" << (1 + timeInfo->tm_mon) << "-" << timeInfo->tm_mday << " ";
                        cout <<" Time:" <<timeInfo->tm_hour << ":" << timeInfo->tm_min << ":" << timeInfo->tm_sec <<endl;

                    }
                    else
                    {
                        cout << "Reservation failed. Not enough tickets available." << endl;
                    }
                    break;
                }
                case 5:
                {
                    int searchCode;
                    cout << "Enter Train Code for Search train: ";
                    cin >> searchCode;
                    TrainNode* foundTrain = trainlist.searchTrain(searchCode);
                    if (foundTrain)
                    {
                        cout << "Train with code " << searchCode << " found:" << endl;
                        foundTrain->train.displayTrainInfo();
                    }
                    else
                    {
                        cout << "Train with code " << searchCode << " not found." << endl;
                    }
                    break;
                }
                case 6:
                {
                    cout << "Exiting program....." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                cout << "----------------------------------" << endl;

            }
        }
        else
        {
            cout<<"Please Write The Correct Name and Password";
        }
    }
}







