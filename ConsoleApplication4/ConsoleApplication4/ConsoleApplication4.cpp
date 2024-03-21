#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Function to encryption
std::string encrypt(std::string plain_text, std::string secret_key) {
    std::string cipher_text;
    for (int Plain_index = 0; Plain_index < plain_text.size(); Plain_index++) {
        int key_index = Plain_index % secret_key.size();
        char encrypted_char = plain_text[Plain_index] ^ secret_key[key_index]; // Do XOR operator
        cipher_text += encrypted_char;
    }
    // Convert the encrypted message to hexadecimal format
    std::stringstream ss;
    for (char c : cipher_text) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
    }
    return ss.str();
}

// Function to decryption
std::string decrypt(std::string cipher_text, std::string secret_key) {
    std::string decrypted_text;
    for (int Cipher_index = 0; Cipher_index < cipher_text.size(); Cipher_index++) {
        int key_index = Cipher_index % secret_key.size();
        char decrypted_char = cipher_text[Cipher_index] ^ secret_key[key_index]; // Do XOR operator
        decrypted_text += decrypted_char;
    }
    return decrypted_text;
}

int main() {
    std::string secret_key, input_text;
    int choice;

    std::cout << "Please input the secret key: ";
    std::getline(std::cin, secret_key);

    // Check if the secret key is empty
    if (secret_key.empty()) {
        std::cout << "Invalid input. Secret key cannot be empty. Please provide a valid secret key." << std::endl;
        return 1; // Exit the program with an error code
    }

    std::cout << "Enter 1 to encrypt or 2 to decrypt: ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    if (choice == 1) {
        std::cout << "Please input the plain text: ";
        std::getline(std::cin, input_text); // Read the entire line, including spaces
        std::string encrypted_message = encrypt(input_text, secret_key); // Implement the encryption function
        std::cout << "Encrypted Message (hex): " << encrypted_message << std::endl;
    }
    else if (choice == 2) {
        std::cout << "Please input the encrypted message in hex format: ";
        std::getline(std::cin, input_text); // Read the entire line, including spaces

        // Convert hex input back to string
        std::string decrypted_message;
        for (size_t i = 0; i < input_text.length(); i += 2) {
            std::string byteString = input_text.substr(i, 2);
            char byte = (char)std::stol(byteString, nullptr, 16);
            decrypted_message += byte;
        }

        std::string original_message = decrypt(decrypted_message, secret_key);
        std::cout << "Decrypted Message: " << original_message << std::endl;
    }
    else {
        std::cout << "Invalid choice. Please enter 1 for encryption or 2 for decryption." << std::endl;
        return 1;
    }

    return 0;
}
