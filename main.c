#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
int d=0;      //counter for dead pieces
int turn=0,end;   //TO DEFINE THE TURNS
 char DEAD[32];
 int finished=0;
#include "load.h"
void start(){
    printf("        ________    __        __    _________    _________   _________  \n");
    printf("       /   _____|  |  |      |  |  |   ______|  |   ______| |   ______| \n");
    printf("      /  /         |  |      |  |  |  |         |  |        |  | \n");
    printf("     *  *          |  |      |  |  |  |         |  |        |  |\n");
    printf("     |  |          |  |      |  |  |  |______   |  |_____   |  |_____   \n");
    printf("     |  |          |  |______|  |  |   ______|  |_____   |  |_____   |  \n");
    printf("     |  |          |   ______   |  |  |               |  |        |  | \n");
    printf("     *  *          |  |      |  |  |  |               |  |        |  |\n");
    printf("      \\  \\______   |  |      |  |  |  |______    _____|  |   _____|  | \n");
    printf("       \\________|  |__|      |__|  |_________|  |________|  |________| \n");
    printf("      _________________________________________________________________\n");
    printf("      _________________________________________________________________\n");
    return ;
}

void first_Initializing (char a[10][10]){
  int i,j;
  finished=0;
  for(i=0;i<10;i++){
        for(j=0;j<10;j++){
                a[i][j] = ' ';
        }}
        for(i=0;i<32;i++){
            DEAD[i]= ' ';
    }

         for(i=1;i<9;i++){
            a[2][i] = 'P';
        }
         for(i=1;i<9;i++){
            a[7][i] = 'p';
        }
        a[8][2] = a [8][7] = 'n';
         a[1][2] = a[1][7] = 'N';
         a[1][3] = a[1][6] = 'B';
         a[8][3]= a[8][6] = 'b';
         a[1][1] = a[1][8] = 'R';
         a[8][1] = a[8][8] = 'r';
        a[1][4] = 'Q'; a[1][5]='K';
        a[8][4] = 'q'; a[8][5] = 'k';
 }
