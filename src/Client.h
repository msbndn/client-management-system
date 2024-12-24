#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client {
private:
    int id;
    std::string name;
    std::string phone_number;
    std::string email;

public:
    Client (const int& id, const std::string& name, const std::string& phone_number, const std::string& email);

    int get_id() const;
    std::string get_name() const;
    std::string get_phone_number() const;
    std::string get_email() const;

    void set_name (const std::string& new_name);
    void set_phone_number (const std::string& new_phone_number);
    void set_email (const std::string& new_email);
    
    void display_client() const;

    std::string get_first_name() const;
    std::string get_second_name() const;
    std::string get_email_name() const;
    std::string get_email_domain() const;
};

#endif