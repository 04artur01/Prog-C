
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/ioctl.h>

#define NAMES 20
#define PHONES 16
#define MAILS 32

typedef struct __attribute__((packed)) {
  char code[3];
  char digits[15];
} PhoneCode;

 PhoneCode phoneCodes[] = {
  {"AFG", "+93"},
  {"ALA", "+358"},
  {"ALB", "+355"},
  {"DZA", "+213"},
  {"ASM", "+1"},
  {"AND", "+376"},
  {"AGO", "+244"},
  {"AIA", "+1"},
  {"ATG", "+1"},
  {"ARG", "+54"},
  {"ARM", "+374"},
  {"ABW", "+297"},
  {"AUS", "+61"},
  {"AUT", "+43"},
  {"AZE", "+994"},
  {"BHS", "+1"},
  {"BHR", "+973"},
  {"BDI", "+257"},
  {"BGD", "+880"},
  {"BRB", "+1"},
  {"BLR", "+375"},
  {"BEL", "+32"},
  {"BLZ", "+501"},
  {"BEN", "+229"},
  {"BMU", "+1"},
  {"BTN", "+975"},
  {"BOL", "+591"},
  {"BES", "+599"},
  {"BIH", "+387"},
  {"BWA", "+267"},
  {"BVT", "+47"},
  {"BRA", "+55"},
  {"IOT", "+246"},
  {"BRN", "+673"},
  {"BGR", "+359"},
  {"BFA", "+226"},
  {"BDI", "+257"},
  {"KHM", "+855"},
  {"CMR", "+237"},
  {"CAN", "+1"},
  {"CPV", "+238"},
  {"CYM", "+1"},
  {"CAF", "+236"},
  {"TCD", "+235"},
  {"CHL", "+56"},
  {"CHN", "+86"},
  {"CX", "+61"},
  {"CCK", "+61"},
  {"COL", "+57"},
  {"COM", "+269"},
  {"COG", "+242"},
  {"COD", "+243"},
  {"COK", "+682"},
  {"CRI", "+506"},
  {"CIV", "+225"},
  {"HRV", "+385"},
  {"CUB", "+53"},
  {"CUW", "+599"},
  {"CYP", "+357"},
  {"CZE", "+420"},
  {"DNK", "+45"},
  {"DJI", "+253"},
  {"DMA", "+1"},
  {"DOM", "+1"},
  {"ECU", "+593"},
  {"EGY", "+20"},
  {"SLV", "+503"},
  {"GNQ", "+240"},
  {"ERI", "+291"},
  {"EST", "+372"},
  {"ETH", "+251"},
  {"FLK", "+500"},
  {"FRO", "+298"},
  {"FJI", "+679"},
  {"FIN", "+358"},
  {"FRA", "+33"},
  {"GUF", "+594"},
  {"PYF", "+689"},
  {"ATF", "+262"},
  {"GAB", "+241"},
  {"GMB", "+220"},
  {"GEO", "+995"},
  {"DEU", "+49"},
  {"GHA", "+233"},
  {"GIB", "+350"},
  {"GRC", "+30"},
  {"GRL", "+299"},
  {"GUM", "+1"},
  {"GTM", "+502"},
  {"GGY", "+44"}
};

struct winsize w;

typedef struct __attribute__((packed)) {
    int id;
    char name[NAMES];
    char surname[NAMES];
    char phone[PHONES];
    char mail[MAILS];
} Contact;

//Prototypes 
//#ifdef functionPrototypes
struct PhoneCode *getPhoneCode(const char *phoneNumber);
void kurs(int mid);
void printMenu(int *Answer2, int mid);
void create(Contact **ptrPers, int *size, int mid);
void search(Contact **ptrPers);
void update(Contact **ptrPers);
void delete(Contact **ptrPers);
void print(Contact **ptrPers);
bool validId(Contact **ptrPers, int *size);
bool validName(Contact **ptrPers, int *size);
bool validSurname(Contact **ptrPers, int *size);
bool validPhone(Contact **ptrPers);
bool validMail(Contact **ptrPers, int *size);
//#endif

//MAIN
int main() {
    ioctl(0, TIOCGWINSZ, &w);
    int tWidth = w.ws_col;
    int mid = tWidth / 3;

    int Answer1 = 0;
    int Answer2 = 0;
    int size = 0;

    //Create dynamic massive
    Contact *person = (Contact *)calloc(1, sizeof(Contact));
    if (person == NULL) {
        return 0;
    }

    //Programm menu start
    printf("%*sDo you want to create contacts book?\n", mid - 12, "");
    do {
        printf("%*s1. Yes\n", mid, "");
        printf("%*s2. No\n\n", mid, "");
        kurs(mid);
        scanf("%d", &Answer1);
        switch (Answer1) {
            case 1:
                Contact **ptrPers = &person;
                (*ptrPers)->id = size + 1;
                do {
                    printMenu(&Answer2, mid);
                    switch (Answer2) {
                        case 1:
                            create(ptrPers, &size, mid);
                            break;
                        case 2:
                            // read contact
                            // search(ptrPers);
                            break;
                        case 3:
                            // update contact
                            // update(person);
                            break;
                        case 4:
                            // delete contact
                            // delete(person);
                            break;
                        case 5:
                            // list contact
                            // print(person);
                            break;
                        case 6:
                            // exit
                            break;
                        default:
                            printf("Invalid option\n");
                            break;
                    }
                } while (Answer2 != 6);
                break;
            case 2:
                printf("Exit program\n");
                return 0;
            default:
                printf("Please select one of the options\n");
                break;
        }
    } while (Answer1 != 1 && Answer2 != 2);
    return 0;
}

