/***********************************************************************************************************************************************************
WHATSAPP FUNCTIONS ARE IMPLEMENTED USING BASIC KNOWLEDGE OF C, DATA STRUCTURES AND ALGORITHMS. TOTAL 9 ALGORITHMS ARE USED. WE HAVE TRIED TO IMPLEMENT
ALMOST ALL FUNCTIONS WHICH ARE PROVIDED BY PRESENT WHATSAPP INCLUDING META AND BETA. WE ARE DAILY USERS OF WHATS-APP, AS A STUDENT WE THOUGHT OF SOME
NEW FUNCTIONS, IF THOSE ARE INTRODUCED IN NEW VERSION WE CAN ENJOY THE LONG TIME JOURNEY IN OUR FUTURE. WE HAD INCLUDED CHANGES IN LOCATION SHARING, SUCH
THAT IF MORE THAN 2 FRIENDS TURN ON LIVE, THEN MINIMUM DISTANCE TO TRAVEL TO ALL FRIENDS CAN BE CALCULATED AND PROVIDED TO USER IN WHATSAPP ONLY,
GAMES CAN ALSO BE INTRODUCED, TO HELP USER TO EXCERSICE THEIR BRAIN AND TO KEEP THEM FRESH FROM THEIR WORK LOAD AND so on.
HEAP SORT : TO SORT AND DISPLAY THE NEWLY RECEIVED CONTACTS BASED ON RANKS. ALONG WITH CONTACT NUMBER RANKS ARE STORED IN ONE FILE.
QUICK SORT : TO SORT CONTACT NUMBERS AFTER READING FROM FILE
MERGE SORT : TO FIRST NOTE THE NUMBER OF MESSAGES FROM EACH CONTACT OR GROUP AND THEN SORT THEM IN DESCENDING ORDER.
             THE CONTACT OR GROUP WITH THE MOST NUMBER OF MESSAGES IS DISPLAYED FIRST.
KRUSKAL'S AND DIJKSTRA : IN LIVE LOCATION FOR SINGLE USER SINGLE FRIEND \ SINGLE USER MANY FRIEND
************************************************************************************************************************************************************/


//HEADER FILE DECLARATION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

//GLOBAL DECLARATION

char bl[20],hc[15];
long long int nm;
int nb,j=0;
long long int phno;

//CREATING STRUCTURE FOR CONTACT SEARCHING
struct contact
{
    char name[20];
    long long int num;

};

//TYPEDEFING NAME FOR STRUCT CONTACT
typedef struct contact CT;

//GLOBAL DECLARATION FOR CONTACT
CT cont[10];
CT group[10];
CT hidec[10];
CT status1[10];
CT arch[10];

//CREATING STRUCTURE FOR WHATSAPP GAMES
struct game
{
    char quest[150];
    char ans[15];
};

typedef struct game GM;
//TYPEDEFING NAME FOR STRUCT GAME

//GLOBAL DECLARATION FOR GAMES
GM R[10];
GM D[10];
GM B[10];

//CREATING STRUCTURE FOR PAYMENT SORT
struct payment
{
    long long int num;
    int money;
};

//TYPEDEFING NAME FOR STRUCT PAYMENT
typedef struct payment PT;

//GLOBAL DECLARATION FOR PAYMENT
PT paymt[10];
PT temp;
PT temp1;

//CREATING STRUCTURE FOR WHATSAPP CONTACT LIST
struct contact_whatsapp
{
    char name[20];
    long long int num;
    struct contact_whatsapp *next;
};

//TYPEDEFING NAME FOR STRUCT LIST OF WHATSAPP CONTACT
typedef struct contact_whatsapp *NODE;

//CREATING STRUCTURE FOR MERGE SORT
struct merge_sort
{
    int num_chats;
    char name[20];
};
typedef struct merge_sort MS;
MS arr[5];

//CREATING STRUCTURE FOR MESSAGES
struct messages
{
    char date[20];
    char time[10];
    char cname[15];
    char text[50];
};

//TYPEDEFING NAME FOR STRUCT MESSAGE
typedef struct messages MG;

//GLOBAL DECLARATION FOR MESSAGES
MG msg[40];

//CREATING STRUCTURE FOR BINARY SEARCH TREE
struct tree
{
    char name[20];
    char num[12];
    struct tree *left;
    struct tree *right;
};

//TYPEDEFING NAME FOR STRUCT TREE
typedef struct tree TREE;

//CREATING STRUCTURE FOR HEAP SORT
struct heap
{
    long long int number;
    int rank;
};

//TYPEDEF FOR STRUCTURE HEAP
typedef struct heap hp;

//GLOBAL DECLARATION FOR HEAP
hp r[20];
hp tempa;


//Function:     getnode
//Description:  Creates a new node with dynamic memory allocation
//Input param:  NULL
//Return Type:  NODE

NODE getnode()
 {
     NODE newn;
     newn=(NODE)malloc(sizeof(struct contact_whatsapp));
     //CREATING NEW NODE

     if(newn==NULL)
     {
         printf("NOT CREATED NODE\n");
         exit(0);
     }

     //MAKING NEXT NODE VALUE IN NEWN AS NULL
     newn->next=NULL;
     return newn;

 }

//Function:     read_details
//Description:  new node structure members are assigned with the data
//Input param:  NULL
//Return Type:  NODE

 NODE read_details()
 {

     NODE temp=getnode();
     //GETTING NEW NODE ADDRESS INTO TEMP

     strcpy(temp->name,bl);
     //COPYING NAME

     temp->num=nm;

     return temp;
 }

 //Function:     insert_end
//Description:  The new created node is inserted at the end of the list
//Input param:  NODE
//Return Type:  NODE

 NODE insert_end(NODE head)
 {
     //VARIABLES DECLARING

     NODE cur=NULL;
     NODE newn=read_details();
     if(head==NULL)
     {
         head=newn;
         //ASSIGNING NEW NODE BY NEW NAME AS HEAD OF ALL FOLLOWING NODES
     }

     else
     {
         cur=head;
         while(cur->next!=NULL)
         {
             cur=cur->next;
             //TRAVELLING TILL LAST NODE
         }

        //LINKING NEW NODE TO LAST NODE
         cur->next=newn;
     }

     //RETURNING ADDRESS OF STARTING NODE
     return head;

 }

//Function:     delete_contact
//Description:  deletes the node in the list which has the incoming contact name
//Input param:  NODE,char a[20]
//Return Type:  NODE (head of the linked list)

 NODE delete_contact(NODE head,char a[20])
 {

    //VARIABLES DECLARATION
    NODE cur=head;
    NODE back=NULL;

    //COMPARING CONTACT NAMES OF HEAD NODE AND DELETE IF IT MATCHES
     if(strcmp(cur->name,a)==0 && cur==head)
     {
         //COPIES THE DETAILS OF NAME AND NUMBER INTO GLOBAL VARIABLES SO THAT THEY CAN BE PUT INTO BLOCKED LIST.
         strcpy(hc,cur->name);
         phno=cur->num;

         //DELETES HEAD NODE AND ASSIGNS THE NEXT NODE AS HEAD
         head=cur->next;
         free(cur);
     }

     //COMPARING CONTACT NAMES OF ALL OTHER NODES WITH INPUT NAME
    while(cur!=NULL)
    {
        if(strcmp(cur->name,a)==0 && cur!=head)
        {
            //COPIES THE DETAILS OF NAME AND NUMBER INTO GLOBAL VARIABLES SO THAT THEY CAN BE PUT INTO BLOCKED LIST.
            strcpy(hc,cur->name);
            phno=cur->num;

            //DELETING THE CUR NODE
            back->next=cur->next;
            free(cur);
            break;
        }

        back=cur;
        cur=cur->next;

    }

    return head;
 }

//Function:     display
//Description:  displays the content present in list
//Input param:  head NODE
//Return Type:  NODE (head of the linked list)

 NODE display(NODE head)
 {
     //VARIBLE OF NODES DECLARING

     NODE cur=head;

     while(cur!=NULL)
     {
         printf("%s %lld\n",cur->name,cur->num);
         cur=cur->next;
     }

     return (head);
 }

//CREATING STRUCTURE FOR TALKED TO
struct talked_to
{
    char name_con[20];
};

//TYPEDEF FOR STRUCTURE TALKED TO
typedef struct talked_to TK;

//GLOBAL DECLARATION FOR TALKED TO
TK spoken[50];

struct vertice
{
    int u,v,w;
};
struct vertice va[4];


//FUNCTION DECLARATION SECTION :

//-----------------****************************------------------//
int error();
//FUNCTION DEFINITION OF ERROR FOR UNSUCCESSFUL STATUS

void contact();
//FUNCTION DEFINITION OF CONTACT TO CREATE LIST USING
//WHATSAPP NUMBER

void start(NODE);
//FUNCTION DEFINITION FOR CREATING NODE AND STARTING OF FUNCTIONS

void make_a_call();
//FUNCTION DEFINITION FOR MAKING A CALL

void send_message();
//FUNCTION DEFINITION FOR SENDING MESSAGE

void block_unblock(NODE);
//FUNCTION DEFINITION FOR BLOCK AND UNBLOCK

void location_sharing();
//FUNCTION DEFINITION OF OCATION SHARING SUCH THAT RECEIVERS CAN FIND LOCATION

void make_a_payment();
//FUNCTION DEFINITION OF MAKING A PAYMENT

void sort_contact();
//FUNCTION DEFINITION FOR SORTING A LIST

void quicksort(long long int a[],int, int );
//FUNCTION DEFINITION FOR SORTING USING QUICK SORT ALGORITHM

void linked_devices();
//FUNCTION DEFINITION TO USE WHATSAPP ON ANY DEVICE

void contact_search(int);
//FUNCTION DEFINITION FOR CONTACT SEARCH
//EITHER BY FULL NAME OR BY SUBSTRING OF THE CONTACT NAME

void search_message(int);
//FUNCTION DEFINITION FOR SEARCHING A MESSAGE
//EITHER BY COMPLETE TEXT OR BY SUBSTRING OF THE TEXT

void group_create();
//FUNCTION DEFINITION TO CREATE GROUPS BY SEARCHING
//IN THE CONTACT LIST

void status();
//FUNCTION DEFINITION OF STATUS

void hidecontact();
//FUNCTION DEFINITION OF HIDING CONTACT

void payment_sort();
//FUNCTION DEFINITION FOR PAYMENT SORTING

void settings();
//FUNCTION DEFINITION OF SETTINGS

void friends_location_connecting();
//FUNCTION DEFINITION OF CONNECTING EVERY FRIENDS LOCATION

void archive(NODE head);
//FUNCTION DEFINITION OF ARCHIVING A CONTACT

void Wapi();
//FUNCTION DEFINITION OF WAPI->WHATSAPP ASSISTANT

void texted_contact(NODE head);
//FUNCTION DEFINITION FOR DISPLAYING THE NAMES OF PEOPLE IN YOUR CHAT LIST AND ALSO THOSE
// PRESENT IN CONTACTS BUT NOT IN CHAT LIST

void find_chats();
//FUNCTION DEFINITION FOR DISPLAYING ALL THE CHATS OF A PARTICULAR CONTACT OR GROUP

void whatsapp_games();
//FUNCTION DEFINITION FOR PLAYING FEW BRAIN STORM GAMES IN NEW VERSION OF WHATSAPP

void maze();
//FUNCTION DEFINITION FOR MAZE GAME

void sudoko();
//FUNCTION DEFINITION FOR SUDOKO GAME

void contact_name_bst();
//FUNCTION DEFINITION FOR CONTACT NAME SORTING USING BST (INSERTION AND INORDER TRAVERSAL)

void heapify(hp r[], int , int );
//FUNCTION DEFINITION FOR HEAPIFYING

void heapSort(hp a[], int );
//FUNCTION DEFINITION FOR COMPARING AND SORTING

void printArr(hp a[], int );
//FUNCTION DEFINITION FOR PRINTING TREE BEFORE AND AFTER HEAPIFICATION

void heap_sorting_array();
//FUNCTION DEFINITION FOR OPENING FILE AND CALLING ALL OTHER FUNCTIONS FOR HEAPIFICATION

void top_chats();
//FUNCTION DEFINITION FOR FINDING THE TOP CHATS (BASED ON THE HIGHER NUMBER OF TEXT MESSAGES) IN DECREASING ORDER

//Function:     hash
//Description:  calculates hash value
//Input param:  string poiter
//Return Type:  int

//STANDARD HASHING FUNCTION
int hash(char *str)
{
    int sum=0;
    if(str==NULL)
        return -1;
    for( ;*str;*str++)
    {
        sum=sum + *str;
    }
    return(sum);
}

//Function:     lock opened
//Description:  check the locking value returned by hash value
//Input param:  NULL
//Return Type:  INT

 int lock_opened()
 {

     char str[20];
     printf("\tENTER YOUR PASSWORD\n");
     scanf("%s",str);
     int value=hash(str);
     if(value == 477)
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }



