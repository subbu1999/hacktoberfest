#include<stdio.h>

int isLeapYear(year){
  if(year%4==0){
    if(year%100==0){
      if(year%400){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      return 1;
    }
  }
  else{
    return 0;
  }
}

int numOfDaysInAMonth(int year, int month){
  if(month==0 || month==2 ||month==4 ||month==6 ||month==7 ||month==9 || month==11){
    return 31;
  }

  // Feb
  else if(month == 1){
    // Leapyear condition
    if(isLeapYear(year))
      return 29;
    else
      return 28;
  }
  else{
    return 30;
  }

}

int firstDayOfYear(int year){
  int fday;
  fday=(((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400)+1)%7;
  return fday;
}

int firstDayOfMonth(int year,int month){
  int num_days= 0;
  switch(month){
    case 11: num_days+=30;
    case 10: num_days+=31;
    case 9: num_days+=30;
    case 8: num_days+=31;
    case 7: num_days+=31;
    case 6: num_days+=30;
    case 5: num_days+=31;
    case 4: num_days+=30;
    case 3: num_days+=31;
    case 2: num_days+=28;
    case 1: num_days+=31;
  }
  if(month==0)
    return firstDayOfYear(year);
  else if(month==1)
    return (num_days+firstDayOfYear(year))%7;
  else{
    if(isLeapYear(year))
      return (num_days+1+firstDayOfYear(year))%7;
    else
      return (num_days+firstDayOfYear(year))%7;
  }

}

void printMonth(int year, int month){
  printf("\n");
  printf("-----------------------------");
  printf("\n");
  char *MonthName[12]={"January","February","March","April","May","June","June","August","September","October","November","December"};
  // Print Month Name
  printf("Month: %s",MonthName[month]);
  printf("\n");
  char *DayNames[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  for(int i=0;i<7;i++){
    printf("%s\t", DayNames[i]);
  }
  printf("\n");
  // printf("First Day of Month: %d",firstDayOfMonth(year,month));
  for(int i=0;i<firstDayOfMonth(year, month);i++){
    printf("\t");
  }

  int day = 1;
  int breakD=0;
  while(day<=numOfDaysInAMonth(year, month)){
    printf("%d\t",day);
 
    if(day == (7-firstDayOfMonth(year, month))){
      printf("\n"); 
      breakD=day;
    }
    else if(day%(breakD+7)==0){
      printf("\n");
      breakD=day;
    }
    day++;
  }
  
}

int main(void){
  int year;
  scanf("%d",&year);
  for(int i=0;i<12;i++)
    printMonth(year,i);
  return 0;
}
