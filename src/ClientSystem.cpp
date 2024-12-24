#include "ClientSystem.h"

std::string ClientSystem::get_filename() const { return filename; }

void ClientSystem::add_to_file(const Client* client) const {
    std::ofstream fout(this->filename, std::ios_base::out | std::ios_base::app);

    if (!fout.is_open())
        return;

    fout << client->get_id() << ";"
            << client->get_name() << ";"
            << client->get_phone_number() << ";"
            << client->get_email()
            << "\n";

    fout.close();
}

void ClientSystem::export_from_file(std::string filename) {
    if (filename.empty()) { filename = this->filename; }

    std::ifstream fin(filename, std::ios_base::in);

    if (!fin.is_open()) { 
        std::cout << "  File not found.\n";
        return; 
    }

    if (fin.peek() == EOF) {
        std::cout << "  File is empty.\n";
        return;
    }

    this->clients.clear();
    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string id_str, name, phone_number, email;

        std::getline(ss, id_str, ';');
        std::getline(ss, name, ';');
        std::getline(ss, phone_number, ';');
        std::getline(ss, email, ';');

        int id = std::stoi(id_str);
        this->clients.emplace_back(id, name, phone_number, email);

        if (id >= this->next_id) { this->next_id = id + 1; }
    }

    fin.close();

    rewrite_file();

    std::cout << "  Data loaded successfully!\n";
} 

void ClientSystem::rewrite_file() const {
    std::ofstream fout(this->filename, std::ios_base::trunc | std::ios_base::out);
    
    if (!fout.is_open()) { return; }

    for (const Client &client : this->clients) {
        fout << client.get_id() << ";"
                << client.get_name() << ";"
                << client.get_phone_number() << ";"
                << client.get_email()
                << "\n";
    }

    fout.close();
}

void ClientSystem::save_to_file(std::string filename) const {
    bool is_new_file = false;

    if (filename.empty()) { 
        is_new_file = true;
        filename = this->filename;
    }

    std::ofstream fout(filename, std::ios_base::out);

    if (!fout.is_open()) { return; }

    if (!is_new_file) { fout.clear(); }

    for (const Client& client : clients) {
        fout << client.get_id() << ';'
                << client.get_name() << ';'
                << client.get_phone_number() << ';'
                << client.get_email() << '\n';
    }

    fout.close();
    std::cout << "  Data saved successfully to \"" << filename << "\"!\n";
}

bool ClientSystem::is_no_client() const {
    return clients.empty();
}

void ClientSystem::add_client (const std::string& name, const std::string& phone_number, const std::string& email) {
    clients.emplace_back(next_id++, name, phone_number, email);

    Client* client = &clients[clients.size() - 1];
    add_to_file(client);
    
    std::cout << "> Client added successfully!\n";
}

void ClientSystem::display_clients() const {
    std::cout << "  ------------------------------\n";
    for (Client client : this->clients) { 
        client.display_client(); 
        std::cout << "  ------------------------------\n";
    }
}

Client* ClientSystem::find_client (const int& id) {
    for (Client& client : this->clients) {
        if (client.get_id() == id) {
            return &client;
        }
    }
    return nullptr;
}

Client* ClientSystem::find_client (const std::string& selection_method, const std::string& seeking_value) {
    if (selection_method == "name") {
        for (Client& client : this->clients) {
            if (client.get_name() == seeking_value) {
                return &client;
            }
        }
        return nullptr;
    } else if (selection_method == "phone_number") {
        for (Client& client : this->clients) {
            if (client.get_phone_number() == seeking_value) {
                return &client;
            }
        }
        return nullptr;
    } else if (selection_method == "email") {
        for (Client& client : this->clients) {
            if (client.get_email() == seeking_value) {
                return &client;
            }
        }
        return nullptr;
    }

    return nullptr;
}

void ClientSystem::edit_client(const int& id, const std::string& name, const std::string& phone_number, const std::string& email) {
    Client* editing_client = find_client(id);

    if (editing_client != nullptr) {
        editing_client->set_name(name);
        editing_client->set_phone_number(phone_number);
        editing_client->set_email(email);

        rewrite_file();
        
        std::cout << "  Client updated successfully!\n";
    } else {
        std::cout << "  Client not found.\n";
    }
}

void ClientSystem::remove_client(const int& id) {
    for (auto client = this->clients.begin(); client != this->clients.end(); client++) {
        if (client->get_id() == id) {
            this->clients.erase(client);
            rewrite_file();
            std::cout << "  Client removed successfully!\n";
            return;
        }
    }
}

void ClientSystem::sort_by_ID() {
    std::sort(this->clients.begin(), this->clients.end(), [](const Client& a, const Client& b) {
        return a.get_id() < b.get_id();
    });

    std::cout << "  Data sorted successfully!\n";
}

void ClientSystem::sort_by_name() {
    std::sort(this->clients.begin(), this->clients.end(), [](const Client& a, const Client& b) {
        //------------------------------------------------------------------------------
        std::string a_name = a.get_second_name() + a.get_first_name();
        std::string b_name = b.get_second_name() + b.get_first_name();
        
        return a_name < b_name;
    });
    
    std::cout << "  Data sorted successfully!\n";
}

void ClientSystem::sort_by_phone_number() {
    std::sort(this->clients.begin(), this->clients.end(), [](const Client& a, const Client& b) {
        return a.get_phone_number() < b.get_phone_number();
    });

    std::cout << "  Data sorted successfully!\n";
}

void ClientSystem::sort_by_email() {
    std::sort(this->clients.begin(), this->clients.end(), [](const Client& a, const Client& b) {
        std::string a_email = a.get_email_domain() + a.get_email_name();
        std::string b_email = b.get_email_domain() + b.get_email_name();
        
        return a_email < b_email;
    });

    std::cout << "  Data sorted successfully!\n";
}