int main()
{

    printf("\n ");
    printf("\n\t  ******************************************************************************************\n");
    printf("\t\t**********************************************************************************************\n");
    printf("\n\t |         |          | |      |      |     =========  | | | |      |      | | | |  | | | |");
    printf("\n\t  |       | |        |  |      |     |  |       |       |          | |     |     |  |     |");
    printf("\n\t   |     |   |      |   |      |    |    |      |        |        |   |    | | | |  | | | |");
    printf("\n\t    |   |     |    |    |======|   |======|     |         |      |=====|   |        |      ");
    printf("\n\t     | |       |  |     |      |  |        |    |           |   |       |  |        |      ");
    printf("\n\t      |         |       |      | |          |   |     | | | |  |         | |        |      ");
    printf("\n\t  ******************************************************************************************\n");
    printf("\t\t**********************************************************************************************\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\tMost of 'whatsapp' functions are implemented using basic knowledge of linkedlist files, logs and other arithmetic operators, we also tried to add modified functions which users are willing to see in new version of \t   whatsapp\n");
    printf("                ________                                                                                                \n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


    //CHECKING LOCKING STATUS
    int check = lock_opened();
    if(check==1)
{

    //INTIALISING HEAD NODE
    NODE head=NULL;

    //OPENING FILE
    FILE *fp3;
    fp3=fopen("Contacts.txt","r");

    if(fp3==NULL)
    {
        //UNSUCCESSFULL STATUS
        printf("FILE NOT OPENED\n");
        int e=error();
        printf("%d",e);
    }

    while(!feof(fp3))
    {
        fscanf(fp3,"%s %lld\n",bl,&nm);
        head=insert_end(head);
        //j++;
    }

    //CLOSING FILE OF CONTACT
    fclose(fp3);

    start(head);

    return(0);
}
else
{
    printf("\tINVALID PASSWORD\n");
    printf("MAKE SURE YOU REMEBER YOUR PASSWORD\n");

    printf("OR ELSE YOU CAN ALWAYS CHANGE IT UNDER LOCK_OPENED FUCTION\n");
    exit(0);
}

}
//Function:     start
//Description:  it is called for start of whatsapp function
//              all other functions are called from this function
//Input param:  NULL
//Return Type:  head (linked list)
//              error status on unsuccessful opening of file
//              with valid printf statement

void start(NODE head)
{

    //VARIABLE DECLARATION
    int ch=0;
    FILE *fp=0,*f=0;

    //CREATING FILES WITH WRITE MODE
    fp = fopen("wlog.txt","w");
    f = fopen("payment.txt","w");

    if(fp==NULL)
    {
        //ERROR OCCURRED DURING OPENING A FILE FOR LOG
        printf("Error occurred during opening a file\n");
        exit(0);
    }
    fclose(fp);
    //CLOSING OF FILE

    if(f==NULL)
    {
        //ERROR OCCURRED DURING OPENING A FILE FOR PAYMENT
        printf("Error occurred during opening a file\n");
        exit(0);
    }
    fclose(f);
    //CLOSING OF FILE

    while(1)
    {

        //DISPLAYING ALL OPTIONS CREATED AS WHATSAPP FUNTION
        printf("\nWHATSAPP LOADING ........................................................................................\nCLICK ANY ONE OPTION :)\n");
        printf("\n\n");
        printf("\tEnter CHOICE to implement the function derived from whatsapp\n");
        printf("\t                 DOING MANUALLY                   \n");
        //OPTION : 01
        printf("\t1 ---->->->> ADD NEW CONTACT\n");

        //OPTION : 02
        printf("\t2 ---->->->> MAKE A CALL\n");

        //OPTION : 03
        printf("\t3 ---->->->> SEND MESSAGE\n");

        //OPTION : 04
        printf("\t4 ---->->->> LOCATION SHARING\n");

        //OPTION : 05
        printf("\t5 ---->->->> MAKE A PAYMENT\n");

        //OPTION : 06
        printf("\t6 ---->->->> BLOCK OR UNBLOCK A WHATSAPP NUMBER\n");

        //OPTION : 07
        printf("\t7 ---->->->> TO GET SORTED CONTACT LIST BASED ON WHATSAPP NUMBER\n\t--->>make sure to create contact list first or else dirty value will be read<<---\n");

        //OPTION : 08
        printf("\t8 ---->->->> LINKED DEVICES\n");

        //OPTION : 09
        printf("\t9 ---->->->> SEARCHING FOR WHATSAPP CONTACTS\n");

        //OPTION : 10
        printf("\t10 --->->->> SEARCHING FOR TEXT MESSAGES IN WHATSAPP\n");

        //OPTION : 11
        printf("\t11 --->->->> CREATING GROUP IN WHATSAPP\n");

        //OPTION : 12
        printf("\t12 --->->->> STATUS\n");

        //OPTION : 13
        printf("\t13 --->->->> SETTINGS\n");

        //OPTION : 14
        printf("\t14 --->->->> ARCHIVE CONTACTS\n");

        //OPTION : 15
        printf("\t15 --->->->> FIND THE SHORTEST PATH TO CREATE A BRIDGE BETWEEN ALL YOUR FRIENDS IN WHATSAPP\n");

        //OPTION : 16
        printf("\t16 --->->->> FIND THE CONTACTS PRESENT IN YOUR CONTACT LIST WITH WHOM YOU HAVE SPOKEN AT LEAST ONCE\n\t\t\t OR NOT SPOKEN AT ALL\n");

        //OPTION : 17
        printf("\t17 --->->->> FIND CHATS OF A PARTICULAR GROUP OR A CONTACT\n");

        //OPTION : 18
        printf("\tIF NEW VERSION OF WHATSAPP HAS FEW GAMES TO REFRESH WITH YOUR CONTACT FRIENDS\n");
        printf("\tTHEN WHY NOT TO TRY? :> COME LET'S PLAY\n");
        printf("\t18 --->->->> WHATSAPP GAMES!\n");

        //OPTION : 19
        printf("\t19 --->->->> SORTING CONTACTS BASED ON CONTACT NAMES\n");
        //DISPLAYING NEW FUNCTAIONALITY OF WHATSAPP ASSISITANT

        //DISPLAYING THE PATH WHERE WAPI CAN BE FOUND IN PHONE
        printf("\t20 --->->->> NEWLY MESSAGE WILL BE DISPLAYED FIRST\n\tSORTING RANK OF CONTACT NUMBERS USING HEAP SORTING TECHNIQUE\n");
        //RANK IS GIVEN TO MENTION RECENT MESSAGES RECEIVED BY ANY CONTACT NUMBER

        //OPTION : 21
        printf("\t21 --->->->> THE TOP CHATS WITH WHOM YOU HAVE THE MOST MESSAGES ARE DISPLAYED IN DESCREASING ORDER\n");

        //OPTION : 22
        printf("\n\tCALL WHATSAPP ASSISTANT   (new feature in updated version of whatsapp)\n");
        printf("\tPATH WAY :> SETTINGS -> ASSISTANT\n");
        printf("\t22 --->->->> WHATSAPP ASSISTANT --->>>> 'WAPI'\n");
        //WAPI IS NAME GIVEN TO WHATSAPP ASSISTANT SAME AS SIRI/ALEXA

        //OPTION : 23
        printf("\t23 --->->->> EXIT FROM WHATSAPP FUNCTION\n");
        //EXIT

        //INPUT CHOICE SELECTED FROM ABOVE OPTIONS
        scanf("%d",&ch);


        switch(ch)
        {

            //cases
           case 1 : contact();
                    //WHATSAPP CONTACT ONLY

                    break;

           case 2 : make_a_call();
                    //WHATSAPP CALL ONLY

                    break;

           case 3 : send_message();
                    //CAN SHARE FROM ANY APPS, LINK WILL BE REDIRECTED TO WHATSAPP

                    break;

           case 4 : location_sharing();
                    //START LOCATION SHARING BY BOTH USER AND RECEIVER, THEN CAN FIND SHORTEST PATH TO REACH THE PERSON TO WHOM USER WANTS TO MEET

                    break;

           case 5 : make_a_payment();
                    //NEED TO LINK BANK ACCOUNT FIRST, USING BPI PAYMENTS CAN BE DONE

                    break;

           case 6 : block_unblock(head);
                    //NEED TO CREATE CONTACT LIST FIRST

                    break;

            case 7 : sort_contact();
                    //CONTACT LIST MUST BE CREATED FIRST

                     break;

            case 8 : linked_devices();
                     //WHATSAPP URL SHOULD BE TYPED IN DEVICE WHERE YOU WANT TO OPEN WHATSAPP

                     break;

            case 9 : printf("\n\t--->>>>>---If you want to search for a particular single contact press 1---<<<<<---\n");
                     printf("\t-->>--If you want to search for contacts with similar names(substrings) press 2--<<--\n");
                     int a=0;
                     scanf("%d",&a);

                    if(a==1)
                    {
                       contact_search(a);
                       printf("%d",1);
                    }
                    else if(a==2)
                    {
                        contact_search(a);
                    }
                    else
                    {
                        printf("\n\t\t!!!! PLEASE ENTER A VALID CHOICE !!!!\n\n");
                    }

                    break;

            case 10 : printf("\n\t-->>>--If you want to search for a particular single message press 1--<<<--\n");
                      printf("\t-->>--If you want to search for messages with a particular substring press 2--<<--\n");
                      int b=0;
                      scanf("%d",&b);

                      if(b==1)
                      {
                          search_message(b);
                      }
                      else if(b==2)
                      {
                          search_message(b);
                      }

                      break;

            case 11 : group_create();
                      //YOU SHOULD CONTENT CONTACTS IN YOUR WHATSAPP

                      break;

            case 12 : status();
                      //SENDS YOUR STATUS TO ALL YOUR CONTACTS

                      break;

            case 13 : settings();
                      //CAN MAKE CHANGES IN YOUR WHATSAPP SETTINGS

                      break;

            case 14 : archive(head);
                      //CAN ARCHIVE YOUR CONTACTS

                      break;

            case 15: friends_location_connecting();
                      //CAN MAKE USE OF SPANNING TREE TO CONNECT ALL YOUR FRIENDS, ONCE THEY START SHARING THIER LIVE LOCATION

                      break;

            case 16 : texted_contact(head);
                      //CAN TEXT TO A CONTACT

                      break;

            case 17 : find_chats();
                      //FINDING CHATS OF PARTICULAR

                      break;

            case 18 : whatsapp_games();
                      //PLAYING GAMES IN NEW VERSION

                      break;

            case 19 : contact_name_bst();
                      //SORTING CONTACTS BASED ON BST

                      break;

            case 20 : heap_sorting_array();

                      //SORTING CONTACT NUMBER BASED ON RANK
                      //RANK IS GIVEN TO MENTION RECENT MESSAGES RECEIVED BY ANY CONTACT NUMBER
                      //EX : 2 RANK IF CONTACT NUMBER SENT ANY MESSAGE BEFORE NEW NUMBER, THIS NUMBER WILL HAVE 1 AS IT'S RANK.
                      //THEN SORTED RANK WILL DISPLAY PHONE NUMBERS BASED ON LAST COME FIRST POSITION

                      break;

            case 21 : top_chats();
                      //THE NUMBER OF MESSAGES OF EACH CONTACT OR GROUP IS FOUND AND THEN THE CONTACTS ARE SORTED IN
                      //DESCENDING ORDER BASED ON THIS NUMBER USING MERGE SORT.
                      break;

            case 22 : Wapi();

                      //NEW FUNCTION CAN BE INTRODUCED IN NEW VWERSION OF WHATSAPP
                      //THIS WILL BE WHATSAPP ASSISTANT

                      break;

            case 23 : exit(0);
                      //EXITING FROM ALL WHATSAPP FUNCTIONS

        }

    }

}


//Function:     error
//Description:  it is called when error is occurred during file opening
//Input param:  NULL
//Return Type:  INT
//              error status on unsuccessful opening of file
//              with valid printf statement


int error()
{
    printf("UNSUCCESSFULL OPERATION\n");
    //FOR SHOWING ERROR -1 IS RETURNED
    return(-1);
}


//Function:     done
//Description:  it is called when successfully operation is done
//Input param:  NULL
//Return Type:  INT
//              success status on successful operation
//              with valid printf statement


int done()
{
    printf("SUCCESSFULL OPERATION\n");
    //FOR SUCCESSFUL +1 IS RETURNED
    return(1);
}


//Function:     adding a new contact
//Description:  Asks user to enter respective name and phone numbers
//              loads the status of contact into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void contact()
{

    //VARIABLE DECLARATION
    long long int number = 0;
    int i=0,contactlist=0 ;
    char name[50];

    char function_name[20]="contact";
    char status[10] = "success";
    char message[20] = "created";
    FILE *fpr=0;


    //FILE OPENING IN APPEND MODE FOR WRITING IN LOG FILE

    fpr=fopen("wlog.txt","a");
    if(fpr==NULL)
    {
        //UNSUCCESSSFUL STATUS
         printf("FILE NOT OPENEND IN LOG\n");
         int e;
         e = error();
         printf("\tSTATUS : %d\n",e);
         exit(0);
    }


    printf("\t****ADD NEW CONTACT ****\n");
    printf("How many contacts you want to add?\n");
    scanf("%d",&contactlist);

    FILE *fp=0;

    //FILE OPENING IN APPEND MODE FOR STORING CONTACTS

    fp=fopen("Contacts.txt","a");
    if(fp==NULL)
    {
        //UNSUCCESSSFUL STATUS
        printf("FILE NOT OPENEND TO CREATE LIST\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);
    }

    //WRITING INTO CONTACT FILE

    for(i = 0;i < contactlist;i++)
    {

        printf("Add contact name for %d contact\n",(i+1));
        scanf("%s",name);

        printf("Add contact number for %d contact\n",(i+1));
        scanf("%lld",&number);

        fprintf(fp,"%s %lld\n",name,number);
    }

    printf("*****CONTACT LIST SUCCESSFULLY CREATED*****\n");

    //USING CTIME, CURRENT EXECUTION TIME AFTER MAKING A CONTACT IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(fpr, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING ALL FILES

    fclose(fpr);
    fclose(fp);

}


//Function:     makes a call
//Description:  Asks user to enter respective phone numbers
//              loads the status of call into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void make_a_call()
{

    //VARIABLE DECLARATION

    long long int user=0;
    long long int receiver=0;
    int press=0;

    char function_name[20]="make_a_call";
    char status[10] = "success";
    char message[20] = "made_a_call";
    FILE *fp=0;

    //OPEINING LOG FILE
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {
        //UNSUCCESSSFUL STATUS
        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);
    }

    //TAKES INPUT FOR USER NUMBER AND RECEIVER'S NUMBER

    printf("\tKINDLY DIAL USER NUMBER AND(hit enter) RECEIVER'S NUMBER\n");
    scanf("%lld",&user);
    scanf("%lld",&receiver);

    printf("\tPRESS 1 FOR ENGLISH, 2 FOR HINDI\n");
    scanf("%d",&press);
    if(press == 1)
    {
        //CALLER TUNE
        printf("THANKS FOR CALLING, THE PERSON YOU HAVE DIAL WILL RECIEVE YOUR CALL SOON\n");

    }
    else
    {
        //CALLER TUNE
        printf("CALL KARNE KE LIYE DHANYAWAAAD, APNE JIS VYAKTI KO CALL KIYA HAI VO SHIGRA HI APKA CALL UTHAENGE\n\n");

    }
    printf("CALLED from %lld to %lld\n",user,receiver);

    //USING CTIME, CURRENT EXECUTION TIME AFTER MAKING A CALL IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);
    fclose(fp);
}


//Function:     sends a message
//Description:  Asks user to enter respective phone numbers
//              loads the status of sending into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void send_message()
{
    //VARIABLE DECLARATION

    long long int user=0,receiver;
    char str[100];
    int press=0;

    FILE *fpr=NULL;
    char function_name[20]="send_message";
    char status[10] = "success";
    char message[20];
    FILE *fp=0;

    //OPENING LOG FILE
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {

        //UNSUCCESSFUL STATUS

        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);
    }

    //TAKING RECEIVER'S NUMBER

    printf("\tKINDLY WRITE RECEIVER'S CONTACT NUMBER\n");
    scanf("%lld",&receiver);

    printf("\tWHICH TYPE OF MESSAGE YOU WANT TO SEND? :\n");
    printf("\t 1-->-->> TEXT\n");
    printf("\t 2-->-->> PHOTOS\n");
    printf("\t 3-->-->> VOICE\n");
    printf("\t 4-->-->> DOC FILES\n");

    scanf("%d",&press);

    //CHECKING FOR GIVEN TYPE
    if(press == 1)
    {
        int flag=0,x=0,t;

        //OPENING THE FILE OF NEW CHATS WHICH CONTAINS ALL THE CHATS SENT BY THE USER TO CONTACTS
        fpr=fopen("new_chats.txt","a");
        printf("\tWrite text message here : (MAKE SURE TO GIVE ONE WORD IN CAPITAL)\n");
        scanf("%s",str);
        printf("\tYOUR MESSAGE IS SENT TO %lld WITH TEXT MESSAGE  %s\n",receiver,str);

        fprintf(fpr,"%s: %lld\n","CONTACT",receiver);
        fprintf(fpr,"%s:- %s\n","YOU",str);
        //CLOSING OF FILE
        fclose(fpr);

        strcpy(message,"sent_text");
        //FOR WRITING THE MESSAGE TYPE : SENT TEXT INTO LOG FILE
    }
    else if(press == 2)
    {
        fpr=fopen("new_chats.txt","a");
        printf("\tPHOTO IS SENT\n");

        fprintf(fpr,"%s: %lld\n","CONTACT",receiver);
        fprintf(fpr,"%s:- %s\n","YOU","<PHOTO>");

        //CLOSING OF FILE
        fclose(fpr);

        strcpy(message,"sent_photo");
        //FOR WRITING THE MESSAGE TYPE: SENT PHOTO/VIDEO INTO LOG FILE
    }
    else if(press == 3)
    {
        fpr=fopen("new_chats.txt","a");
        printf("\tYOUR VOICE RECORD IS SENT\n");

        fprintf(fpr,"%s: %lld\n","CONTACT",receiver);
        fprintf(fpr,"%s:- %s\n","YOU","<VOICE_MESSAGE>");

        //CLOSING OF FILE
        fclose(fpr);

        strcpy(message,"sent_voice");
        //FOR WRITING THE MESSAGE TYPE : VOICE MESSAGE INTO LOG FILE
    }
    else
    {
        fpr=fopen("new_chats.txt","a");
        printf("\tYOUR DOCUMENT IS SENT\n");

        fprintf(fpr,"%s: %lld\n","CONTACT",receiver);
        fprintf(fpr,"%s:- %s\n","YOU","<DOCUMENT>");

        //CLOSING OF FILE
        fclose(fpr);

        strcpy(message,"sent_document");
        //FOR WRITING THE MESSAGE TYPE : DOCUMENTS INTO LOG FILE
    }

    //USING CTIME, CURRENT EXECUTION TIME AFTER SENDING A MESSAGE IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING ALL FILES
    fclose(fp);
}


