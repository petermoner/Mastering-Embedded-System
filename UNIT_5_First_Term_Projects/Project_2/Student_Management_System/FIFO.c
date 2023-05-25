/*
 * FIFO.c
 *
 *  Created on: May 24, 2023
 *      Author: Peter Moner
 */


#include "FIFO.h"


typedef enum{
	QUEUE_EMPTY,
	QUEUE_NOTEMPTY,
	QUEUE_FULL,
	QUEUE_NOTFULL
}fifo_status_t;

static int id_check(fifo_buffer * buffer,int id)
{
	int ret=-1;
	element_type* print=(buffer->buf);
	while(print != (buffer->back))
	{
		if(id == print->roll)
		{
			ret = 1;
		}
		else
		{
		}

		print++;
	}
	return ret;
}

/*==========================================================================================*/


fifo_status_t IS_FULL(fifo_buffer * buffer)
{
	fifo_status_t ret;
	if((buffer->count)==(buffer->length))
	{
		ret=QUEUE_FULL;
	}
	else
	{
		ret=QUEUE_NOTFULL;
	}
	return ret;
}

/*==========================================================================================*/

fifo_status_t IS_EMPTY(fifo_buffer * buffer)
{
	fifo_status_t ret;
	if((buffer->count)==0)
	{
		ret=QUEUE_EMPTY;
	}
	else
	{
		ret=QUEUE_NOTEMPTY;
	}
	return ret;
}

/*==========================================================================================*/

ret_status_t School_System_Create(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	if(NULL==buffer)
	{
		setbuf(stdout,NULL);
		DPRINTF("Error!!...creating queue...is failed\n");
		ret=R_NOK;
	}
	else{
		(buffer->base)=	(buffer->buf);
		(buffer->back)=	(buffer->buf);
		(buffer->front)=(buffer->buf);
		(buffer->count)=0;
		(buffer->length)=MAX_SIZE;
		setbuf(stdout,NULL);
		DPRINTF("[INFO] creating School System...is Done\n");
		ret=R_OK;
	}
	return ret;
}

/*==========================================================================================*/

ret_status_t School_Add_Students_From_File(fifo_buffer * buffer)
{
	FILE *fp = fopen("student.txt","r");
	ret_status_t ret=R_NOK;
	int i=0,id_ret=-1;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front))
	{
		DPRINTF("[ERORR]...in accessing data\n");
		ret=R_NOK;
	}

	else{
		ret=R_NOK;

		if(!fp)
		{
			DPRINTF("[ERORR]...no characters exist in File...!!");
			exit(1);
		}

		//adding one student every loop
		while(!feof(fp))
		{
			if(QUEUE_FULL==IS_FULL(buffer))
			{
				DPRINTF("\n[ERORR]...No Space For Another Student....school is full\n");
				ret=R_NOK;
				break;
			}
			else
			{
				fscanf(fp,"%d",&((buffer->back)->roll));
				id_ret=id_check(buffer,((buffer->back)->roll));

				if(1 == id_ret)
				{
					DPRINTF("\n===========================================================================");
					DPRINTF("\n[ERORR] Roll Number  %d  is already taken",(buffer->back)->roll);
					fscanf(fp, "%*[^\n]");
					continue;
				}

				fscanf(fp,"%s",&((buffer->back)->fname));
				fscanf(fp,"%s",&((buffer->back)->lname));
				fscanf(fp,"%f",&((buffer->back)->gpa));

				for(i=0;i<5;i++)
				{
					fscanf(fp,"%d",&((buffer->back)->course_id[i]));
				}

				DPRINTF("\n===========================================================================");
				DPRINTF("\n[INFO] Roll Number  %d  is Saved Successfully",(buffer->back)->roll);
				DPRINTF("\n-----------------------------------------------------------------------");
				DPRINTF("\n[INFO] The total number of students is %d ",(buffer->count)+1);
				DPRINTF("\n[INFO] You can add up to %d students",buffer->length);
				DPRINTF("\n[INFO] You can add %d more students\n",(buffer->length)-(buffer->count)-1);
				(buffer->count)++;

				if((buffer->back)==((buffer->base)+(buffer->length)*sizeof(element_type)))
				{
					(buffer->back)=	(buffer->base);
				}
				else
				{
					(buffer->back)++;
				}

			}

			ret=R_OK;
		}
		fclose(fp);
	}

	return ret;
}

