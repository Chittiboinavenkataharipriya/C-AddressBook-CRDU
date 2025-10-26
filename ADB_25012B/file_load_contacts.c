#include<stdio.h>
#include"contact.h"

int load_contacts(struct Address_book *addressbook)
{
    FILE *fp = fopen("contacts.csv","r");
    if(!fp)
    {
        printf("Error file name\n");
        addressbook->contact_count = 0;
        return 0;
    }

    fscanf(fp, "#%d\n", &addressbook->contact_count);

    for(int i=0;i<addressbook->contact_count;i++)
    {
        int ind;
        fscanf(fp, "%d.%[^,],%[^,],%[^\n]\n",&ind,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }

    fclose(fp);
    printf("\nContacts loaded successfully from 'contacts.csv'.\n");
    return 1;
}