//Function:     location sharing
//Description:  Helps user to share their live location to receivers phone number
//              Asks user whether to find shortest path to reach receivers location as well
//              loads the status of sending into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void location_sharing()
{
    //VARIABLE DECLARATION

    int maxtime=0;
    int trace = 0;

    char function_name[20]="location_sharing";
    char status[10] = "success";
    char message[20] = "location_shared";
    FILE *fp=0;

    //OPENING LOG FILE

    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);
    }

    //TAKING MAX TIME YOU WANT TO KEEP LOCATION SHARING ON

    printf("\t-->>START LOCATION SHARING FROM WHATSAPP<<--\n");
    printf("\t****YOUR LIVE LOCATION WILL BE SHARED TO ALL CONTACTS PRESENT IN THAT CHAT WHERE YOU ARE SENDING****\n");
    printf("\tGive maximum time you want to keep location live\n");

    scanf("%d",&maxtime);
    int a=0;

    //VARIABLE FOR STORING SHORTEST DISTANCE

    printf("\tWANT TO START REACH LOCATION?");
    printf("\tFUNCTION EXPLANATIION : TRACE SHORTEST PATH TO REACH RECEIVERS PLACE -->> ENTER 1 TO START\n");
    //USING DIJKSTRA SHORTEST PATH FROM YOUR LOCATION TILL RECEIVER'S LOCATION

    scanf("%d",&trace);
    if(trace == 1)
    {

    //DIJKSTRA TO FIND MINIMUM PATH BETWEEN USER AND RECEIVER SAY USER IS AT 0TH NODE AND RECEIVER AT NODE 3rd

    //VARIABLE DECLARATION
    int dist[25], path[25], visited[25];
    int source=0;

    int max_infinity=999999;
    int array[100][100];

    int i,j,vertex,edge,v1,v2,time,u,query,store,temp,k,m,n;

    //VERTEX AND EDGES AS HOUSES AND ROADS IN LOCATION MAP

    vertex = 4;
    edge = 4;

    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
        {
            if(i==j)
            {
                array[i][j]=0;
            }
            else
            {
                array[i][j]= max_infinity;
            }
        }
    }

    //ASSUMPTION IS CONSIDERED THERE ARE ONLY 4 VERTICES(HOUSE IN A CITY) AND 4 EDGES(ROADS HAVING WEIGHT SAY TAXI CHARGES)

    printf("For 4 vertices and 4 edges\n");
    printf("MAKE SURE TO INCLUDE 1 VERTEX AS 3\n");

    for(i=0;i<edge;i++)
    {
        printf("Give values for (u,v) and time t for edge %d\n",i);
        scanf("%d%d%d",&v1,&v2,&time);
        for(j=0;j<vertex;j++)
        {

            for(temp=0;temp<vertex;temp++)
            {

                if(j==v1 && temp==v2)
                {
                    array[j][temp]=time;
                }
            }
        }
    }


    for(i=0;i<vertex;i++)
    {
        path[i]=0;
        visited[i]=0;
        dist[i]=array[0][i];
    }


    visited[source]=1;
    int min=1000000;

    for(i=0;i<vertex;i++)
    {
        if(visited[i]!=1 && dist[i]<min)
        {
            min=dist[i];
            u=i;
        }
    }
    visited[u]=1;

    for(i=0;i<vertex-2;i++)
    {
        for(m=0;m<vertex;m++)
        {

        if(visited[m]!=1)
        {

            if(dist[u]+array[u][m]<dist[m])
            {

                dist[m]=dist[u]+array[u][m];
                path[m]=u;
            }
        }
        }
    min=100000;

    for(n=0;n<vertex;n++)
    {
        if(visited[n]!=1 && dist[n]<min)
        {
            min=dist[n];
            u=n;
        }
    }
    visited[u]=1;

    }


   query = 1;
   //shortest path from user = 0 and receiver = 3 SO ONLY ONE QUERY
   int ar[query];

    for(i=0;i<query;i++)
    {

        printf("TYPE 3, AS FRIEND IS PRESENT AT NODE 3\n");
        scanf("%d",&ar[i]);

    }

    for(i=0;i<query;i++)
    {
        store = ar[i];
        printf("MINIMUM DISTANCE TO REACH FROM USER = 0TH NODE TO RECEIVER 3RD NODE :\n");

        a = dist[store];

        printf("%d\n",dist[store]);
    }

   }

    //USING CTIME, CURRENT EXECUTION TIME OF LOCATION STATUS IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);

    time_t mytime;
    mytime = time(NULL);
    fprintf(fp, "%s %s %s %s %d\n", ctime(&mytime), function_name, status, message,a);
    //SHORTEST DISTANCE IS ALSO DUMPED INTO LOG FILE

    //CLOSING LOGFILE
    fclose(fp);

}


//Function:     payment_sort
//Description:  Sorts the contact numbers based on the amount sent to them by the user.
//              Displays the contact numbers in the decreasing order of the amount sent to them.
//                Insertion sort is used.
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void payment_sort()
{

    //VARIABLE DECLARATION
    int i,j,v,c,m=0,l=0,y=0,x=0;
    FILE *fp=NULL;

    //OPENING PAYMENT FILE
    //IT SHOULD CONTAIN MINIMUM 2 CONTACTS SO BEFORE SORTING NEED TO PAY

    fp=fopen("payment.txt","r");
    if(fp==NULL)
    {

        printf("\tFILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }
    while(!feof(fp))
    {
        //Reading the contents of the payment file and storing them in an array.
        fscanf(fp,"%lld %d\n",&paymt[l].num,&paymt[l].money);

        //Incrementing l to note the total number of payments done.
        l++;
    }

    //INSERTION SORT
    for(i=1;i<=l-1;i++)
    {

        temp=paymt[i];
        j=i-1;

        while(j>=0 && paymt[j].money<temp.money)
        {
            temp1=paymt[j];

            paymt[j]=paymt[j+1];
            paymt[j+1]=temp1;
            j=j-1;
        }

        paymt[j+1]=temp;
    }

    printf("\tSORTED\n");

    for(i=0;i<l;i++)
    {
        printf("%lld %d\n",paymt[i].num,paymt[i].money);
    }


}


//Function:     makes a payment
//Description:  Asks user to enter receivers phone numbers current amount, as well as amount to send
//              loads the status of sending into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              unsuccessful status on not sufficient balance
//              error status on unsuccessful opening of file


void make_a_payment()
{
    //CONSIDERING BANK ACCOUNT IS LINKED TO WHATSAPP
    long long int receiver = 0;
    int amount = 0,send=0;
    FILE *fp=0,*f=0;

    char function_name[20]="make_a_payment";
    char status[15];
    char message[20] = "unshared";
    time_t mytime;
    mytime = time(NULL);

    //OPENING FILE FOR LOG AND PAYMENT

    fp=fopen("wlog.txt","a");
    f=fopen("payment.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);
    }

    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("FILE NOT OPENEND FOR PAYMENT LOG\n");

        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);
    }

    //TAKING RECEIVER'S NUMBER FOR SENDING PAYMENT

    printf("\tENTER RECEIVER'S NUMBER\n");
    printf("\tMAKE SURE RECEIVER HAS ALSO LINKED BANK ACCOUNT TO THAT WHATSAPP NUMBER\n");
    scanf("%lld",&receiver);

    //CURRENT BANK BALANCE OF USER

    printf("\t*****ENTER CURRENT BANK BALANCE*****\n");
    scanf("%d",&amount);

    //AMOUNT USER WANTS TO SEND

    printf("\t*****ENTER AMOUNT TO BE SEND*****\n");
    scanf("%d",&send);

    if(amount >= send)
    {

        printf("\tAmount is sent to %lld with remaining balance %d\n",receiver,(amount-send));
        strcpy(status,"success");
        strcpy(message,"shared");

        fprintf(f,"%lld %d\n",receiver,send);

        //USING CTIME, CURRENT EXECUTION TIME OF PAYMENT STAUS IS LOADED INTO LOG FILE

        int d;
        d=done();
        printf("\tSTATUS : %d\n",d);
        fprintf(fp, "%s %s %s %s %d\n", ctime(&mytime), function_name, status, message,(amount-send));



        //CLOSING OF FILES
        fclose(fp);
        fclose(f);

    }

    //FOR UNCUCCESSFUL PAYMENT DUE TO INSUFFICIENT BALANCE

    else
    {
    printf("\tCANNOT SEND AS INSUFFICIENT BALANCE\n");

    //UNSUCCESSFUL STATUS

    int e;
    e = error();
    printf("\t%d\n",e);
    strcpy(status,"unsuccessful");

    //USING CTIME, CURRENT EXECUTION TIME OF UNSUCCESSFUL PAYMENT IS LOADED INTO LOG FILE

    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING OF FILES
    fclose(fp);
    fclose(f);


    }

    int ch=0;
    printf("Do you wish to sort your contact numbers based on the amount sent in the decreasing order?\n");
    printf("If yes press 1, If no press 2\n");
    scanf("%d",&ch);

    //Choice 1 sorts the contacts based on the money sent to them and displays them.
    if(ch==1)
    {
        payment_sort();
    }


}


//Function:     Sort contact list whatsapp
//Description:  Sort the contact list using quick sort
//              Confirms whether contact list is full or no
//              loads the status of sorted into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


 void sort_contact()
 {

     //VARIABLE DECLARATION

    long long int number=0,a[50];
    int i=0,j;
    char name[50],astring[50];
    int last =0,first=0;
    FILE *fpr=0,*fp=0;

    //OPENING A CONTACT FILE
    fpr=fopen("Contacts.txt","r");
    if(fpr==NULL)
    {

        printf("FILE NOT OPENEND TO CONTACT LIST\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);

    }


    char function_name[20]="sort_contact";
    char status[10]="success";
    char message[20]="sorted";

    i=0;
    while(!feof(fpr))
    {
        fscanf(fpr,"%s %lld\n", name, &number);

        a[i]=number;
        i++;
    }


    printf("Already existing contact list(ONLY CONTACT NUMBERS) : \n");
    printf("\n");
    for(j=0;j<i;j++)
    {
        printf("%lld\n",a[j]);
        last = a[j];
    }


    //QUICK SORT FUNCTION
    quicksort(a,0,(i-1));


    //CLOSING OF CONTACTS FILE
    fclose(fpr);


    printf("The Sorted Order is (AFTER QUICK SORT): ");
    printf("\n");

    for(j=0;j<i;j++)
    {
        printf("%lld\n",a[j]);
        last = a[j];
    }



    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);

    time_t mytime;
    mytime = time(NULL);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(fp);


 }


//Function:     Quick sort
//Description:  Sort the contact list using contact number
//Input param:  NULL
//Return Type:  NULL


void quicksort(long long int number[50],int first,int last)
{
    //VARIABLE DECLARATION
    int i, j, pivot, temp;

    if(first<last)
    {

       pivot=first;
       i=first;
       j=last;

       while(i<j)
        {

            //COMAPRING VALUES
            while(number[i]<=number[pivot]&&i<last)
              i++;


            while(number[j]>number[pivot])
              j--;

             if(i<j)
             {

               temp=number[i];
               number[i]=number[j];
               number[j]=temp;

             }

        }


        temp=number[pivot];
        number[pivot]=number[j];

        number[j]=temp;

        //CALLING QUICK SORT FOR FIRST HALF
        quicksort(number,first,j-1);

        //CALLING QUICK SORT FOR SECOND HALF
        quicksort(number,j+1,last);


    }

}


//Function:     linked devices
//Condition:    NULL
//Description:  Scan the QR code
//              loads the status of sending into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void linked_devices()
{

    //VARIABLE DECLARATION
    char function_name[20]="linked_devices";
    char status[10]="success";
    char message[20]="linked";
    FILE *fp=0;

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("FILE NOT OPENEND\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);

    }

    //TYPE WHATSAPP URL INTO DEVICE OTHER THAN MOBILE
    printf("\tKindly open whatsapp url on other device\n");

    //GIVING EXAMPLE OF QR CODE
    printf("\t----->>>--->>SCAN THE QR CODE SHOWN BELOW <<---<<<-----\n");


    printf("\n\t     ____   ____ ");
    printf("\n\t    |****| |****|");
    printf("\n\t    |****| |****|");
    printf("\n\t    |____| |____|\n\n");


    printf("*****LINKING A DEVICE******\n");
    printf("\tWHATSAPP MESSAGES DOWNLOADING.................. (1%---45%----60%--->>100)% \n\n");
    printf("\t_______DEVICES ARE NOW LINKED_______\n");


    time_t mytime;
    mytime = time(NULL);
    printf("\tMESSAGE ON PHONE : YOU LOGGED IN TO WHATSAPP ON WINDOWS AT %s\n",ctime(&mytime));

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL LINKING DEVICE IS LOADED INTO LOG FILE
    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //OPENING OF LOG FILE
    fclose(fp);


}