/*==========================================================================================*/


ret_status_t School_Add_Student_Manually(fifo_buffer * buffer)
{
	char text[20];
	int i=0,id_ret=-1;
	ret_status_t ret=R_NOK;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_FULL==IS_FULL(buffer))
	{
		DPRINTF("[ERORR]...in accessing data\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");
		DPRINTF("\nEnter Student Roll Number: ");
		gets(text);
		(buffer->back)->roll=atoi(text);


		id_ret=id_check(buffer,((buffer->back)->roll));

		if(1 == id_ret)
		{
			DPRINTF("\n===========================================================================");
			DPRINTF("\n[ERORR] Roll Number  %d  is already taken",(buffer->back)->roll);
		}

		else
		{
			DPRINTF("\nEnter Student First Name: ");
			gets((buffer->back)->fname);

			DPRINTF("\nEnter Student Last Name: ");
			gets((buffer->back)->lname);


			DPRINTF("\nEnter Student GPA: ");
			gets(text);
			(buffer->back)->gpa=atof(text);

			DPRINTF("\nEnter Student courses ID: ");

			for(i=0;i<5;i++)
			{
				DPRINTF("\nID %d: ",i+1);
				gets(text);
				(buffer->back)->course_id[i]=atoi(text);
			}

			DPRINTF("\n[INFO] Roll Number  %d  is Saved Successfully",(buffer->back)->roll);
			DPRINTF("\n-----------------------------------------------------------------------");
			DPRINTF("\n[INFO] The total number of students is %d ",(buffer->count)+1);
			DPRINTF("\n[INFO] You can add up to %d students",buffer->length);
			DPRINTF("\n[INFO] You can add %d more students\n",(buffer->length)-(buffer->count)-1);

			(buffer->count)++;

			if((buffer->back)==((buffer->base)+(buffer->length)*sizeof(element_type)))
			{
				(buffer->back)=	(buffer->base);
			}
			else
			{
				(buffer->back)++;
			}
		}

		ret=R_OK;
	}
	return ret;
}


/*==========================================================================================*/


ret_status_t School_find_by_id(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	element_type* print=(buffer->buf);
	int i=0,flag=0,id=0;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");
		DPRINTF("\nEnter id to be checked:");
		scanf("%d",&id);

		while(print != (buffer->back))
		{
			if(id == print->roll)
			{
				DPRINTF("\n------------------------------------------------------------------");
				DPRINTF("\n[INFO]...Roll %d is already exist",id);
				DPRINTF("\nRoll %d data :\n",id);
				DPRINTF("\n\nStudent Name>>>> %s",print->fname);
				DPRINTF(" %s",print->lname);
				DPRINTF("\nStudent GPA Number: %.2f",print->gpa);

				for(i=0;i<5;i++)
				{
					DPRINTF("\n[%d]Course ID is: %d",i+1,print->course_id[i]);
				}

				flag=1;
			}
			else
			{
			}

			print++;
		}

		if(flag == 0)
		{
			DPRINTF("\n------------------------------------------------------------------");
			DPRINTF("\n[ERORR]...Roll %d is not exist",id);
		}

		ret=R_OK;
	}
	return ret;
}


/*==========================================================================================*/


