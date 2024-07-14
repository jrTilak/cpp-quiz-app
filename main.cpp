#include <iostream>
#include "src/utils.cpp"
#include "src/class.cpp"
#include "src/quiz.cpp"
#include "src/admin.cpp"
#include "src/analytics.cpp"
#include "src/db.cpp"

using namespace std;

int main()
{
  clearScreen();
  // variables
  int option = 0;

  while (true)
  {
    // Display the main menu
    cout << "Welcome to the game!" << "\n\n";
    cout << "1. Take a quiz" << endl;
    cout << "2. Admin Portal" << endl;
    cout << "3. Analytics and Reports" << endl;
    cout << "4. Exit" << endl;

    cout << "Choose an option: ";
    cin >> option;

    switch (option)
    {
    case 1:
      clearScreen();
      handleQuizGame();
      break;

    case 2:
      clearScreen();
      handleAdminPanel();
      break;

    case 3:
      clearScreen();
      handleAnalytics();
      break;

    case 4:
      clearScreen();
      cout << "Goodbye!\n\n"
           << endl;
      return 0;

    default:
      clearScreen();
      cout << "Invalid option. Please try again." << endl;
      break;
    }
  }
}