void print_board(char a[10][10]){
    int i,j;
    int z=0,c;     //COUNTER TO PRINT THE DEAD PIECES
    system("@cls||clear");
    for(i=0;i<10;i++){
            // TO MAKE THE BOAED BIGGER  BY PRINTING A COLORED LINE BEFORE THE ARRAY LINE
            printf("\n");
            if(i!=0&&i!=9){
            printf("        ");
            for(c=0;c<9;c++){
                    if(c==0){printf("     ");}else{
                if((i+c)%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),127);printf("     ");}
                else if((i+c)%2==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);printf("     ");}
            }}SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            printf("\n");}else{printf("\n");}    //THE END OF MAKING THE BOARD BIGGER
        if(i!=0){         //TO START FROM THE SECOND LINE
        if(z<=32){        //TO PRINT THE DEAD PICES BEFORE THE BOARD
        printf("%c",DEAD[z]); printf("%c",DEAD[z+1]); printf("%c",DEAD[z+2]); printf("%c",DEAD[z+3]);        //PRINT 8ELEMENT FROM THE ARRAY
        printf("%c",DEAD[z+4]); printf("%c",DEAD[z+5]); printf("%c",DEAD[z+6]); printf("%c",DEAD[z+7]);      //OF THE DEAD PIECES
        }else{
         printf("        ");}}else{printf("        ");}
        for(j=0;j<10;j++){
            if((j==0||j==9)&&(i!=0&&i!=9)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);           //CHANGING THE COLOR
            a[1][0]=1;a[2][0]=2;a[3][0]=3;a[4][0]=4;a[5][0]=5;                     //SET THE NUMBERS TO LEFT AND RIGHT
            a[6][0]=6;a[7][0]=7;a[8][0]=8;
            a[1][9]=1;a[2][9]=2;a[3][9]=3;a[4][9]=4;a[5][9]=5;
            a[6][9]=6;a[7][9]=7;a[8][9]=8;
            printf("  %d  ",a[i][j]);
            }else if((i==0||i==9)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);           //CHANGING THE COLOR
            a[0][1]='A';a[0][2]='B';a[0][3]='C';a[0][4]='D';                       //SET THE CHARS TO LEFT AND RIGHT
            a[0][5]='E';a[0][6]='F';a[0][7]='G';a[0][8]='H';
            a[9][1]='A';a[9][2]='B';a[9][3]='C';a[9][4]='D';
            a[9][5]='E';a[9][6]='F';a[9][7]='G';a[9][8]='H';
            printf("  %c  ",a[i][j]);
            }
            else if((i+j)%2==0){
            if(isupper(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else if(islower(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),127);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),127);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            }else if(((i+j)%2!=0)){
            if(isupper(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),128);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else if(islower(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            }
        }if(i==1)printf("press(UNDO)to undo");
         if(i==2)printf("press(REDO)to redo");
         if(i==3)printf("press(SAVE)to save");
         if(i==4)printf("press(exit)to exit");
        if(i!=0&&i!=9){                       // TO MAKE THE BOAED BIGGER  BY PRINTING A COLORED LINE AFTER THE ARRAY LINE
        printf("\n");printf("        ");
            for(c=0;c<9;c++){
                    if(c==0){printf("     ");}else{
                if((i+c)%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),127);printf("     ");}
                else if((i+c)%2==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);printf("     ");}
            }}SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}else{printf("\n");}

        if(i!=0)z+=8;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);        //RETURNING THE DEFAILT COLOR
    }
}
void print_inred(char a[10][10]){
    int i,j;
    int z=0,c;     //COUNTER TO PRINT THE DEAD PIECES
    system("@cls||clear");
    for(i=0;i<10;i++){
            // TO MAKE THE BOAED BIGGER  BY PRINTING A COLORED LINE BEFORE THE ARRAY LINE
            printf("\n");
            if(i!=0&&i!=9){
            printf("        ");
            for(c=0;c<9;c++){
                    if(c==0){printf("     ");}else{
                if((i+c)%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);printf("     ");}
                else if((i+c)%2==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);printf("     ");}
            }}SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            printf("\n");}else{printf("\n");}    //THE END OF MAKING THE BOARD BIGGER
        if(i!=0){         //TO START FROM THE SECOND LINE
        if(z<=32){        //TO PRINT THE DEAD PICES BEFORE THE BOARD
        printf("%c",DEAD[z]); printf("%c",DEAD[z+1]); printf("%c",DEAD[z+2]); printf("%c",DEAD[z+3]);        //PRINT 8ELEMENT FROM THE ARRAY
        printf("%c",DEAD[z+4]); printf("%c",DEAD[z+5]); printf("%c",DEAD[z+6]); printf("%c",DEAD[z+7]);      //OF THE DEAD PIECES
        }else{
         printf("        ");}}else{printf("        ");}
        for(j=0;j<10;j++){
            if((j==0||j==9)&&(i!=0&&i!=9)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);           //CHANGING THE COLOR
            a[1][0]=1;a[2][0]=2;a[3][0]=3;a[4][0]=4;a[5][0]=5;                     //SET THE NUMBERS TO LEFT AND RIGHT
            a[6][0]=6;a[7][0]=7;a[8][0]=8;
            a[1][9]=1;a[2][9]=2;a[3][9]=3;a[4][9]=4;a[5][9]=5;
            a[6][9]=6;a[7][9]=7;a[8][9]=8;
            printf("  %d  ",a[i][j]);
            }else if((i==0||i==9)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);           //CHANGING THE COLOR
            a[0][1]='A';a[0][2]='B';a[0][3]='C';a[0][4]='D';                       //SET THE CHARS TO LEFT AND RIGHT
            a[0][5]='E';a[0][6]='F';a[0][7]='G';a[0][8]='H';
            a[9][1]='A';a[9][2]='B';a[9][3]='C';a[9][4]='D';
            a[9][5]='E';a[9][6]='F';a[9][7]='G';a[9][8]='H';
            printf("  %c  ",a[i][j]);
            }
            else if((i+j)%2==0){
            if(isupper(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else if(islower(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),251);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            }else if(((i+j)%2!=0)){
            if(isupper(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else if(islower(a[i][j])){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),203);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);      //CHANGING THE COLOR
            printf("  %c  ",a[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}        //RETURNING THE DEFAILT COLOR
            }
        }if(i!=0&&i!=9){                       // TO MAKE THE BOAED BIGGER  BY PRINTING A COLORED LINE AFTER THE ARRAY LINE
        printf("\n");printf("        ");
            for(c=0;c<9;c++){
                    if(c==0){printf("     ");}else{
                if((i+c)%2==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);printf("     ");}
                else if((i+c)%2==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);printf("     ");}
            }}SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}else{printf("\n");}

        if(i!=0)z+=8;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);        //RETURNING THE DEFAILT COLOR
    }
}
void read_move(char a[10][10],FILE *save,FILE *redo){
   if(finished) return;
    char c1,c2; char p;
    int r1,r2;
    if(turn%2==0){printf("\nplayer1(black):");}else{printf("\nplayer2(white):");}
     char r[6];
    fgets(r,6,stdin);
     c1=r[0]; c2=r[2];  p=r[4];
    r1=r[1]-48; r2=r[3]-48;
    // if(!isupper(p) && !islower(p)&& p != '\n') read_move(a,save,redo);
     if(p=='\n'){p='?';}
    if(c1=='e'){exit(0); ;}
    else if(c1=='S'){
        saving(a,save);
    }else if(c1=='U'){undo(a,save);
    }else if(c1=='R'){do_redo(a,save,redo);}
    if(c1>='A'&&c1<='H'&&c2>='A'&&c2<='H'&&r1>=1&&r1<=8&&r2>=1&&r2<=8){
    redo=fopen("text2.txt","w");
    fclose(redo);
       c1= r[0]-64; r1=r[1]-48; c2=r[2]-64; r2=r[3]-48;
       if((turn%2==0&&isupper(a[r1][c1]))||(turn%2==1&&islower(a[r1][c1]))){
        switch(a[r1][c1]){
          case('p'):  if(pawns(a,r1,c1,r2,c2)) moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('r'):  if(rooks(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case ('n'):  if( knight(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,save); read_move(a,save,redo); break;
          case('b'):    if( bishop(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('q'):  if(queen(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
        case('k'):  if(king(a,r1,c1,r2,c2))   moveing(a,r1,c1,r2,c2,save); read_move(a,save,redo); break;
          case('P'):  if(PAWNS(a,r1,c1,r2,c2)) moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('R'): if(ROOKS(a,r1,c1,r2,c2)) moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('N'):  if (KNIGHT(a,r1,c1,r2,c2)) moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('B'):   if(BISHOP(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          case('Q'):  if(QUEEN (a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
        case('K'):    if(KING(a,r1,c1,r2,c2))  moveing(a,r1,c1,r2,c2,p,save); read_move(a,save,redo); break;
          default: read_move(a,save,redo); break;
        }
       }else{printf("you cannot move this piece\n");
            read_move(a,save,redo);
       }
} else{
read_move(a,save,redo);
}}
void undo(char a[10][10],FILE *save,FILE *redo){
    char lastmoves[5000];
    int i=0;
    save=fopen("text1.txt","r");
    fgets(lastmoves,5000,save);     //TO COPY THE MOVES FILE TO ARRAY OF CHARS TO DELET THE LAST MOVE
    fclose(save);
    save=fopen("text1.txt","w");     //OPEN ON WRIGHT MODE TI DELET THE ALL MOVES SAVED IN THE FILE
    while(lastmoves[i+5]!='\0'){    //PUTING ALL MOVES IN THE FILE EXCEPT THE LAST MOVE
        fputc(lastmoves[i],save);
        i++;
    }
    fclose(save);
    redo=fopen("text2.txt","a");    //TO SAVE THE LAST UNDO MOVE IN A NEW FILE
    while(lastmoves[i]!='\0'){
        fputc(lastmoves[i],redo);
        i++;
    }
    fclose(redo);
    first_Initializing(a);
    load(a,save);        //TO LOAD THE GAME WITHOUT THE LAST MOVE
}
void do_redo(char a[10][10],FILE *save,FILE *redo){
    char c1,c2,p;
    int r1,r2;
    char lastundo[5000];    //last undo moves
    int i=0;
    int flag=1,test;
    redo=fopen("text2.txt","r");
    if((test=fgetc(redo))==(-1)){flag=0;}
    fclose(redo);
    if(flag){
    redo=fopen("text2.txt","r");
    fseek(redo,-5,SEEK_END);
    fscanf(redo,"%c%d%c%d%c",&c1,&r1,&c2,&r2,&p);    //TO GET THE LAST UNDO MOVE
    fclose(redo);
    make_move(a,r1,c1,r2,c2,p);             //MAKING THE LAST UNDO MOVE AGAIN
    redo=fopen("text2.txt","r");
    fgets(lastundo,5000,redo);               //REMOVEING THE LAST MOVE FROM THE FILE AFTER DO IT
    fclose(redo);                           //..
    redo=fopen("text2.txt","w");           //...
    while(lastundo[i+5]!='\0'){            //...
        fputc(lastundo[i],redo);          // ...
        i++;                              //...
    }
    fclose(redo);
    save=fopen("text1.txt","a");    //TO SAVE THE LAST UNDO MOVE
    while(lastundo[i]!='\0'){
        fputc(lastundo[i],save);
        i++;
    }
    fclose(save);}
    print_board(a);
    read_move(a,save,redo);
}
void saving(char a[10][10],FILE *save){
    FILE *save2;
    char lastmoves[5000];
    int i=0;
    save=fopen("text1.txt","r");
    fgets(lastmoves,5000,save);     //TO COPY THE MOVES FILE TO ARRAY OF CHARS TO DELET THE LAST MOVE
    fclose(save);
    save2=fopen("text3.txt","w");
    while(lastmoves[i]!='\0'){    //PUTING ALL MOVES IN THE FILE
        fputc(lastmoves[i],save2);
        i++;
    }
    fclose(save2);
}

int STALEMTE(char a[10][10]){
    int i,j;
    for(i=1;i<=8;i++){                  //checking if any piece can move
        for(j=1;j<=8;j++){
            if(isupper(a[i][j])){
                switch(a[i][j]){
                 case('P'): if(CHECK_P(a,i,j)){ return 0; } break;
                 case('R'): if(CHECK_R(a,i,j)){ return 0; } break;
                 case('N'): if(CHECK_N(a,i,j)){ return 0; } break;
                 case('B'): if(CHECK_B(a,i,j)){ return 0; } break;
                 case('Q'): if(CHECK_Q(a,i,j)){ return 0; } break;
                 case('K'): if(CHECK_K(a,i,j)){ return 0; } break;


        }
            }
        }
    }
    return 1;
}
int CHECK_P(char a[10][10],int r1,int c1){                 //check if the pawns can make any move
    if(PAWNS(a,r1,c1,r1+1,c1)&&r1+1<=8) { if(check_move(a,r1,c1,r1+1,c1)) { return 1; }}
    if(PAWNS(a,r1,c1,r1+1,c1+1)&&r1+1<=8&&c1+1<=8) { if(check_move(a,r1,c1,r1+1,c1+1)) { return 1; }}
    if(PAWNS(a,r1,c1,r1+1,c1-1)&&r1+1<=8&&c1-1>=1) { if(check_move(a,r1,c1,r1+1,c1-1)) { return 1; }}
    return 0;
}
int CHECK_R(char a[10][10],int r1,int c1){         //check if the rook can make any move
    if(ROOKS(a,r1,c1,r1+1,c1)&&(r1+1<=8&&r1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1)) { return 1; }}
    if(ROOKS(a,r1,c1,r1-1,c1)&&(r1-1<=8&&r1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1)) { return 1; }}
    if(ROOKS(a,r1,c1,r1,c1+1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1,c1+1)) { return 1; }}
    if(ROOKS(a,r1,c1,r1,c1-1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1,c1-1)) { return 1; }}
    return 0;
}
int CHECK_B(char a[10][10],int r1,int c1){         //check if the bishop can make any move
    if(BISHOP(a,r1,c1,r1+1,c1+1)&&(r1+1<=8&&r1+1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1+1)) { return 1; }}
    if(BISHOP(a,r1,c1,r1-1,c1-1)&&(r1-1<=8&&r1-1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1-1)) { return 1; }}
    if(BISHOP(a,r1,c1,r1-1,c1+1)&&(r1-1<=8&&r1-1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-1,c1+1)) { return 1; }}
    if(BISHOP(a,r1,c1,r1+1,c1-1)&&(r1+1<=8&&r1+1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+1,c1-1)) { return 1; }}
    return 0;
}
int CHECK_Q(char a[10][10],int r1,int c1){                //check if the queen can make any move
    if(CHECK_B(a,r1,c1)||CHECK_R(a,r1,c1)){return 1;}
    return 0;
}
int CHECK_N(char a[10][10],int r1,int c1){           //check if the knight can make any move
     if(KNIGHT(a,r1,c1,r1+2,c1+1)&&(r1+2<=8&&r1+2>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+2,c1+1)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1+2,c1-1)&&(r1+2<=8&&r1+2>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+2,c1-1)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1-2,c1+1)&&(r1-2<=8&&r1-2>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-2,c1+1)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1-2,c1-1)&&(r1-2<=8&&r1-2>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-2,c1-1)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1+1,c1+2)&&(r1+1<=8&&r1+1>=1)&&(c1+2<=8&&c1+2>=1)) { if(check_move(a,r1,c1,r1+1,c1+2)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1+1,c1-2)&&(r1+1<=8&&r1+1>=1)&&(c1-2<=8&&c1-2>=1)) { if(check_move(a,r1,c1,r1+1,c1-2)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1-1,c1+2)&&(r1-1<=8&&r1-1>=1)&&(c1+2<=8&&c1+2>=1)) { if(check_move(a,r1,c1,r1-1,c1+2)) { return 1; }}
     if(KNIGHT(a,r1,c1,r1-1,c1-2)&&(r1-1<=8&&r1-1>=1)&&(c1-2<=8&&c1-2>=1)) { if(check_move(a,r1,c1,r1-1,c1-2)) { return 1; }}
     return 0;
}
int CHECK_K(char a[10][10],int r1,int c1){   //check if the king can make any move
     if(KING(a,r1,c1,r1+1,c1+1)&&(r1+1<=8&&r1+1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1+1)) { return 1; }}
     if(KING(a,r1,c1,r1-1,c1-1)&&(r1-1<=8&&r1-1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1-1)) { return 1; }}
     if(KING(a,r1,c1,r1+1,c1-1)&&(r1+1<=8&&r1+1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+1,c1-1)) { return 1; }}
     if(KING(a,r1,c1,r1-1,c1+1)&&(r1-1<=8&&r1-1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-1,c1+1)) { return 1; }}
     if(KING(a,r1,c1,r1+1,c1)&&(r1+1<=8&&r1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1)) { return 1; }}
     if(KING(a,r1,c1,r1-1,c1)&&(r1-1<=8&&r1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1)) { return 1; }}
     if(KING(a,r1,c1,r1,c1-1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1,c1-1)) { return 1; }}
     if(KING(a,r1,c1,r1,c1+1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1,c1+1)) { return 1; }}
     return 0;
}

