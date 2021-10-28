/*
*/
/* A simple calculator program,
controlled by a menu and 
divided into separate functions */
#include <iostream>
#include <cmath>
using namespace std;

//---------- Function Prototypes -----------
string op;
void print_menu();
double get_value();
double cylindersa();
double cylinderv();
double conesa();
double divide(double, double);
double operand1, operand2, answer;
bool complexproblem = false;
int choice, valid_choice;
string equation;
//--------------  Main -------------------
int main()
{
       do
       {
              print_menu();
              cin >> choice;
              valid_choice = 1; // assume choice is valid
              switch (choice)
              {
              case 0: // program will exit
                     break;
              case 1: // addition
                     operand1 = get_value();
                     operand2 = get_value();
                     answer = operand1 + operand2;
                     op = " + ";
                     break;
              case 2: // division
                     operand1 = get_value();
                     operand2 = get_value();
                     answer = divide(operand1, operand2);
                     op = " / ";
                     break;
              case 3:
                     operand1 = get_value();
                     operand2 = get_value();
                     answer = operand1 - operand2;
                     op = " - ";
                     break;
              case 4:
                     cylindersa();
                     complexproblem = true;
                     break;
              case 5:
                     cylinderv();
                     complexproblem = true;
                     break;
              case 6:
                     conesa();
                     complexproblem = true;
                     break;
              default:
                     valid_choice = 0; // choice is invalid
                     cout << "Invalid Choice." << endl;
              }
              if (valid_choice && choice != 0)
              { // if choice is valid, print the answer

                     if(complexproblem == true)
                     {
                            cout << endl << equation << endl << "Answer = " << answer << endl;
                     }
                     else
                     {
                            //works really well for single operator things, terrilbe for multi-operator problems, like surface area
                            cout << endl
                          << "Answer = " << operand1 << op << operand2 << " = " << answer << endl;
                     }
                     
              }
       } while (choice != 0); // if not 0, loop back to start
       return 0;
}
//--------------  Functions -------------------
double cylindersa()
{
       equation = "2(pi)rh+2(pi)r^2";
       cout << "Radius: " << endl;
       operand1 = get_value();
       cout << "Height: " << endl;
       operand2 = get_value();
       answer = 2 * M_PI * operand1 * operand2 + 2 * M_PI * operand1 * operand1;
       return answer;
}
double cylinderv()
{
       equation = "(pi)r^2h";
       cout << "Radius: " << endl;
       operand1 = get_value();
       cout << "Height: " << endl;
       operand2 = get_value();
       answer = M_PI * operand1 * operand1 * operand2;
       return answer;
}
double conesa()
{
       equation = "(pi)r(r+sqrt(h^2+r^2)";
       cout << "Radius: " << endl;
       operand1 = get_value();
       cout << "Height: " << endl;
       operand2 = get_value();
       answer = M_PI * operand1 *(operand1 + sqrt(operand1 *operand1 + operand2 *operand2));
       return answer;
}
double divide(double dividend, double divisor)
{
       if (divisor == 0)
       {
              return 0; // avoids divide by zero errors
       }
       else
              return (dividend / divisor);
}
//----------------- get_value function ----------------
double get_value()
{
       double temp_value;
       cout << "Please, enter a value: ";
       cin >> temp_value;
       cout << "Thanks." << endl;
       return temp_value;
}
//-------------------- print_menu function -------------
void print_menu()
{
       cout << endl;
       cout << "Add (1)" << endl;
       cout << "Divide (2)" << endl;
       cout << "Subtract (3)" << endl;
       cout << "Cylinder Surface Area (4)" << endl;
       cout << "Cylinder Volume (5)" << endl;
       cout << "Cone Surface Area (6)" << endl;
       cout << "Exit (0)" << endl;
       cout << "Enter your choice: ";
}