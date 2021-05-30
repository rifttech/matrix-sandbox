#include <iostream>
#include <fstream>
#include "string"
#include "lib/json.hpp"
#include "src/Matrix.h"

using json = nlohmann::json;
using namespace std;

// for convenience
Matrix &load_matrix(const json &j, const string &name);

void print_actions();

int loop(Matrix &left, Matrix &right);

double read_user_input();

json load_file();




int main() {
    json j = load_file();

    auto left = load_matrix(j, "left");
    auto right = load_matrix(j, "right");

    print_actions();

    return loop(left, right);
}

json load_file() {
    std::ifstream i("file.json");
    json j;
    i >> j;
    return j;
}

void print_result(Matrix &matrix) {
    cout << "Result:" << endl;
    matrix.print();
}

int loop(Matrix& left, Matrix& right) {
    while (true) {
        int choice = 0;
        cout << "Choose Option:";
        cin >> choice;
        cout << endl;


        if (choice >= 11 || choice <= 0) {
            cout << "Exiting..." << endl;
            return 0;
        }
        switch (choice) {
            case 1: {
                try {
                    Matrix p = left * right;
                    print_result(p);
                }catch (const std::runtime_error& e){
                    cout << "Got Error: " << e.what() << endl;
                }
            }
                break;
            case 2: {
                try {
                    Matrix p = left + right;
                    print_result(p);
                }catch (const std::runtime_error& e){
                    cout << "Got Error: " << e.what() << endl;
                }
            }
                break;
            case 3: {
                double n = read_user_input();
                Matrix result = left * n;
                print_result(result);
            }
                break;
            case 4: {
                double n = read_user_input();
                Matrix result = left + n;
                print_result(result);
            }
                break;
            case 5: {
                double n = read_user_input();
                left = n;
                print_result(left);
            }
                break;
            case 6: {
                double n = read_user_input();
                right = n;
                print_result(right);
            }
                break;
            case 7: {
                print_actions();
            }
                break;
            case 8: {
                left.print();
            }
                break;
            case 9: {
                right.print();
            }
                break;
            case 10: {
                json j = load_file();
                left = load_matrix(j, "left");
                right = load_matrix(j, "right");
            }
                break;
            case 11: {
                return 0;
            }
        }
    }
}

void print_actions() {
    cout << endl << "Available Options:" << endl;
    cout << "\t1. Multiply: A * B" << endl;
    cout << "\t2. Add:  A + B" << endl;
    cout << "\t3. Multiply n:  A*n" << endl;
    cout << "\t4. Add n: A+n" << endl;
    cout << "\t5. Assign A:  A = n" << endl;
    cout << "\t6. Assign B:  A = n" << endl;
    cout << "\t7. Print Actions" << endl;
    cout << "\t8. Print A" << endl;
    cout << "\t9. Print B" << endl;
    cout << "\t10. Reload Matrices" << endl;
    cout << "\t11. Exit" << endl;
}

Matrix &load_matrix(const json &src, const string &name) {
    Matrix temp((int) src[name][0].size(), (int) src[name].size());
    cout << "Load Matrix : " << name << endl;
    for (int i = 0; i < temp.getRowSize(); i++) {
        cout << "|" << " ";
        for (int j = 0; j < temp.getColumnSize(); j++) {
            cout << src[name][i][j] << " ";
            temp.set(i, j, src[name][i][j]);
        }
        cout << "|" << endl;
    }
    return temp;
}

double read_user_input() {
    double n = 0;
    cout << "Enter number: ";
    cin >> n;
    return n;
}