int stalemte(char a[10][10]){
    int i,j;
    for(i=1;i<=8;i++){                  //checking if any piece can move
        for(j=1;j<=8;j++){
            if(islower(a[i][j])){
                switch(a[i][j]){
                 case('p'): if(check_p(a,i,j)){ return 0; } break;
                 case('r'): if(check_r(a,i,j)){ return 0; } break;
                 case('n'): if(check_n(a,i,j)){ return 0; } break;
                 case('b'): if(check_b(a,i,j)){ return 0; } break;
                 case('q'): if(check_q(a,i,j)){ return 0; } break;
                 case('k'): if(check_k(a,i,j)){ return 0; } break;


        }
            }
        }
    }
    return 1;
}

int check_p(char a[10][10],int r1,int c1){                 //check if the pawns can make any move
    if(pawns(a,r1,c1,r1-1,c1)&&r1-1>=1) { if(check_move(a,r1,c1,r1-1,c1)) { return 1; }}
    if(pawns(a,r1,c1,r1-1,c1+1)&&r1-1>=1&&c1+1<=8) { if(check_move(a,r1,c1,r1-1,c1+1)) { return 1; }}
    if(pawns(a,r1,c1,r1-1,c1-1)&&r1-1>=1&&c1-1>=1) { if(check_move(a,r1,c1,r1-1,c1-1)) { return 1; }}
    return 0;
}
int check_r(char a[10][10],int r1,int c1){         //check if the rook can make any move
    if(rooks(a,r1,c1,r1+1,c1)&&(r1+1<=8&&r1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1)) { return 1; }}
    if(rooks(a,r1,c1,r1-1,c1)&&(r1-1<=8&&r1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1)) { return 1; }}
    if(rooks(a,r1,c1,r1,c1+1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1,c1+1)) { return 1; }}
    if(rooks(a,r1,c1,r1,c1-1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1,c1-1)) { return 1; }}
    return 0;
}
int check_b(char a[10][10],int r1,int c1){         //check if the bishop can make any move
    if(bishop(a,r1,c1,r1+1,c1+1)&&(r1+1<=8&&r1+1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1+1)) { return 1; }}
    if(bishop(a,r1,c1,r1-1,c1-1)&&(r1-1<=8&&r1-1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1-1)) { return 1; }}
    if(bishop(a,r1,c1,r1-1,c1+1)&&(r1-1<=8&&r1-1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-1,c1+1)) { return 1; }}
    if(bishop(a,r1,c1,r1+1,c1-1)&&(r1+1<=8&&r1+1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+1,c1-1)) { return 1; }}
    return 0;
}
int check_q(char a[10][10],int r1,int c1){                //check if the queen can make any move
    if(check_b(a,r1,c1)||check_r(a,r1,c1)){return 1;}
    return 0;
}
int check_n(char a[10][10],int r1,int c1){           //check if the knight can make any move
     if(knight(a,r1,c1,r1+2,c1+1)&&(r1+2<=8&&r1+2>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+2,c1+1)) { return 1; }}
     if(knight(a,r1,c1,r1+2,c1-1)&&(r1+2<=8&&r1+2>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+2,c1-1)) { return 1; }}
     if(knight(a,r1,c1,r1-2,c1+1)&&(r1-2<=8&&r1-2>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-2,c1+1)) { return 1; }}
     if(knight(a,r1,c1,r1-2,c1-1)&&(r1-2<=8&&r1-2>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-2,c1-1)) { return 1; }}
     if(knight(a,r1,c1,r1+1,c1+2)&&(r1+1<=8&&r1+1>=1)&&(c1+2<=8&&c1+2>=1)) { if(check_move(a,r1,c1,r1+1,c1+2)) { return 1; }}
     if(knight(a,r1,c1,r1+1,c1-2)&&(r1+1<=8&&r1+1>=1)&&(c1-2<=8&&c1-2>=1)) { if(check_move(a,r1,c1,r1+1,c1-2)) { return 1; }}
     if(knight(a,r1,c1,r1-1,c1+2)&&(r1-1<=8&&r1-1>=1)&&(c1+2<=8&&c1+2>=1)) { if(check_move(a,r1,c1,r1-1,c1+2)) { return 1; }}
     if(knight(a,r1,c1,r1-1,c1-2)&&(r1-1<=8&&r1-1>=1)&&(c1-2<=8&&c1-2>=1)) { if(check_move(a,r1,c1,r1-1,c1-2)) { return 1; }}
     return 0;
}
int check_k(char a[10][10],int r1,int c1){   //check if the king can make any move
     if(king(a,r1,c1,r1+1,c1+1)&&(r1+1<=8&&r1+1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1+1)) { return 1; }}
     if(king(a,r1,c1,r1-1,c1-1)&&(r1-1<=8&&r1-1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1-1)) { return 1; }}
     if(king(a,r1,c1,r1+1,c1-1)&&(r1+1<=8&&r1+1>=1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1+1,c1-1)) { return 1; }}
     if(king(a,r1,c1,r1-1,c1+1)&&(r1-1<=8&&r1-1>=1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1-1,c1+1)) { return 1; }}
     if(king(a,r1,c1,r1+1,c1)&&(r1+1<=8&&r1+1>=1)) { if(check_move(a,r1,c1,r1+1,c1)) { return 1; }}
     if(king(a,r1,c1,r1-1,c1)&&(r1-1<=8&&r1-1>=1)) { if(check_move(a,r1,c1,r1-1,c1)) { return 1; }}
     if(king(a,r1,c1,r1,c1-1)&&(c1-1<=8&&c1-1>=1)) { if(check_move(a,r1,c1,r1,c1-1)) { return 1; }}
     if(king(a,r1,c1,r1,c1+1)&&(c1+1<=8&&c1+1>=1)) { if(check_move(a,r1,c1,r1,c1+1)) { return 1; }}
     return 0;
}

