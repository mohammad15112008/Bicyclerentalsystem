#include <iostream>
#include <string>

using namespace std;

enum enBicycleType { Adult = 1, Kids = 2 };
enum enBicycleFeatures { Roads = 1, Mountains = 2, Electric = 3 };

struct Bicycle {
    enBicycleType type;
    enBicycleFeatures features;
    double rentalCost;
    int numDays;
    int standardRentalCost = 15;
    int insuranceFee = 50;
    int totalRental = 0;
};



void PrintListOfBicycle()
{
    cout << "************************" << endl;
    cout << "       Your Bicycle     " << endl;
    cout << "************************" << endl;
    cout << "1: Adult Bicycle" << endl;
    cout << "2: Kids Bicycle" << endl;
    cout << "************************" << endl;
    cout << "Please enter the type of bicycle you would like to rent (1 for Adult, 2 for Kids): ";
}

void PrintBicycleFeatures()
{
    cout << "************************" << endl;
    cout << "       Bicycle Features     " << endl;
    cout << "************************" << endl;
    cout << "1: Suitable for roads" << endl;
    cout << "2: Mountain bike" << endl;
    cout << "3: Electric bike" << endl;
    cout << "************************" << endl;
    cout << "Please enter the features of the bicycle you would like to rent (1-3): ";
}

enBicycleType ReadBicycleType()
{
    short int type;
    cin >> type;
    return static_cast<enBicycleType>(type);
}

enBicycleFeatures ReadBicycleFeatures()
{
    short int features;
    cin >> features;
    return static_cast<enBicycleFeatures>(features);
}

int ReadNumberOfDays()
{
    int numDays;
    cout << "Enter the number of days you want to rent: ";
    cin >> numDays;
    return numDays;
}

string GetBicycleTypeName(enBicycleType type)
{
    return (type == Adult) ? "Adult Bicycle" : "Kids Bicycle";
}

string GetBicycleFeaturesName(enBicycleFeatures features)
{
    switch (features)
    {
    case Roads:
        return "Suitable for roads";
    case Mountains:
        return "Mountain bike";
    case Electric:
        return "Electric bike";
    default:
        return "Unknown features";
    }
}

int main()
{
    int choice;
    PrintListOfBicycle();
    int TP = 0;

    do
    {
        enBicycleType selectedType = ReadBicycleType();
        PrintBicycleFeatures();
        enBicycleFeatures selectedFeatures = ReadBicycleFeatures();

        Bicycle selectedBicycle;
        selectedBicycle.type = selectedType;
        selectedBicycle.features = selectedFeatures;
        selectedBicycle.numDays = ReadNumberOfDays();


        cout << "Today is " << GetBicycleTypeName(selectedBicycle.type) << endl;
        cout << "Bicycle Features: " << GetBicycleFeaturesName(selectedBicycle.features) << endl;
        cout << "Rental price for " << selectedBicycle.numDays << " days: JD" << (selectedBicycle.numDays * selectedBicycle.standardRentalCost) << endl;
        cout << "Insurance fee: JD" << selectedBicycle.insuranceFee << endl;


        TP += (selectedBicycle.numDays * selectedBicycle.standardRentalCost + selectedBicycle.insuranceFee);

        cout << "Do you want to rent another bicycle? (1 for yes, 0 for no): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Please enter the type of bicycle you would like to rent." << endl;
        }
        else
        {
            cout << "Thanks for using our system." << endl;
        }

    } while (choice != 0);

    cout << "Total rental cost: JD" << TP << "\tComprehensive insurance:" << endl;

    return 0;
}