ret_status_t School_find_by_first_name(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	element_type* print=(buffer->buf);
	int i=0,flag=0;
	char text[15];

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\nEnter First name to be checked: ");
		gets(text);

		while(print != (buffer->back))
		{
			if(!(stricmp(text,print->fname)))
			{
				DPRINTF("\n===========================================================================");
				DPRINTF("\nStudent %s is already exist\n",text);
				DPRINTF("\n\nStudent Name>>>> %s",print->fname);
				DPRINTF(" %s",print->lname);
				DPRINTF("\nStudent Roll Number: %d",print->roll);
				DPRINTF("\nStudent GPA Number: %.2f",print->gpa);

				for(i=0;i<5;i++)
				{
					DPRINTF("\n[%d]Course ID is: %d",i+1,print->course_id[i]);
				}

				flag=1;
			}
			else
			{
			}

			print++;
		}

		if(flag == 0)
		{
			DPRINTF("\n------------------------------------------------------------------");
			DPRINTF("\nStudent %s is not exist\n",text);
		}

		ret=R_OK;
	}
	return ret;
}


/*==========================================================================================*/


ret_status_t School_How_many_students_in_course(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	element_type* print=(buffer->buf);
	int i=0,counter=0,course_id=0;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");
		DPRINTF("\nEnter course id to be checked:");
		scanf("%d",&course_id);

		while(print != (buffer->back))
		{

			for(i=0;i<5;i++)
			{
				if(course_id == print->course_id[i])
				{
					DPRINTF("\n------------------------------------------------------------------");
					DPRINTF("\n\nStudent Name>>>> %s",print->fname);
					DPRINTF(" %s",print->lname);
					DPRINTF("\nStudent Roll Number: %d",print->roll);
					DPRINTF("\nStudent GPA Number: %.2f",print->gpa);

					counter++;
					break;
				}
				else{
					//nothing
				}

			}

			print++;
		}

		if(counter == 0)
		{
			DPRINTF("\n------------------------------------------------------------------");
			DPRINTF("\n[ERORR]... course %d hasn't any number of students",course_id);
		}
		else{
			DPRINTF("\n------------------------------------------------------------------");
			DPRINTF("\n[INFO]... course %d has %d students",course_id,counter);
		}

		ret=R_OK;
	}
	return ret;
}

/*==========================================================================================*/


ret_status_t School_number_of_students(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front))
	{
		DPRINTF("Error!!....in accessing data\n");
		ret=R_NOK;
	}
	else
	{

		if(QUEUE_EMPTY==IS_EMPTY(buffer))
		{
			DPRINTF("\n===========================================================================");
			DPRINTF("\n [ERORR]...No students was added before...! ");
		}
		else
		{
			DPRINTF("\n===========================================================================");
			DPRINTF("\n[INFO] The total number of students is %d ",(buffer->count));
			DPRINTF("\n[INFO] You can add up to %d students\n",buffer->length);
			DPRINTF("[INFO] You can add %d more students\n",(buffer->length)-(buffer->count));
		}
		ret=R_OK;
	}
	return ret;
}

/*==========================================================================================*/


ret_status_t School_delete_student(fifo_buffer * buffer)
{
	ret_status_t ret=R_NOK;
	int id=0,flag=0;
	element_type* current = (buffer->base) ;
	element_type* next = current + 1;


	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");

		DPRINTF("\nEnter id to be deleted:");
		scanf("%d",&id);

		for (int i=0;i<(buffer->count);i++)
		{
			if(current->roll == id)
			{
				flag=1 ;
			}
			if(1 == flag)
			{
				*current = *next ;
			}

			if (current == (buffer->base + buffer->length - 1))
			{
				current = buffer->base;
			}
			else
			{
				current++;
			}
			if (next == (buffer->base + buffer->length - 1))
			{
				next = buffer->base;
			}
			else
			{
				next++;
			}
		}

		if (flag == 1)
		{
			DPRINTF("\n[INFO]...Student Deleted Successfully\n");
			(buffer->back)--;
			(buffer->count)--;
		}
		else
		{
			DPRINTF("\n[ERORR]...student ID [%d] NOT Found",id);
		}

		ret=R_OK;
	}
	return ret;
}

