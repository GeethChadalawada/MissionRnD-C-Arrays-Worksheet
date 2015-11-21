/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student 
{
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K)
{
	int i = 0, j = 0, tempscore = 0;
	char *tempname = (char*)malloc(sizeof(char) * 10);
	struct student **top;
	
	if (students == NULL || len <= 0 || K <= 0)
		return NULL;

	if (K > len)
		K = len;

	top = (struct student**)malloc(sizeof(struct student*) * K);

	for (i = 0; i < K; i++)
	{
		top[i] = (struct student *)malloc(sizeof(struct student));
	}

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (students[i].score > students[j].score)
			{
				tempname = students[i].name;
				tempscore = students[i].score;
				students[i].name = students[j].name;
				students[i].score = students[j].score;
				students[j].name = tempname;
				students[j].score = tempscore;
			}
		}
	}

	
	for (i = 0, j = len - K; i < K; i++)
	{
		(*top[i]).name = students[j].name;
		(*top[i]).score = students[j++].score;
	}

	return top;
}