int  CHECK  (char a[10][10]){                        //FIND POSITION OF THE KING
       int i,j,r2,c2; int flag =1;
       for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]== 'K') {
              r2=i; c2=j;  break; }}}

    for(i= 1; i< 9;i++){
                                        //check all the squares under king
         if(r2+i>8 )break;
         if(isupper(a[r2+i][c2])) break;
         if(islower(a[r2+i][c2])) {
            if (a[r2+i][c2] != 'r' && a[r2+i][c2] != 'q' ) break;
             flag =0;
         }
    }
    for(i= 1; i< 9;i++){                                    //check all squares above king
         if(r2-i<0 )break;
         if(isupper(a[r2-i][c2])) break;
         if(islower(a[r2-i][c2])) {
            if (a[r2-i][c2] != 'r' && a[r2-i][c2] != 'q' )  break;
             flag =0;
         }
    }
     for(i= 1; i< 9;i++){
         if(c2+i>8 )break;                   //check all squares right king
       if(isupper(a[r2][c2+i])) break;
         if(islower(a[r2][c2+i])) {
            if (a[r2][c2+i] != 'r' && a[r2][c2+i] != 'q' ) break;
             flag =0;
         }
    }
    for(i= 1; i<9;i++){
         if(c2-i<0 )break;                                //check all squares left king
          if(isupper(a[r2][c2-i])) break;
         if(islower(a[r2][c2-i])) {
            if (a[r2][c2-i] != 'r' && a[r2][c2-i] != 'q' )  break;
             flag =0;
         }
    }


    for(i=1;i<9;i++){                           //check the way 1
        if((r2+i)>8 || (c2+i)>8) break;
        if(isupper(a[r2+i][c2+i])) break;
        if(islower(a[r2+i][c2+i])) {
        if(a[r2+i][c2+i] != 'b' && a[r2+i][c2+i] != 'q') break;
         flag =0;
        }
    }
        for(i=1;i<9;i++){                           //check the way 2
        if((r2-i)<1 || (c2-i)<1) break;
         if(isupper(a[r2-i][c2-i])) break;
        if(islower(a[r2-i][c2-i])) {
        if(a[r2-i][c2-i] != 'b' && a[r2-i][c2-i] != 'q') break;
         flag =0;}}

    for(i=1;i<9;i++){                           //check the way 3

        if((r2+i)>8 || (c2-i)<1) break;
        if(isupper(a[r2+i][c2-i])) break;
        if(islower(a[r2+i][c2-i])) {
        if(a[r2+i][c2-i] != 'b' && a[r2+i][c2-i] != 'q') break;
         flag =0; }}

        for(i=1;i<9;i++){                           //check the way 4
        if((r2-i) <1 || (c2+i)>8) break;
        if(isupper(a[r2-i][c2+i])) break;
        if(islower(a[r2-i][c2+i])) {
        if(a[r2-i][c2+i] != 'b' && a[r2-i][c2+i] != 'q') break;
         flag =0;}}

       if(a[r2+1][c2+1] == 'p' || a[r2+1][c2-1] == 'p' || a[r2+1][c2+1] == 'k' || a[r2+1][c2-1] == 'k'  ) {   flag=0; }
     if(a[r2+1][c2+2] == 'n' || a[r2+1][c2-2] == 'n' || a[r2-1][c2+2] == 'n' || a[r2-1][c2-2] == 'n'  )    {   flag=0; }
     if(a[r2+2][c2+1] == 'n' || a[r2+2][c2-1] == 'n' || a[r2-2][c2+1] == 'n' || a[r2-2][c2-1] == 'n' )     {   flag=0; }
     if(a[r2-1][c2+1]== 'k' || a[r2-1][c2-1]== 'k' || a[r2-1][c2]== 'k' || a[r2+1][c2]== 'k' || a[r2][c2+1]== 'k' || a[r2][c2-1]== 'k' ) flag=0;

                return flag;
   }

int check_move (char a[10][10],int r1,int c1,int r2,int c2){
     int flag =1; int flag2=0; char temp;
       if(a[r2][c2] != ' ')  {temp=a[r2][c2]; flag2=1;}
            a[r2][c2]= a[r1][c1];
            a[r1][c1]= ' ';

            if((turn%2 == 1) && !(CHECK(a)) )  {
                flag=0;
                }
            else if((turn%2 == 0) && !(check(a))){
                flag=0;
                }
    a[r1][c1]=a[r2][c2];
    a[r2][c2]=' ';
    if(flag2){a[r2][c2]=temp;}
    return flag;

}