/*==========================================================================================*/


ret_status_t School_print_students(fifo_buffer * buffer)
{
	int i=0;
	element_type* print=(buffer->base);
	ret_status_t ret=R_NOK;

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");
		DPRINTF("\nPrinting all students:\n");

		while(print != (buffer->back))
		{
			DPRINTF("\n\nStudent Name>>>> %s",print->fname);
			DPRINTF(" %s",print->lname);
			DPRINTF("\nStudent Roll Number: %d",print->roll);
			DPRINTF("\nStudent GPA Number: %.2f",print->gpa);

			for(i=0;i<5;i++)
			{
				DPRINTF("\n[%d]Course ID is: %d",i+1,print->course_id[i]);
			}

			print++;
		}

		ret=R_OK;
	}
	return ret;
}


/*==========================================================================================*/


ret_status_t School_update_student(fifo_buffer * buffer)
{

	ret_status_t ret=R_NOK;
	element_type* print=(buffer->buf);
	int flag=0,id=0,selection=0,course_selection=0;
	char text[15];

	if(NULL==buffer||NULL==(buffer->base)||NULL==(buffer->back)||NULL==(buffer->front)||QUEUE_EMPTY==IS_EMPTY(buffer))
	{
		DPRINTF("[ERORR]...maybe the system has no any students\n");
		ret=R_NOK;
	}
	else
	{
		DPRINTF("\n===========================================================================");
		DPRINTF("\nEnter id to be updated:");
		scanf("%d",&id);

		while(print != (buffer->back))
		{
			if(id == print->roll)
			{
				DPRINTF("\nSelect which data want to be updated:");
				DPRINTF("\n1.Update first name");
				DPRINTF("\n2.Update last name");
				DPRINTF("\n3.Update roll number");
				DPRINTF("\n4.Update GPA number");
				DPRINTF("\n5.Update courses");

				DPRINTF("\nEnter your Selection: ");
				scanf("%d",&selection);

				switch(selection)
				{
				case 1:
					DPRINTF("\nEnter Student First Name: ");
					gets(print->fname);
					break;
				case 2:
					DPRINTF("\nEnter Student Last Name: ");
					gets(print->lname);
					break;
				case 3:
					DPRINTF("\nEnter Student Roll Number: ");
					gets(text);
					print->roll=atoi(text);
					break;
				case 4:
					DPRINTF("\nEnter Student GPA: ");
					gets(text);
					print->gpa=atof(text);
					break;
				case 5:
					DPRINTF("\nEnter Student courses ID (1 : 5) : ");
					scanf("%d",&course_selection);

					switch(course_selection)
					{
					case 1:
						DPRINTF("\nID [1]: ");
						gets(text);
						print->course_id[0]=atoi(text);
						break;
					case 2:
						DPRINTF("\nID [2]: ");
						gets(text);
						print->course_id[1]=atoi(text);
						break;
					case 3:
						DPRINTF("\nID [3]: ");
						gets(text);
						print->course_id[2]=atoi(text);
						break;
					case 4:
						DPRINTF("\nID [4]: ");
						gets(text);
						print->course_id[3]=atoi(text);
						break;
					case 5:
						DPRINTF("\nID [5]: ");
						gets(text);
						print->course_id[4]=atoi(text);
						break;
					default:
						DPRINTF("\n[ERORR]...your course_selection isn't Exist");
						break;
					}
					break;
					default:
						DPRINTF("\n[ERORR]...your Selection isn't Exist");
						break;
				}

				flag=1;

				DPRINTF("\n---------------------------------------------------------------------------");
				DPRINTF("\n[INFO]...Updating is Done Successfully\n");

			}
			else
			{
			}

			print++;
		}

		if(flag == 0)
		{
			DPRINTF("\n---------------------------------------------------------------------------");
			DPRINTF("\n[ERORR]...Roll %d is not exist",id);
		}

		ret=R_OK;
	}
	return ret;
}
