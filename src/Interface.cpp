#include "Interface.h"

namespace interface {
    void add_client_option(ClientSystem *const client_system) {
        std::string name;
        std::cout << "> Enter a name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::string phone_number;
        std::cout << "  Enter a phone_number (w\\out spaces): ";
        std::getline(std::cin, phone_number);
        
        std::string email;
        std::cout << "  Enter an email (w\\out spaces): ";
        std::getline(std::cin, email);
        
        if (!name.empty() && !phone_number.empty() && !email.empty())
            client_system->add_client(name, phone_number, email);
    }

    void find_client_by_ID(ClientSystem *const client_system) {
        std::cout << "> Enter id to find a client: ";
        int id = 0;
        std::cin >> id;

        Client* client = client_system->find_client(id);
        if (client) {
            std::cout << "  Client found successfully:\n";
            client->display_client();
        }else {
            std::cout << "  Client not found!\n";
        }
    }

    void find_client_by_name(ClientSystem *const client_system) {
        std::cout << "> Enter name to find a client: ";
        std::string name;
        std::cin.ignore();
        std::getline(std::cin, name);

        Client* client = client_system->find_client("name", name);
        if (client) {
            std::cout << "  Client found successfully:\n";
            client->display_client();
        }else {
            std::cout << "  Client not found!\n";
        }
    }
    
    void find_client_by_phone_number(ClientSystem *const client_system) {
        std::cout << "> Enter phone number to find a client: ";
        std::string phone_number;
        std::cin >> phone_number;

        Client* client = client_system->find_client("phone_number", phone_number);
        if (client) {
            std::cout << "  Client found successfully:\n";
            client->display_client();
        }else {
            std::cout << "  Client not found!\n";
        }
    }
    
    void find_client_by_email(ClientSystem *const client_system) {
        std::cout << "> Enter email to find a client: ";
        std::string email;
        std::cin >> email;

        Client* client = client_system->find_client("email", email);
        if (client) {
            std::cout << "  Client found successfully:\n";
            client->display_client();
        }else {
            std::cout << "  Client not found!\n";
        }
    }

    void find_client_option(ClientSystem *const client_system) {
        std::cout << "> Choose the option:\n"
                  << "  1. Search client by ID\n" 
                  << "  2. Search client by name\n"
                  << "  3. Search client by phone number\n"
                  << "  4. Search client by email\n"
                  << "> ";

        short option;
        std::cin >> option;

        if (option == 1) { interface::find_client_by_ID(client_system); }
        else if (option == 2) { interface::find_client_by_name(client_system); }
        else if (option == 3) { interface::find_client_by_phone_number(client_system); }
        else if (option == 4) { interface::find_client_by_email(client_system); }
    }

    void edit_client_option(ClientSystem *const client_system) {
        std::cout << "> Enter id to find a client: ";
        int id = 0;
        std::cin >> id;

        if (client_system->find_client(id)) {
            std::cout << "\n  Enter new name: ";
            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "  Enter new phone: ";
            std::string phone_number;
            std::getline(std::cin, phone_number);

            std::cout << "  Enter new email: ";
            std::string email;
            std::getline(std::cin, email);

            if (!name.empty() && !phone_number.empty() && !email.empty()) 
                client_system->edit_client(id, name, phone_number, email);
        }
    }

    bool confirm_action(const std::string& action, const std::string& description) {
        std::cout << "  Are you sure to " << action << "?\n"
                    << "  (" << description << ")\n"
                    << "  Yes(y) or No(n): ";
        char ch;
        std::cin >> ch;
        if (ch == 'y' || ch == 'Y') { return true; }
        return false;
    }

    void remove_client_option(ClientSystem *const client_system) {
        std::cout << "> Enter id to find a client: ";
        int client_id = 0;
        std::cin >> client_id;
        
        if (client_system->find_client(client_id)) {
            if (interface::confirm_action("delete client", "Deleted user cannot be restored"))
                client_system->remove_client(client_id);
        }else {
            std::cout << "  Client not found!\n";
        }
    }

    void pause_to_click() {
        std::cout << std::endl;
        system("pause");
    }

    void export_from_file(ClientSystem *const client_system) {
        if (!confirm_action("export data", "Unsaved data will be lost")) { return; }

        std::cout << "  Enter path to file: ";
        std::string repository;
        std::cin >> repository;
        client_system->export_from_file(repository);
    }

    void save_to_file(ClientSystem *const client_system) {
        std::cout << "  Enter path to file: ";
        std::string repository;
        std::cin >> repository;
        client_system->save_to_file(repository);
    }

    void display_clients(ClientSystem *const client_system) {
        std::cout << "\n  Clients:\n";
        client_system->display_clients();
        std::cout << "  \\End list.\n";
    }

    void sort_clients(ClientSystem *const client_system) {
        // Sort by ID
        // Sort by name
        // Sort by phone_number
        // Sort by email
        std::cout << "  Choose the option:\n"
                  << "  1. Sort by ID\n"
                  << "  2. Sort by name\n"
                  << "  3. Sort by phone number\n"
                  << "  4. Sort by email\n"
                  << "> ";

        short option;
        std::cin >> option;

        if (option == 1) { client_system->sort_by_ID(); }
        else if (option == 2) { client_system->sort_by_name(); }
        else if (option == 3) { client_system->sort_by_phone_number(); }
        else if (option == 4) { client_system->sort_by_email(); }
    }
}