int CHECKMATE_2(char a[10][10],int kr,int kc,int r2,int c2){
    int i,j;
    for(i=1;i<9;i++){
        for(j=1;j<9;j++){
            if(isupper(a[i][j])){
                switch(a[i][j]){
                 case('P'): if(PAWNS(a,i,j,r2,c2)) { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('R'): if(ROOKS(a,i,j,r2,c2))  { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('N'): if(KNIGHT(a,i,j,r2,c2)) { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('B'): if(BISHOP(a,i,j,r2,c2))   { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('Q'): if(QUEEN(a,i,j,r2,c2))  { if(check_move(a,i,j,r2,c2)) { return 1; }} break;

        }
            }
        }
    }
    return 0;
}


void CHECKMATE(char a[10][10],FILE *save,FILE *redo){
         int i,j,r2,c2; int flag =1; int fcheck=0;
       for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]== 'K') {
              r2=i; c2=j;  break; }}}

    for(i= 1; i< 9;i++){
                                        //check all the squares under king
         if(r2+i>8 )break;
         if(isupper(a[r2+i][c2])) break;
         if(islower(a[r2+i][c2])) {
            if (a[r2+i][c2] != 'r' && a[r2+i][c2] != 'q') break;
             flag =0; break;
         }
    }
       if(!flag) {
       for(j=1;j<=i;j++){                         //send all square betwen r and k
         if(CHECKMATE_2(a,r2,c2,r2+j,c2)) fcheck=1;
       }} flag=1;

    for(i= 1; i< 9;i++){                                    //check all squares above king
         if(r2-i<0 )break;
         if(isupper(a[r2-i][c2])) break;
         if(islower(a[r2-i][c2])) {
            if (a[r2-i][c2] != 'r' && a[r2-i][c2] != 'q' )  break;
             flag =0; break;
         }
    }
    if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(CHECKMATE_2(a,r2,c2,r2-j,c2)) fcheck=1;
    } } flag=1;

     for(i= 1; i< 9;i++){
                                                    //check all squares right king
         if(c2+i>8 )break;
       if(isupper(a[r2][c2+i])) break;
         if(islower(a[r2][c2+i])) {
            if (a[r2][c2+i] != 'r' && a[r2][c2+i] != 'q' ) break;
             flag =0; break;
         }
    }
     if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(CHECKMATE_2(a,r2,c2,r2,c2+j)) fcheck=1;
    } } flag=1;


    for(i= 1; i<9;i++){
            if(c2-i<1 )break;
           if(isupper(a[r2][c2-i])) break;                                 //check all squares left king
         if(islower(a[r2][c2-i])) {
            if (a[r2][c2-i] != 'r' && a[r2][c2-i] != 'q' )  break;
             flag =0; break;
         }
    }

      if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(CHECKMATE_2(a,r2,c2,r2,c2-j)) fcheck=1;
    } } flag=1;


    for(i=1;i<9;i++){                           //check the way 1
        if((r2+i)>8 || (c2+i)>8) break;
        if(isupper(a[r2+i][c2+i])) break;
        if(islower(a[r2+i][c2+i])) {
        if(a[r2+i][c2+i] != 'b' && a[r2+i][c2+i] != 'q') break;
         flag =0; break;
        }
    }
     if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(CHECKMATE_2(a,r2,c2,r2+j,c2+j)) fcheck=1;
    } } flag=1;


        for(i=1;i<9;i++){                           //check the way 2
        if((r2-i)<1 || (c2-i)<1) break;
         if(isupper(a[r2-i][c2-i])) break;
        if(islower(a[r2-i][c2-i])) {
        if(a[r2-i][c2-i] != 'b' && a[r2-i][c2-i] != 'q') break;
        flag =0; break;  }}

         if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(CHECKMATE_2(a,r2,c2,r2-j,c2-j)) fcheck=1;
    } } flag=1;


    for(i=1;i<9;i++){                           //check the way 3
          if((r2+i)>8 || (c2-i)<1) break;
          if(isupper(a[r2+i][c2-i])) break;
        if(islower(a[r2+i][c2-i])) {
        if(a[r2+i][c2-i] != 'b' && a[r2+i][c2-i] != 'q') break;
           flag =0; break;
         }}
           if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(CHECKMATE_2(a,r2,c2,r2+j,c2-j)) fcheck=1;
    } } flag=1;



        for(i=1;i<9;i++){                           //check the way 4
         if(isupper(a[r2-i][c2+i])) break;
        if((r2-i) <1 || (c2+i)>8) break;
        if(islower(a[r2-i][c2+i])) {
        if(a[r2-i][c2+i] != 'b' && a[r2-i][c2+i] != 'q') break;
          flag =0; break;
        }}
              if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(CHECKMATE_2(a,r2,c2,r2-j,c2+j)) fcheck=1;
    } } flag=1;


     if(a[r2+1][c2+1] == 'p' ) { if(CHECKMATE_2(a,r2,c2,r2+1,c2+1))  fcheck=1;}
     if(a[r2+1][c2-1] == 'p')   { if(CHECKMATE_2(a,r2,c2,r2+1,c2-1)) fcheck=1 ;}
     if(a[r2+1][c2+2] == 'n')    {  if(CHECKMATE_2(a,r2,c2,r2+1,c2+2))  fcheck=1; }
     if( a[r2+1][c2-2] == 'n')  { if(CHECKMATE_2 (a,r2,c2,r2+1,c2-2))  fcheck=1;}
     if(a[r2-1][c2+2] == 'n')    { if(CHECKMATE_2 (a,r2,c2,r2-1,c2+2))  fcheck=1;}
     if(a[r2-1][c2-2] == 'n')  { if(CHECKMATE_2 (a,r2,c2,r2-1,c2-2))  fcheck=1;}
     if(a[r2+2][c2-1] == 'n')  {  if(CHECKMATE_2(a,r2,c2,r2+2,c2-1))  fcheck=1;}
     if(a[r2-2][c2+1] == 'n') { if(CHECKMATE_2(a,r2,c2,r2-2,c2+1))  fcheck=1;}
     if(a[r2-2][c2-1] == 'n') {  if(CHECKMATE_2(a,r2,c2,r2-2,c2-1))  fcheck=1;}
     if(a[r2+2][c2+1] == 'n')   {  if(CHECKMATE_2(a,r2,c2,r2+2,c2+1))  fcheck=1; }

        int fking=0;
             if(KING(a,r2,c2,r2+1,c2+1) &&(r2+1<9) &&(c2+1<9 )){ if(check_move(a,r2,c2,r2+1,c2+1)) fking= 1;}
        if(KING(a,r2,c2,r2-1,c2-1) &&(r2-1>0) &&(c2-1>0)) {  if(check_move(a,r2,c2,r2-1,c2-1)) fking= 1;}
         if(KING(a,r2,c2,r2-1,c2+1) &&(r2-1>0)&&(c2+1<9))  { if(check_move(a,r2,c2,r2-1,c2+1)) fking= 1;}
          if(KING(a,r2,c2,r2+1,c2-1)&&(r2+1<9)&&(c2-1>0))  {if(check_move(a,r2,c2,r2+1,c2-1)) fking= 1;}
           if(KING(a,r2,c2,r2+1,c2)&&(r2+1<9)) { if(check_move(a,r2,c2,r2+1,c2))  fking= 1;}
           if(KING(a,r2,c2,r2-1,c2)&&(r2-1>0)) { if(check_move(a,r2,c2,r2-1,c2))  fking= 1;}
          if(KING(a,r2,c2,r2,c2+1)&&(c2+1<9)) { if(check_move(a,r2,c2,r2,c2+1)) fking= 1;}
          if(KING(a,r2,c2,r2,c2-1) &&(c2-1>0)) { if(check_move(a,r2,c2,r2,c2-1)) fking= 1;}



        if(fcheck || fking) {printf("it is not check mate\n");}
        else{ printf("it is check mate player 2 win\n"); print_inred(a); finished=1; end=2; read_move(a,save,redo); }

   }