//FUNCTIONS//////////////////////////////////////////////////////////////////////
/*OK*/
void kurs(int mid) {
    printf("%*s", mid, "");
}

/*OK*/
void printMenu(int *Answer2, int mid) {
    printf("%*s Contacts menu = * = * =\n", mid, "= * = * =");
    printf("%*s   1. Create\n", mid, "");
    printf("%*s   2. Search\n", mid, "");
    printf("%*s   3. Update\n", mid, "");
    printf("%*s   4. Delete\n", mid, "");
    printf("%*s   5. List\n", mid, "");
    printf("%*s   6. Exit\n\n", mid, "");
    kurs(mid);
    scanf("%d", Answer2);
}

/*Half*/
void create(Contact **ptrPers, int *size, int mid) {
    ++(*size);
    *ptrPers = (Contact *)realloc(*ptrPers, (*size) * sizeof(Contact));
    if (*ptrPers == NULL) {
        return;
    }
    Contact *person = (*ptrPers) + (*size);
    /*OK*/
    //Insert Name
    do {
        printf("%*sEnter correct name\n", mid, "");
        kurs(mid);
        scanf(" %s", ((*ptrPers) + (*size) - 1)->name);
    } while (!validName(ptrPers, size));
    /*OK*/
    //Insert Surname
    do {
        printf("%*sEnter correct surname\n", mid, "");
        kurs(mid);
        scanf(" %s", ((*ptrPers) + (*size) - 1)->surname);
    } while (!validSurname(ptrPers, size));
    /*OK*/
    //Insert Phone
    do {
        printf("%*sEnter correct phone\n", mid, "");
        kurs(mid);
        scanf(" %s", ((*ptrPers) + (*size) - 1)->phone);
    } while (!validPhone(*ptrPers));

    /*OK
    //Insert Mail
    do {
        printf("%*sEnter correct mail\n", mid, "");
        kurs(mid);
        scanf(" %s", ((*ptrPers) + (*size) - 1)->mail);
    } while (!validMail(ptrPers, size));
    */
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*OK*/
bool validName(Contact **ptrPers, int *size) {
    bool Caps = false;
    bool Lows = false;
    bool Lenght = false;

    if (((*ptrPers) + (*size) - 1)->name[0] >= 'A' && ((*ptrPers) + (*size) - 1)->name[0] <= 'Z') {
        Caps = true;
    }

    for (int i = 1; ((*ptrPers) + (*size) - 1)->name[i] != '\0'; ++i) {
        if (((*ptrPers) + (*size) - 1)->name[i] >= 'a' && ((*ptrPers) + (*size) - 1)->name[i] <= 'z') {
            Lows = true;
        } else {
            Lows = false;
            break;
        }
    }
    if (strlen(((*ptrPers) + (*size) - 1)->name) >= 2 && strlen(((*ptrPers) + (*size) - 1)->name) <= NAMES) {
        Lenght = true;
    }
    return (Caps && Lows && Lenght);
}

/*OK*/
bool validSurname(Contact **ptrPers, int *size) {
    bool Caps = false;
    bool Lows = false;
    bool Lenght = false;

    if (((*ptrPers) + (*size) - 1)->surname[0] >= 'A' && ((*ptrPers) + (*size) - 1)->surname[0] <= 'Z') {
        Caps = true;
    }

    for (int i = 1; ((*ptrPers) + (*size) - 1)->surname[i] != '\0'; ++i) {
        if (((*ptrPers) + (*size) - 1)->surname[i] >= 'a' && ((*ptrPers) + (*size) - 1)->surname[i] <= 'z') {
            Lows = true;
        } else {
            Lows = false;
            break;
        }
    }
    if (strlen(((*ptrPers) + (*size) - 1)->surname) >= 2 && strlen(((*ptrPers) + (*size) - 1)->surname) <= NAMES) {
        Lenght = true;
    }
    return (Caps && Lows && Lenght);
}

/*OK*/
bool validPhone(Contact *ptrPers) 
{
    
    struct PhoneCode *getPhoneCode(const char *phoneNumber)
    printf("%s", phoneCodes[0]);
    {
        for (int i = 0; i < sizeof(phoneCodes) / sizeof(phoneCodes[0]); ++i) {
            if (strncmp(phoneNumber, phoneCodes[i].digits, strlen(phoneCodes[i].digits)) == 0) {
              printf("%s", &phoneCodes[i]);
                return &phoneCodes[i];              
                }
            }
        }
        printf("%s", phoneCodes[sizeof(phoneCodes) / sizeof(phoneCodes[0])]);
        return NULL;
}