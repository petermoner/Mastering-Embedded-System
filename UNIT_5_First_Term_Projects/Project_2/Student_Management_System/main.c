/*
 * main.c
 *
 *  Created on: May 24, 2023
 *      Author: Peter Moner
 */
#include "FIFO.h"

int main(void)
{
	fifo_buffer school;
	char text [3] ;

	School_System_Create(&school);

	while (1)
	{
		DPRINTF("\n	============================\n") ;
		DPRINTF("\tChoose on the following options\n\n") ;
		DPRINTF("1 : Add Students From File \n") ;
		DPRINTF("2 : Add Student Manually \n") ;
		DPRINTF("3 : Find Student by ID \n") ;
		DPRINTF("4 : Find Student by First Name \n") ;
		DPRINTF("5 : How Many Students in Course \n") ;
		DPRINTF("6 : Number OF Students \n") ;
		DPRINTF("7 : Delete Student \n") ;
		DPRINTF("8 : Update Student \n") ;
		DPRINTF("9 : Show All Students \n") ;
		DPRINTF("10 : Exit  \n") ;
		DPRINTF("\n====================================================");

		DPRINTF("\nEnter your Choice : ") ;
		gets (text) ;
		DPRINTF("\n	============================\n") ;

		switch (atoi(text))
		{
		case 1:
			School_Add_Students_From_File(&school);
			break;
		case 2:
			School_Add_Student_Manually(&school);
			break;
		case 3:
			School_find_by_id(&school);
			break ;
		case 4:
			School_find_by_first_name(&school);
			break ;
		case 5:
			School_How_many_students_in_course(&school);
			break ;
		case 6:
			School_number_of_students(&school);
			break ;
		case 7:
			School_delete_student(&school);
			break ;
		case 8:
			School_update_student(&school);
			break ;
		case 9:
			School_print_students(&school);
			break ;
		case 10:
			DPRINTF("Quit of School System...Bye \n") ;
			exit(1);
			break ;
		default :
			DPRINTF("[ERORR]...Your Choice isn't Exist\n") ;
		}
	}

	return 0;
}
