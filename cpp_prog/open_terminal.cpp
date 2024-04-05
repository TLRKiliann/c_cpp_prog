#include <iostream>
#include <unistd.h>

using namespace std;

//sudo speedtest-cli --simple (test la bande passante)

//terminal 2
class NetStat {
    public:
	void callnet()
	{
        try {
            std::system("gnome-terminal -- bash -c 'netstat -puten; exec bash'");
        } catch (int error) {
            cout << "error : " << error <<endl;
        }
	}
};

//terminal 3
class NmapClass {
    public:
	void display_ports()
	{
        try {
            //address_ip in system
            std::system("gnome-terminal -- bash -c 'nmap -sV -sC 10.0.2.15; exec bash'");
        } catch (int error) {
            cout << "error : " << error <<endl;
        }
	}
};

//terminal 4
class PsClass {
    public:
	void display_process()
	{
        try {
            //address_ip in system
            std::system("gnome-terminal -- bash -c 'ps -eo pid,ppid,cmd,%cpu,%mem --sort=-%cpu | head -n 4; exec bash'");
        } catch (int error) {
            cout << "error : " << error <<endl;
        }
	}
};

//terminal 1
class Routes: public NetStat, public NmapClass, public PsClass {
    protected:
        void display_protected()
        {
            cout << "\nConnection status: Ok" <<endl;
            cout << "\n=== === ===\n" <<endl;
        }

    public:
        void func_name()
        {
            try {
                int callsys = system("hostname -I");
                if (callsys != 0)
                {
                    cout << "system() not done !"<<endl;
                }
            } catch (int error) {
                cout << "error: " << error <<endl;
            }
            display_protected();
            sleep(2);
        }
};

int main()
{
    Routes dataNet;
    cout << "--- Network-View --- \n"<<endl;

    try {
        dataNet.func_name();
        dataNet.callnet();
        sleep(1);
        dataNet.display_ports();
        sleep(1);
        dataNet.display_process();
    } catch (int error) {
        cout << "error: " << error <<endl;
    }

    return 0;
}
