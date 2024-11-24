#include <iostream>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <functional>
#include <memory> 
using namespace std;


class Vehicle {
public:
    virtual void createVehicle() = 0;
};

class Jeep : public Vehicle {     // ----> Jeep class
public:
    void createVehicle() override {
        cout << ":::::::-> Jeep Produced." << endl;
    }
};

class Benz : public Vehicle {    // -----> Benz class
public:
    void createVehicle() override {
        cout << ":::::::-> Benz Produced." << endl;
    }
};

class RollsRoyce : public Vehicle {  // -----> RollsRoyce class
public:
    void createVehicle() override {
        cout << ":::::::-> Rolls-Royce Produced." << endl;
    }
};

class Ferrari : public Vehicle {    // ---> ferrari class
public:
    void createVehicle() override {
        cout << ":::::::-> Ferrari Produced." << endl;
    }
};


class Factory {
public:
    static unique_ptr<Vehicle> vehicleFactory(const string& productType) {
        static unordered_map<string, function<Vehicle* ()>> factoryMap = { // unordered map were new instance of different vehicles are returned as value
            {"benz", []() { return new Benz(); }},
            {"jeep", []() { return new Jeep(); }},
            {"ferrari", []() { return new Ferrari(); }},
            {"rollsroyce", []() { return new RollsRoyce(); }}
        };
        if (factoryMap.count(productType)) {
            return unique_ptr<Vehicle>(factoryMap[productType]());
        }
        return nullptr;
    }
};


void simulateCheck() {                   // This function delays the outputs on the client side.
    cout << "\n\n \t\t::: Checking ";
    for (int i = 0; i <= 4; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
    }
    cout << endl;
}

class I_Client {
public:
    static void garage() { // Here is the client class that displays the data.
        system("cls");
        cout << "\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "*************** Vehicles available ***************\n\n";
        cout << "::: benz" << endl;
        cout << "::: jeep" << endl;
        cout << "::: ferrari" << endl;
        cout << "::: rollsroyce";
        cout << "\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "Enter Product Type: ";
        string productType;
        cin >> productType;

        auto vehicle = Factory::vehicleFactory(productType);
        system("cls");

        simulateCheck(); 

        if (vehicle) {
            vehicle->createVehicle();
            this_thread::sleep_for(chrono::milliseconds(5000));
            garage();
        }
        else {
            cout << "\n\n \t\t::::::: No such product :::::::" << endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            garage();
        }
    }
};

int main() {
    auto startTime = chrono::high_resolution_clock::now();
    I_Client::garage();

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> timeComplexity = endTime - startTime;
    cout << "\n\n\n\n::::::::::::: TIME COMPLEXITY :::::::::::::" << endl;
    cout << "::::: Run time: " << timeComplexity.count() << "ms" << endl;
    system("pause > 0");
}
