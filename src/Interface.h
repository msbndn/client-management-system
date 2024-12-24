#ifndef INTERFACE_H
#define INTERFACE_H

#include "ClientSystem.h"

namespace interface {
    void add_client_option(ClientSystem *const client_system);
    void find_client_by_ID(ClientSystem *const client_system);
    void find_client_by_name(ClientSystem *const client_system);
    void find_client_by_phone_number(ClientSystem *const client_system);
    void find_client_by_email(ClientSystem *const client_system);
    void find_client_option(ClientSystem *const client_system);
    void edit_client_option(ClientSystem *const client_system);
    bool confirm_action(const std::string& action, const std::string& description);
    void remove_client_option(ClientSystem *const client_system);
    void pause_to_click();
    void export_from_file(ClientSystem *const client_system);
    void save_to_file(ClientSystem *const client_system);
    void display_clients(ClientSystem *const client_system);
    void sort_clients(ClientSystem *const client_system);
}

#endif