#include "ClientSystem.h"
#include "Interface.h"

int main() {
    system("cls");

    ClientSystem *client_system = new ClientSystem;
    client_system->export_from_file();

    while(true) {
        system("cls");

        std::cout << "> " << client_system->get_filename() << "\n\n";

        if (client_system->is_no_client()) {
            std::cout << "Choose the option:\n"
                      << "1. Add client\n"
                      << "2. Export from file\n" 
                      << "0. Close the system\n"
                      << "> ";
            short option = 0;
            std::cin >> option;

            if (option == 0) { break; } 
            else if (option == 1) { interface::add_client_option(client_system); }
            else if (option == 2) { interface::export_from_file(client_system); }
        } else {
            std::cout << "Choose the option:\n"
                      << "1. Search client\n"
                      << "2. Show clients\n"
                      << "3. Sort clients\n\n"
                      << "4. Add client\n"
                      << "5. Edit client\n"
                      << "6. Remove client\n\n"
                      << "7. Export from file\n"
                      << "8. Save to file\n\n"
                      << "0. Close the system\n"
                      << "> ";
            
            short option = 0;
            std::cin >> option;

            if (option == 0) { break; }
            else if (option == 1) { interface::find_client_option(client_system); } 
            else if (option == 2) { interface::display_clients(client_system); } 
            else if (option == 3) { interface::sort_clients(client_system); }
            else if (option == 4) { interface::add_client_option(client_system); } 
            else if (option == 5) { interface::edit_client_option(client_system); } 
            else if (option == 6) { interface::remove_client_option(client_system); } 
            else if (option == 7) { interface::export_from_file(client_system); }
            else if (option == 8) { interface::save_to_file(client_system); }

        }
        
        interface::pause_to_click();
    }

    delete client_system;
    std::cout << "\n> Client system closed successfully!\n";

    return 0;
}