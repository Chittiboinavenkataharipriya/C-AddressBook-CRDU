#include <stdio.h>
#include "contact.h"
/* Structure declaration */

int arr_ind[100];
int arr_count = 0; 
int main()
{
    /* Variable and structre defintion */
    char option;
    struct Address_book addressbook;

    init_intitalization(&addressbook);

    load_contacts(&addressbook);
    
    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1. Add contact\n2. Display contact\n3. Search contact\n4. Edit contact\n5. Delete contact\n6. Save contact\n7. Exit\n");
        printf("Enter the option : ");
        scanf("%hhd", &option);

        switch (option) /* Based on choosed option */
        {
            case 1:
            {
                create_contact(&addressbook);
                break;
            }

            case 2:
            {
                printf("List contacts:");
                list_contacts(&addressbook);
                break;
            }
            case 3:
            {
                search_contacts(&addressbook);
                break;
                
            }
            case 4:
            {
                edit_contact(&addressbook);
                break;
            }
            case 5:
            {
                // printf("Delete Contact menu : \n1.Search by Name \n2.Search by Mobile number\n3.Search by Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
                delete_contact(&addressbook);
                break;
            }
            case 6:
            {
                printf("Saving contacts\n");
                save_contacts(&addressbook);
                break;
            }
            case 7:
            {
                printf("INFO : Save and Exit...\n");
                return 0;
                break;
            }
            default:
            {
                printf("Invalid option \n");
                break;
            }
            
        }
    }
    return 0;
}
