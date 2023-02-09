/*
 * program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: d643w879
 */
#include <stdio.h>
#include <stdlib.h>

float* read_file(){
	FILE *file_ptr;
	float numbers_array[12];
	char line[100];
	int i = 0;
	file_ptr = fopen("input.txt" , "r");
	
	while(fgets(line, 100, file_ptr)){
		numbers_array[i] = atof(line);
		i++;
	} return numbers_array;
}

void sales_report(float* numbers, char* months){
	int i = 0;
	
	printf("Monthly Sales Report for 2022:\n");
	printf("Month\tSales\n");
	printf("\n");
	for(i=0; i<12; i++){
		printf("months[i] \t numbers[i]");
	}
	
}

void sales_sum(float* numbers, char* months){
	int i = 0;
	float max = numbers[0];
	int max_month;				  
    float min = numbers[0];
    int min_month;
	printf("Sales Summary:\n");
	
	for(i=0; i<12; i++){
		if(numbers[i] > max){
			max = numbers[i];
			max_month = i;
		}}
	for(i=0; i<12; i++){
			if(numbers[i] < min){
				min = numbers[i];
				min_month = i;
			}}
	float sum = numbers[0]+numbers[1]+numbers[2]+numbers[3]+numbers[4]+numbers[5]+numbers[6]+numbers[7]+numbers[8]+numbers[9]+numbers[10]+numbers[11];
	float avg = sum/12;	
	
	printf("Minimum sales:\t%f\t%c\n", min, months[min_month]);
	printf("Maximum sales:\t%f\t%c\n", max, months[max_month]);
	printf("Average sales:\t%f" , avg);
}


int main(){
	float* numbers = read_file();
	char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	sales_report(numbers, months);

	return 0;


}

