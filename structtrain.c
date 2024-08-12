//Train no: int

//Train NAME: String

//Departure Time: Aggregate type TIME

//Arrival time: Aggregate type TIME

//Strat Station: String


//End Station: String

#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct TIME{
int hour;
int minute;
}TIME;
typedef struct TRAIN_INFO{
int train_no;
char train_name[35];
char start_st[35];
char end_st[35];
TIME dept_time;
TIME arr_time;
} TRAIN;

void train_edit (TRAIN *, int *);

int main (void)

{

int no_of_trains = 0;

int i;

int choice;

char dept_st[35];

char arr_st[35];

TIME train_time;

TRAIN train[MAX];

//Call train_edit function first time.

train_edit (train, &no_of_trains);

while (1)

{

//Display Main Menu

printf ("\t\t\t***MENU***\n");

printf ("1. List all the trains departed from a particular station.\n");

printf ("2. List all the trains departed from a particular station at a particular time.\n");

printf ("3. List all the trains departed from particular station within the next one hour of a given time.\n");

printf ("4. List all the trains between a pair of start station and end station.\n");

printf ("5. Edit train details.\n");

printf ("6. Exit.\n");

printf ("Your choice: ");

//Input choice

scanf ("%d", &choice);

switch (choice)

{

//List all the trains departed from a particular station.

case 1:

printf ("\n\t\t***INPUT DETAILS***\n");

printf ("Depart Station: ");

fflush (stdin);

gets (dept_st);

//Print trains

for(i=0;i<=no_of_trains-1;i++)

{

if (strcmp (train[i].start_st, dept_st) == 0)

{

printf("%d\t\t%s\t%s\t%s\t%d:%d\t%d:%d\n", train[i].train_no, train[i].train_name,

train[i].start_st, train[i].end_st, train[i].dept_time.hour,

train[i].dept_time.minute, train[i].arr_time.hour, train[i].arr_time.minute);

}

}

printf ("\n");

break;

//List all the trains departed from a particular station at a particular time.

case 2:

printf ("\n\t\t***INPUT DETAILS***\n");

printf ("Depart Station: ");

fflush (stdin);

gets (dept_st);

printf ("Train Time: \n");

printf ("Hour: ");

scanf ("%d", &train_time.hour);

printf ("Minute: ");

scanf ("%d", &train_time.minute);

//Print trains

for (i=0;i<= no_of_trains-1;i++)
{
if (strcmp (train[i].start_st, dept_st) == 0 && train[i].dept_time.hour == train_time.hour
&& train[i].dept_time.minute == train_time.minute)

{

printf ("%d\t\t%s\t%s\t%s\t%d:%d\t%d:%d\n", train[i].train_no,

train[i].train_name, train[i].start_st, train[i].end_st, train[i].dept_time.hour,

train[i].dept_time.minute, train[i].arr_time.hour, train[i].arr_time.minute);

}

}

printf ("\n");

break;

//List all the trains departed from particular station within the next one hour of a given time.

case 3:

printf ("\n\t\t***INPUT DETAILS***\n");

printf ("Depart Station: ");

fflush (stdin);

gets (dept_st);

printf ("Time: \n");

printf ("Hour: ");

scanf ("%d", &train_time.hour);

printf ("Minute: ");

scanf ("%d", &train_time.minute);
//Print trains

for (i=0;i<=no_of_trains-1;i++)
{
if (strcmp (train[i].start_st, dept_st) == 0 && ((train[i].dept_time.hour == train_time.hour

&& train[i].dept_time.minute >= train_time.minute)

|| (train[i].dept_time.hour == train_time.hour + 1

&& train[i].dept_time.minute <= train_time.minute)))

{

printf ("%d\t\t%s\t%s\t%s\t%d:%d\t%d:%d\n", train[i].train_no,

train[i].train_name, train[i].start_st, train[i].end_st, train[i].dept_time.hour,

train[i].dept_time.minute, train[i].arr_time.hour, train[i].arr_time.minute);

}

}

printf ("\n");

break;

//List all the trains between a pair of start station and end station.

case 4:

printf ("\n\t\t***INPUT DETAILS***\n");

printf ("Depart Station: ");

fflush (stdin);

gets (dept_st);

printf ("Arrival Station: ");

fflush (stdin);

gets (arr_st);



//Print trains

for (i=0;i<=no_of_trains-1;i++)

{

if ((strcmp (train[i].start_st, dept_st) == 0) && (strcmp (train[i].end_st, arr_st) == 0))

{

printf ("%d\t\t%s\t%s\t%s\t%d:%d\t%d:%d\n", train[i].train_no,

train[i].train_name, train[i].start_st, train[i].end_st, train[i].dept_time.hour,

train[i].dept_time.minute, train[i].arr_time.hour, train[i].arr_time.minute);

}

}

printf ("\n");

break;



//Edit train details. Call for train_edit

case 5:

printf ("\n");

train_edit (train, &no_of_trains);

break;



//Exit

case 6:

return 0;

//Wrong Choice

default:

printf ("\nError! Wrong Choice.\n\n");

}

}

return 0;

}

