#include <iostream>

int deposit (int x, int y);

int withdraw (int x, int y);

void checkbalance (int x);

int main () {

    int input, check, choice, balance = 0;

    std::cout << "*********************WELCOME TO THE BANK*********************\n";

    do{

        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";

        std::cout << "Your choice : ";
        std::cin >> choice;

        switch (choice){

            case 1:
                std::cout << "How much money would you like to deposit: ";
                std::cin >> input;

                while(input <= 0){

                    if(input == 0){
                        std::cout << "You haven't depositted any money!\n";
                        std::cout << "Enter a valid amount: ";
                        std::cin >> input;
                    }
                    else if(input < 0){
                        std::cout << "Your deposit can't be negative\n";
                        std::cout << "Enter a valid amount: ";
                        std::cin >> input;
                    }

                }

                balance = deposit(input, balance);

                break;

            case 2:
                std::cout << "How much would you like to withdraw: ";
                std::cin >> input;

                while(input <= 0){

                    if(input == 0){
                        std::cout << "You haven't withdrawn any money!\n";
                        std::cout << "Enter a valid amount: ";
                        std::cin >> input;
                    }
                    else if(input < 0){
                        std::cout << "Your withdraw can't be negative\n";
                        std::cout << "Enter a valid amount: ";
                        std::cin >> input;
                    }

                }

                check = balance - input;

                while(check < 0 ){

                    // check = 1;

                    int x;

                    std::cout << "You have insufficient funds!\n";
                    std::cout << "Consider checking your balance or try a lower ammount\n";

                    std::cout << "1. Check your balance and enter a new amount\n";
                    std::cout << "2. Enter a new amount\n";
                    std::cout << "Your choice: ";
                    std::cin >> x;

                    while(x < 1 || x > 2){
                        std::cout << "Invalid input!\n";
                        std::cout << "Please choose between 1 and 2: ";
                        std::cin >> x;
                    }

                    if(x == 1){
                        checkbalance(balance);
                        std::cout << "Your new amount: ";
                        std::cin >> input;
                    }
                    else if(x == 2){
                        std::cout << "Your new amount: ";
                        std::cin >> input;
                        check = balance - input;
                    }


                }

                balance = withdraw(input, balance);

                break;

            case 3:
                checkbalance(balance);
                break;

            case 4:
                std::cout << "Thank you for using our bank\n";
                break;
            default:
                std::cout << "Invalid Input! Choose between 1-4! ";
                std::cin >> choice;
                break;
        }

    }

    while(choice != 4);

    return 0;

}

int deposit (int x, int y){

    y = y + x;
    std::cout << "You've successfully depositted " << x << '\n';
    std::cout << "Current Balance : " << y << '\n';

    return y;

}

int withdraw (int x, int y){

    y = y - x;
    std::cout << "You've successfully withdrawn " << x << '\n';
    std::cout << "Current Balance : " << y << '\n';

    return y;

}

void checkbalance (int x){

    std::cout << "Your balance is " << x << ".\n";

}
