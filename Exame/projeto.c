#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct date
{
	int day, month, year;
	int hour, minute;
	int duration;
	char time[1]; //AM or PM

}DATE;

typedef struct reservation
{
	int code;
	int row, chair;
	char pay[5];         //yes or no
	char name[20];
	bool paid;
	bool exist;

}RESERVATION;
typedef struct show
{
	float price;
	int code;
	char title[10], genre[10];
	RESERVATION reservation[20];
	DATE date;
	bool exist;
	bool ocupation;

}SHOW;

typedef struct room
{
	int code, rows, chairs;
	char locality_name[20];
	SHOW show[20];
	bool ocupation;
	bool exist;

}ROOM;



void inicialization(ROOM* p)
{

	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			for (int i = 0; i < 20; i++)
			{
				p[j].exist = false;
				p[j].ocupation = false;
				p[j].show[c].exist = false;
				p[j].show[c].ocupation = false;
				p[j].show[c].reservation[i].paid = false;
				p[j].show[c].reservation[i].exist = false;
			}
		}
	}
}


void add_new_room(ROOM* p)
{
	int j = 0;

	while (p[j].exist == true)
	{
		if (p[j].exist == true)
		{
			j++;
		}

	}


	printf("\nWhere the new room is located?");
	scanf("%s", &p[j].locality_name);

	printf("\nHow many rows does the room has?");
	scanf("%d", &p[j].rows);

	printf("\nHow many chairs does the row has?");
	scanf("%d", &p[j].chairs);


	p[j].exist = true;

	p[j].code = j + 1;

}

void rooms_list(ROOM* p)
{


	for (int j = 0; j < 20; j++)
	{
		if (p[j].exist == true)
		{
			printf("\n%d\t%s\t%d %d\n", p[j].code, p[j].locality_name, p[j].rows, p[j].chairs);
		}
	}


}

void remove_room(ROOM* p)
{
	int room_code;

	printf("\nWhat is the room's code you desire to remove?");
	scanf("%d", &room_code);

	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			for (int i = 0; i < 20; i++)
			{
				if (p[j].code == room_code)
				{
					p[j].locality_name[0] = '\0';
					p[j].exist = false;
					p[j].chairs = 0;
					p[j].rows = 0;
					//p[j].code = 0;
					p[j].show[c].exist = false;
					p[j].show[c].reservation[i].exist = false;



				}
			}
		}
	}
}

void add_new_show(ROOM* p)
{
	int room_code;

	printf("\nWhat is the room's code you desire to alocate the show?");
	scanf("%d", &room_code);

	int j = 0, c = 0;

	while (p[j].code != room_code && p[j].exist == true  && j < 20)
	{
		j++;

	}

	if (p[j].exist == false && p[j].code == 0)
	{
		while (p[j].code != room_code && p[j].exist == false && j < 20)
		{
			j++;

		}
	}
	


	while (p[j].show[c].exist == true && c < 20)
	{
		c++;
	}


	if (p[j].code == room_code && p[j].show[c].exist == false && p[j].exist == true && j < 20 && c < 20)
	{
		printf("\nWhat is the show's name?");
		scanf("%s", p[j].show[c].title);

		printf("\nWhat is the show's genre?");
		scanf("%s", p[j].show[c].genre);

		printf("\nWhat is the date of the show?");
		scanf("%d %d %d", &p[j].show[c].date.day, &p[j].show[c].date.month, &p[j].show[c].date.year);

		printf("\nWhat is the ticket's price?");
		scanf("%f", &p[j].show[c].price);

		printf("\nWhen does the show start?\nExample:10:00 AM\n");
		scanf("%d %d %s", &p[j].show[c].date.hour, &p[j].show[c].date.minute, p[j].show[c].date.time);

		printf("\nWhat is the show's duration in minutes?");
		scanf("%d", &p[j].show[c].date.duration);


		p[j].show[c].code = c + 1;

		p[j].show[c].exist = true;

	}
	else
	{
		printf("\nIts not possible to add show\n");
	}


}

void remove_show(ROOM* p)
{
	int room_code, show_code;

	printf("\nWhat is the room's code and the show's code you desire to remove?");
	scanf("%d %d", &room_code, &show_code);

	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			if (p[j].code == room_code && p[j].show[c].code == show_code)
			{
				p[j].show[c].exist = false;
			}
		}
	}
}




