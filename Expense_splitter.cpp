#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n; // n is the number of people involved
    cout << "Enter number of friends: ";
    cin >> n;

    //Defining vectors that stores input

    vector<string> names(n);
    vector<double> expenses(n);
    //-----------------------//
    vector<double> balances(n);

    //Defining a variable total that will store the total amount of money spend
    double total = 0;
    
    //Taking required input from the user

    for (int i = 0; i < n; i++) {
        cout << "Enter name of person " << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter expense of " << names[i] << ": ";
        cin >> expenses[i];
        total += expenses[i];
    }

    //Calculate the share of each person
    
    double share = total / n;

    for (int i = 0; i < n; i++) {
        balances[i] = expenses[i] - share;
    }
    
    
    cout << fixed << setprecision(2); 
    // The above line ensures that all floating-point numbers printed from now on
    // will show exactly 2 digits after the decimal point, in fixed-point notation.
    // This is useful for displaying money amounts clearly (like 500.00 instead of 500.0).
    cout<<endl;
    cout << "--- Expense Report ---"<<endl;;
    cout << "Total Expense: " << total << endl;
    cout << "Each person should pay: " << share << endl<<endl;

    cout << "--- Settlement ---"<<endl; 

    // Create lists for debtors and creditors and store in vectors named debtors and creditors respectively

    vector<int> debtors, creditors;

    for (int i = 0; i < n; i++) {
        if (balances[i] < 0) debtors.push_back(i);
        else if (balances[i] > 0) creditors.push_back(i);
    }

    int i = 0, j = 0;
    while (i < debtors.size() && j < creditors.size()) {
        double amount = min(-balances[debtors[i]], balances[creditors[j]]);

        cout << names[debtors[i]] << " should pay "
             << names[creditors[j]] << " : " << amount << endl;

        balances[debtors[i]] += amount;
        balances[creditors[j]] -= amount;

        if (balances[debtors[i]] == 0) i++;
        if (balances[creditors[j]] == 0) j++;
    }

    cout << "\nAll settlements done successfully!" << endl;

    return 0;
}
