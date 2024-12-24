#ifndef CLIENTSYSTEM_H
#define CLIENTSYSTEM_H

#include "Client.h"

#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

class ClientSystem {
private:
    std::vector<Client> clients;
    int next_id = 1;
    std::string filename = "data\\clients.csv";

public:
    std::string get_filename() const;
    void add_to_file(const Client* client) const;
    void export_from_file(std::string filename = "");
    void rewrite_file() const;
    void save_to_file(std::string filename = "") const;

    void display_clients() const;

    bool is_no_client() const;
    void add_client (const std::string& name, const std::string& phone_number, const std::string& email);
    void edit_client(const int& id, const std::string& name, const std::string& phone_number, const std::string& email);
    void remove_client(const int& id);

    Client* find_client (const int& id);
    Client* find_client (const std::string& selection_method, const std::string& seeking_value);
    
    void sort_by_ID();
    void sort_by_name();
    void sort_by_phone_number();
    void sort_by_email();
};

#endif