int checkmate_2(char a[10][10],int kr,int kc,int r2,int c2){
    int i,j;


    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            if(islower(a[i][j])){
                switch(a[i][j]){
                 case('p'): if(pawns(a,i,j,r2,c2)) { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('r'): if(rooks(a,i,j,r2,c2))  { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('n'): if(knight(a,i,j,r2,c2)) { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('b'): if(bishop(a,i,j,r2,c2))   { if(check_move(a,i,j,r2,c2)) { return 1; }} break;
                 case('q'): if(queen(a,i,j,r2,c2))  { if(check_move(a,i,j,r2,c2)) { return 1; }} break;

        }
            }
        }
    }
    return 0;
}


 void checkmate(char a[10][10],FILE *save,FILE *redo){
         int i,j,r2,c2; int flag =1; int fcheck=0;
       for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]== 'k') {
              r2=i; c2=j;  break; }}}

    for(i= 1; i< 9;i++){
                                        //check all the squares under king
         if(r2+i>8 )break;
         if(islower(a[r2+i][c2])) break;
         if(isupper(a[r2+i][c2])) {
            if (a[r2+i][c2] != 'R' && a[r2+i][c2] != 'Q') break;
            flag =0; break;
         }
    }
       if(!flag) {
       for(j=1;j<=i;j++){                         //send all square betwen r and k
         if(checkmate_2(a,r2,c2,r2+j,c2)) fcheck=1;
       }} flag=1;

    for(i= 1; i< 9;i++){                                    //check all squares above king
         if(r2-i<1 )break;
         if(islower(a[r2-i][c2])) break;
         if(isupper(a[r2-i][c2])) {
            if (a[r2-i][c2] != 'R' && a[r2-i][c2] != 'Q' )  break;
             flag =0; break;
         }
    }
    if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(checkmate_2(a,r2,c2,r2-j,c2)) fcheck=1;
    } } flag=1;

     for(i= 1; i< 9;i++){
                                                    //check all squares right king
         if(c2+i>8 )break;
       if(islower(a[r2][c2+i])) break;
         if(isupper(a[r2][c2+i])) {
            if (a[r2][c2+i] != 'R' && a[r2][c2+i] != 'Q' ) break;
             flag =0; break;
         }
    }
     if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(checkmate_2(a,r2,c2,r2,c2+j)) fcheck=1;
    } } flag=1;


    for(i=1; i<9;i++){
         if(c2-i<1 )break;
           if(islower(a[r2][c2-i])) break;                                 //check all squares left king
         if(isupper(a[r2][c2-i])) {
            if (a[r2][c2-i] != 'R' && a[r2][c2-i] != 'Q' )  break;
            flag =0; break;
         }
    }

      if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen r and k
        if(checkmate_2(a,r2,c2,r2,c2-j)) fcheck=1;
    } } flag=1;


    for(i=1;i<9;i++){                           //check the way 1
        if((r2+i)>8 || (c2+i)>8) break;
        if(islower(a[r2+i][c2+i])) break;
        if(isupper(a[r2+i][c2+i])) {
        if(a[r2+i][c2+i] != 'B' && a[r2+i][c2+i] != 'Q') break;
         flag =0; break;
        }
    }
     if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(checkmate_2(a,r2,c2,r2+j,c2+j)) fcheck=1;
    } } flag=1;


        for(i=1;i<9;i++){                           //check the way 2
         if(islower(a[r2-i][c2-i])) break;
        if((r2-i)<1 || (c2-i)<1) break;
        if(isupper(a[r2-i][c2-i])) {
        if(a[r2-i][c2-i] != 'B' && a[r2-i][c2-i] != 'Q') break;
           flag =0; break;  }}

         if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(checkmate_2(a,r2,c2,r2-j,c2-j)) fcheck=1;
    } } flag=1;


    for(i=1;i<9;i++){                           //check the way 3
          if(islower(a[r2+i][c2-i])) break;
        if((r2+i)>8 || (c2-i)<1) break;
        if(isupper(a[r2+i][c2-i])) {
        if(a[r2+i][c2-i] != 'B' && a[r2+i][c2-i] != 'Q') break;
             flag =0; break;
         }}
           if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(checkmate_2(a,r2,c2,r2+j,c2-j)) fcheck=1;
    } } flag=1;



         for(i=1;i<9;i++){                           //check the way 4
        if((r2-i) <1 || (c2+i)>8) break;
        if(islower(a[r2-i][c2+i])) break;
        if(isupper(a[r2-i][c2+i])) {
        if(a[r2-i][c2+i] != 'B' && a[r2-i][c2+i] != 'Q') break;
         flag =0; break; }}
              if(!flag){
    for(j=1;j<=i;j++){                                  //send all square betwen b/q and k
        if(checkmate_2(a,r2,c2,r2-j,c2+j)) fcheck=1;
    } } flag=1;


       if(a[r2-1][c2+1] == 'P' ) { if(checkmate_2(a,r2,c2,r2-1,c2+1))  fcheck=1;}
       if(a[r2-1][c2-1] == 'P')   { if(checkmate_2(a,r2,c2,r2-1,c2-1)) fcheck=1 ;}
     if(a[r2+1][c2+2] == 'N')    {  if(checkmate_2(a,r2,c2,r2+1,c2+2))  fcheck=1; }
     if( a[r2+1][c2-2] == 'N')  { if(checkmate_2 (a,r2,c2,r2+1,c2-2))  fcheck=1;}
     if(a[r2-1][c2+2] == 'N')    { if(checkmate_2 (a,r2,c2,r2-1,c2+2))  fcheck=1;}
     if(a[r2-1][c2-2] == 'N')  { if(checkmate_2 (a,r2,c2,r2-1,c2-2))  fcheck=1;}
     if(a[r2+2][c2-1] == 'N')  {  if(checkmate_2(a,r2,c2,r2+2,c2-1))  fcheck=1;}
     if(a[r2-2][c2+1] == 'N') { if(checkmate_2(a,r2,c2,r2-2,c2+1))  fcheck=1;}
     if(a[r2-2][c2-1] == 'N') {  if(checkmate_2(a,r2,c2,r2-2,c2-1))  fcheck=1;}
     if(a[r2+2][c2+1] == 'N')   {  if(checkmate_2(a,r2,c2,r2+2,c2+1))  fcheck=1; }


        int fking=0;
        if(king(a,r2,c2,r2+1,c2+1) &&(r2+1<9) &&(c2+1<9 )){ if(check_move(a,r2,c2,r2+1,c2+1)) fking= 1;}
        if(king(a,r2,c2,r2-1,c2-1) &&(r2-1>0) &&(c2-1>0)) {  if(check_move(a,r2,c2,r2-1,c2-1)) fking= 1;}
        if(king(a,r2,c2,r2-1,c2+1) &&(r2-1>0)&&(c2+1<9))  { if(check_move(a,r2,c2,r2-1,c2+1)) fking= 1;}
        if(king(a,r2,c2,r2+1,c2-1)&&(r2+1<9)&&(c2-1>0))  {if(check_move(a,r2,c2,r2+1,c2-1)) fking= 1;}
        if(king(a,r2,c2,r2+1,c2)&&(r2+1<9)) { if(check_move(a,r2,c2,r2+1,c2))  fking= 1;}
        if(king(a,r2,c2,r2-1,c2)&&(r2-1>0)) { if(check_move(a,r2,c2,r2-1,c2))  fking= 1;}
        if(king(a,r2,c2,r2,c2+1)&&(c2+1<9)) { if(check_move(a,r2,c2,r2,c2+1)) fking= 1;}
        if(king(a,r2,c2,r2,c2-1) &&(c2-1>0)) { if(check_move(a,r2,c2,r2,c2-1)) fking= 1;}



        if(fcheck || fking) {printf("it is not check mate\n");}
        else{ printf("it is check mate player 2 win\n"); print_inred(a); finished=1; end =1; read_move(a,save,redo); }
   }

int check (char a[10][10]){
         int i,j,r2,c2; int flag =1;
       for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]== 'k') {                         //find r &c of king
              r2=i; c2=j;  break; }}}

    for(i= 1; i< 9;i++){                                //check all the squares under king
         if(r2+i>8 )break;
         if(islower(a[r2+i][c2])) break;
         if(isupper(a[r2+i][c2])) {
            if (a[r2+i][c2] != 'R' && a[r2+i][c2] != 'Q' ) break;
             flag =0;
         }
    }
    for(i= 1; i< 9;i++){                                    //check all squares above king
         if(r2-i<1 )break;
         if(islower(a[r2-i][c2])) break;
         if(isupper(a[r2-i][c2])) {
            if (a[r2-i][c2] != 'R' && a[r2-i][c2] != 'Q' )  break;
            flag =0;
         }
    }
     for(i= 1; i< 9;i++){                                       //check all squares right king
         if(c2+i>8 )break;
         if(islower(a[r2][c2+i])) break;
         if(isupper(a[r2][c2+i])) {
            if (a[r2][c2+i] != 'R' && a[r2][c2+i] != 'Q' ) break;
             flag =0;
         }
    }
    for(i= 1; i< 9;i++){                                    //check all squares left king
         if(c2-i<0 )break;
         if(islower(a[r2][c2-i])) break;
         if(isupper(a[r2][c2-i])) {
            if (a[r2][c2-i] != 'R' && a[r2][c2-i] != 'Q' )  break;
             flag =0;
         }
    }


    for(i=1;i<9;i++){                           //check the way 1
        if((r2+i)>8 || (c2+i)>8) break;
         if(islower(a[r2+i][c2+i])) break;
        if(isupper(a[r2+i][c2+i])) {
        if(a[r2+i][c2+i] != 'B' && a[r2+i][c2+i] != 'Q') break;
         flag =0;
        }
    }
        for(i=1;i<9;i++){                           //check the way 2
        if((r2-i)<1 || (c2-i)<1) break;
       if(islower(a[r2-i][c2-i])) break;
        if(isupper(a[r2-i][c2-i])) {
        if(a[r2-i][c2-i] != 'B' && a[r2-i][c2-i] != 'Q') break;
         flag =0;}}

    for(i=1;i<9;i++){                           //check the way 3
        if((r2+i)>8 || (c2-i)<1) break;
        if(islower(a[r2+i][c2-i])) break;
        if(isupper(a[r2+i][c2-i])) {
        if(a[r2+i][c2-i] != 'B' && a[r2+i][c2-i] != 'Q') break;
         flag =0; }}

        for(i=1;i<9;i++){                           //check the way 4
        if((r2-i) <1 || (c2+i)>8) break;
        if(islower(a[r2-i][c2+i])) break;
        if(isupper(a[r2-i][c2+i])) {
        if(a[r2-i][c2+i] != 'B' && a[r2-i][c2+i] != 'Q') break;
         flag =0;}}


       if(a[r2-1][c2+1] == 'P' || a[r2-1][c2-1] == 'P' || a[r2-1][c2+1] == 'K' || a[r2-1][c2-1] == 'K'  ) {   flag=0; }
     if(a[r2+1][c2+2] == 'N' || a[r2+1][c2-2] == 'N' || a[r2-1][c2+2] == 'N' || a[r2-1][c2-2] == 'N'  )    {   flag=0; }
     if(a[r2+2][c2+1] == 'N' || a[r2+2][c2-1] == 'N' || a[r2-2][c2+1] == 'N' || a[r2-2][c2-1] == 'N' )     {   flag=0; }
     if(a[r2+1][c2+1]== 'K' || a[r2-1][c2]== 'K' || a[r2+1][c2]== 'K' || a[r2+1][c2-1]== 'K' || a[r2][c2+1]== 'K' || a[r2][c2-1]== 'K' ) flag=0;

                return flag;
   }

