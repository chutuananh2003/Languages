#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts;
};

void addContact(struct AddressBook* book, const char* name, const char* phone, const char* email) {
    if (book->numContacts < MAX_CONTACTS) {
        struct Contact* newContact = &book->contacts[book->numContacts];
        strncpy(newContact->name, name, sizeof(newContact->name));
        strncpy(newContact->phone, phone, sizeof(newContact->phone));
        strncpy(newContact->email, email, sizeof(newContact->email));
        book->numContacts++;
    } else {
        printf("Danh bạ đã đầy, không thể thêm liên hệ mới.\n");
    }
}

void displayContacts(const struct AddressBook* book) {
    printf("your contacts:\n");
    for (int i = 0; i < book->numContacts; i++) {
        const struct Contact* contact = &book->contacts[i];
        printf("Name: %s\n", contact->name);
        printf("Phone Number: %s\n", contact->phone);
        printf("Email: %s\n", contact->email);
        printf("---------------------------\n");
    }
}

int main() {
    struct AddressBook myAddressBook;
    myAddressBook.numContacts = 0;

    while (1) {
        printf("Choose Options:\n");
        printf("1. Add Contact\n");
        printf("2. Show Contacts\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                char phone[15];
                char email[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(&myAddressBook, name, phone, email);
                break;
            }
            case 2:
                displayContacts(&myAddressBook);
                break;
            case 3:
                printf("Good Bye!\n");
                exit(0);
            default:
                printf("Invalid Choise. Please try again.\n");
        }
    }

    return 0;
}

