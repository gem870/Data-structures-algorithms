

#include <iostream>
#include <string>
#include <list>
using namespace std;

class INotification {
public:
    virtual void notification(string msg) = 0;
};

class Devices : public INotification {
private:
    string deviceId;

public:
    Devices(string deviceId) {
        this->deviceId = deviceId;
    }
    void notification(string msg) override {
        cout << "::)-> Mail recieved: " << msg << " (device)." << endl;
    }
};

class GroupedDevices {
private:
    list< INotification* > listOfDevices;
public:
    void signIn(INotification* deviceName) {
        listOfDevices.push_back(deviceName);
    }
    void signOut(INotification* deviceName) {
        listOfDevices.remove(deviceName);
    }
    void notify(string msg) {
        for (auto& usedDevice : listOfDevices)
        {
            usedDevice->notification(msg);
        }
    }
};




int main()
{
    GroupedDevices* gpDevice = new GroupedDevices();
    Devices* phone = new Devices("phone");
    Devices* ipad = new Devices("ipad");
    Devices* labtop = new Devices("labtop");
    Devices* desktop = new Devices("desktop");

    gpDevice->signIn(phone);
    gpDevice->signIn(ipad);
    gpDevice->signIn(labtop);
    gpDevice->signIn(desktop);

    cout << "\n\n \t All sign in devices" << endl;
    gpDevice->notify("bank alart");

    gpDevice->signOut(phone);
    gpDevice->signOut(ipad);
    cout << "\n\n \t sign out devices: {phone and ipad}" << endl;
    gpDevice->notify("Another bank alart");

    delete phone;
    phone = nullptr;

    delete ipad;
    ipad = nullptr;

    delete labtop;
    labtop = nullptr;

    delete desktop;
    desktop = nullptr;
}


