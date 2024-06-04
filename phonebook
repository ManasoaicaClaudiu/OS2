#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <regex>

class Phonebook {
private:
    std::map<std::string, std::string> contacts;
    std::mutex mtx;  
public:
    void addContact(const std::string& name, const std::string& phone) {
        std::lock_guard<std::mutex> lock(mtx);
        contacts[name] = phone;
        std::cout << "Contact added: " << name << " - " << phone << std::endl;
    }

    void removeContact(const std::string& name) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << "Contact removed: " << name << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void displayContacts() {
        std::lock_guard<std::mutex> lock(mtx);
        if (contacts.empty()) {
            std::cout << "The phonebook is empty." << std::endl;
        } else {
            std::cout << "Contacts:" << std::endl;
            for (const auto& contact : contacts) {
                std::cout << contact.first << ": " << contact.second << std::endl;
            }
        }
    }
};

void displayContactsThread(Phonebook& phonebook) {
    phonebook.displayContacts();
}

bool isValidPhoneNumber(const std::string& phone) {
    
    std::regex phone_regex("\\d{10}");
    return std::regex_match(phone, phone_regex);
}

int main() {
    Phonebook phonebook;
    int choice;
    std::string name, phone;

    do {
        std::cout << "1. Add contact" << std::endl;
        std::cout << "2. Remove contact" << std::endl;
        std::cout << "3. Display contacts" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                
                do {
                    std::cout << "Enter phone number (10 digits): ";
                    std::getline(std::cin, phone);
                    if (!isValidPhoneNumber(phone)) {
                        std::cout << "Invalid phone number. Please try again." << std::endl;
                    }
                } while (!isValidPhoneNumber(phone));
                
                phonebook.addContact(name, phone);
                break;
            case 2:
                std::cout << "Enter name to remove: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                phonebook.removeContact(name);
                break;
            case 3: {
                std::thread t(displayContactsThread, std::ref(phonebook));
                t.join();
                break;
            }
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
