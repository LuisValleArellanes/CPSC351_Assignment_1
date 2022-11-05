#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h> 
#include <string> 
using namespace std; 


int main(){

    FILE *locations = fopen("locations.txt", "r"); 
    float long1, lat1;
    int counter =0; 
    char buffer[1024];
    string fileprefix = "file"; 
    
    
  
    int parentpid = getpid(); 
    int parentuid = getuid(); 
    int parentgid = getgid();
    printf("///////////////////////////////////PARENT INFO/////////////////////////////////////////////\n"); 
    printf("Parent PID: %d\n", parentpid); 
    printf("Parent UID: %d\n", parentuid); 
    printf("Parent GID: %d\n", parentgid); 
    printf("//////////////////////////////////////////////////////////////////////////////////////////\n"); 


    if (locations == NULL){
        printf("unable to read file\n"); 
    }
    else{
        printf("File is Valid...\n"); 
    }

    while(!feof(locations)){ //read till end of file 
        //store longitude and latitude of each line 
        fscanf(locations, "%f", &lat1); 
        fscanf(locations, "%f", &long1); 

        counter++; 
        string filename = fileprefix + to_string(counter) + ".json"; 

        fprintf(stderr, "File Name: %s\n", filename.c_str());
        snprintf(buffer, 1024, "https://api.open-meteo.com/v1/forecast?latitude=%f&longitude=%f&current", lat1, long1); 
        printf("%s \n", buffer); 

        int pid = fork(); 


        if (pid == 0){ //check for child
            //curl weather url 
            int childpid = getpid(); 
            int childuid = getuid(); 
            int childgid = getgid();
            printf("///////////////////////////////////CHILD INFO/////////////////////////////////////////////\n"); 
            printf("Child PID: %d\n", childpid); 
            printf("Child UID: %d\n", childuid); 
            printf("Child GID: %d\n", childgid); 
            printf("//////////////////////////////////////////////////////////////////////////////////////////\n"); 

            execlp("/usr/bin/curl", "curl", "-o", filename.c_str(), buffer, NULL); 
            exit(1); 
        }else{
            //do parent stuff
            wait(NULL); 
        }



    }
    
    return 0; 
}