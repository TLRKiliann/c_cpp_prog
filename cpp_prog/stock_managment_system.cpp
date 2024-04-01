#include <iostream>

using namespace std;

class Original {
    private:
        float price;
        string name;
        int nb_stock;
        double total = 0.00;

    public:
        Original(float x, string y, int z)
        {
            this->price = x;
            this->name = y;
            this->nb_stock = z;
        }

        void display_prod()
        {
            cout << name << " - Prix: " << price << " - Stock: " << nb_stock <<endl;
        }

        void bying_prod(int d_client)
        {
            if (this->nb_stock >= d_client)
            {
                this->total += d_client;
                //cout << "Total test : " << this->total <<endl;
                this->nb_stock = nb_stock - d_client;
                cout << "Nbre restant de " << this->name << " en stock : "<< nb_stock <<endl;
            }
            else
            {
                cout << "Il n'en reste pas suffisamment en stock : " << nb_stock <<endl;
            }
        }

        double total_payment(Original& target)
        {
            double total = target.total * target.price;
            cout << "Total : " << total <<".- en : " << target.name <<endl;
            return total;
        }
};

int main()
{
    Original pommes(3.20, "Pommes", 22); //60
    Original oranges(2.10, "Oranges", 11); //20
    Original bananes(1.25, "Bananes", 30); //30
    //1620 (110) 330 220 110
    int product, nb, cpt = 0;
    char c;

    while (1)
    {
        cout << "Choisissez un produit : " <<endl;
        cout << "Pommes tapper 1 : " <<endl;
        cout << "Oranges tapper 2 : " <<endl;
        cout << "Bananes tapper 3 : " <<endl;
        cin >> product;
        cout << "Vous avez choisi : " << product <<endl;

        if (product == 1)
        {
            pommes.display_prod();
            cout << "choisissez le nb: " <<endl;
            cin >> nb;
            if (nb > 0)
            {
                pommes.bying_prod(nb);
            }
            else
            {
                cout << "Vous 'avez pas choisi de quantité." <<endl;
            }
        }
        else if (product == 2)
        {
            oranges.display_prod();
            cout << "choisissez le nb: " <<endl;
            cin >> nb;
            if (nb > 0)
            {
                oranges.bying_prod(nb);
            }
            else
            {
                cout << "Vous 'avez pas choisi de quantité." <<endl;
            }
        }
        else if (product == 3)
        {
            bananes.display_prod();
            cout << "choisissez le nb: " <<endl;
            cin >> nb;
            if (nb > 0)
            {
                bananes.bying_prod(nb);
            }
            else
            {
                cout << "Vous 'avez pas choisi de quantité." <<endl;
            }
        }
        else
        {
            cout << "Nous n'avons pas ce produit !" <<endl;
        }

        pommes.total_payment(oranges);
        pommes.total_payment(bananes);
        oranges.total_payment(pommes);

        cout << "\nVoulez-vous continuer vos achats ? y=oui n=non" <<endl;
        cin >> c;

        if (c == 'y')
        {
            cout << "ok on continue" <<endl;
            cpt++;
        }
        else
        {
            cout << "Vous avez acheté pour un total : " <<endl;
            double last_total = pommes.total_payment(oranges) +
                pommes.total_payment(bananes) + oranges.total_payment(pommes);
            cout << "\nTotal : " << last_total << ".-" <<endl;

            cout << "\nAu revoir !" <<endl;
            break;
        }
    }
    return 0;
}