int PAWNS(char a[10][10],int r1,int c1,int r2,int c2){
         int flag=0;
         if(r1==2){         //CHECKING IF THE SOLDIER DIDNOT MOVE BEFORE
            if((((r2-r1)==1||(r2-r1)==2)&&c1==c2)&&a[r2][c2]==' '){  //AT THE BEGINNING IT MOVES ONLY ONE OR TWO STEPS
                flag=1;
            }else if(((r2-r1)==1&&(abs(c2-c1)==1))&&(islower(a[r2][c2]))){ //IT COULD MOVE TO EAT ONE OF THE ENEMY PIECES
                flag=1;
            }else{}
         }else if(r1!=2){
            if(((r2-r1)==1&&c1==c2)&&a[r2][c2]==' '){   //IT CAN MOVE ONLY ONE STEP IF NOTHING IN FRONT OF IT
                flag=1;
            }else if(((r2-r1)==1&&(abs(c2-c1)==1))&&(islower(a[r2][c2]))){
                flag=1;
            }else{}   //ANY THING ELSE IT WOULDNOT MOVE
         }

         return flag;
}

int pawns (char a[10][10],int r1,int c1,int r2,int c2){
         int flag=0;
         if(r1==7){         //CHECKING IF THE SOLDIER DIDNOT MOVE BEFORE
            if((((r1-r2)==1||(r1-r2)==2)&&c1==c2)&&a[r2][c2]==' '){  //AT THE BEGINNING IT MOVES ONLY ONE OR TWO STEPS
                flag=1;
            }else if(((r1-r2)==1&&(abs(c1-c2)==1))&&(isupper(a[r2][c2]))){ //IT COULD MOVE TO EAT ONE OF THE ENEMY PIECES
                flag=1;
            }else{}
         }else if(r1!=7){
            if(((r1-r2)==1&&c2==c1)&&a[r2][c2]==' '){   //IT CAN MOVE ONLY ONE STEP IF NOTHING IN FRONT OF IT
                flag=1;
            }else if(((r1-r2)==1&&(abs(c1-c2)==1)&&(isupper(a[r2][c2])))){
                flag=1;
            }else{}   //ANY THING ELSE IT WOULDNOT MOVE
         }
         return flag;
}

