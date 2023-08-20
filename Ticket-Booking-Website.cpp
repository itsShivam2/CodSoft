#include <iostream>
#include <string>
using namespace std;
class Movie
{
protected:
    string title;
    string releaseDate;
    int duration;
    double ticketPrice;
    bool seats[50];

public:
    Movie(string t, string rd, int d, double tp) : title(t), releaseDate(rd), duration(d), ticketPrice(tp)
    {
        for (int i = 0; i < 50; i++)
        {
            seats[i] = true;
        }
    }

    virtual void displayDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "Duration: " << duration << endl;
        cout << "TicketPrice: " << ticketPrice << endl;
    }
    virtual string getTitle()
    {
        return title;
    }
    virtual double getTicketPrice()
    {
        return ticketPrice;
    }
    virtual void changeTicketPrice(double newPrice)
    {
        ticketPrice = newPrice;
        cout << "ticket price is changed successfully!! " << endl;
    }
    void displayAvailableSeats()
    {
        cout << "available seats for " << title << ": " << endl;
        for (int i = 0; i < 50; i++)
        {
            if (seats[i])
                cout << "seat " << i + 1 << "is available " << endl;
        }
    }
    bool bookSeat(int seatNumber)
    {
        if (seatNumber >= 1 && seatNumber <= 50)
        {
            if (seats[seatNumber - 1])
            {
                seats[seatNumber - 1] = false;
                return true;
            }

            else
            {
                cout << "seat " << seatNumber << "is already booked try later: " << endl;
                return false;
            }
        }
        else
        {

            cout << "invalid seat number pls choose seat between 1 and 50: " << endl;
            return false;
        }
    }
};

class UserClass : public Movie
{
public:
    UserClass(string t, string rd, int d, double tp) : Movie(t, rd, d, tp) {}

    void displayDetails() override
    {
        cout << "=== Movie Details ===" << endl;
        Movie::displayDetails();
    }
};
class AdminClass : public Movie
{
public:
    AdminClass(string t, string rd, int d, double tp)
        : Movie(t, rd, d, tp) {}
    void displayDetails() override
    {
        cout << "===Movie Details===" << endl;
        Movie::displayDetails();
    }
};
int main()
{
    const string adminPassword = "shivam";
    const int maxMovies = 3;
    Movie *movies[maxMovies];
    int numMovies = 0;

    int choice;
    do
    {

        cout << "\n=== Movie Booking System ===" << endl;
        cout << "1. Add new movie (admin only)" << endl;
        cout << "2. Delete movie (admin only)" << endl;
        cout << "3. Change ticket price (admin only)" << endl;
        cout << "4. Currently playing movies list" << endl;
        cout << "5. Available seats list" << endl;
        cout << "6. Book a ticket" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            cout << "enter the password: ";
            string password;
            cin >> password;
            if (password == adminPassword)
            {
                if (numMovies >= maxMovies)
                    cout << "Maximum number of movies reached. Delete old movies before adding new ones." << endl;
                else
                {
                    string title, releaseDate;
                    int duration;
                    double ticketPrice;
                    cout << "enter the TITLE of the movie: " << endl;
                    cin.ignore();
                    getline(cin, title);
                    cout << "enter the release date: " << endl;
                    cin.ignore();
                    getline(cin, releaseDate);
                    cout << "enter the duration in minutes: " << endl;
                    cin >> duration;
                    cout << "enter the ticket price: " << endl;
                    cin >> ticketPrice;
                    movies[numMovies] = new AdminClass(title, releaseDate, duration, ticketPrice);
                    numMovies++;
                    cout << "movie added succesfully : ! " << endl;
                }
            }
            else
            {
                cout << "enter a valid password !! " << endl;
            }
            break;
        }
        case 2:
        {
            cout << "enter the password: ";
            string password;
            cin >> password;
            if (password == adminPassword)
            {
                string title;
                cout << "enter the TITLE of the movie to DELETE :" << endl;
                cin.ignore();
                getline(cin, title);
                bool found = false;
                for (int i = 0; i < numMovies; i++)
                {
                    if (movies[i]->getTitle() == title)
                    {
                        delete movies[i];
                        movies[i] = movies[numMovies - 1];
                        numMovies--;
                        found = true;
                        break;
                    }
                }
                if (found)
                    cout << "movie deleted successfully !" << endl;
                else
                    cout << "Movie with this title is not found. Please try again." << endl;
            }
            else
            {
                cout << "enter a valid password !! " << endl;
            }
            break;
        }
        case 3:
        {
            cout << "enter the password: ";
            string password;
            cin >> password;
            if (password == adminPassword)
            {
                string title;
                cout << "enter the movie title to change the ticket price : " << endl;
                cin.ignore();
                getline(cin, title);
                bool found = false;
                for (int i = 0; i < numMovies; i++)
                {
                    if (movies[i]->getTitle() == title)
                    {
                        double newPrice;
                        cout << "enter the new ticket price : " << endl;
                        cin >> newPrice;
                        movies[i]->changeTicketPrice(newPrice);
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "movie with this title name is not found pls try again!" << endl;
            }
            else
            {
                cout << "invalid password try again !" << endl;
            }
            break;
        }

        case 4:
        {
            cout << "===Currently Playing Movies List===" << endl;
            for (int i = 0; i < numMovies; i++)
            {
                movies[i]->displayDetails();
                cout << endl;
            }
            break;
        }

        case 5:
        {
            string title;
            cout << "Enter the movie title to display available seats: ";
            cin.ignore();
            getline(cin, title);
            bool found = false;
            for (int i = 0; i < numMovies; i++)
            {
                if (movies[i]->getTitle() == title)
                {
                    movies[i]->displayAvailableSeats();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Movie with this title is not found. Please try again." << endl;
            }
            break;
        }

        case 6:
        {
            string title;
            cout << "Enter the movie title : ";
            cin.ignore();
            getline(cin, title);
            cout << endl;
            string name;
            cout << "enter your name : ";
            getline(cin, name);

            string contact;
            cout << "enter your contact number: ";
            getline(cin, contact);

            bool found = false;
            for (int i = 0; i < numMovies; i++)
            {
                if (movies[i]->getTitle() == title)
                {
                    movies[i]->displayAvailableSeats();
                    int numSeats;
                    cout << "enter the number of seats you want to book: " << endl;
                    cin >> numSeats;
                    int seatNumber[50];
                    bool bookingSuccessful = true; // Initialize bookingSuccessful to true
                    for (int j = 0; j < numSeats; j++)
                    {
                        cout << "enter seat number: " << j + 1 << ": ";
                        cin >> seatNumber[j];
                        if (!movies[i]->bookSeat(seatNumber[j]))
                        {
                            bookingSuccessful = false;
                            break;
                        }
                    }

                    if (bookingSuccessful)
                    {
                        cout << "Dear " << name << " , your ticket is boocked successfully" << endl;
                        cout << "movie: " << title << endl;
                        cout << "seat numbers : ";
                        for (int j = 0; j < numSeats; j++)
                        {
                            cout << seatNumber[j] << " ";
                        }
                        cout << endl;
                        cout << "Contact: " << contact << endl;
                    }
                    else
                    {
                        cout << "seat booking failed pls try again" << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Movie with this title is not found. Please try again." << endl;
            }
            break;
        }

        case 7:
        {
            for (int i = 0; i < numMovies; i++)
            {
                delete movies[i];
            }
            cout << "existing the program" << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid choice , try again." << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}