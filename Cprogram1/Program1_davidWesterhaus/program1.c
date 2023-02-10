/*
 * program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: d643w879
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float* read_file(int* num_floats){
	FILE *file = fopen("input.txt" , "r");
	
	//check if file has stuff in it
	if(file == NULL){
		printf("unable to open file...");
		exit(EXIT_FAILURE);
	}
	
	float* numbers_array;
	int i = 0;
	int capacity = 0;
	float f;
	//iterate through file
	while(fscanf(file, "%f", &f) == 1){
		if(i == capacity){
			capacity = capacity == 0 ? 1 : 2 * capacity;
			numbers_array = realloc(numbers_array, capacity * sizeof(float));
		}
		
		numbers_array[i++] = f;
	} 
	*num_floats = i;
	return numbers_array;
}

void sales_report(float* numbers, char** months){
	int i = 0;
	
	printf("Monthly Sales Report for 2022:\n");
	printf("-------------------------------\n\n");
	printf("MONTH\tSALES\n");

	for(i=0; i<12; i++){
		printf("%s\t", months[i]);
		printf("$%.2f\n", numbers[i]);
	}
	
}

void sales_sum(float* numbers, char** months){
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
	
	printf("Minimum sales:\t$%.2f\t(%s)\n", min, months[min_month]);
	printf("Maximum sales:\t$%.2f\t(%s)\n", max, months[max_month]);
	printf("Average sales:\t$%.2f\n" , avg);
}

void six_month(float* numbers, char** months){
	printf("Six-Month Moving Average Report:\n");

	for(int start_month = 0; start_month < 7; start_month++){
		float sum = numbers[start_month]+numbers[start_month+1]+numbers[start_month+2]+numbers[start_month+3]+numbers[start_month+4]+numbers[start_month+5];
		float avg = sum/6;
		//printf("%s\t-\t%s\t$%.2f", months[start_month], months[start_month+5], avg);
		printf("%s\t - \t%s\t", months[start_month], months[start_month+5]);
		printf("$%.2f\n", avg);
	}
}

void high_to_low(float* numbers, char** months){
	int i, j;
	float temp;
	char* temp_month;

	// sort array
	for(i=0; i < 12; i++){
		for(j=i+1; j<12; j++){
			if(numbers[j] > numbers[i]){
				temp = numbers[i];
				temp_month = months[i];
				numbers[i] = numbers[j];
				months[i] = months[j];
				numbers[j] = temp;
				months[j] = temp_month;
			}
		}
	}
	
	//print sorted array
	printf("\nSales Report (Highest to Lowest):\n");
	printf("MONTH\tSALES\n");
	for(i=0; i<sizeof(numbers); i++){
		printf("%s\t$%.2f\n", months[i], numbers[i]);
	}




	
}

int main(){
	int float_num = 12;
	float* numbers = read_file(&float_num);
	int i;
	char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	sales_report(numbers, months);
	printf("\n");
	sales_sum(numbers, months);
	printf("\n");
	six_month(numbers, months);
	high_to_low(numbers, months);
	printf("\n");



	return 0;


}

