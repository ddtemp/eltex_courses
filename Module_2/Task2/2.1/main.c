#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_JOB_TITLE_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100
#define MAX_SOCIAL_MEDIA_LENGTH 100
#define MAX_CONTACTS 100

typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char job_title[MAX_JOB_TITLE_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social_media[MAX_SOCIAL_MEDIA_LENGTH];
} Contact;

void addContact(Contact* contacts, int* contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Достигнуто максимальное количество контактов.\n");
        return;
    }

    Contact newContact;

    printf("Введите имя: ");
    if (fgets(newContact.first_name, sizeof(newContact.first_name), stdin)) {
        newContact.first_name[strcspn(newContact.first_name, "\n")] = 0;
    }

    printf("Введите фамилию: ");
    if (fgets(newContact.last_name, sizeof(newContact.last_name), stdin)) {
        newContact.last_name[strcspn(newContact.last_name, "\n")] = 0;
    }

    printf("Введите место работы и должность: ");
    if (fgets(newContact.job_title, sizeof(newContact.job_title), stdin)) {
        newContact.job_title[strcspn(newContact.job_title, "\n")] = 0;
    }

    printf("Введите номер телефона: ");
    if (fgets(newContact.phone_number, sizeof(newContact.phone_number), stdin)) {
        newContact.phone_number[strcspn(newContact.phone_number, "\n")] = 0;
    }

    printf("Введите адрес электронной почты: ");
    if (fgets(newContact.email, sizeof(newContact.email), stdin)) {
        newContact.email[strcspn(newContact.email, "\n")] = 0;
    }

    printf("Введите ссылку на соцсеть или мессенджер: ");
    if (fgets(newContact.social_media, sizeof(newContact.social_media), stdin)) {
        newContact.social_media[strcspn(newContact.social_media, "\n")] = 0;
    }

    contacts[*contactCount] = newContact;
    (*contactCount)++;

    printf("Контакт добавлен!\n");
}

void printContact(Contact contact) {
    printf("Имя: %s %s\n", contact.first_name, contact.last_name);
    printf("Место работы и должность: %s\n", contact.job_title);
    printf("Номер телефона: %s\n", contact.phone_number);
    printf("Адрес электронной почты: %s\n", contact.email);
    printf("Соцсеть или мессенджер: %s\n", contact.social_media);
    printf("\n");
}

void listContacts(Contact* contacts, int contactCount) {
    for (int i = 0; i < contactCount; i++) {
        printf("Контакт #%d:\n", i + 1);
        printContact(contacts[i]);
    }
}

void editContact(Contact* contacts, int contactCount) {
    int contactIndex;
    printf("Введите номер контакта, который вы хотите отредактировать: ");
    scanf("%d", &contactIndex);
    getchar();

    if (contactIndex >= 1 && contactIndex <= contactCount) {
        printf("Введите новую информацию для контакта #%d:\n", contactIndex);
        addContact(contacts, &contactCount);
        printf("Контакт отредактирован!\n");
    } else {
        printf("Неправильный номер контакта.\n");
    }
}

void deleteContact(Contact* contacts, int* contactCount) {
    int contactIndex;
    printf("Введите номер контакта, который вы хотите удалить: ");
    scanf("%d", &contactIndex);
    getchar();

    if (contactIndex >= 1 && contactIndex <= *contactCount) {
        for (int i = contactIndex - 1; i < *contactCount - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*contactCount)--;
        printf("Контакт удален!\n");
    } else {
        printf("Неправильный номер контакта.\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    char inputBuffer[256];  // Буфер для ввода

    while (1) {
        printf("Выберите действие:\n");
        printf("1. Добавить контакт\n");
        printf("2. Вывести список контактов\n");
        printf("3. Редактировать контакт\n");
        printf("4. Удалить контакт\n");
        printf("5. Выход\n");

        printf("Выбор: ");
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin)) {
            int choice = atoi(inputBuffer);

            switch (choice) {
                case 1:
                    addContact(contacts, &contactCount);
                    break;
                case 2:
                    listContacts(contacts, contactCount);
                    break;
                case 3:
                    editContact(contacts, contactCount);
                    break;
                case 4:
                    deleteContact(contacts, &contactCount);
                    break;
                case 5:
                    return 0;
                default:
                    printf("Неправильный выбор. Пожалуйста, выберите действие из списка.\n");
            }
        }
    }
}
