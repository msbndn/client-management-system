#include "Client.h"


Client::Client (const int& id, const std::string& name, const std::string& phone_number, const std::string& email) 
    : id(id), name(name), phone_number(phone_number), email(email) {}

int Client::get_id() const { return id; }
std::string Client::get_name() const { return name; }
std::string Client::get_phone_number() const { return phone_number; }
std::string Client::get_email() const { return email; }

void Client::set_name (const std::string& new_name) { name = new_name; }
void Client::set_phone_number (const std::string& new_phone_number) { phone_number = new_phone_number; }
void Client::set_email (const std::string& new_email) { email = new_email; }

void Client::display_client() const {
    std::cout << "  ID: " << id << "\n"
                << "  Name: " << name << "\n"
                << "  Phone number: " << phone_number << "\n"
                << "  Email: " << email << "\n";
}

std::string Client::get_first_name() const {
    std::string first_name = "";

    for(const char& ch : this->name) {
        if (ch != ' ') {
            first_name.push_back(ch);
        } else {
            break;
        }
    }

    return first_name;
}

std::string Client::get_second_name() const {
    std::string second_name = "";

    bool is_second_name = false;
    for(const char& ch: this->name) {
        if (ch == ' ') { 
            is_second_name = true; 
            continue;
        }
        if (is_second_name) { second_name.push_back(ch); }
    }

    return second_name;
}

std::string Client::get_email_name() const {
    std::string email_name = "";

    for(const char& ch : this->email) {
        if (ch != '@') {
            email_name.push_back(ch);
        } else {
            break;
        }
    }

    return email_name;
}

std::string Client::get_email_domain() const {
    std::string domain = "";

    bool is_domain = false;
    for(const char& ch: this->email) {
        if (ch == '@') { 
            is_domain = true; 
            continue;
        }
        if (is_domain) { domain.push_back(ch); }
    }

    return domain;
}