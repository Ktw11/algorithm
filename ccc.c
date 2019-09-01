#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXLINE 100
#define MAXARGS 20
#define MAXHIST 200
char cmdline[MAXLINE];
char *argv[MAXARGS];
char *cwd;
char buff[MAXLINE+1];
int argc;
int status;
pid_t pid;
char his[MAXHIST][MAXHIST];
int tmp = 0;
int fd;

int redirect_check(){
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"<")==0){
            return 1;
        }
    }
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],">")==0){
            return 2;
        }
    }
    return 0;
}


int redirect(){
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],"<")==0){
            fd = open(argv[i+1],O_RDONLY);
            dup2(fd,0);
            close(fd);
        }
    }
    for(int i=0;i<argc;i++){
        if(strcmp(argv[i],">")==0){
            fd = open(argv[i+1],O_RDWR);
            dup2(fd,1);
            close(fd);
        }
    }
    execvp(argv[0],argv);
    return 0;
}

int parseline(char *cmdline, char **argv)
{
  int count = 0;
  char *separator = " \n\t";
  argv[count] = strtok(cmdline, separator);
  while ((argv[count] != NULL) && (count+1 < MAXARGS)) {
   argv[++count] = strtok(NULL, separator);
  }
  return count;
} // 문자 파싱

void hist(){
  for(int i=0;i<=tmp;i++){
        printf("%d : %s\n",i+1,his[i]);
  }
} // history 구현

void cd(){
    if(argc == 1){
        char *temp = getenv("HOME");
        chdir(temp);
    }
    else if(argc == 2){
        if(chdir(argv[1]) == -1){
            perror(argv[1]);
        }
    }
}

int main(void){
    while(1){
        char *a;
        fputs(" 2015038695_seungho$ ",stdout);
        fgets(cmdline, MAXLINE, stdin);
        argc = parseline(cmdline,argv);

        // for(int i=0;i<MAXHIST;i++){
        //         his[tmp][i] = cmdline[i];
        //     } // history 저장
        // printf("%s %s\n",cmdline,argv[1]);

        for(int i=0;i<strlen(cmdline);i++){
                his[tmp][i] = cmdline[i];
            } // history 저장
        int k =0;
        if(argv[1] != NULL){
            int j =0;
            his[tmp][strlen(cmdline)] = ' ';
            for(int i=strlen(cmdline)+1;i<strlen(argv[1])*2+1;i++){
                his[tmp][i] = argv[1][j++];
            } // history 저장
        }
        

        if(argc == 0) continue;

        else if(argc == 1 && strcmp(argv[0],"history") == 0){
            hist();
        }

        else if(strcmp(argv[0],"cd")==0){
            cd();
        }
        else if(argc==1 && strcmp(argv[0],"pwd")==0){
            cwd = getcwd(buff,256);
            printf("%s\n",cwd);
        }



        else{
            if((pid=fork())<0){
                perror("fork error");
            }
            else if(pid==0){
                execvp(argv[0],argv);
            }
            else{
                wait(&status);
            }
        }
        tmp++;
    }
}