//Function:     contacts_search
//Description:  Searches and displays the contact names based on the input given
//              Choice 1 searches the contacts based on full name.
//              Choice 2 searches the contacts based on substring given.
//Input param:  int
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void contact_search(int a)
{

    //VARIABLE DECLARATION
    int i=-1,j=0,flag=0;
    char cont_search[15];
    FILE *fp=0,*f=0;


    char function_name[20]="contact_search";
    char status[20]="unsuccessful";
    char message[20]="contact_not_found";
    time_t mytime;
    mytime = time(NULL);

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }
    //OPENING OF CONTACTS FILE
    f=fopen("Contacts.txt","r");


    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tCOULDN'T OPEN THE FILE OF CONTACTS\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }
    int c=0;

    while(!feof(f))
    {
         i++;
         //READING FROM FILE AND STORING THE CONTENTS IN AN ARRAY
         fscanf(f,"%s %lld\n",cont[i].name,&cont[i].num);

         //INCREMENTING c TO FIND THE TOTAL NUMBER OF CONTACTS PRESENT IN THE FILE
         c++;
    }


    //CLOSING OF FILE
    fclose(f);

    //CHOICE 1 MEANS WE WANT TO SEARCH THE PARTICULAT CONTACT NAME BASED ON FULL NAME.
    if(a==1)
    {
        printf("\tEnter the contact name you want to search\n");
        scanf("%s",cont_search);
        //LOOP RUNS FROM i to c(the total number of contacts);
        for(i=0;i<c;i++)
         {
             //CHECKS IF THE USER GIVEN INPUT NAME IS EQUAL TO ANY OF THE FILE READ CONTACT NAMES
            if(strcmp(cont_search,cont[i].name)==0)
            {
                //UPDATING FLAG AS 1 TO NOTE THAT THE CONTACT IS FOUND
                flag=1;
                printf("\n\t\tCONTACT FOUND:-\t%s\tNUMBER:-%lld\n",cont[i].name,cont[i].num);


                strcpy(status,"successful");
                strcpy(message,"contact_found");
                int d=done();
                printf("\t\tSTATUS: %d\n\n",d);


                time_t mytime;
                fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);
                //CLOSING
                fclose(fp);
                break;

            }
        }
        //IF THE CONTACT IS NOT FOUND, FLAG REMAINS 0 AND THE FOLLOWING PART EXECUTES
            if(flag==0)
        {
            mytime = time(NULL);
            fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);
            printf("\n\t\tSEARCH UNSUCCESSFUL\n");
            printf("\t\tCONTACT WITH NAME %s NOT FOUND\n\n",cont_search);
        }

            fclose(fp);
    }

    //CHOICE 2 MEANS THAT THE USER HAS OPTED TO SEARCH FOR CONTACT NAMES BASED ON THE SUBSTRINGS
    //'AN' CAN FETCH YOU ANANYA OR AMAN OR SHRAVANI


        if(a==2)
        {
            //VARIABLE DECLARATION
            int x=0,y=0,m=0,k=0,z=0,n=0,l=0;
            char b[20],cont1[20];

            printf("\t\tEnter the substring of the contact you want to search\n");
            printf("\t\tFor example:- 'AN' can fetch you ANANYA and AUSHA and RIAN\n");


            //TAKE THE INPUT FROM THE USER
            scanf("%s",cont1);

            //FINDING THE STRING LENGTH OF THE PATTERN TO FIND (INPUT STRING)
            y=strlen(cont1);
            printf("\n\t\tCONTACTS MATCHING THE STRING '%s' ARE\n",cont1);


            //LOOP RUNS FOR ALL THE CONTACT NAMES AND FINDS IF THE GIVEN SUBSTRING IS PRESENT IN THEM OR NOT
            for(i=0;i<c;i++)
            {

                //INITIALIZING THE VARIABLES TO 0
                z=0;
                k=0;
                n=0;

                strcpy(b,cont[i].name);

                //FINDING THE STRING LENGTH OF THE PRESENT CONTACT NAME
                x=strlen(b);

                //WHILE LOOP RUNS TILL k IS LESS THAN THE CONTACT NAME LENGTH.
                 while(k<x)
                {

                   //checks for every character of the contact name and given substring.
                    if(b[k]==cont1[z])
                    {
                        //IF THE CHARACTER MATCHES INCREMENT k,z and n by 1
                        //BECAUSE BY DOING SO WE CAN COMPARE THE NEXT CHARACTER OF BOTH SUBSTRING AND CONTACT
                        //'n' represents how many characters are matched until now.
                        k++;
                        z++;
                        n++;
                    }

                    else
                    {

                        //IF THE CHARACTER DOESN'T MATCH INCREMENT ONLY k by 1
                        //'n' will be initialized to 0 as no characters are matched.
                        //z will also become 0 as we have to match the next character of contact name with the starting letter of substring.
                        k++;
                        z=0;
                        n=0;
                    }

                    //n represents number of characters matched and y represents length of substring
                    //If they are equal, that means the present contact contains the substring
                    if(n==y)
                    {

                        flag=1;
                        l++;
                        printf("\t\t");
                        printf("   %s\t%lld\n",b,cont[i].num);


                        //break out of the while loop
                        break;

                    }
                }
            }



          printf("\t->>>>-THERE ARE %d CONTACT NAMES WHICH CONTAIN THE SUBSTRING '%s' IN THEM-<<<<-\n\n",l,cont1);

          //CLOSING FILE
               time_t mytime;
                fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);
                fclose(fp);
       }

}


