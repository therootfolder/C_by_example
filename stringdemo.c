#include <stdio.h>
#include <string.h>

void concatenating();
void string_to_numeric();
void numeric_to_string();
void string_parser();
void string_length();
void string_copy();
void string_explore();


int main(int argc, const char* argv[]) {

    concatenating();
    string_to_numeric();
    numeric_to_string();
    string_parser();
    string_length();
    string_copy();
    string_explore();

    return 0;
}

void concatenating(){
    printf("====concatenating===\n");

    char str1[30] = "hello";
    char str2[10] = "wolrd";

    strcat(str1,str2);
    printf("result: %s\n",str1);

}

void string_to_numeric(){
    printf("====string_to_numeric===\n");
    char str1[10] = "10";
    char str2[10] = "28.74";

    int num1;
    float num2;

    sscanf(str1,"%d",&num1);
    sscanf(str2,"%f",&num2);

    printf("num1: %d\n",num1);
    printf("num2: %f\n",num2);

}

void numeric_to_string(){
    printf("====numeric_to_string===\n");
    int n = 10;
    float m = 23.78;

    char num1[10];
    char num2[10];

    sprintf(num1,"%d",n);
    sprintf(num2,"%.2f",m);

    printf("num1: %s\n",num1);
    printf("num2: %s\n",num2);

}

void string_parser(){
    char cities[40] = "Tokyo;Berlin;London;New York";
    char token[2]=";";
    char* city;

    printf("cities: %s\n",cities);

    city = strtok(cities, token);
    while(city != NULL){
        printf("%s\n", city );
        city = strtok(NULL, token);
    }

}

void string_length(){
    char str[20] = "Hello world";

    printf("str: %s\n",str);
    printf("length: %d\n",(int)strlen(str));

}

void string_copy(){
    char str[15] = "Hello world";
    char new_str[20];

    strcpy(new_str,str);
    printf("str: %s\n",str);
    printf("new_str: %s\n",new_str);

    memset(new_str, '\0', sizeof(new_str));
    strncpy(new_str,str,5);
    printf("strncpy-new_str: %s\n",new_str);

}

void string_explore(){
    char str[15] = "Hello world";
    int index;

    for(index=0;index<strlen(str);index++){
        printf("%c\n",str[index]);
    }

}