int rooks (char a[10][10],int r1,int c1,int r2,int c2){
    int i,j,flag; j=0; flag =0;
   if (!(islower((a[r2][c2]))) && (!((r1!=r2 && c1 != c2) || (c1== c2 && r1 == r2)))) {  //CHECK THER IS NO OF HIS ITEM IN THE POS2
       flag =1;
    if(r1==r2 && c1<c2 ){                                                       //CHECK IT ILL MOVE VERTICAL OR HORIZI
        for(i=c1+1;i<c2;i++){
            if((a[r1][i]) != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }
    }

        if(r1==r2 && c2<c1 ){                                                       //CHECK IT ILL MOVE VERTICAL OR HORIZI
        for(i=c2+1;i<c1;i++){
            if((a[r1][i]) != ' ') { flag = 0; break; }                    //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
       }
    }

    if(c1==c2 && r1<r2){
            for(i=r1+1;i<r2;i++){
            if((a[i][c2]) != ' ') {flag = 0; break; }
            flag = 1;
        }
    }
       if(c1==c2 && r1>r2){
            for(i=r2+1;i<r1;i++){
            if((a[i][c2]) != ' ') { flag = 0; break; }
            flag = 1;
        }}}     return flag;  }


int  ROOKS (char a[10][10],int r1,int c1,int r2,int c2){

    int i,j,flag; j=0; flag =0;
   if (!(isupper((a[r2][c2]))) && (!((r1!=r2 && c1 != c2) || (c1== c2 && r1 == r2)))) {  //CHECK THER IS NO OF HIS ITEM IN THE POS2
       flag =1;
    if(r1==r2 && c1<c2 ){                                                       //CHECK IT ILL MOVE VERTICAL OR HORIZI
        for(i=c1+1;i<c2;i++){
            if((a[r1][i]) != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }
    }

        if(r1==r2 && c2<c1 ){                                                       //CHECK IT ILL MOVE VERTICAL OR HORIZI
        for(i=c2+1;i<c1;i++){
            if((a[r1][i]) != ' ') { flag = 0; break; }                    //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
       }
    }

    if(c1==c2 && r1<r2){
            for(i=r1+1;i<r2;i++){
            if((a[i][c2]) != ' ') {flag = 0; break; }
            flag = 1;
        }
    }
       if(c1==c2 && r1>r2){
            for(i=r2+1;i<r1;i++){
            if((a[i][c2]) != ' ') { flag = 0; break; }
            flag = 1;
        }}}     return flag;  }


int KNIGHT (char a[10][10],int r1,int c1,int r2,int c2){
     int flag =0;
    if((abs(r2-r1)==2&&abs(c2-c1)==1&&a[r2][c2]==' ')||(abs(r2-r1)==1&&abs(c2-c1)==2&&a[r2][c2]==' ')){
              flag =1;
     }else if((abs(r2-r1)==2&&abs(c2-c1)==1&&islower(a[r2][c2]))||(abs(r2-r1)==1&&abs(c2-c1)==2&&islower(a[r2][c2]))){
             flag =1;
    } return flag;

}

int knight (char a[10][10],int r1,int c1,int r2,int c2){
    int flag =0;
    if((abs(r2-r1)==2&&abs(c2-c1)==1&&a[r2][c2]==' ')||(abs(r2-r1)==1&&abs(c2-c1)==2&&a[r2][c2]==' ')){
              flag =1;
     }else if((abs(r2-r1)==2&&abs(c2-c1)==1&&isupper(a[r2][c2]))||(abs(r2-r1)==1&&abs(c2-c1)==2&&isupper(a[r2][c2]))){
             flag =1;
    } return flag;

}

int BISHOP(char a[10][10],int r1,int c1,int r2,int c2){
      int i,j; int flag =0;
      if (!(isupper(a[r2][c2])) && (!(abs(r2-r1) != abs(c2-c1)))) {
            flag =1;
    if((r2>r1)&&(c2>c1)){                                               //1
        for(i=1;i<(c2-c1);i++){
            if(a[r1+i][c1+i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}

    if((r2<r1)&&(c2<c1)){                                           //2
          for(i=1;i<(c1-c2);i++){
            if(a[r1-i][c1-i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}
          if((r2>r1)&&(c2<c1)){                                     //3
              for(i=1;i<(c1-c2);i++){
            if(a[r1+i][c1-i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             } }
            if((r2<r1)&&(c2>c1)){                                       //4
                  for(i=1;i<(c2-c1);i++){
            if(a[r1-i][c1+i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}} return flag;

          }


int bishop (char a[10][10],int r1,int c1,int r2,int c2){


       int i,j; int flag =0;
      if (!(islower(a[r2][c2])) && (!(abs(r2-r1) != abs(c2-c1)))) {
            flag =1;
    if((r2>r1)&&(c2>c1)){                                               //1
        for(i=1;i<(c2-c1);i++){
            if(a[r1+i][c1+i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}

    if((r2<r1)&&(c2<c1)){                                           //2
          for(i=1;i<(c1-c2);i++){
            if(a[r1-i][c1-i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}
          if((r2>r1)&&(c2<c1)){                                     //3
              for(i=1;i<(c1-c2);i++){
            if(a[r1+i][c1-i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             } }
            if((r2<r1)&&(c2>c1)){                                       //4
                  for(i=1;i<(c2-c1);i++){
            if(a[r1-i][c1+i] != ' ') { flag = 0; break; }                   //CHECK ALL VERTICAL SQUARE EMPTY
            flag = 1;
             }}} return flag;

          }

int QUEEN (char a[10][10],int r1,int c1,int r2,int c2) {
        int flag =0;
        if(ROOKS(a,r1,c1,r2,c2)|| BISHOP(a,r1,c1,r2,c2)) flag =1;
          return flag;
       }

int queen (char a[10][10],int r1,int c1,int r2,int c2) {
        int flag =0;
        if(rooks(a,r1,c1,r2,c2)|| bishop(a,r1,c1,r2,c2)) flag =1;
          return flag;
       }

int KING(char a[10][10],int r1,int c1,int r2,int c2){
    int flag=0;
    if(((abs(r1-r2)==1&&abs(c1-c2)==1)||(abs(r1-r2)==1&&abs(c1-c2)==0)||(abs(r1-r2)==0&&abs(c1-c2)==1))&&a[r2][c2]==' '){
        flag=1;
    }else if(((abs(r1-r2)==1&&abs(c1-c2)==1)||((abs(r1-r2)==1&&abs(c1-c2)==0))||((abs(r1-r2)==0&&abs(c1-c2)==1)))&&islower(a[r2][c2])){
             flag=1;
    }else if(r1==1 &&c1==5 &&r2==1 && c2== 7 && a[1][8]=='R' && a[1][6] ==' ' && a[1][7] == ' '){
        flag=1;}
    return flag;
}
int king(char a[10][10],int r1,int c1,int r2,int c2){
    int flag=0;
    if(((abs(r1-r2)==1&&abs(c1-c2)==1)||(abs(r1-r2)==1&&abs(c1-c2)==0)||(abs(r1-r2)==0&&abs(c1-c2)==1))&&a[r2][c2]==' '){
        flag=1;
    }else if(((abs(r1-r2)==1&&abs(c1-c2)==1)||((abs(r1-r2)==1&&abs(c1-c2)==0))||((abs(r1-r2)==0&&abs(c1-c2)==1)))&&isupper(a[r2][c2])){
             flag=1;
    } else if(r1== 8 && c1== 5 &&r2==8 &&c2==7 && a[8][6] ==' ' && a[8][7]==' '&& a[8][8]=='r' ){ flag=1;}
    return flag;
}


void moveing (char a[10][10],int r1,int c1,int r2,int c2,char p,FILE *save,FILE *redo){
     int flag =0; int flag2=0; int flag3=0; int flag4=0;                  // flags  1 for check promotion 2 to check if it take piece 3 to CASTLE 4 to castle
      if((a[r1][c1]=='P'&&r2==8&&(p=='Q'||p=='R'||p=='N'||p=='B'))){a[r1][c1]=p; flag =1; }
        else if((a[r1][c1]=='p'&&r2==1&&(p=='q'||p=='r'||p=='n'||p=='b'))){a[r1][c1]=p; flag=1;}
        else if(a[r1][c1]=='K' &&r1==1 &&c1==5 &&r2==1 && c2== 7 && a[1][8]=='R' && a[1][6] ==' ' && a[1][7] == ' '){ flag3=1;}
        else if(a[r1][c1]== 'k' && r1== 8 && c1== 5 &&r2==8 &&c2==7 && a[8][6] ==' ' && a[8][7]==' '&& a[8][8]=='r' ){
                flag4=1;}

       if(a[r2][c2] != ' ')  {DEAD[d++]= a[r2][c2]; flag2=1; Beep(550, 100);}      //if piece taken put it in DEAD array
            a[r2][c2]= a[r1][c1];                                  //do move to test it
            a[r1][c1]= ' ';
            if(flag3) {  a[1][8]=' '; a[1][6]='R'; }                // do castle
            if(flag4){ a[8][8]= ' '; a[8][6]='r';  }              // do castle
 else if(turn%2==0 && check(a) ) {if(stalemte(a)) { print_board(a); finished=1; end=0; read_move(a,save,redo);  }}
            if(turn%2==1 && !CHECK(a)) { CHECKMATE(a,save,redo); }
else if(turn%2==1 && CHECK(a) ) {if(STALEMTE(a)) { print_board(a);  finished=1; end=0; read_move(a,save,redo);  }}
            if(turn%2 == 0 && !check(a)) { checkmate(a,save,redo); }
            if((turn%2 == 0) && !(CHECK(a)) )  {                            // undo the move case making  his king in danger
                printf("the king in danger\n");
                if(flag) {
                    a[r1][c1]='P';
                    a[r2][c2]=' ';
                    if(flag2) {a[r2][c2] =DEAD[--d]; DEAD[d++] =' ';}           //back the taken piece
                    read_move(a,save,redo);
                } else if(flag3){ a[1][8]='R'; a[1][6]=' '; a[1][5]='K'; a[1][7]=' ';  print_inred(a);  read_move(a,save,redo); }
                else{
                a[r1][c1]= a[r2][c2];
                a[r2][c2]=' ';
               if(flag2) {a[r2][c2] =DEAD[--d]; DEAD[d++] =' ';}
           print_inred(a);   read_move(a,save,redo);}
            } else if((turn%2 == 1) && !(check(a))){
             printf("the king in danger\n");
               if(flag) {
                    a[r1][c1]='p';
                    a[r2][c2]=' ';
                    if(flag2) {a[r2][c2] =DEAD[--d]; DEAD[d++] =' ';}
              print_inred(a);  read_move(a,save,redo);
                } else if(flag4){ a[8][8]='r';a[8][6]=' '; a[8][5]='k';a[8][7]=' ';  print_inred(a);  read_move(a,save,redo); }
                else{
                a[r1][c1]= a[r2][c2];
                a[r2][c2]=' ';
            if(flag2) {a[r2][c2] =DEAD[--d]; DEAD[d++] =' ';}
       print_inred(a);  read_move(a,save,redo);}
           } else{
            turn++;
            c1=c1+64;
            c2=c2+64;
            save=fopen("text1.txt","a");
            fprintf(save,"%c%d%c%d%c",c1,r1,c2,r2,p);
            fclose(save);
       if((!CHECK(a))|| (!check(a))) { Beep(8000, 400); printf("the king in danger\n");  print_inred(a);}
       else  {  print_board(a);}
             }

  }
int main()
{
    start();
    char n;
    FILE *save;
    FILE *redo;  //TO SAVE THE UNDO MOVES
    FILE *save2;
    char a[10][10];
    while(n!=4 ){
    printf("\n\n");
    printf("\t\t\t 1.Start a new game.\n");
    printf("\t\t\t 2.Start the last game.\n");
    printf("\t\t\t 3.Start the last saved game.\n");
    printf("\t\t\t 4.Exit.\n");
    scanf("%c",&n);
    n=n-48;
    first_Initializing(a);
     if(n==1){
        save=fopen("text1.txt","w");
        fclose(save);
        finished=0;
        printf("\n\n\n");
        print_board(a); do {
        read_move(a,save,redo);} while(finished !=1); print_inred(a);
    }else if(n==2){
        load(a,save);
        finished=0;
    }else if(n==3){
        load2(a,save,save2);
        finished=0;
    }if(n==1||n==2||n==3){
            print_inred(a);
        if(end == 0) {printf("it is stalemate the game finished draw\n"); turn=0; Beep(7000,1000);  }
     else if(end==1) { printf("player 1 wins \n"); turn=0;}
     else if(end ==2) printf("player 2 wins \n");
    }
    }


    return 0;
}
