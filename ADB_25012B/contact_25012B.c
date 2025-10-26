#include <stdio.h>
#include "contact.h"
#include <string.h>

extern int arr_ind[100];
extern int arr_count;

/* Function definitions */
void init_intitalization(struct Address_book *addressbook)
{
    addressbook->contact_count=0;
    for(int i=0;i<100;i++)
    {
        addressbook->contact_details[i].Name[0] = '\0';
        addressbook->contact_details[i].Mobile_number[0] = '\0';
        addressbook->contact_details[i].Mail_ID[0] = '\0';
    }   
}
int create_contact(struct Address_book *addressbook)
{
    struct Contact_data *new_contact = &addressbook->contact_details[addressbook->contact_count];
    char ch;
    while(1)
    {
        printf("Enter Name : ");
        scanf(" %[^\n]",new_contact->Name);

        if(checking_valid_name(new_contact->Name))
        {
            break;  //valid
        }
        else 
        {
            printf("\nDo you want to :\n1. Enter the name again \n2. Exit \nEnter your choice : ");
            scanf(" %c",&ch);
            getchar();

            if(ch == '1')
            {
                continue;
            }
            else if(ch == '2')
            {
                printf("Exiting to the main menu. \n");
                return 0;
            }
            else
            {
                printf("Invalid choice returning to main menu.\n");
                return 0;
            }
        }
    }
    while(1)
    {
        printf("Enter the Mobile Number with 10 digits: ");
        scanf(" %s",new_contact->Mobile_number);
        if(checking_valid_number(new_contact->Mobile_number))
        {
            if(checking_unique_number(new_contact->Mobile_number,addressbook))
            {
                break;   //valid
            }
            else
            {
                printf("Given Mobile Number already exists.\n");
                printf("\nDo you want to:\n1. Enter the Mobile number again \n2. Exit \nEnter your choice: ");
                scanf(" %c", &ch);
                getchar();
                if(ch == '1')
                {
                    continue;
                }
                else if(ch == '2')
                {
                    printf("Exiting to the main menu.\n");
                    return 0;
                }
                else
                {
                    printf("Invalid choice returning to main menu.\n");
                    return 0;
                }
            }
        }
        else
        {
            printf("\nDo you want to :\n1. Enter the Mobile number again \n2. Exit \nEnter your choice : ");
            scanf(" %c",&ch);
            getchar();
            if(ch == '1')
            {
                continue;
            }
            else if(ch == '2')
            {
                printf("Exiting to the main menu. \n");
                return 0;
            }
            else
            {
                printf("Invalid choice returning to main menu.\n");
                return 0;
            }
        }
    }
    while(1)
    {
        printf("Enter Mail ID : ");
        scanf(" %[^\n]",new_contact->Mail_ID);
        if(checking_valid_mail(new_contact->Mail_ID))
        {
            if(checking_unique_mail(new_contact->Mail_ID,addressbook))
            {
                break;//valid
            }
            else
            {
                printf("Given Mail ID already exists.\nDo you want to:\n1. Enter the Mail ID again \n2. Exit \nEnter your choice:");
                scanf(" %c", &ch);
                getchar();
                if(ch == '1')
                {
                    continue;
                }
                else if(ch == '2')
                {
                    printf("Exiting to the main menu.\n");
                    return 0;
                }
                else
                {
                    printf("Invalid choice returning to main menu.\n");
                    return 0;
                }
            }
        }
        else
        {
            printf("\nDo you want to : \n1. Enter the Mail ID again.\n2. Exit \nEnter Your choice : ");
            scanf(" %c",&ch);
            getchar();
            if(ch == '1')
                continue;
            else if(ch == '2')
            {
                printf("Exiting to the Main menu.\n");
                return 0;
            }
            else
            {
                printf("Invalid choice returning to the main menu.\n");
                return 0;
            }
        }
    }
    addressbook->contact_count++;
    printf("Contact added Successfully.\n");
    return 1;
}
void list_contacts(struct Address_book *addressbook)
{
    if(addressbook->contact_count == 0)
    {
        printf("Address book is empty.Please Add contacts to list.\n");
        return;
    }
    printf("List of Contacts :\n");
    printf("%-5s\t%-32s %-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
    for(int i=0;i<addressbook->contact_count;i++)
    {
        printf("%d\t%-32s %-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
    }
}
int search_contacts(struct Address_book *addressbook)
{
    char input[40];
    char option;
    char ch;
    while (1)
    {
        printf("\nSearch Contact Menu:\n1. Search by Name\n2. Search by Mobile Number\n3. Search by Mail ID\n4. Exit to Main Menu\nEnter your option: ");
        scanf(" %c", &option);
        getchar();
        switch(option)
        {
            case '1':
            {
                while (1)
                {
                    printf("Enter Name to Search: ");
                    scanf(" %[^\n]", input);
                    getchar();

                    if (checking_valid_name(input))
                    {
                        search_by_name(addressbook, input);
                        break;
                    }
                    else
                    {
                        printf("\nDo you want to :\n1. Enter Name Again\n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();
                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                break;
            }
            case '2':
            {
                while (1)
                {
                    printf("Enter Mobile Number to Search: ");
                    scanf(" %s", input);
                    getchar();

                    if (checking_valid_number(input))
                    {
                        search_by_number(addressbook, input);
                        break;
                    }
                    else
                    {
                        printf("\nDo yyou want to :\n1. Enter Mobile Number Again\n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();

                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                break;
            }
            case '3':
            {
                while (1)
                {
                    printf("Enter Mail ID to Search: ");
                    scanf(" %[^\n]",input);
                    getchar();
                    if (checking_valid_mail(input))
                    {
                        search_by_mail(addressbook, input);
                        break;
                    }
                    else
                    {
                        printf("\nDo you want to :\n1. Enter Mail ID Again\n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();
                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                break;
            }
            case '4':
            {
                printf("Exiting to the Main Menu...\n");
                return 0;
            }
            default :
            {
                printf("Invalid choice returning to the Main menu.\n");
                break;
            }
        }
    }
    return 1;
}
int edit_contact(struct Address_book *addressbook)
{
    struct Contact_data *contact = NULL;
    char choice;
    while(1)
    {
        contact = search_contacts_for_edit(addressbook);

        if(contact == NULL)
        {
            printf("No contact selected for editing. Returning to main menu.\n");
            return 0;
        }
        printf("\nEdit Contact Menu :\n1. Edit by Name\n2. Edit by Mobile Number\n3. Edit by Mail ID\n4. Edit All fields\n5. Exit to Main Menu\nEnter your choice: \n");
        scanf(" %c",&choice);
        getchar();
        switch(choice)
        {
            case '1':
            {
                edit_name(contact);
                break;
            }
            case '2':
            {
                edit_mobile_number(contact, addressbook);  
                break;
            }
            case '3':
            {
                edit_mail_id(contact, addressbook);
                break;
            }
            case '4':
            {
                edit_all_details(contact, addressbook); 
                break;
            }
            case '5':
            {
                printf("Returning to main menu...\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice,try again.\n");
                continue;
            }
        }
    }
    return 1;
}
int delete_contact(struct Address_book *addressbook)
{
    char input[40];
    char option;
    char ch;
    char found, i;
    if(addressbook->contact_count == 0)
    {
        printf("Address book is empty. Nothing to delete.\n");
        return 0;
    }
    while(1)
    {
        printf("\nDelete Contact Menu:\n1. Delete by Name\n2. Delete by Mobile Number\n3. Delete by Mail ID\n4. Exit to the main menu.\nEnter your option: ");
        scanf(" %c", &option);
        getchar();
        found = 0;
        switch(option)
        {
            case '1':
            {
                while(1)
                {
                    printf("Enter Name to delete : ");
                    scanf(" %[^\n]", input);
                    getchar();

                    if(!checking_valid_name(input))
                    {
                        printf("\nDo you want to :\n1. Enter Name Again\n2. Exit\nEnter your choice: ");
                        scanf(" %c",&ch);
                        getchar();
                        if(ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int arr_count = 0;
                    printf("%5s\t%-32s\t%-10s\t\t%35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                    for(i=0;i<addressbook->contact_count;i++)
                    {
                        if(strcmp(addressbook->contact_details[i].Name,input)==0)
                        {
                            arr_ind[arr_count++] = i;
                            printf("%d\t%-32s\t%-10s\t\t%-35s\n",arr_count,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                        }
                    }
                    if(arr_count == 0)
                    {
                        printf("Contact not found.\n");
                        break;
                    }
                    int sn;
                    printf("\nEnter the serial No. of Contact you want to delete : ");
                    scanf("%d",&sn);
                    getchar();
                    if(sn >= 1 && sn <= arr_count)
                    {
                        delete_contact_index(addressbook,arr_ind[sn-1]);
                    }
                    else
                    {
                        printf("Invalid serial number.\n");
                    }
                    break;
                }
                break;
            }
            case '2':
            {
                while(1)
                {
                    printf("Enter Mobile number to delete : ");
                    scanf(" %s",input);
                    getchar();
                    if(checking_valid_number(input))
                    {
                        printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                        for(i=0;i<addressbook->contact_count;i++)
                        {
                            if(strcmp(addressbook->contact_details[i].Mobile_number,input)==0)
                            {
                                printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                                delete_contact_index(addressbook, i);
                                found = 1;
                                break;
                            }
                        }
                        if(!found)
                        {
                            printf("Contact not found.\n");
                        }
                        break;
                    }
                    else
                    {
                        printf("\nDo you wnat to :\n1. Enter Mobile Number Again\n2. Exit to Delete Menu\nEnter your choice : ");
                        scanf(" %c",&ch);
                        getchar();
                        if(ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                break;
            }
            case '3':
            {
                while(1)
                {
                    printf("Enter Mail ID to delete : ");
                    scanf(" %[^\n]", input);
                    getchar();
                    if(checking_valid_mail(input))
                    {
                        printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                        for(i=0;i<addressbook->contact_count;i++)
                        {
                            if(strcmp(addressbook->contact_details[i].Mail_ID,input)==0)
                            {
                                printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                                delete_contact_index(addressbook, i);
                                found = 1;
                                break;
                            }
                        }
                        if(!found)
                        {
                            printf("Contact not found.\n");
                        }
                        break;
                    }
                    else
                    {
                        printf("\nDo you wnat to :\n1. Enter Mail ID Again\n2. Exit to Delete Menu\nEnter your choice : ");
                        scanf(" %c",&ch);
                        getchar();
                        if(ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }

                    }
                }
                break;
            }
            case '4':
            {
                printf("Exiting to main Menu.\n");
                return 0;
            }
            default:
            {
                printf("Invalid option. \n");
            }
        }
    }
    return 1;
}
int save_contacts(struct Address_book *addressbook)
{
    FILE *fp = fopen("Contacts.csv", "w");
    if(fp == NULL)
    {
        printf("Error openning file for saving");
        return 0;
    }
    fprintf(fp, "#%d\n",addressbook->contact_count);

    for(int i=0 ;i<addressbook->contact_count;i++)
    {
        fprintf(fp, "%d.%s,%s,%s\n", i+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }

    fclose(fp);
    printf("Contacts saved successfully from 'contacts.csv'.\n");
    return 1;
}
// Validations Part Functions
// For Name Validations.
int is_all_digits(const char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int start_with_number(const char *str)
{
    if(str[0] >= '0' && str[0] <= '9')
    {
        return 0;
    }
    return 1;
}
int checking_valid_name(const char *str)
{
    if(!start_with_number(str))
    {
        printf("Invalid Name : Name should not start with a number.\n");
        return 0;
    }
    if(!is_all_digits(str))
    {
        printf("Invalid Name : Name should not contain numbers.\n");
        return 0;
    }
    return 1;
}
//For Mobile Number Validation
int Only_numbers(const char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int start_of_mobile_number(const char *str)
{
    if(str[0] >= '6' && str[0] <= '9')
    {
        return 1;
    }
    return 0;
}
int length_check_number(const char *str)
{
    return strlen(str) == 10;
}
int checking_valid_number(const char *str)
{
    if(!length_check_number(str))
    {
        printf("Invalid Mobile Number : Mobile Number must be 10 digits.\n");
        return 0;
    }
    if(!Only_numbers(str))
    {
        printf("Invalid Mobile number : Mobile Number should be in numbers.\n");
        return 0;
    }
    if(!start_of_mobile_number(str))
    {
        printf("Invalid Mobile number : Mobile number should start with in range of 6 to 9.\n");
        return 0;
    }
    return 1;
}
int checking_unique_number(const char* Mobile_number, const struct Address_book *addressbook)
{
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number, Mobile_number)==0)
        {
            return 0;
        }
    }
    return 1;
}
//For Mail ID validations functions
int starts_with_lowercase(const char *mail)
{
    return (mail[0] >= 'a' && mail[0] <= 'z');
}
int lowercase_only(const char *mail)
{
    for(int i=0;mail[i] != '\0';i++)
    {
        if((mail[i] < 'a' || mail[i] > 'z') && mail[i] != '@' && mail[i] != '.')
        {
            return 0;
        }
    }
    return 1;
}
int contains_at_symbol(const char *mail)
{
    int count=0;
    for(int i=0;mail[i] != '\0';i++)
    {
        if(mail[i] == '@')
        {
            count++;
        }
    }
    return (count == 1);
}
int ends_with_dotcom(const char *mail)
{
    int len = strlen(mail);
    int count = 0;
    for (int i = 0; i <= len - 4; i++)
    {
        if (strncmp(&mail[i], ".com", 4) == 0)
        {
            count++;
        }
    }
    if (count == 1 && strcmp(&mail[len - 4], ".com") == 0)
    {
        return 1;
    }
    return 0;
}
int check_between_at_and_dotcom(const char *mail)
{
    int at = -1;
    int dot = -1;
    int len = strlen(mail);
    for (int i = 0;i < len; i++)
    {
        if (mail[i] == '@')
        {
            at = i;
            break;
        }
    }
    if (len >= 4 && strcmp(&mail[len - 4], ".com") == 0)
    {
        dot = len - 4;
    }
    if (at == -1 || dot == -1 || dot - at <= 4)
    {
        return 0;
    }
    int count = 0;
    for (int i = at + 1; i < dot; i++)
    {
        if (mail[i] < 'a' || mail[i] > 'z') 
        {
            return 0;
        }
        count++;
    }
    return (count >= 1);
}
int checking_valid_mail(const char *mail)
{
    if (!starts_with_lowercase(mail))
    {
        printf("Invalid Mail ID : Mail ID should start with a lowercase letter.\n");
        return 0;
    }
    if (!lowercase_only(mail))
    {
        printf("Invalid Mail ID : Mail ID should contain only lowercase letters.\n");
        return 0;
    }
    if (!contains_at_symbol(mail))
    {
        printf("Invalid Mail ID : In Mail ID, Only one '@' symbol should be there.\n");
        return 0;
    }
    if (!ends_with_dotcom(mail))
    {
        printf("Invalid Mail ID : Mail ID should end with one'.com'.\n");
        return 0;
    }
    if (!check_between_at_and_dotcom(mail))
    {
        printf("Invalid Mail ID : In between '@' and '.com', must have atleast 4 lowercase letters and no digits.\n");
        return 0;
    }
    return 1;
}
int checking_unique_mail(const char* Mail_ID, const struct Address_book *addressbook)
{
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID, Mail_ID)==0)
        {
            return 0;
        }
    }
    return 1;
}
//Searching Name in the List.
int search_by_name(struct Address_book *addressbook, const char *Name)
{
    arr_count = 0;
    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        if (strcmp(addressbook->contact_details[i].Name, Name) == 0)
        {
            arr_ind[i] = arr_count++;
            printf("%d\t%-32s\t%-10s\t\t%-35s\n",arr_count,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
        }
    }
    if(arr_count == 0)
    {
        printf("Contact with Name '%s' not found.\n", Name);
        return 0;
    }
    return 1;
}
//Searching Mobile Number in the List
int search_by_number(struct Address_book *addressbook, const char *Mobile_number)
{
    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        if (strcmp(addressbook->contact_details[i].Mobile_number, Mobile_number) == 0)
        {
            printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
            return 1;
        }
    }
    printf("Contact with Mobile Number '%s' not found.\n", Mobile_number);
    return 0;
}
//Searching Mail ID in the list
int search_by_mail(struct Address_book *addressbook, const char *Mail_ID)
{
    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        if (strcmp(addressbook->contact_details[i].Mail_ID, Mail_ID) == 0)
        {
            printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
            return 1;
        }
    }
    printf("Contact with Mail ID '%s' not found.\n", Mail_ID);
    return 0;
}
//Deletion Function 
int delete_contact_index(struct Address_book *addressbook, int index)
{
    if(index < 0 || index >= addressbook->contact_count)
    {
        printf("Invalid index for deletion.\n");
        return 0;
    }
    for(int j = index ; j < addressbook->contact_count - 1 ; j++)
    {
        addressbook->contact_details[j] = addressbook->contact_details[j+1];
    }
    addressbook->contact_count--;
    printf("Conatct deleted successfully.\n");
    return 1;
}
//Editing 
//searching the contact and  validating for edit
struct Contact_data* search_contacts_for_edit(struct Address_book *addressbook)
{
    char input[40];
    char option;
    char ch;
    while (1)
    {
        printf("\nSeach Contact Menu. \n1. Search by Name\n2. Search by Mobile Number\n3. Search by Email\n4. Exit to Main Menu\nEnter your choice: ");
        scanf(" %c", &option);
        getchar();
        switch(option)
        {
            case '1':
            {
                while (1)
                {
                    printf("Enter name to search: ");
                    scanf(" %[^\n]", input);
                    getchar();

                    if (!checking_valid_name(input))
                    {
                        printf("Do you want to :\n1. Enter name again\n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();
                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    arr_count = 0;
                    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                    for (int i = 0; i < addressbook->contact_count; i++)
                    {
                        if (strcmp(addressbook->contact_details[i].Name, input) == 0)
                        {
                            arr_ind[arr_count] = i;
                            printf("%d\t%-32s\t%-10s\t\t%-35s\n",arr_count+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                            arr_count++;
                        }
                    }
                    if(arr_count == 0)
                    {
                        printf("Contact not found with that name.\n");
                        break;
                    }
                    int sn;
                    printf("\nEnter the Serial No. of the contact you want to edit : ");
                    scanf("%d",&sn);
                    getchar();
                    if(sn >= 1 && sn <= arr_count)
                    {
                        return &addressbook->contact_details[arr_ind[sn - 1]];
                    }
                    else
                    {
                        printf("Invalid Serial number.Returning to the main menu.\n");
                        break;
                    }
                }
                break;
            }
            case '2':
            {
                while (1)
                {
                    printf("Enter mobile number to search: ");
                    scanf("%s", input);
                    getchar();
                    if (!checking_valid_number(input))
                    {
                        printf("Do you want to : \n1.Enter the mobile Number again \n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();
                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                    for (int i = 0; i < addressbook->contact_count; i++)
                    {
                        if (strcmp(addressbook->contact_details[i].Mobile_number, input) == 0)
                        {
                            printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                            return &addressbook->contact_details[i];
                        }
                    }
                    printf("Contact not found with that mobile number.\n");
                    break;
                }
            }
            case '3':
            {
                while (1)
                {
                    printf("Enter email ID to search: ");
                    scanf(" %[^\n]", input);
                    getchar();
                    if (!checking_valid_mail(input))
                    {
                        printf("Invalid email!\n1. Enter again.\n2. Exit to Search Menu\nEnter your choice: ");
                        scanf(" %c", &ch);
                        getchar();
                        if (ch == '1')
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    printf("%-5s\t%-32s\t%-10s\t\t%-35s\n","S.no.","Contact Name","Contact Number","Contact Mail");
                    for (int i = 0; i < addressbook->contact_count; i++)
                    {
                        if (strcmp(addressbook->contact_details[i].Mail_ID, input) == 0)
                        {
                            printf("%d\t%-32s\t%-10s\t\t%-35s\n",i+1,addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                            return &addressbook->contact_details[i];
                        }
                    }
                    printf("Contact not found with that email.\n");
                    break;
                }
            }
            case '4':
            {
                printf("Exiting to main menu...\n");
                return NULL;
            }
            default :
            {
                printf("Invalid option. Please try again.\n");
            }
        }
    }
}
// Editing Name ...
int edit_name(struct Contact_data *contact)
{
    char new_name[35];
    char ch;

    while (1)
    {
        printf("Enter new name: ");
        scanf(" %[^\n]", new_name);
        getchar();

        if (checking_valid_name(new_name))
        {
            strcpy(contact->Name, new_name);
            printf("Name updated successfully!\n");
            return 1;
        }
        else
        {
            printf("Invalid name.\nDo you want to :\n1. Enter name again\n2. Exit\nEnter your choice :\n");
            scanf(" %c",&ch);
            getchar();

            if(ch == '1')
            {
                continue;
            }
            else if(ch =='2')
            {
                printf("Exiting name edit and returning to edit menu.\n");
                return 0;
            }
            else
            {
                printf("Invalid choice. Exiting to edit menu.\n");
                return 0;
            }
            return 0; 
        }
    }
}
//Editing Mobile number ....
int edit_mobile_number(struct Contact_data *contact, struct Address_book *addressbook)
{
    char new_number[15];
    char ch;

    while (1)
    {
        printf("Enter new mobile number: ");
        scanf(" %s", new_number);
        getchar();

        if (checking_valid_number(new_number))
        {
            if(checking_unique_number(new_number,addressbook))
            {
                strcpy(contact->Mobile_number, new_number);
                printf("Mobile number updated successfully!\n");
                return 1;   
            }
            else
            {
                printf("Entered number is already exists.\nDo you want to :\n1. Enter mobile number again\n2. Exit\nEnter your choice :\n");
                scanf(" %c",&ch);
                getchar();

                if(ch == '1')
                {
                    continue;
                }      
                else if(ch =='2')
                {
                    printf("Exiting mobile number edit and returning to edit menu.\n");
                    return 0;
                }
                return 0;
            }
        }
        else
        {
            printf("Invalid mobile number.\nDo you want to :\n1. Enter mobile number again\n2. Exit\nEnter your choice :\n");
            scanf(" %c",&ch);
            getchar();

            if(ch == '1')
            {
                continue;
            }
            else if(ch =='2')
            {
                printf("Exiting mobile number edit and returning to edit menu.\n");
                return 0;
            }
            return 0;
        }
    }
}
//Editing Mail ID.......
int edit_mail_id(struct Contact_data *contact, struct Address_book *addressbook)
{
    char new_mail[40];
    char ch;

    while (1)
    {
        printf("Enter new email ID: ");
        scanf(" %[^\n]", new_mail);
        getchar();

        if (checking_valid_mail(new_mail))
        {
            if(checking_unique_mail(new_mail,addressbook))
            {
                strcpy(contact->Mail_ID, new_mail);
                printf("Email ID updated successfully!\n");
                return 1;
            }
            else
            {
                printf("Entered mail is already exits.\nDo you want to :\n1. Enter Mail ID again\n2. Exit\nEnter your choice :\n");
                scanf(" %c",&ch);  
                getchar();
                if(ch == '1')
                {
                    continue;
                }
                else if(ch =='2')
                {
                    printf("Exiting mail id edit and returning to edit menu.\n");
                    return 0;
                }
                return 0;
            }
        }
        else
        {
            printf("Invalid email ID.\nDo you want to :\n1. Enter Mail ID again\n2. Exit\nEnter your choice :\n");
            scanf(" %c",&ch);  
            getchar();

            if(ch == '1')
            {
                continue;
            }
            else if(ch =='2')
            {
                printf("Exiting mail id edit and returning to edit menu.\n");
                return 0;
            }
            return 0;
        }
    }
}
//Edit all details....
int edit_all_details(struct Contact_data *contact, struct Address_book *addressbook)
{
    int update;
    if (edit_name(contact))
    {
        update++;
    }
    if (edit_mobile_number(contact, addressbook))
    {
        update++;
    }
    if (edit_mail_id(contact, addressbook))
    {
        update++;
    }
    if (update == 3)
    {
        printf("All fields updated successfully.\n");
    }
    else
    {
        printf("One or more fields were not updated due to invalid input.\n");
    }
    return update;
}