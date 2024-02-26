#include <iostream>
#include <string>

using namespace std;

namespace Views
{
    class UI
    {
    public:
        void prompt(const string text)
        {
            cout << text;
        }

        string getUserName()
        {
            string userName;
            getline(cin, userName);
            return userName;
        }

        string getPassword()
        {
            string password;
            getline(cin, password);
            return password;
        }
    };
}

namespace Models
{
    class Login
    {
        string _userName = "Boniich";
        string _password = "123456";

    public:
        bool checkData(string userName, string password);
    };

    bool Login::checkData(string userName, string password) {

        if ((_userName == userName) && (_password == password)) {
            return true;
        }
        else {
            return false;
        }

    }
}

namespace Controllers
{
    class LoginController {
        Views::UI* _view;
        Models::Login* _login;

    public:
        LoginController(Views::UI* view, Models::Login* login) {
            _view = view;
            _login = login;
        }

        void doLogin() {
            _view->prompt("Ingresa tu usuario: ");
            string userName = _view->getUserName();

            cout << endl;

            _view->prompt("Ingresa tu contraseña: ");
            string password = _view->getPassword();

            cout << endl;

            bool isUserRegistred = _login->checkData(userName, password);

            if (isUserRegistred) {
                _view->prompt("Has ingresado correctamente");
            }
            else {
                _view->prompt("Ups! Alguno de los datos es erroneo! Revisalos por favor!");
            }
        }

    };
}


int main()
{
    Views::UI ui;
    Models::Login login;

    Controllers::LoginController loginController (&ui, &login);

    loginController.doLogin();

    return 0;
}
