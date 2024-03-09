#include <stdio.h>
#include <string.h>

void monthlySales(char month[][12], float sales[], FILE *fptr2);

void salesSummary(char month[][12], float sales[], FILE *fptr2);

void sixMonthReport(char month[][12], float sales[], FILE *fptr2);

void salesReportHighestToLowest(char month[][12], float sales[], FILE *fptr2);

int main(){

    float sales[12];
    char month[12][12] = {"January", "February", "March", 
                          "April", "May", "June", 
                          "July", "August", "September", 
                          "October", "November", "December"};

    FILE *fptr;
    fptr = fopen("input.tsv", "r");

    FILE *fptr2;
    fptr2 = fopen("output.tsv", "w");

    for(int i = 0; i < 12; i++){
        fscanf(fptr, "%f", &sales[i]);
    }

    monthlySales(month, sales, fptr2);
    fprintf(fptr2, "\n");
    salesSummary(month, sales, fptr2);
    fprintf(fptr2, "\n");
    sixMonthReport(month, sales, fptr2);
    fprintf(fptr2, "\n");
    salesReportHighestToLowest(month, sales, fptr2);

    fclose(fptr);
    fclose(fptr2);

    return 0;
}

void monthlySales(char month[][12], float sales[], FILE *fptr2){
    fprintf(fptr2, "Monthly sales report for 2022:\n");
    fprintf(fptr2, "Month       Sales\n");
    for (int i = 0; i < 12; i++){
        fprintf(fptr2, "%-12s$%-12.2f\n", month[i], sales[i]);
    }
}

void salesSummary(char month[][12], float sales[], FILE *fptr2){
    int minimumIndex;
    int maximumIndex;
    float minimumSale = 100000000000000.0000;
    float maximumSale = -10000000000000.000;
    float average = 0;
    for (int i = 0; i < 12; i++){
        if (minimumSale > sales[i]){
            minimumSale = sales[i];
            minimumIndex = i;
        }
        if (maximumSale < sales[i]){
            maximumSale = sales[i];
            maximumIndex = i;
        }
        average += sales[i];
    }
    average = average / 12.0;
    fprintf(fptr2, "Sales summary:\n");
    fprintf(fptr2, "Minimum sales:\t$%-12.2f\t(%s)\n", sales[minimumIndex], month[minimumIndex]);
    fprintf(fptr2, "Maximum sales:\t$%-12.2f\t(%s)\n", sales[maximumIndex], month[maximumIndex]);
    fprintf(fptr2, "Average sales:\t$%-12.2f\n", average);
}

void sixMonthReport(char month[][12], float sales[], FILE *fptr2){
    fprintf(fptr2, "Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++){
        float average = 0;
        for (int j = i; j < i+6; j++){
            average += sales[j];
        }
        average /= 6.0;
        fprintf(fptr2, "%-12s-  %-12s\t$%.2f\n", month[i], month[i+5], average);
    }
}

void salesReportHighestToLowest(char month[][12], float sales[], FILE *fptr2){
    fprintf(fptr2, "Sales Report (Highest to Lowest):\n");
    fprintf(fptr2, "Month\tSales\n");
    int sortedArrayIndexes[12] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    for (int z = 0; z < 11; z++){
        float maximumSale = 0;
        int monthIndex = -1;
        for(int i = 0; i < 12; i++){

            for (int j = 0; j < 12; j++){

                if (i == sortedArrayIndexes[j]){
                    goto continue2;
                } 

            } 
            if(maximumSale < sales[i]){

                maximumSale = sales[i];
                monthIndex = i;

            }
            continue2:;
        }
        sortedArrayIndexes[z] = monthIndex;
        fprintf(fptr2, "%-12s\t$%.2f\n", month[monthIndex], maximumSale);
    }

}