//Function:     search_message
//Description:  searches the text message in the chat_final list based on the input message.
//              Choice 1 displays only the single message which matches entirely with the input.
//              Choice 2 displays all the messages which contain the input substring.
//Input param:  int
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void search_message(int b)
{

    //VARIABLE DECLARATION

    int i=0,j=0,flag=0,c=0;
    char a[50];
    FILE *fp=0,*f=0;

    char function_name[20]="search_message";
    char status[20]="unsuccessful";
    char message[20]="text_not_found";

    time_t mytime;
    mytime = time(NULL);

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");

        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);
    }

    //OPENING OF FILE CHAT

    f=fopen("chat_final.txt","r");
    if(f==NULL)
    {

        //UNSUCCESSFUL STATUS
        printf("\tCOULDN'T OPEN THE FILE OF CHATS\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    char check[20],date1[20],time1[20],z[10],name1[20],text1[20];


    while(!feof(f))
    {
        //IN THE FILE WE HAVE WRITTEN THE CONTACT OR GROUP NAME FIRST AND THEN THE CHATS OF THE PARTICULAR CONTACT OR GROUP.
         fscanf(f,"%s ",check);

         //CHECKING IF THE LINE READ FROM FILE IS THE 'CONTACT NAME LINE' OR 'TEXT MESSAGE LINE'.
         //'CONTACT NAME LINE' CONTAINS ONLY THE CONTACT NAME OR GROUP NAME AND 'TEXT MESSAGE LINE'CONTAINS THE DATE,TIME,NAME AND TEXT OF CHAT.

         //IF ITS A CONTACT LINE THEN IT CONTAINS ONLY TWO CHARACTERS IN THE LINE AND THEY ARE READ
         if(check[0]=='/' && check[1]=='/')
         {
             //THE CONTACT OR GROUP NAME IS STORED INTO THE SPOKEN ARRAY
             fscanf(f,"%s",spoken[j].name_con);
             j++;
         }
         else
         {
             //READING THE DATE,TIME,NAME AND TEXT MESSAGE AND STORING THEM IN msg array.
             fscanf(f,"%s %s %s %s\n",msg[i].time,z,msg[i].cname,msg[i].text);
             strcpy(msg[i].date,check);
             //i is incremented to find the total messages sent or received in our chats.
             c++;
             i++;
         }
    }


    //CLOSING FILE
    fclose(f);

    //CHOICE 1 REPRESENTS THAT WE WANT TO FIND THE COMPLETE MESSAGES WHICH MATCHED THE COMPLETE INPUT MESSAGE.
    if(b==1)
    {
        int x=0,t=0;
        char c[30];
        printf("\t\t-->>>--PLEASE ENTER THE TEXT MESSAGE YOU WISH TO SEARCH FOR--<<<--\n");
        scanf("%s",a);

        //LOOP RUNS TILL i BECAUSE WE HAVE STORED i MESSAGES IN OUR ARRAY AFTER READING FROM FILE
        for(x=0;x<i;x++)
        {
            //COMPARING THE INPUT MESSAGE TO THE MESSAGE IN ARRAY
            if(strcmp(msg[x].text,a)==0)
            {
                flag=1;
                //flag is assigned the value of 1 to note that the message was found


                //COPYING THE MESSSAGE INTO c
                strcpy(c,msg[x].text);
                t=0;

                printf("\t\t\t-->>--THE MESSAGE IS FOUND:--<<--\n");

            //THE FOLLOWING LOOP REMOVES THE UNDERSCORES AND REPLACES THEM BY SPACES
             while(t<strlen(c))
                {
                    if(c[t]=='_')
                        printf(" ");
                    else
                        printf("%c",c[t]);
                    t++;
                }
            printf("  was sent by %s\n\n",msg[x].cname);
          }


       }
       int d;
        d=done();
        printf("\tSTATUS : %d\n",d);

        fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
        fclose(fp);
    }

    //CHOICE 2 REPRESENTS THAT WE WANT TO FIND ALL THE MESSAGES WHICH CONTAIN THE SUBSTRING.
    if(b==2)
    {
        int x=0,y=0,m=0,k=0,z=0,n=0,l=0,t;
        char b[20],mesg[20];

        printf("\t\t--->>---PLEASE ENTER THE SUBSTRING OF THE TEXT MESSAGE YOU WISH TO SEARCH FOR---<<---\n");
        printf("\tFor example:- 'DSA' can fetch you 'Hey.How was your DSA paper?' and 'Tomorrow we have DSA submission.'\n");
        scanf("%s",mesg);


        //FINDING THE STRING LENGTH OF THE PATTERN( input message)
        y=strlen(mesg);
        printf("\nTEXT MESSAGES MATCHING THE STRING '%s' ARE\n",mesg);
        for(i=0;i<c;i++)
        {
            //INITIALIZING z,k,n=0;
            // n represents the number of characters matched between pattern and text
            z=0;
            k=0;
            n=0;

            //copying the content of text to b and finding the string length
            strcpy(b,msg[i].text);
            x=strlen(b);

            //while loop runs till k is less than the length of the message (text)
            while(k<x)
            {

              //CHECKING IF EACH OF THE CHARACTERS OF TEXT AND PATTERN MATCH
                if(b[k]==mesg[z])
                {

                    //IF THE PRESENT CHARACTER MATCHES INCREMENTING BOTH k ans z by ONE SO AS TO CHECK FOR THE NEXT CHARACTER
                    // n is incremented by 1 to denote the number of characters matching up-to now.
                    k++;
                    z++;
                    n++;

                }

                else
                {

                    //If the character match fails k is incremented by 1 and is checked for match starting by the first character of the pattern.
                    // n again becomes 0 as no character are matched
                    k++;
                    z=0;
                    n=0;

                }

                //If n equals y then the present text message contains the given substring
                if(n==y)
                {

                    printf("\t");
                    t=0;
                    flag=1;
                    l++;

                    //The following while loop displays the message by replacing underscores with spaces
                    while(t<strlen(msg[i].text))
                    {


                    if(msg[i].text[t]=='_')
                        printf(" ");
                    else
                        printf("%c",msg[i].text[t]);
                    t++;

                    }
                    printf("\tSENT BY %s\n",msg[i].cname);
                    break;
                }
             }
          }


          printf("\n\t->>>>-THERE ARE %d TEXT MESSAGES WHICH CONTAIN THE SUBSTRING '%s' IN THEM-<<<<-\n\n",l,mesg);

    }

}


//Function:     group_create
//Description:  creates a group by taking contact names as input from the user
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file


void group_create()
{
    //VARIABLE DECLARATION
    int i=0,j=0,m=0,flag=0,x=0,n=0;
    char a[20];
    FILE *fp=0,*f=0;


    char function_name[20]="search_message";
    char status[20]="unsuccessful";
    char message[20]="text_not_found";
    time_t mytime;
    mytime = time(NULL);

    //OPENING LOG FILE
    f=fopen("wlog.txt","a");

    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    //NEW GROUP CREATION
    printf("\tHEY THERE! LOOKS LIKE YOU ARE TRYING TO CREATE A GROUP. LET ME HELP YOU WITH IT.\n\n");
    printf("\tENTER THE GROUP NAME PLEASE\n");
    scanf("%s",group[i].name);
    i++;


    printf("\tNOW JUST ENTER THE CONTACT NAMES WHOM YOU WANT TO ADD IN THE GROUP AND ENTER 'OK' ONCE IT'S DONE\n");
    //OPENING CONTACT FILE
    fp=fopen("Contacts.txt","r");


    if(fp==NULL)
    {
        //UNSUCESSFUL STATUS
        printf("\tFILE NOT OPENED TO CONTACTS\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    while(!feof(fp))
    {

        fscanf(fp,"%s %lld\n",cont[j].name,&cont[j].num);
        j++;

    }

    //CLOSING CONTACT FILE
    fclose(fp);
    m=1;

    //LOOP RUNS TILL flag is not equal to 1
    //The input contact names to create group are taken until user says 'OK'
    while(flag!=1)
    {


        //taking input contact name from user
        printf("\t\tENTER CONTACT NAME:-\n");
        scanf("%s",a);

        if(strcmp(a,"OK")==0)
        {
            flag=1;
            break;
        }

        else
        {
            x=0;
            for(i=0;i<j;i++)
            {
                //checking if the input contact name is present in the contacts list
                if(strcmp(a,cont[i].name)==0)
                {

                    x=1;
                    //If it is present, then add it into group
                    strcpy(group[m].name,cont[i].name);
                    group[m].num=cont[i].num;
                    m++;

                    break;

                }
            }


            //If the contact is not found in contact list
            if(x==0)
            {
                printf("\tNAME NOT FOUND IN YOUR CONTACT LIST. PLEASE ENTER AGAIN\n");
            }
        }
    }

    printf("\nYOUR GROUP IS READY.DO YOU WISH TO DISPLAY THE CONTACT DETAILS OF MEMBERS OF THE GROUP\n");
    printf("\tIF YES ENTER 1 OR ELSE ENTER 0\n");
    scanf("%d",&n);
    i=0;

    //Choice 1 displays the group details- name and participants
    if(n==1)
    {
        printf("\t\tGROUP NAME:-\t%s\n\n",group[i].name);
        for(i=1;i<m;i++)
        {

            printf("\t\t%s\t%lld\n",group[i].name,group[i].num);

        }
        printf("\t-->>-- There are %d participants in your group --<<--\n",m-1);
    }

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL CREATION OF GROUP IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);

}


//Function:     blocks or unblocks other phone number in whatsapp chat
//Condition:    contact list must be full
//Description:  Asks user to enter respective phone numbers
//              loads the status of sending into log file
//Input param:  head node of list
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file

void block_unblock(NODE head)
{
    //VARIABLE DECLARATION
    NODE head2;
    NODE cur=NULL,cur1=NULL;
    int i=0,n=0,j=0,m,flag=0,x=0,z=0;
    char a[20];

    char function_name[20]="unblock";
    char status[20]="successful";
    char message[20]="blocked";

    time_t mytime;
    mytime = time(NULL);

    FILE *fp=0;
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {
        printf("LOG FILE NOT OPENEND\n");
        int e=error();
        printf("STATUS :-> %d",e);
        exit(0);
    }


    printf("\t-->>--ARE YOU WILLING TO BLOCK A NEW CONTACT? PLEASE PRESS 1--<<--\n");
    printf("\t-->>-ARE YOU WILLING TO UNBLOCK AN ALREADY BLOCKED CONTACT? PLEASE PRESS 2--<<--\n");
    int ch=0;
    scanf("%d",&ch);


    //Choice 1 is to block a new contact
    if(ch==1)
     {
        //Creating another list to store the blocked contacts
        head2=NULL;
        head=display(head);
        printf("CHHOSE THE CONTACTS TO BLOCK FROM THE ABOVE CONTACTS\n");
        printf("\n\tFOLLOW THE STEPS BELOW TO BLOCK A CONTACT\n");
        printf("\tPLEASE ENTER HOW MANY CONTACTS YOU WANT TO BLOCK\n");


        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cur1=head;
            flag=0;

            printf("\tENTER THE CONTACT NAME YOU WISH TO BLOCK\n");
            scanf("%s",a);

            //It traverses the entire list to find if the given contact is present
            //in contacts list or not
            while(cur1!=NULL)
            {

                //If the contact is found update flag as 1 and break out of while loop
                if(strcmp(cur1->name,a)==0)
                {
                    flag=1;
                    break;
                }
                cur1=cur1->next;
            }

        //If the contact is found in contacts list then the following steps execute
        if(flag==1)
        {

            //The user is asked to confirm if he wants to block the contact
            printf("\tBlock %s?",a);
            printf("\tBlocked contacts cannot call or send you messages. This contact will not be notified\n");
            printf("\t\tFor confirmation press 1\n\t\tIf you don't want to block press 2\n\n");
            scanf("%d",&x);

            //If the user confirms to block the contact is blocked
            if(x==1)
            {
                nb++;
                strcpy(bl,cur1->name);

                printf("BLOCKED %s\n",cur1->name);
                nm=cur1->num;

                //The details of the blocked contact is stored in another list of all blocked contacts.
                head2=insert_end(head2);

                //The blocked contact is deleted from the present list as it should contain only

                //unblocked contacts.
                head=delete_contact(head,a);

            }
            else
            {
                printf("\tNOT BLOCKED\n");
            }
        }

        //If the contact is not present then a message is displayed
        if(flag==0)
        {
            printf("\tContact not found\n");
        }


    }

        printf("\n\t\tTHE NOT BLOCKED CONTACTS ARE\n");
        {
            //The not blocked contacts are displayed from the list
        cur=head;i=0;
        while(cur!=NULL)
        {
            printf("%s %lld\n",cur->name,cur->num);
            cur=cur->next;
            i++;
        }


        }

        printf("\t-->>--DO YOU WISH TO LOOK AT THE BLOCKED CONTACTS?--<<--\n");
        printf("\t------->>IF YES PRESS 1, IF NO PRESS 2 TO UNBLOCK<<--------\n");
        scanf("%d",&z);

        if(z==1)
        {
            //Blocked contacts are displayed from the list
            cur=head2;
            printf("\n\t-->>--THE BLOCKED CONTACTS ARE--<<--\n");
            while(cur!=NULL)
            {
                printf("%s %lld\n",cur->name,cur->num);
                cur=cur->next;
            }
            printf("\n");
        }
    }

    strcpy(message,"block");
    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //CHOICE 2 IS TO UNBLOCK AN ALREADY BLOCKED CONTACT
    if(ch==2)
    {
        char ub[20];
        printf("\n\t--->>>---FOLLOW THE STEPS BELOW TO UNBLOCK A CONTACT---<<<---\n");
        printf("\tTHE ALREADY BLOCKED CONTACTS ARE AS FOLLOWS\n");

        //THE CUR POINTER TRAVERSES THROUGH THE BLOCKED LIST AND DISPLAYS THE CONTENTS
        cur1=head2;
            while(cur1!=NULL)
            {
                printf("%s %lld\n",cur1->name,cur1->num);
                cur1=cur1->next;
            }
        printf("\t-->>--ENTER THE CONTACT NAME YOU WISH TO UNBLOCK--<<--\n");
        scanf("%s",ub);

        //THE CUR POINTE TRAVERSES TO THE NODE WHICH CONTAINS THE NAME GIVEN AS INPUT BY THE USER
        cur=head2;
            while(cur!=NULL)
            {
                if(strcmp(cur->name,ub)==0)
                {

                    strcpy(bl,cur->name);
                    printf("-->>--UNBLOCKED %s--<<--\n",cur->name);
                    nm=cur->num;

                    //THE NODE OF THIS CONTACT IS DELETED FROM THE BLOCKED LIST AS IT GETS UNBLOCKED.
                    head2=delete_contact(head2,ub);

                    //A NEW NODE CONTAINING THIS CONTACT DETAILS IS INSERTED IN THE UNBLOCKED LIST
                    head=insert_end(head);

                }

                cur=cur->next;
            }

        //UNBLOCKED CONTACTS ARE DISPLAYED FROM THE LIST

        printf("\n\t--->>-- THE NOT BLOCKED CONTACTS ARE --<<---\n");
        cur=head;
        printf("\n");
        while(cur!=NULL)
            {
                printf("%s %lld\n",cur->name,cur->num);
                cur=cur->next;
            }
            printf("\n");
    }

    //USING CTIME, CURRENT EXECUTION TIME OF BLOCKED IS LOADED INTO LOG FILE

    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


}


//Function:     Keep status of your current mood and share to all friends via whatsapp
//Description:  status forwarding to all contacts if chosen 1
//              can hide few contacts before uploading status otherwise
//              loads the status of status into log file
//Input param:  NULL
//Return Type:  NULL
//              success status on successful operation
//              error status on unsuccessful opening of file



void status()
{
    //VARIABLE DECLARATION

    int hide=0,i=0;
    FILE *fpr=0,*fp=0;
    long long int no;
    char name[30];


    char function_name[20]="status";
    char status[20]="successful";
    char message[20]="status_sent";
    time_t mytime;
    mytime = time(NULL);

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");

    //OPENING OF CONTACTS FILE
    fpr=fopen("Contacts.txt","r");

    if(fpr==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENEND TO CONTACT LIST\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    if(fp==NULL)
    {
        //UNSUCESSFUL STATUS
        printf("\tFILE NOT OPENEND TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    //FOR STATUS UPLOADING
    printf("\t******SELECT PHOTOS FROM GALLERY******\n");
    printf("Want to share your status to all your contacts? press -> 0 <-\nIF Want to hide status from certain contacts?OR PRESS ->1<- to continue status sending message\n");
    scanf("%d",&hide);

    if(hide!=1)
    {

        printf("\tYOUR STATUS IS FORWADED TO ALL YOUR FOLLOWING CONTACTS : \n");
        while(!feof(fpr))
        {

           i++;
           fscanf(fpr,"%s %lld",name,&no);
           printf("%s %lld\n",name,no);

        }

    }

    else
    {
        //FUNCTION CALL TO HIDE FEW CONTACTS

        hidecontact();

    }

    printf("\t----->>> YOUR STATUS IS SENT TO YOUR CONTACTS <<<-----\n");


    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL STATUS UPLOADING IS LOADED INTO LOG FILE
    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);



    //CLOSING OF LOG FILE
    fclose(fp);
    //CLOSING OF CONTACTS FILE
    fclose(fpr);

}

//Function:     acc_hide
//Description:  Changes in account section can be made
//              Confirms whether want to hide particular settings from all or few people
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void acc_hide(char set_name[15])
{
    //VARIABLE DECLARATION
   NODE acc_hide1,cur2;
   FILE *fp=NULL;
   fp=fopen("Contacts.txt","r");
   int i=0,num=0,flag;
   char h_name[15],name[15];
   long long int number;

   //READING FROM FILE AND DISPLAYING ALL THE CONTACTS FROM WHICH YOU CAN CHOOSE
   while(!feof(fp))
   {
       fscanf(fp,"%s %lld\n",name,&number);
       printf("%s\n",name);
   }
   fclose(fp);


   printf("\tPLEASE ENTER FOR HOW MANY CONTACTS YOU WISH TO HIDE YOUR %s AMONG THE ABOVE CONTACTS.\n",set_name);
   scanf("%d",&num);

   for(i=0;i<num;i++)
   {
       printf("PLEASE ENTER THE CONTACT NAME\n");
       scanf("%s",bl);

       //THE INPUT CONTACT NAME IS INSERTED INTO THE acc_hide1 LIST
       acc_hide1=insert_end(acc_hide1);
   }


   //DISPLAYING THE LIST OF ACC_HIDE1 AS IT CONTAINS CONTACTS FOR WHICH SETTING IS HIDDEN.
   printf("\t\tTHE CONTACTS FOR WHICH YOUR %s IS NOT VISIBLE ARE\n",set_name);
   acc_hide1=display(acc_hide1);


   //FOR DISPLAYING THE CONTACTS FOR WHICH IT IS NOT HIDDEN AGAIN READ FROM FILE
   printf("\n\t\tTHE CONTACTS FOR WHICH YOUR %s IS VISIBLE ARE\n",set_name);
   fp=fopen("Contacts.txt","r");
   //READING FROM THE FILE AND COMPARING THEM WITH ALL THE CONTENTS OF THE LIST.


   //IF THE NAME READ FROM FILE IS PRESENT IN THE LIST THEN IT IS NOT DISPLAYED.
   cur2=acc_hide1;


    while(!feof(fp))
    {
        flag=0;
        cur2=acc_hide1;
        fscanf(fp,"%s %lld\n",name,&number);

        //CHECKING IF IT IS PRESENT IN acc_hide LIST
        while(cur2!=NULL)
        {
            if(strcmp(cur2->name,name)==0)
            {
                //IF IT IS PRESENT UPDATE FLAG AS 1 AND COPY THE NUMBER ALSO.
                cur2->num=number;
                flag=1;
            }
            cur2=cur2->next;
        }

        //IF THE CONTACT IS NOT IN acc_hide1 LIST DISPLAY ITS DETAILS UNDER UNHIDDEN.
        if(flag==0)
        {
            printf("%s %lld\n",name,number);
        }
    }
    fclose(fp);

}


//Function:     accounts in whatsapp section
//Description:  Changes in account section can be made
//              Confirms whether want to hide particular settings from all or few people
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void accounts()
{

    //VARIABLE DECLARATION

    char function_name[20]="accounts";
    char status[20]="successful";
    char message[20]="accounts_changed";
    char set_name[15];


    time_t mytime;
    mytime = time(NULL);
    FILE *fp=0;

    //OPENING LOG FILE
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {

        //UNSUCCESSFUL STATUS

        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    int lastseen=0,about=0,profilephoto=0;


    printf("PRIVACY ------->\n");
    printf("press 1 for enable or 0 for disable\n");


    printf("***** LAST SEEN FOR ALL *****\n");
    scanf("%d",&lastseen);

    if(lastseen==0)
    {
        strcpy(set_name,"lastseen");
        acc_hide(set_name);
    }

    else
    {
        printf("\tEVERYONE CAN SEE YOUR LASTSEEN\n");
    }


    printf("\npress 1 for enable or 0 for disable\n");
    printf("***** PROFILE PHOTO FOR ALL *****\n");
    scanf("%d",&profilephoto);


    if(profilephoto == 0)
    {
        strcpy(set_name,"profilephoto");
        acc_hide(set_name);
    }

    else
    {
        printf("\tEVERYONE CAN SEE YOUR PROFILE PHOTO\n");
    }

    printf("\nPress 1 for enable or 0 for disable\n");

    printf("***** ABOUT FOR ALL *****\n");
    scanf("%d",&about);


    if(about == 0)
    {
        strcpy(set_name,"about");
        acc_hide(set_name);
    }

    else
    {
        printf("\tEVERYONE CAN SEE YOUR ABOUT\n");
    }


    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL ACCOUNTS IS LOADED INTO LOG FILE
    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(fp);

}

//Function:     chats in whatsapp settings
//Description:  Changes in chats section can be made
//              Confirms whether want to hide particular settings from all or few people
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void chats()
{

    //VARIABLE DECLARATION

    char function_name[20]="chats";
    char status[20]="successful";
    char message[20]="chats_changed";
    time_t mytime;

    FILE *fp=0;
    mytime = time(NULL);

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    int press=0;
    char theme[10],font[10];

    printf("\t----->>> 1 for THEME\n");
    printf("\t----->>> 2 for WALLPAPER\n");
    printf("\t----->>> 3 for MEDIA VISIBILITY\n");
    printf("\t----->>> 4 for FONT SIZE\n");


    char enable[10]="disable";



        printf("\tCHOOSE THEME\n");
        printf("\tS for SYSTEM DEFAULT\n");
        printf("\tL for LIGHT\n");
        printf("\tD for DARK\n");
        scanf("%s",theme);

        printf("\t------>>>>>> Select photos for wallpaper <<<<<<-------\n");


        printf("\t------>>>>>> Want to show newly downloaded media in your phone's gallery <<<<<<-------\n");
        printf("\tGive input as 'ENABLE' for enabling this option\n");
        scanf("%s",enable);


        printf("\tCHOOSE FONT SIZE\n");
        printf("\tS for SMALL\n");
        printf("\tM for MEDIUM\n");
        printf("\tL for LARGE\n");
        scanf("%s",font);

    printf("\t----->> THEME -->>>>>> %s, WALLPAPER, MEDIA -->>>>>> %s, FONT SIZE -->>>>>> %s, UPDATED FOR YOUR WHATSAPP <<-----\n",theme,enable,font);

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL CHATS IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //CLOSING LOG FILE
    fclose(fp);

}

//Function:     Notification in whatsapp settings
//Description:  Changes in notification section can be made
//              Confirms which type of tone
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void notifications()
{

    //VARIABLE DECLARATION

    char function_name[20]="notifications";
    char status[20]="successful";
    char message[30]="notifications_changed";

    time_t mytime;
    mytime = time(NULL);
    FILE *fp=0;

    //OPENING LOG FILE
    fp=fopen("wlog.txt","a");

    if(fp==NULL)
    {
        //UNSUCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    int enable=0;
    char tone[20];

    printf("\tSet conversation tones on??\n");
    printf("\t--->> Press 1 for enabling OR 0<<---\n");
    scanf("%d",&enable);


    printf("\tEnter tone you want to select(give name) from -->>\n");
    printf("\tNONE\n\tANDES\n\tBIRD\n\tCHILDLIKE\n\tCLOCK\n\tDOBE\n\tDUST\n\tEMERGENCY\n\tMONEY\n");
    scanf("%s",tone);
    if(enable == 1)
    {

        printf("\tConversation Tone is enabled and Notification Tone is set to %s",tone);
        //DISPLAYING TONE
    }

    else
    {

        printf("\tConversation Tone is disabled\n");
        //DISABLED
    }

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL NOTIFICATION IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(fp);

}

//Function:     storage_and_data in whatsapp settings
//Description:  Changes in storage_and_data section can be made
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void storage_and_data()
{

    //VARIABLE DECLARATION

    char function_name[20]="storage_and_data";
    char status[20]="successful";
    char message[30]="storagedata_changed";
    time_t mytime;

    FILE *fp=0;
    mytime = time(NULL);

    //OPENING LOG FILE
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {

        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    int data_calls=0,ch=0;

    printf("\tPress ->>>> 1 <<<<- for enabling USE LESS DATA FOR CALLS\n");
    scanf("%d",&data_calls);

    printf("\tMEDIA AUTO-DOWNLOAD\n");

    printf("\tVoice messages are always automatically downloaded :\nCHOOSE TO CHANGE MEDIA DOWNLOADING WHEN PHONE IS CONNECTED TO :\n");


    printf("\tENTER 1 ->>>> WHEN USING MOBILE DATA\n");
    printf("\tENTER 2 ->>>> WHEN CONNECTED ON Wi-Fi\n");
    printf("\tENTER 3 ->>>> WHEN ROAMING\n");
    scanf("%d",&ch);


    if (ch == 1)
    {

        printf("\tALL MEDIA IS AUTO DOWNLOADED WHILE USING MOBILE DATA\n");
        //MOBILE DATA

    }
    else if (ch == 2)
    {

        printf("\tALL MEDIA IS AUTO DOWNLOADED WHILE CONNECTED ON Wi-Fi \n");
        //WI-FI

    }
    else
    {

        printf("\tALL MEDIA IS AUTO DOWNLOADED WHEN ROAMING\n");
        //ROAMING

    }

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL STORAGE AND DATA IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //CLOSIG OF LOG FILE
    fclose(fp);

}

//Function:     invite a friend in whatsapp settings
//Description:  Changes in invite a friend section can be made
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void invite_a_friend()
{

    //DECLARING VARIABLES

    char function_name[20]="invite_a_friend";
    char status[20]="successful";
    char message[30]="invitefriend_changed";
    FILE *fp=0;

    time_t mytime;
    mytime = time(NULL);

    //OPENING LOG FILE
    fp=fopen("wlog.txt","a");


    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tLOG FILE NOT OPENED\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    char phone_name[30],name[30];
    printf("\tENTER YOUR PHONE NAME ::  \n");
    scanf("%s",phone_name);


    printf("\tChoose (Enter) contact name to whom you want to invite");
    scanf("%s",name);


    printf("\tLet's chat on WhatsApp! It's a fast, simple, and secure app we can use to message and call each other for free. Get it at https://whatsapp.com/dl/%s\n\t\tRegards:%s\n\n",phone_name,name);

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL INVITING A FRIEND IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING OF LOG FILE


    fclose(fp);

}

//Function:     settings in whatsapp
//Description:  Changes in settings section can be made for your whatsapp
//              type of changes want to made is asked before allowing to change anything
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation
//              successful changes or no change made in whatsapp is dumbed into log

void settings()
{

    //VARIABLE DECLARATION

   long long int number;
   char name[20],about[50];
   int click=0;
   char function_name[20]="settings";
   char status[20]="successful";
   char message[20]="settings_done";


   FILE *fp=0;
   time_t mytime;
   mytime = time(NULL);

   //OPENING LOG FILE
   fp=fopen("wlog.txt","a");

   if(fp==NULL)
    {

        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

   printf("\t----->>>>Give your user name<<<<-----\n");
   scanf("%s",name);


   printf("\t----->>>>Give a 'about' in one word to your whatsapp account<<<<----\n");
   scanf("%s",about);


   printf("\t----->>>>Give your phone number whatsapp account<<<<----\n");
   scanf("%lld",&number);


   printf("\n\n<-   PROFILE\n");
   printf("\n      'DirectPicture'      \n");
   printf("\t()  NAME  \n");
   printf("\t          %s\n",name);
   printf("\t(i) ABOUT  \n");
   printf("\t          %s\n",about);
   printf("\t()  Phone \n");
   printf("\t          %lld\n",number);

   printf("\n");
   printf("\n");


   printf("\tCLICK FOLLOWING OPTIONS FOR :\n");

   printf("\t1 ------>>>>>>> ACCOUNTS\n");
   printf("\t2 ------>>>>>>> CHATS\n");
   printf("\t3 ------>>>>>>> NOTIFICATIONS\n");
   printf("\t4 ------>>>>>>> STORAGE AND DATA\n");
   printf("\t5 ------>>>>>>> INVITE A FRIEND\n");
   scanf("%d",&click);

   if(click == 1)
   {

       accounts();
   }
   else if(click == 2)
   {

       chats();
   }
   else if(click == 3)
   {

        notifications();
   }
   else if(click == 4)
   {

       storage_and_data();
   }
   else if(click == 5)
   {

       invite_a_friend();
   }
   else
   {

       printf("\t\tNo settings changed\n");
       strcpy(message,"settings_unchanged");

   }

   //FROM PHONE FROM META, OTHER DEVICE WILL BE BETA

   printf("\t**********************^^^^^^^^^^^^^^^^^^^^      from META       ^^^^^^^^^^^^^^^^^^^^*************************\n");


   //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL SETTINGS CHANGED IS LOADED INTO LOG FILE
   fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


   //CLOSING LOG FILE
   fclose(fp);

}

//Function:     hidecontact
//Description:  hiding some contacts which are taken by user
//              and displaying from file unhided contact
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void hidecontact()
{

    //VARIABLE DECLARATION

    NODE hide=NULL;
    long long int no;
    char name[30];
    FILE *fp=0;
    int i=0,count=0,k=0;

    //OPENING CONTACT FILE

    fp=fopen("Contacts.txt","r");

    if(fp==0)
    {
        //UNSUCCESFUL STATUS
        printf("\tFILE NOT OPENEND TO CONTACT LIST\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    printf("\t---->>> SELECT THE FOLLOWING CONTACTS <<<----\n");

    //READING FROM THE FILE OF CONTACTS
    while(!feof(fp))
    {

         i++;
         fscanf(fp,"%s %lld\n",bl,&nm);
         printf("%s %lld\n",bl,nm);

         //INSERTING THE CONTACTS INTO hide LIST
         hide=insert_end(hide);

    }

    printf("\tHow many accounts you want to hide??\n");
    scanf("%d",&count);


    printf("\tWRITE THE %d CONTACT NAME FROM ABOVE CONTACTS YOU WANT TO HIDE\n",count);
    for(i=0;i<count;i++)
    {

        scanf("%s",name);

        //DELETING THE CONTACT FROM THE LIST AS NOW IT WILL BE HIDDEN
        hide=delete_contact(hide,name);

        //STORING THE HIDDEN CONTACTS IN hidec ARRAY
        strcpy(hidec[j].name,hc);
        hidec[j].num=phno;
        j++;

    }

    printf("\t\tHIDDEN CONTACTS\n\n");

    //DISPLAYING THE HIDDEN CONTACTS
    for(k=0;k<j;k++)
    {
        printf("%s %lld\n",hidec[k].name,hidec[k].num);
    }

    //DISPLAYING THE UNHIDDEN CONTACTS
    printf("\t\tUNHIDDEN CONTACTS\n\n");

    hide=display(hide);
    //FUNCTION CALL FOR DISPLAYING UNHIDDEN CONTACTS


    //CLOSING CONTACT FILE
    fclose(fp);


}
//Function:     archive contacts
//Description:  Hides few contact from display in whatsapp
//Input param:  Node
//Return Type:  NULL
//              valid output on successful operation


void archive(NODE head)
{

    //VARIABLE DECLARATION

    NODE archieve=NULL;
    NODE cur2=NULL;
    FILE *fp = 0,*f=0;
    long long int number;
    char name[30];


    int i=0,count=0,l,a,flag=0;
    char function_name[20]="archive";
    char status[20]="successful";
    char message[20]="archive_done";

    //OPENING CONTACTS FILE

    fp = fopen("Contacts.txt","r");
    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE OF CONTACTS NOT OPENEND\n");
        int e;
        e = error();
        printf("\tSTATUS : %d\n",e);
        exit(0);

    }

    //OPENING LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }

    printf("\tENTER THE CONTACTS YOU WANT TO ARCHIVE FROM FOLLOWING CONTACT LIST\n");

    //DISPLAYS ALL THE CONTACT NAMES AVAILABLE FOR THE USER TO CHOOSE FROM
    head=display(head);

    printf("\t*******ARCHIVE*******\n");


    printf("\t\tHOW MANY CONTACTS DO YOU WISH TO ARCHIEVE?\n");
    scanf("%d",&a);

    printf("\tPLEASE ENTER THE CONTACT NAMES\n");

        for(l=0;l<a;l++)
        {

            scanf("%s",bl);
            //THE CONTACT NAMES WHICH NEED TO BE ARCHIEVED ARE INSERTED INTO ARCHIEVE LIST
            archieve=insert_end(archieve);

        }

        printf("\tARCHIEVED CONTACTS\n");

        //THE ARCHIEVED CONTACTS ARE DISPLAYED
        archieve=display(archieve);

     cur2=archieve;

    // printf("\n check %s\n",cur2->name);
    printf("\n\tNOT ARCHIEVED CONTACTS\n");


    //READING FROM THE FILE AND CHECKING IF THE DATA READ FROM FILE IS ARCHIEVED OR NOT
    //IF IT IS NOT PRESENT IN LIST THEN IT MEANS THAT ISN'T ARCHIEVED AND SO IS DISPLAYED.
    while(!feof(fp))
    {

        flag=0;
        cur2=archieve;
        fscanf(fp,"%s %lld\n",name,&number);

        while(cur2!=NULL)
        {

            if(strcmp(cur2->name,name)==0)
            {

                cur2->num=number;
                flag=1;
            }
            cur2=cur2->next;

        }

        //IF FLAG=0, THE CONTACT IS NOT PRESENT IN ARCHIEVED LIST SO IT IS DISPLAYED.
        if(flag==0)
        {
            printf("%s %lld\n",name,number);
        }

    }


    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL ARCHIVE IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);

    //CLOSING CONTACTS FILE
    fclose(fp);

}

//Function:     find
//Description:  find function called by kruskal's code
//Input param:  integer array and variable
//Return Type:  integer
//              valid output on successful operation


int find(int a[9],int u,int v)
{

    if(a[u] == a[v])
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

//Function:     union
//Description:  union function called by kruskal's code
//Input param:  integer array and variable
//Return Type:  integer
//              valid output on successful operation


int union_(int a[9],int u, int v)
{
    //VARIABLE DECLARATION

    int i;
    int temp_ ;

    temp_ = a[u];
    for(i=0;i<9;i++)
    {
        if(temp_ == a[i])
        {
            //COPYING VALUE FROM V TO I
            a[i]=a[v];
        }
    }

}

//Function:     friend's location
//Description:  friend's location is all connected using kruskal's code, to get minimum distance spanning tree
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation
//              on successful operation status dumped into log file
//              pair of edges is given as output of kruskal's code

void friends_location_connecting()
{

    //VARIABLE DECLARATION

    char function_name[35]="friends_location_connecting";
    char status[20]="successful";
    char message[25]="shortestpath_given";
    FILE *f=0;


    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


   int m[4][4]={{0,1,1,0},{1,0,0,1},{1,1,0,0},{0,1,0,0}}, n=4, i;
   //ONLY FOUR FRIENDS LOCATION IS CONSIDERED STATICALLY

   int a[9];
    int j;
    struct vertice temp[4];
    //STRUCT VARIABLE TEMP IS TAKEN


    printf("Enter vertex u,v and edges w\n");
    printf("GIVE INPUT BASED ON WEIGHT MATRIX\n");
    printf(" m[4][4]={{0,1,1,0},{1,0,0,1},{1,1,0,0},{0,1,0,0}} \n");

    for(i=0;i<n;i++)
    {
        //TAKING INPUT VERTICES (V,U) AND WEIGHT W

        printf("\tFor vertex %d edge to vertex %d\n",(i+1),(i+2));
        scanf("%d%d%d",&va[i].u,&va[i].v,&va[i].w);

    }


    printf("\tEntered value :\n");

    for(i=0;i<n;i++)
    {
        printf("\t%d\t%d\t%d\n",va[i].u,va[i].v,va[i].w);

    }

    n=5;
    //BUBBLE SORT IS USED
    for(i=0;i<n-2;i++)
    {

        for(j=0;j<n-2-i;j++)
        {

            if(va[j].w > va[j+1].w)
            {

                temp[j].w = va[j+1].w;
                va[j+1].w = va[j].w;
                va[j].w = temp[j].w;

            }

        }

    }

    //SORTED VALUES OF DISTANCE IS DISPLAYED
    printf("\tSorted value\n");

    n=4;
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",va[i].u,va[i].v,va[i].w);
    }


    int vt=0,k;

    for(i=0;i<9;i++)
    {
        a[i]=vt;
        vt++;
    }

    printf("\tMinimum weighted root to reach friends location : \n");

    for(i=0;i<n;i++)
    {

        k = find(a,va[i].u,va[i].v);
        if(k==0)
        {
            printf("\t%d %d\t",va[i].u,va[i].v);
            union_(a,va[i].u,va[i].v);
        }

    }


    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL KRUSKAL'S CODE IS LOADED INTO LOG FILE

    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);

}

//Function:     texted_contact
//Description:  Displays the names of contacts with whom we have spoken atleast once and
//              also those contacts with whom we have not spoken once also but are present in our contacts.
//Input param:  head node of list
//Return Type:  NULL
//              valid output on successful operation

void texted_contact(NODE head)
{
    //VARIABLE DECLARATION

    int a=0;
    printf("Do you wish to look at the contacts with whom you have spoken at least once? If yes press --> 1 <--\n");
    printf("Do you wish to look at the contacts with whom you have not spoken at all ? If yes press --> 2 <--\n");
    scanf("%d",&a);


        int i=0,j=0,flag=0,c=0,k;
        char m[10];
        FILE *fp=0,*f=0;


        char function_name[20]="search_message";
        char status[20]="unsuccessful";
        char message[20]="text_not_found";
        time_t mytime;
        mytime = time(NULL);

        //OPENING OF FILE LOG
        fp=fopen("wlog.txt","a");


        if(fp==NULL)
        {
            //UNSUCCESSFUL STATUS

            printf("\tLOG FILE NOT OPENED\n");
            int e;
            e = error();
            printf("\t%d\n",e);
            exit(0);

        }

        //OPENING OF CHAT_FINAL FILE

        f=fopen("chat_final.txt","r");


        if(f==NULL)
        {

            //UNSUCCESSFUL STATUS
            printf("\tCOULDN'T OPEN THE FILE OF CHATS\n");
            int e;
            e = error();
            printf("\t%d\n",e);
            exit(0);


        }

        fclose(fp);

        char check[20],date1[20],time1[20],z[10],name1[20],text1[20];

        //READING FROM CHATS FILE
        while(!feof(f))
        {

           fscanf(f,"%s ",check);

         if(check[0]=='/' && check[1]=='/')
         {

             fscanf(f,"%s",m);

             //COMAPRES IF THE LINE CONTAINS THE CONTACT NAME
             if(strcmp(check,"//CONTACT:-")==0)
             {
                 //IF THE CONTACT NAME IS PRESENT THEN IT IS STORED IN THE SPOKEN ARRAY
                strcpy(spoken[j].name_con,m);
                j++;

             }
         }


         else
         {
             fscanf(f,"%s %s %s %s\n",msg[i].time,z,msg[i].cname,msg[i].text);
             strcpy(msg[i].date,check);

             c++;
             i++;
         }
        }

        //CLOSING OF FILE
        fclose(f);


    //CHOICE 1 REPRESENTS THAT WE HAVE TO DISPLAY CONTACT NAMES WITH WHOM WE HAVE SPOKEN ATLEAST ONCE
    if(a==1)
    {
        for(k=0;k<j;k++)
        {
           printf("%s\n",spoken[k].name_con);
        }
    }


    //CHOICE 2 REPRESENTS THAT WE HAVE TO DISPLAY CONTACT NAMES WITH WHOM WE HAVE NOT SPOKEN ONCE ALSO
    if(a==2)
    {

        NODE cur;
        int k,flag=0;

        printf("\t-->-->> NOT SPOKEN CONTACTS <<--<--\n\n");
        cur=head;

        //WHILE LOOP TRAVERSES THROUGH THE ENTIRE LIST OF CONTACTS
        while(cur!=NULL)
        {

            flag=0;
            for(k=0;k<j;k++)
            {

                //CHECKING IF THE CONTACT NAME IN THE LIST IS ALSO PRESENT IN THE SPOKEN ARRAY
                if(strcmp(cur->name,spoken[k].name_con)==0)
                {
                    flag=1;
                }

            }

            //IF THE NAME IS NOT PRESENT IN SPOKEN ARRAY THEN IT IS DISPLAYED
            if(flag==0)
            {
                printf("%s %lld\n",cur->name,cur->num);
            }

            cur=cur->next;
        }
    }
}


//Function:     find_chats
//Description:  finds and displays all the chats of a particular group or contact
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void find_chats()
{
    //VARIABLE DECLARATION
    int flag=0,x=0;
    FILE *fp=NULL;

    //OPENING
    fp=fopen("chat_final.txt","r");
    char check[20],date1[20],time1[20],z[10],name1[20],text1[70],a[15],m[15];


    printf("\tPLEASE ENTER THE NAME OF THE CONTACT OR GROUP OF WHICH YOU WANT TO FETCH THE CHATS\n");
    scanf("%s",a);

    //READING FROM THE FILE OF CHATS
        while(!feof(fp))
        {
           fscanf(fp,"%s ",check);

           if(check[0]=='/' && check[1]=='/')
         {
             flag=0;
             fscanf(fp,"%s",m);


             if(strcmp(m,a)==0)
             {
                printf("\n");

                //UPDATING FLAG AS 1 IF WE FIND THE CONTACT NAME OR GROUP NAME IN THE FILE OF CHATS
                flag=1;
                x=1;
             }
         }
         else
         {
             fscanf(fp,"%s %s %s %s\n",time1,z,name1,text1);

             //IF FLAG IS EQUAL TO 1 THEN WE HAVE TO PRINT THE MESSAGES OF THAT CONTACT OR GROUP
             if(flag==1)
                printf("\t%s- %s\n",name1,text1);
         }

       }

       //IF FLAG IS EQUAL TO 0 THEN THAT PARTCIULAR CONTACT NAME OR GROUPIS NOT PRESENT IN OUR CHATS FILE
       if(x==0)
       {
           printf("\tThe contact %s is not present in your chat list.\n",a);
       }

        fclose(fp);

}


//Function:     game_riddles
//Description:  added as a new functionality in whatsapp version to get refreshed
//              answer need to entered for all type of question or can exit from game
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void game_riddles()
{

    FILE *f=NULL;
    char function_name[20]="riddle";
    char status[20]="played";
    char message[20]="done";


    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    int n,i=0,score=0;
    char a[10];

    //STATICALLY ASSIGNING THE QUESTION ANS ANSWERS OF THE GAME
    strcpy(R[0].quest,"It has keys, but no locks. It has space, but no room. You can enter, but can’t go inside.What is it?");
    strcpy(R[0].ans,"KEYBOARD");
    strcpy(R[1].quest,"A grandmother, 2 mothers, and 2 daughters went to the movies and bought 1 ticket each. How many tickets did they buy in total?");
    strcpy(R[1].ans,"3");
    strcpy(R[2].quest,"What begins with an “e” and only contains one letter?");
    strcpy(R[2].ans,"ENVELOPE");


    printf("\tLet's begin!\n");
    printf("\tHOW MANY RIDDLES DO YOU WISH TO SOLVE?\n");
    scanf("%d",&n);

    printf("\tNOTE:- You have to give your answers in capitl letters and one-word answers only\n");
    printf("\t--->>--- EVERY CORRECT ANSWER WILL FETCH YOU 10 MARKS ---<<---\n");

    for(i=0;i<n;i++)
    {
        printf("\t\t----->>>------> %d <-----<<<-----\n",i+1);
        printf("%s\n",R[i].quest);
        scanf("%s",a);


        //COMPARING IF THE USER GIVEN ANSWER IS EQUAL TO THE ANSWER STORED
        if(strcmp(R[i].ans,a)==0)
        {
            printf("YOUR ANSWER IS DEFINITELY CORRRECT!\n");

            //INCREMENTING THE SCORE BY 10 IF THE ANSWER IS CORRECT
            score+=10;
        }

        //IF THE USER GIVEN ANSWER IS WRONG THEN CORRECT ANSWER IS DISPLAYED
        else
        {
            printf("OOPS! WRONG ANSWER! THE CORRECT ANSWER IS %s.\n",R[i].ans);
        }
    }

    if(score>10)
    {
        printf("\n\t WOHOOO YOUR SCORE IS %d. DEFINITELY A GOOD RIDDLE SOLVER!\n",score);
    }

    else
    {
        printf("\n\t YOUR SCORE IS %d. LOOKS LIKE YOU GOT CONFUSED WITH SOME.\n",score);
    }

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL RIDDLE IS LOADED INTO LOG FILE



    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);

}

//Function:     game_dsa
//Description:  added as a new functionality in whatsapp version to get refreshed
//              answer need to entered for all type of question or can exit from game
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void game_dsa()
{
    //VARIABLE DECLARATION

    FILE *f=NULL;
    char function_name[20]="dsa";
    char status[20]="played";
    char message[20]="done";

    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    int i,n,score=0;
    char a[15];

    //STATICALLY ASSIGNING THE QUESTION ANS ANSWERS OF THE GAME
    strcpy(D[0].quest,"Which sorting algorithms will take least time when items are identical?");
    strcpy(D[0].ans,"INSERTION");
    strcpy(D[1].quest,"For quick evacuation, when cities become nodes during flood, we use DFS or BFS?");
    strcpy(D[1].ans,"BFS");
    strcpy(D[2].quest,"Is merge sort in place?");
    strcpy(D[2].ans,"NO");


    printf("\tLet's begin!\n");
    printf("\tHow many questions would you like to answer?\n");
    scanf("%d",&n);


    printf("\tNOTE:- You have to give your answers in capital letters and one-word answers only\n");
    for(i=0;i<n;i++)
    {
        printf("\t\t----->>>------> %d <-----<<<-----\n",i+1);
        printf("%s\n",D[i].quest);
        scanf("%s",a);

        //COMPARING IF THE USER GIVEN ANSWER IS SAME AS THE ANSWER STORED
        if(strcmp(D[i].ans,a)==0)
        {
            printf("YOUR ANSWER IS DEFINITELY CORRRECT!\n");

            //INCREMENTING THE SCORE BY 10 IF THE ANSWER IS CORRECT
            score+=10;
        }
        else
        {
            printf("OOPS! WRONG ANSWER! THE CORRECT ANSWER IS %s.\n",D[i].ans);
        }
    }

    if(score>10)
    {
        printf("\n\tWOHOOO YOUR SCORE IS %d. DEFINITELY A DSA GENIUS!\n",score);
    }

    else
    {
        printf("\n\t YOUR SCORE IS %d. LOOKS LIKE YOU GOT CONFUSED WITH SOME.\n",score);
    }
    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL DSA GAME IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //CLOSING LOG FILE
    fclose(f);
}


//Function:     game_bollywood
//Description:  added as a new functionality in whatsapp version to get refreshed
//              answer need to entered for all type of question or can exit from game
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void game_bollywood()
{

    //VARIABLE DECLARATION

    FILE *f=NULL;
    char function_name[20]="bollywood";
    char status[20]="played";
    char message[20]="done";

    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {

        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    int i,n,score=0;
    char a[15];


    //STATICALLY ASSIGNING THE QUESTION ANS ANSWERS OF THE GAME
    strcpy(B[0].quest,"In Jab We Met, what is the name of Geet's cousin?\n");
    strcpy(B[0].ans,"ROOP");
    strcpy(B[1].quest,"What is the name of the lead female character in Dilwale Dulhania Le Jayenge?\n");
    strcpy(B[1].ans,"SIMRAN");
    strcpy(B[2].quest,"In Om Shanti Om, what does Deepika Padukone's character Shantipriya do?\n");
    strcpy(B[2].ans,"ACTRESS");
    strcpy(B[3].quest,"WhO is actor in 'rabh ne banadi jodi'\n");
    strcpy(B[3].ans,"SHAHRUKH");
    strcpy(R[4].quest,"What is name of rahul's daughter in 'kuch kuch hota hai' movie?\n");
    strcpy(R[4].ans,"");


    printf("\tLet's begin!\n");
    printf("\tHow many questions would you like to answer?\n");
    scanf("%d",&n);

    printf("\tNOTE:- You have to give your answers in capital letters and one-word answers only\n");
    for(i=0;i<n;i++)
    {

        printf("\t\t----->>>------> %d <-----<<<-----\n",i+1);
        printf("%s\n",B[i].quest);
        scanf("%s",a);

        //COMPARING IF THE USER GIVEN ANSWER IS SAME AS THE ANSWER STORED
        if(strcmp(B[i].ans,a)==0)
        {
            printf("YOUR ANSWER IS DEFINITELY CORRRECT!\n");

            //INCREMENTING THE SCORE BY 10 IF THE ANSWER IS CORRECT
            score+=10;
        }

        else
        {
            printf("OOPS! WRONG ANSWER! THE CORRECT ANSWER IS %s.\n",B[i].ans);
        }
    }

    if(score>10)
    {
        printf("\n\tWOHOOO YOUR SCORE IS %d. DEFINITELY A BOLLYWOOD QUEEN!\n",score);
    }

    else
    {
        printf("\n\t YOUR SCORE IS %d. LOOKS LIKE YOU GOT CONFUSED WITH SOME.\n",score);
    }


    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL BOLLYWOOD GAME IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);
}


//Function:     whatsapp_games
//Description:  Gives user the choice to choose any of the 5 fun games to play
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation


void whatsapp_games()
{

    int a;

    printf("\t---->>-- WELCOME TO THE MOST FUN PART OF NEW WHATSAPP VERSION --<<----\n");
    printf("\t PLEASE SELECT WHICH ONE OF THE FOLLOWING FUN GAMES YOU WISH TO PLAY\n");

    printf("\t\t1---> BAITHE BAITHE KYA KARE? CHALO SOLVE KARTE HAIN 'RIDDLES'!\n");
    printf("\t\t2---> IT'S DSA QUIZ TIME! ANSWER THESE AND KNOW IF YOU ARE A GENIUS.\n");
    printf("\t\t3---> WHOSE THE BOLLYWOOD QUEEN? PLAY AND CHECK IF IT'S YOU!\n");
    printf("\t\t4---> MAZE GAME\n");
    printf("\t\t ---> MY NAME ITSELF HAS A RIDDLE FOR YOU!!(evil laugh) :> :>\n");
    printf("\t\t ---> HATERS WILL HATE ME, AND LOVERS WILL LIKE ME AS BRAIN NEEDS TO GET EXCERSIZED BEFORE SOLVING ME\tGUESS WHO I AM?\n");
    printf("\t\t5---> SUDOKO HERE!\n");

    scanf("%d",&a);


    if(a==1)
    {
        game_riddles();
    }
    else if(a==2)
    {
        game_dsa();
    }
    else if(a==3)
    {
        game_bollywood();
    }
    else if(a==4)
    {
        maze();
    }
    else if(a==5)
    {
        sudoko();
    }
    else
    {
        printf("IT SEEMS YOU CHOOSED WRONG CHOICE\n");
    }

}

//WHATSAPP ASSISTANT
void Wapi()
{

    //VARIABLE DECLARATION


    FILE *f=NULL;
    char function_name[20]="wapi";
    char status[20]="yes";
    char message[20]="done";
    int flag=0;

    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    char name_user[30];
    int wapi_assistant;
    printf("\tHEY!! THIS IS WAPI, YOUR WHATSAPP ASSISTANT.\n");
    printf("\tWhat will you like to give your name, that will help me to call you?\n");
    scanf("%s",name_user);

    //WAPI INBUILT FUNCTIONS EXPECTED IN NEW WHATSAPP VERSION

     while(1)
    {

        printf("\t1 ->> MAKE A PAYMENT WAPI\n");
        printf("\t2 ->> MAKE A WHATSAPPCALL\n");
        printf("\t3 ->> OPEN MY SETTINGS\n");
        printf("\t4 ->> MAKE A GROUP FOR ME\n");
        printf("\t5 ->> SEARCH A CONTACT NUMBER FOR ME\n");
        printf("\t6 ->> EXIT\n");
        scanf("%d",&wapi_assistant);


        switch(wapi_assistant)
        {

            case 1 : make_a_payment;
                     flag=1;
                     break;

            case 2 : make_a_call();
                     flag=1;
                     break;

            case 3 : settings();
                     flag=1;
                     break;

            case 4 : group_create();
                     flag=1;
                     break;

            case 5 : printf("\n\t--->>>>>---If you want to search for a particular single contact press 1---<<<<<---\n");
                     printf("\t-->>--If you want to search for contacts with similar names(substrings) press 2--<<--\n");
                     int a=0;
                     scanf("%d",&a);
                     flag=1;

                    if(a==1)
                    {
                       contact_search(a);
                       printf("%d",1);
                    }
                    else if(a==2)
                    {
                        contact_search(a);
                    }
                    else
                    {
                        printf("\n\t\t!!!! PLEASE ENTER A VALID CHOICE !!!!\n\n");
                    }
                    break;

            case 6 : fclose(f);

                     exit(0);

        }

    }
    if(flag==1)
    {
        //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL WAPI STATUS IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);


    //CLOSING LOG FILE
    fclose(f);
    }
    else
    {
        fclose(f);
    }

}

//MAZE GAME INTRODUCED BY WHATSAPP
void maze()
{
    //VARIABLE DECLARATION

    FILE *f=NULL;
    char function_name[20]="maze";
    char status[20]="played";
    char message[20]="done";

    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {

        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);


    }



   int a=0,ch=0,b=0,c=0,d=0;
   printf("\n\t     _____ 0  ___________       ");
   printf("\n\t     |A  |   |   ____B___|      ");
   printf("\n\t     |1__    |  3|       |      ");
   printf("\n\t     |     |_____|    |9 |      ");
   printf("\n\t     |2 |_4__D| 8     |_E|        ");
   printf("\n\t     |     C|     7|  |  |        ");
   printf("\n\t     |  _5__|  __H_|10 12|        ");
   printf("\n\t     |6________|G ____|_F|         \n");
   printf("\t---->>-- WELCOME TO THE MOST FUN PART OF NEW WHATSAPP VERSION --<<----\n");
   printf("\tYOU ARE HERE TO PLAY THE MAZE GAME\n");

   printf("\tINSTRUCTIONS TO PLAY :\n");
   printf("\tYOU WANT TO HELP MOUSE TO REACH CHEESE PLACED AT OTHER END\n");
   printf("\tMOUSE IS PRESENT AT NODE -> 0\n");
   printf("\tAND CHEESE AT G\n");
   printf("\tSELECT THE PATH WHICH YOU FEEL WILL BE THE CORRECT TUNNEL PATH FOR MOUSE TO REACH CHEESE\n");


   while(1)
   {
       printf("\tLET'S BEGIN WITH GAME, TIGHTEN YOUR BRAIN CELLS\n\t\t\t\t  GO~~~~~~~~~~~~~~~~~~~\n");
       printf("\tWhere should mouse go? path 1, 2, 3 or 4????\nTHINK AND ANSWER\n");
       scanf("%d",&a);
       if(a==1)
       {
           printf("\n");
           printf("\n");
           printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
           printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'A'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
           printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
           printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
           scanf("%d",&ch);
           if(ch==0)
           {
               exit(0);
           }
           else
           {
               maze();
               exit(0);
           }
       }
       if(a==3)
       {
           printf("\n");
           printf("\n");
           printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
           printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'B'\n\tYOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
           printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
           printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
           scanf("%d",&ch);
           if(ch==0)
           {
               exit(0);
           }
           else
           {
               maze();
               exit(0);
           }
       }
       if(a==4)
       {
           printf("\n");
           printf("\n");
           printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
           printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'D'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
           printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
           printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
           scanf("%d",&ch);
           if(ch==0)
           {
               exit(0);
           }
           else
           {
               maze();
               exit(0);
           }
       }
       if(a==2)
       {
           printf("\tUH......HA ;)\n");
           printf("\tYES YOUR ANSWER IS RIGHT ,STILL NEED TO TRAVEL MORE. CHOOSE NEXT PATH TO CONTINUE\n");
           printf("\tYOU HAVE 2 OPTIONS : 5 OR 6");
           scanf("%d",&b);
           if(b==5)
           {
                printf("\n");
                printf("\n");
                printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
                printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'C'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
                printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
                printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
                scanf("%d",&ch);
                if(ch==0)
                {
                   exit(0);
                }
                else
                {
                    maze();
                    exit(0);
                }
           }
           if(b==6)
           {
               printf("\n");
               printf("\n");
               printf("\tUH......HA ;)\n");
               printf("\tYES YOUR ANSWER IS RIGHT ,STILL NEED TO TRAVEL MORE. CHOOSE NEXT PATH TO CONTINUE\n");
               printf("\tYOU HAVE 2 OPTIONS : 7 OR 8");
               scanf("%d",&c);
               if(c==7)
               {
                   printf("\n");
                   printf("\n");
                   printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
                   printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'H'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
                   printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
                   printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
                   scanf("%d",&ch);
                   if(ch==0)
                   {
                      exit(0);
                   }
                    else
                    {
                       maze();
                       exit(0);
                    }
                }
                else if(c==8)
                {
                     printf("\n");
                     printf("\n");
                     printf("\tUH......HA ;)\nMOUSE IS COMING HOME, WITH TITLE 'MOUSE(TIGER) ZINDA HAI'\n");
                     printf("\tYES YOUR ANSWER IS RIGHT ,STILL NEED TO TRAVEL MORE. CHOOSE NEXT PATH TO CONTINUE\n");
                     printf("\tYOU HAVE 3 OPTIONS : 9, 10 OR 12");
                     scanf("%d",&d);
                     if(d==9)
                     {
                        printf("\n");
                        printf("\n");
                        printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
                        printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'E'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
                        printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
                        printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
                        scanf("%d",&ch);
                        if(ch==0)
                        {
                            exit(0);
                        }
                        else
                        {
                            maze();
                            exit(0);
                        }
                     }
                     else if(d==12)
                     {
                         printf("\n");
                         printf("\n");
                         printf("\tOHHO!!!! QUITE CLOSE ANSWER. BUT------>> YOU CHOOSED WRONG ANSWER MR.MOUSE\n");
                         printf("\tNOW YOU REACHED YOUR FRIENDS HOUSE 'F'\n YOU NEED TO RETURN BACK AS YOUR FRIEND IS NOT THERE AT HOME TO FEED YOU\n");
                         printf("\tDO YOU WANT TO RESTART OR QUITE THE GAME??\n");
                         printf("\tPlease enter 1 or 0, 1 FOR RESTARTING AND 0 FOR EXITING FROM GAME(THIS WILL LEAVE MR.MOUSE HUNGRY)\n");
                         scanf("%d",&ch);
                         if(ch==0)
                         {
                             exit(0);
                         }
                         else
                         {
                             maze();
                             exit(0);
                         }

                     }
                     else if(d==10)
                     {
                         printf("\n");
                         printf("\n");
                         printf("\tFINALLY YOU I MEAN MOUSE!, IS AT HOME TO EAT YUMMY CHEESE!!\n");
                         printf("\tMOUSE IS GRATEFUL OF YOU, IT WANTS TO THANKS YOU!!\n");
                         printf("\tBYE!    \n");
                         printf("\t        ~~MR.MOUSE\n");
                     }
                     else
                     {
                         printf("\n");
                         printf("\n");
                         printf("\tOHHO, YOU CHOOSED WRONG PATH, YOU HAVE TO RESTART\n");
                         printf("\tNO WAY HOME\n");
                         exit(0);
                     }

                }

           }
           else
           {
               printf("\n");
               printf("\n");
               printf("\tOHHO, YOU CHOOSED WRONG PATH\n");
               printf("\tNO WAY HOME\n");
               exit(0);
           }

       }
       else
       {
           printf("\n");
           printf("\n");
           printf("\tWRONG PATH CHOOSED, PLEASE RESTART\n");
           printf("\tNO WAY HOME\n");
           exit(0);
       }

   }
   //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL MAZE GAME  IS LOADED INTO LOG FILE


    int m;
    m=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);
}

//ANSWER OD SUDOKO
void answer()
{

    printf("\n\t        ______________________   ");
    printf("\n\t       |  4  |  2  |  1  |  3 |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t       |  1  |  3  |  4  |  2 |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t       |  3  |  4  |  2  |  1 |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t       |  2  |  1  |  3  |  4 |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
}


//SUDOKO GAME INTRODUCED BY WHATSAPP
void sudoko()
{
    FILE *f=NULL;
    char function_name[20]="sudoko";
    char status[20]="played";
    char message[20]="done";

    //OPENING OF LOG FILE
    f=fopen("wlog.txt","a");
    if(f==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    int row=0,column=0,sudoko=0,count=0;
    int solution_activated = 0;
    printf("\tHEY! WELCOME TO BRAIN MASH UP GAMES.\nCOME LET'S PLAY 4cross4 MATRIX SUDOKO\n");
    printf("\tIT'S A EASY START LET'S PLAY WUSH~~~~~~~~~~~~~~\n");
    printf("\n\t          1     2     3     4    ");
    printf("\n\t        ______________________   ");
    printf("\n\t    1  |  4  |  2  |     |  3 |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t    2  |  1  |  3  |  4  |    |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t    3  |     |  4  |  2  |    |  ");
    printf("\n\t       |_____|_____|_____|____|  ");
    printf("\n\t    4  |     |     |     |    |  ");
    printf("\n\t       |_____|_____|_____|____|  ");

    printf("\n\tINSTRUCTIONS TO GIVE ANSWER IN THE FORMAT :\n ");
    //ROW
    printf("\tYOU NEED TO GIVE ROW NUMBER Ex:1\n");
    //COLUMN
    printf("\tYOU NEED TO GIVE COLUMN NUMBER Ex:3\n");
    printf("IF ENTERED VALUES ARE CORRECT THEN GAME ALLOWS PLAYER TO ENTER THE SUDOKO VALUE\n\tOTHERWISE GAME WILL TERMINATE\n");

    //TERMINATING CONDITION HERE IS ENTERING WRONG ROW AND COLUMN VALUE
    //YOU CAN GET ANSWER AT ANY MOMENT YOU NEED, BUT AT THAT TIME GAME WILL END
    while(count!=8)
    {
        if(solution_activated==1)
        {
            answer();
            printf("GAME ENDED\n");
            exit(0);
        }
        printf("ENTER ROW NUMBER\n");
        scanf("%d",&row);
        printf("ENTER COLUMN NUMBER \n");
        scanf("%d",&column);

        if(row == 1 && column ==3)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==1)
            {
                printf("\tWOOHAA.....\n");
                printf("\tASHCHARY CHAKIT.....(don't worry HINDI word for surprised )\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
            }
        }
        else if(row == 2 && column == 4)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==2)
            {
                printf("\tWOOHAA.....\n");
                printf("\tGREAT WORK!\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 3 && column == 1)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==3)
            {
                printf("\tWOOHAA.....\n");
                printf("\tI THINK YOU ARE GEIUS IN PLACING NUMBERS IN THEIR HOUSE\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 3 && column == 4)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==1)
            {
                printf("\tWOOHAA.....\n");
                printf("\tYOU CALCULATED RIGHT ANSWER\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 4 && column == 1)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==2)
            {
                printf("\tWOOHAA.....\n");
                printf("\tSUDOKO PLAYER, GREAT WORK\n");
                count++;
            }
            else
            {
                printf("\tYOU TYPED WRONG ANSWER, TRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 4 && column == 2)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==1)
            {
                printf("\tWOOHAA.....\n");
                printf("\tDEBAKK.....(don't worry KOREAN word for AMAZING)\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 4 && column == 3)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==3)
            {
                printf("\tWOOHAA.....\n");
                printf("\tAMAZING CHAMPION IS PLAYING MY GAME HUH?!!\n");
                count++;
            }
            else
            {
                printf("\tYOU TYPED WRONG ANSWER, TRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else if(row == 4 && column == 4)
        {
            printf("ENTER SUDOKO VALUE : \n");
            scanf("%d",&sudoko);
            if(sudoko==4)
            {
                printf("\tWOOHAA.....\n");
                printf("\tYOU CALCULATED RIGHT ANSWER\n");
                count++;
            }
            else
            {
                printf("\tWRONG ANSWER, NO WORRIES!!\n\tTRY AGAIN\n");
                printf("\tYOU WANT SOLUTION? IF YES PRESS 1 OTHERWISE 0\n");
                scanf("%d",&solution_activated);
            }
        }
        else
        {
            printf("\tNO SUCH ROW AND COLUMN EXIST, GAME IS TERMINATING\n\tYOU NEED TO RESTART\n");
            exit(0);
        }
    }
    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL SUDOKO GAME IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(f, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE
    fclose(f);
}


//INSERTING CONTACT NAMES INTO BINARY SEARCH TREE
TREE* insert_into_bst(TREE *root,char data[15],char a[12])
{
    TREE *newnode;
    newnode=(TREE*)malloc(sizeof(TREE));
    //NEW NODE CREATED

    if(newnode==NULL)
    {
        printf("memory allocation failed\n");
        return root;
    }

    //COPYING THE NEWNODE'S CONTACT NAME AND NUMBER WITH CONTACT DETAILS
    strcpy(newnode->name,data);
    strcpy(newnode->num,a);

    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        return root;
    }

    TREE *curr;
    TREE *parent;
    curr=root;
    parent=NULL;


    while(curr!=NULL)
    {
        parent=curr;

        //IF strcmp RETURNS A NEGATIVE VALUE THEN THE newnode's name COMES BEFORE THE currnode's name IN ALPHABETICAL ORDER.
        if(strcmp(newnode->name,curr->name)<0)
            curr=curr->left;
        else
            curr=curr->right;
    }

    //COMPARING WHICH NAME COMES BEFORE IN ALPHABETICAL ORDER

    if(strcmp(newnode->name,parent->name)<0)
        parent->left=newnode;
    else
        parent->right= newnode;

    return root;
}


//INORDER TRAVERSAL TO PRINT IN ALPHABETICAL ORDER
void inorder(TREE *root)
{

    //TRAVERSES THROUGH THE TREE AND DISPLAYING THE CONTACT NAMES
    //INORDER TRAVERSAL DISPLAYS NAMES IN ALPHABETICAL ORDER
    if(root!=NULL)
    {

        inorder(root->left);
        printf("%s\t\t%s\n",root->name,root->num);
        inorder(root->right);

    }

}

//FUNCTION TO SORT CONTACT NAMES BASED ON BINARY SEARCH TREE
void contact_name_bst()
{

    //VARIABLES
    TREE *root;
    root=NULL;
    FILE *fp=NULL;

    //OPENING OF CONTACTS FILE
    fp=fopen("Contacts.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s %s\n",bl,hc);
        root=insert_into_bst(root,bl,hc);
    }

    //CLOSING OF CONTACT FILE
    fclose(fp);

    //CALLING INORDER FUNCTION TO PRINT NAMES
    inorder(root);
}


void heapify(hp r[], int n, int i)
{

    int largest = i;
    // Initialize largest as root

    int left = 2*i + 1;
    // left child

    int right = 2*i + 2;
    // right child

    // If left child is larger than root
    if (left < n && r[left].rank > r[largest].rank)
    {
       largest = left;
    }

    // If right child is larger than root
    if (right < n && r[right].rank > r[largest].rank)
    {
        largest = right;
    }
    // If root is not largest

    if (largest != i)
    {
        // swap a[i] with a[largest]

        tempa = r[i];
        r[i] = r[largest];
        r[largest] = tempa;

        heapify(r, n, largest);
    }
}

/*Function to implement the heap sort*/
void heapSort(hp a[], int n)
{
    int i=0;

    for (i = (n/2 )- 1; i >= 0; i--)
        heapify(a, n, i);
     // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        /* Move current root element to end*/
        // swap a[0] with a[i]
        hp temp;
         temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }

}

/* function to print the array elements */
void printArr(hp arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("\t%lld %d\n",arr[i].number, arr[i].rank);

    }

}

//SORTING BY HEAP
void heap_sorting_array()
{

    //VARIABLE DECLARAING
    FILE *fp=NULL;
    char function_name[20]="rank_heap";
    char status[20]="sorted";
    char message[20]="done";

    //OPENING OF LOG FILE
    fp=fopen("wlog.txt","a");
    if(fp==NULL)
    {
        //UNSUCCESSFUL STATUS
        printf("\tFILE NOT OPENED TO LOG\n");
        int e;
        e = error();
        printf("\t%d\n",e);
        exit(0);

    }


    int i=0;
    FILE *f=0;

    //OPENING OF RANK FILE
    f = fopen("rank.txt","r");
    if(f == 0)
    {

        printf("FILE NOT OPENED\n");
        exit(0);
    }
    while(!feof(f))
    {

           fscanf(f,"%lld %d",&r[i].number,&r[i].rank);
           printf("%lld %d\n",r[i].number,r[i].rank);
           i++;

    }

    printf("%d",i);
    int n = i;

    printf("IN FILE UNSORTED RANK OF MESSAGES RECEIVED BY CONTACT NUMBER ARE :---> \n");
    printArr(r, n);

    //HEAP SORT
    heapSort(r, n);

    printf("\nAFTER SORTING,FIRST MESSAGE SENT BY CONTACT IS DISPLAYED ACCORDING TO RANK. THE DISPLAY OF YOUR WHATSAPP WILL BE :---> \n");
    printArr(r, n);

    //USING CTIME, CURRENT EXECUTION TIME OF SUCCESSFUL HEAP SORT STATUS IS LOADED INTO LOG FILE


    int d;
    d=done();
    printf("\tSTATUS : %d\n",d);
    time_t mytime;
    mytime = time(NULL);
    fprintf(fp, "%s %s %s %s\n", ctime(&mytime), function_name, status, message);

    //CLOSING LOG FILE AND RANK FILE
    fclose(fp);
    fclose(f);

}

//MERGING
void merge(MS arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    MS L[n1];
    MS R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i].num_chats >= R[j].num_chats) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSort(MS arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//Function:     top_chats
//Description:  Displays the contact names and number of messages exchanged between user and them in the decreasing order
//              Merge sort is used to sort based on the number of messages
//Input param:  NULL
//Return Type:  NULL
//              valid output on successful operation

void top_chats()
{
    //VARIABLE DECLARATION
    FILE *fp=NULL;
    fp=fopen("chat_final.txt","r");
    char check[20],date1[20],time1[20],z[10],name1[20],text1[60],a[20],m[20];
    int i=-1,x=0,k=-1,t=0;

    //READING FROM THE FILE OF CHATS
    while(!feof(fp))
    {
         fscanf(fp,"%s ",check);
         if(check[0]=='/' && check[1]=='/')
         {
             x=0;
             t=0;
             j++;
             fscanf(fp,"%s",m);
         }

         else
         {
             fscanf(fp,"%s %s %s %s\n",time1,z,name1,text1);
             if(x==0)
             {
                 //STORING THE CONTACT NAME AND NUMBER OF TEXT MESSAGES IN ARRAY
                 arr[k].num_chats=i;
                 strcpy(arr[k].name,a);
                 k++;
             }

                    //INCREMENTING t WILL COUNT THE NUMBER OF MESSAGES EXHANGED WITH THAT PARTICULAR CONTACT OR GROUP
                    t++;
                    i=t;

                x=1;
                strcpy(a,m);
         }
    }


    //STORING THE LAST CONTACT OR GROUP NAME AND NUMBER OF TEXT MESSAGES IN ARRAY
    arr[k].num_chats=i;
    strcpy(arr[k].name,a);
    fclose(fp);

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);
    printf("\n");

    //DISPLAYING THE SORTED CONTACT NAMES AND NUMBER OF MESSAGES ASSOCIATED WITH THEM IN DECREASING ORDER
    for (int i = 0; i < arr_size; i++)
        printf("%s\t\tNUMBER OF MESSSAGES:- %d\n",arr[i].name,arr[i].num_chats);

    printf("\n");
}