void train_edit (TRAIN *train, int *no_of_trains)

{

int choice;

int i, train_num;

TRAIN temp;

while (1)

{

//Display Train Edit Menu

printf ("\t\t***TRAIN EDIT MENU***\n");

printf ("1. Add Train.\n");

printf ("2. Delete Train.\n");

printf ("3. Exit Train Edit Menu.\n");

printf ("Your Choice: ");

//Input choice

scanf ("%d", &choice);

switch (choice)

{

//Add Train

case 1:

//Already maximum trains.

if (*no_of_trains >= MAX)

{

printf ("\nError! There are already maximum trains.\n\n");

break;

}

//Input train details in temp variable.

printf ("\nInput Train Number: ");

scanf ("%d", &temp.train_no);

//Check if train number already exist or not.

for (i = 0; i <= *no_of_trains-1; i++)

{

if (train[i].train_no == temp.train_no)

{

printf ("Error! Train number %d already exist. Please try again.\n\n");

temp.train_no = -1;

break;

}

}

if (temp.train_no == -1)

break;



printf ("Input Train Name: ");

fflush (stdin);

gets (temp.train_name);

printf ("Input Start Station: ");

fflush (stdin);

gets (temp.start_st);

printf ("Input End Station: ");

fflush (stdin);

gets (temp.end_st);

printf ("Input Departure Time: \n");

printf ("Hour: ");

scanf ("%d", &temp.dept_time.hour);

printf ("Minute: ");

scanf ("%d", &temp.dept_time.minute);

printf ("Input Arrival Time: \n");

printf ("Hour: ");

scanf ("%d", &temp.arr_time.hour);

printf ("Minute: ");

scanf ("%d", &temp.arr_time.minute);

//Add temp into sorted array.

train[*no_of_trains] = temp;

for(i=*no_of_trains;i>=1;i--)

{

if(train[i-1].train_no>=train[i].train_no)

{

temp = train[i-1];

train[i-1] = train[i];

train[i] = temp;

}

else

break;

}

*no_of_trains = *no_of_trains + 1;

printf("Train %d added successfully.\n\n", train[i].train_no);

break;



//Delete Train

case 2:

//No train available.

if (*no_of_trains == 0)

{

printf ("\nError! No Train Available.\n\n");

break;

}



//Input train details.

printf ("\nInput Train Number: ");

scanf ("%d", &train_num);



//Find and delete train.

for (i=0;i<=*no_of_trains-1;i++)

{

if (train[i].train_no==train_num)

{

while(i<=*no_of_trains-1)

{

train[i] = train[i + 1];

i++;

}

*no_of_trains = *no_of_trains-1;

printf ("Train %d deleted successfully.\n\n", train_num);

train_num = -1;

break;

}

}



//Train not found.

if (train_num != -1)

printf ("Error! Train %d not found\n\n", train_num);



break;



//Exit Train Edit Menu

case 3:

printf ("\n");

return;



//Wrong choice

default:

printf ("\nError! Wrong Choice.\n\n");

}

}

}

