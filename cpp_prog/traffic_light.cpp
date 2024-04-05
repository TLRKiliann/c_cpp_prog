#include <iostream>
#include <unistd.h>

using namespace std;

//pas de this avec les method static.
class Route {
    private:
        string route;
        string color;
        string anti_route;
        string anti_color;
        string orange;

    public:
        Route(string x, string y, string z, string w)
        {
            this->route = x;
            this->color = y;
            this->anti_route = z;
            this->anti_color = w;
            this->orange = "orange";
        }

        void display_msg(Route& target)
        {
            if (target.route == "route a") {
                cout << target.route << " Let's go !" <<endl;
                sleep(3);
            } else if (target.route == "route b") {
                cout << target.route << " Waiting..." <<endl;
                sleep(3);
            }
        }

        void display_nextII(Route& target)
        {
            if (target.route == "route a")
            {
                cout << "Le feux est : " << target.anti_color << " pour " << target.route <<endl;
                sleep(3);
                display_msg(target);
            } else if (target.route == "route b") {
                cout << "Le feux est : " << target.anti_color << " pour " << target.route <<endl;
                sleep(3);
                display_msg(target);
            }
        }

        void display_next(Route& target)
        {
            if (this->orange == "orange") {
                cout << "Le feu devient : " << this->orange << " pour " << target.route <<endl;
                sleep(3);
                display_nextII(target);
            }
        }

        void display_color(Route& target)
        {
            if (target.color == "red") {
                cout << target.route << ": la couleur est : " << target.color <<endl;
                cout << "Le feu devient: " << target.anti_color << " pour " << target.anti_route << " et les voutures circulent." <<endl;
                sleep(3);
                display_next(target);
            } else if (target.color == "vert") {
                cout << target.route << ": la couleur est : " << target.color <<endl;
                cout << "Le feu devient: " << target.anti_color << " pour: " << target.anti_route << " et les voitures sont à l'arret." <<endl;
                sleep(3);
                display_next(target);
            } else {
                cout << "La couleur ???" <<endl;
            }
        }
};

int main()
{
    /*
    Schema:
    a
       |
    ___|___
    b
    */
    //static call => Route::method(obj);
    char stop;
    int n = 0;
    do {
        Route route_a("route a", "red", "route b", "vert");
        Route route_b("route b", "vert", "route a", "red");

        route_a.display_color(route_a);
        route_b.display_color(route_b);
        n++;
    } while (n < 2);

    return 0;
}