void shows_list(ROOM* p)
{
	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			if (p[j].show[c].exist == true)
			{
				printf("\n%d-\t%d\t%s\t%s\t%d/%d/%d\t%f\t%d:%d %s\t%d\n", p[j].code, p[j].show[c].code, p[j].show[c].title, p[j].show[c].genre,
					p[j].show[c].date.day, p[j].show[c].date.month, p[j].show[c].date.year, p[j].show[c].price,
					p[j].show[c].date.hour, p[j].show[c].date.minute, p[j].show[c].date.time, p[j].show[c].date.duration);
			}
		}
	}
}

void add_new_reservation(ROOM* p)
{
	int i = 0, j = 0, c = 0, room_code, show_code;
	int row, chair;
	char r;

	printf("\nWhat is the room's code and show's code you desire to make a reservation?");

	scanf("%d %d", &room_code, &show_code);

	printf("\nWhat is the row and the chair you desire to reserve?");
	scanf("%d %d", &row, &chair);



	while (p[j].code != room_code && j < 20) //p[j].exist == false && 
	{
		j++;
	}

	while (p[j].show[c].code != show_code && c < 20) //(p[j].show[c].exist == false && 
	{
		c++;
	}

	while (p[j].show[c].reservation[i].exist == true && i < 20)
	{
		i++;
	}


	if (row > p[j].rows || chair > p[j].chairs)
	{
		printf("\nIts not possible to make a reservation\n");
	
	}



	for (int a = 0; a < 20; a++)
	{
		if (row == p[j].show[c].reservation[a].row && chair == p[j].show[c].reservation[a].chair)
		{
			printf("\nThat place is ocupied\n");

		}
			
	}






	if (p[j].exist == true && p[j].code == room_code && p[j].show[c].exist == true && p[j].show[c].code == show_code && p[j].show[c].reservation[i].exist == false && j < 20 && i < 20 && c < 20)
	{

			printf("\nWhat is the name of the client?");
			scanf("%s", &p[j].show[c].reservation[i].name);

			
			printf("\nDid the client paid?");
			scanf("%s", &p[j].show[c].reservation[i].pay);
			
			
			p[j].show[c].reservation[i].exist = true;
			p[j].show[c].reservation[i].code = i + 1;
			p[j].show[c].reservation[i].row = row;
			p[j].show[c].reservation[i].chair = chair;
		
	}
	else
	{
		printf("\nIts not possible to make a reservation\n");
	}


}

void remove_reservation(ROOM* p)
{

	int room_code, show_code, reservation_code;

	printf("\nWhat is the room's code, the show's code and the reservation's code you desire to remove?");
	scanf("%d %d %d", &room_code, &show_code, &reservation_code);







	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			for (int i = 0; i < 20; i++)
			{
				if (p[j].code == room_code && p[j].show[c].code == show_code && p[j].show[c].reservation[i].code == reservation_code)
				{
					p[j].show[c].reservation[i].exist = false;
				}
			} 
		}
	}
}


void reservation_list(ROOM* p)
{
	for (int j = 0; j < 20; j++)
	{
		for (int c = 0; c < 20; c++)
		{
			for (int i = 0; i < 20; i++)
			{
				if (p[j].show[c].reservation[i].exist == true)
				{
					printf("\n%d %d %d - %s %s\n", p[j].code, p[j].show[c].code, p[j].show[c].reservation[i].code,
						p[j].show[c].reservation[i].name, p[j].show[c].reservation[i].pay);
				}
			}
		}
	}
}








void main()
{
	ROOM p[20];

	int option;

	inicialization(p);

	do
	{
		printf("\n\n\tMENU****\n");
		printf("1 - Insert new room\n");
		printf("2 - Remove room\n");
		printf("3 - Check rooms list\n");
		printf("4 - Insert new show\n");
		printf("5 - Remove show\n");
		printf("6 - Check shows list\n");
		printf("7 - Insert new reservation\n");
		printf("8 - Remove reservation\n");
		printf("9 - Check reservations list\n");
		
		

		printf("15 - Quit the program\n");
		printf("\nWhich operation do you want to execute:");
		scanf("%d", &option);


		switch (option)
		{
		case 1:add_new_room(p); break;
		case 2:remove_room(p); break;
		case 3:rooms_list(p); break;
		case 4:add_new_show(p); break;
		case 5:remove_show(p); break;
		case 6:shows_list(p); break;
		case 7:add_new_reservation(p); break;
		case 8:remove_reservation(p); break;
		case 9:reservation_list(p); break;
		
	
		case 15:printf("\nEnd of execution\n"); break;
		default:printf("\nOperation not found...\n");
		}

		system("pause");

	} while (option != 15);

}
