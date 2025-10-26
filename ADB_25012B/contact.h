#ifndef CONTACT_H
#define CONTACT_H

struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
};


struct Address_book
{
    struct Contact_data contact_details[100];
    int contact_count;
};

/* Function declarations */
void init_intitalization(struct Address_book *addressbook);
int create_contact(struct Address_book *addressbook);
void list_contacts(struct Address_book *addressbook);
int search_contacts(struct Address_book *addressbook);
int edit_contact(struct Address_book *addressbook);
int delete_contact(struct Address_book *addressbook);
int save_contacts(struct Address_book *addressbook);
int load_contacts(struct Address_book *addressbook);
//validations  functions declaration/prototypes

//Name Vlidations
int is_all_digits(const char *str);
int start_with_number(const char *str);
int checking_valid_name(const char *str);                                                                               

//Number validations
int Only_numbers(const char *str);
int length_check_number(const char *str);
int start_of_mobile_number(const char *str);
int checking_valid_number(const char *str);
int checking_unique_number(const char* Mobile_number, const struct Address_book *addressbook);

//Mail Validations
int starts_with_lowercase(const char *mail);
int lowercase_only(const char *mail);
int contains_at_symbol(const char *mail);
int ends_with_dotcom(const char *mail);
int check_between_at_and_dotcom(const char *mail);
int checking_valid_mail(const char *mail);
int checking_unique_mail(const char* Mail_ID, const struct Address_book *addressbook);

//Searching Contact
int search_by_name(struct Address_book *addressbook, const char *Name);
int search_by_number(struct Address_book *addressbook, const char *Mobile_number);
int search_by_mail(struct Address_book *addressbook, const char *Mail_ID);

//Deletion of Contact
int delete_contact_index(struct Address_book *addressbook, int index);

//Edit of Contact
struct Contact_data* search_contacts_for_edit(struct Address_book *addressbook);
int edit_name(struct Contact_data *contact);
int edit_mobile_number(struct Contact_data *contact, struct Address_book *addressbook);
int edit_mail_id(struct Contact_data *contact, struct Address_book *addressbook);
int edit_all_details(struct Contact_data *contact, struct Address_book *addressbook);
#endif // CONTACT_H
// CONTACT_H        