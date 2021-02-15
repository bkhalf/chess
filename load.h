void load(char a[10][10],FILE *save){
    turn=0; d=0;
    int j=0;
        char c1,c2,p;
        int r1,r2,flag;
        save=fopen("text1.txt","r");
        while((flag=fgetc(save))!=(-1)){
        fseek(save, j, SEEK_SET);
            fscanf(save,"%c%d%c%d%c",&c1,&r1,&c2,&r2,&p);
            make_move(a,r1,c1,r2,c2,p);
        j+=5;
    }
    fclose(save);
    print_board(a);
    read_move(a,save);
} void load2(char a[10][10],FILE *save,FILE *save2){
    turn=0; d=0;
    int j=0;
    char lastmoves[5000];
    int i=0;
        char c1,c2,p;
        int r1,r2,flag;
        save2=fopen("text3.txt","r");
        while((flag=fgetc(save2))!=(-1)){
        fseek(save2, j, SEEK_SET);
            fscanf(save2,"%c%d%c%d%c",&c1,&r1,&c2,&r2,&p);
            make_move(a,r1,c1,r2,c2,p);
        j+=5;
    }
    fclose(save2);
    save2=fopen("text3.txt","r");
    fgets(lastmoves,5000,save2);     //TO COPY THE MOVES FILE TO ARRAY OF CHARS TO DELET THE LAST MOVE
    fclose(save2);
    save=fopen("text1.txt","w");
    while(lastmoves[i]!='\0'){    //PUTING ALL MOVES IN THE FILE EXCEPT THE LAST MOVE
        fputc(lastmoves[i],save);
        i++;
    }
    fclose(save);
    print_board(a);
    read_move(a,save);
}

int castle=0; int CASTLE=0;

void make_move(char a[10][10],int r1,char c1,int r2,char c2,char p){

    if(c1>='A'&&c1<='H'&&c2>='A'&&c2<='H'&&r1>=1&&r1<=8&&r2>=1&&r2<=8){
       c1=c1-64;
       c2=c2-64;

        switch(a[r1][c1]){
          case('p'):  lpawns(a,r1,c1,r2,c2,p); break;
          case('r'):  if(lrooks(a,r1,c1,r2,c2)) Lmoveing(a,r1,c1,r2,c2);  break;
          case ('n'): lknight(a,r1,c1,r2,c2); break;
          case('b'):  if(lbishop(a,r1,c1,r2,c2))  Lmoveing(a,r1,c1,r2,c2); break;
          case('q'):  if(lqueen(a,r1,c1,r2,c2))   Lmoveing(a,r1,c1,r2,c2); break;
          case('k'):  if(lking(a,r1,c1,r2,c2))    Lmoveing(a,r1,c1,r2,c2); break;
          case('P'): LPAWNS(a,r1,c1,r2,c2,p); break;
          case('R'): if(LROOKS(a,r1,c1,r2,c2))   Lmoveing(a,r1,c1,r2,c2);  break;
          case('N'): LKNIGHT(a,r1,c1,r2,c2); break;
          case('B'): if(LBISHOP(a,r1,c1,r2,c2))  Lmoveing(a,r1,c1,r2,c2); break;
          case('Q'): if(LQUEEN(a,r1,c1,r2,c2))   Lmoveing(a,r1,c1,r2,c2); break;
          case('K'): if(LKING(a,r1,c1,r2,c2))  Lmoveing(a,r1,c1,r2,c2); break;

        }
}
  }

  int LKING(char a[10][10],int r1,int c1,int r2,int c2,FILE *save,FILE *redo){
    int flag=0;
    if(((abs(r1-r2)==1&&abs(c1-c2)==1)||(abs(r1-r2)==1&&abs(c1-c2)==0)||(abs(r1-r2)==0&&abs(c1-c2)==1))&&a[r2][c2]==' '){
        flag=1;
    }else if(((abs(r1-r2)==1&&abs(c1-c2)==1)||((abs(r1-r2)==1&&abs(c1-c2)==0))||((abs(r1-r2)==0&&abs(c1-c2)==1)))&&islower(a[r2][c2])){
             flag=1;
    } else if(r1==1 &&c1==5 &&r2==1 && c2== 7 && a[1][8]=='R' && a[1][6] ==' ' && a[1][7] == ' '){
    CASTLE=1;    flag=1;}
    return flag;
}
int lking(char a[10][10],int r1,int c1,int r2,int c2,FILE *save,FILE *redo){
    int flag=0;
    if(((abs(r1-r2)==1&&abs(c1-c2)==1)||(abs(r1-r2)==1&&abs(c1-c2)==0)||(abs(r1-r2)==0&&abs(c1-c2)==1))&&a[r2][c2]==' '){
        flag=1;
    }else if(((abs(r1-r2)==1&&abs(c1-c2)==1)||((abs(r1-r2)==1&&abs(c1-c2)==0))||((abs(r1-r2)==0&&abs(c1-c2)==1)))&&isupper(a[r2][c2])){
             flag=1;
    } else if(r1== 8 && c1== 5 &&r2==8 &&c2==7 && a[8][6] ==' ' && a[8][7]==' '&& a[8][8]=='r' ){ flag=1; castle=1;}
    return flag;
}

void LPAWNS (char a[10][10],int r1,int c1,int r2,int c2, char p){
         if(r1==2){         //CHECKING IF THE SOLDIER DIDNOT MOVE BEFORE
            if((((r2-r1)==1||(r2-r1)==2)&&c1==c2)&&a[r2][c2]==' '){  //AT THE BEGINNING IT MOVES ONLY ONE OR TWO STEPS
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];                                //IF NOTHING IN FRONT OF IT
                a[r1][c1] = ' ';
                turn++;
            }else if((r2-r1)==1&&(abs(c2-c1)==1)&&(islower(a[r2][c2]))){ //IT COULD MOVE TO EAT ONE OF THE ENEMY PIECES
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
            }
         }else if(r1!=2){
            if(((r2-r1)==1&&c1==c2)&&a[r2][c2]==' '){   //IT CAN MOVE ONLY ONE STEP IF NOTHING IN FRONT OF IT
               if(r2 != 8){
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
                }
                else {
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = p;
                a[r1][c1] = ' ';
                turn++;
                }

            }else if((r2-r1)==1&&(abs(c2-c1)==1)&&(islower(a[r2][c2]))){
               if(r2 != 8){
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
                }
                else {
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = p;
                a[r1][c1] = ' ';
                turn++;
                }

            }  //ANY THING ELSE IT WOULDNOT MOVE
         }
}

void lpawns (char a[10][10],int r1,int c1,int r2,int c2,char p){
         if(r1==7){         //CHECKING IF THE SOLDIER DIDNOT MOVE BEFORE
            if((((r1-r2)==1||(r1-r2)==2)&&c1==c2)&&a[r2][c2]==' '){  //AT THE BEGINNING IT MOVES ONLY ONE OR TWO STEPS
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];                                //IF NOTHING IN FRONT OF IT
                a[r1][c1] = ' ';
                turn++;
            }else if((r1-r2)==1&&(abs(c1-c2)==1)&&(isupper(a[r2][c2]))){ //IT COULD MOVE TO EAT ONE OF THE ENEMY PIECES
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
            }
         }else if(r1!=7){
            if(((r1-r2)==1&&c2==c1)&&a[r2][c2]==' '){   //IT CAN MOVE ONLY ONE STEP IF NOTHING IN FRONT OF IT
                 if(r2 != 1){
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
                }
                else {
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = p;
                a[r1][c1] = ' ';
                turn++;
                }
            }else if((r1-r2)==1&&(abs(c1-c2)==1)&&(isupper(a[r2][c2]))){
               if(r2 != 1){
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = a[r1][c1];
                a[r1][c1] = ' ';
                turn++;
                }
                else {
                if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
                a[r2][c2] = p;
                a[r1][c1] = ' ';
                turn++;
                }

            }   //ANY THING ELSE IT WOULDNOT MOVE
         }

}
void LKNIGHT (char a[10][10],int r1,int c1,int r2,int c2){
    if((abs(r2-r1)==2&&abs(c2-c1)==1&&a[r2][c2]==' ')||(abs(r2-r1)==1&&abs(c2-c1)==2&&a[r2][c2]==' ')){
        if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
        a[r2][c2] = a[r1][c1];
        a[r1][c1] = ' ';
        turn++;
    }else if((abs(r2-r1)==2&&abs(c2-c1)==1&&islower(a[r2][c2]))||(abs(r2-r1)==1&&abs(c2-c1)==2&&islower(a[r2][c2]))){
        if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
        a[r2][c2] = a[r1][c1];
        a[r1][c1] = ' ';
        turn++;
    }
}

void lknight (char a[10][10],int r1,int c1,int r2,int c2){
    if((abs(r2-r1)==2&&abs(c2-c1)==1&&a[r2][c2]==' ')||(abs(r2-r1)==1&&abs(c2-c1)==2&&a[r2][c2]==' ')){
        if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
        a[r2][c2] = a[r1][c1];
        a[r1][c1] = ' ';
        turn++;
    }else if((abs(r2-r1)==2&&abs(c2-c1)==1&&isupper(a[r2][c2]))||(abs(r2-r1)==1&&abs(c2-c1)==2&&isupper(a[r2][c2]))){
        if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
        a[r2][c2] = a[r1][c1];
        a[r1][c1] = ' ';
        turn++;
    }

}

 int lrooks (char a[10][10],int r1,int c1,int r2,int c2){
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

int  LROOKS (char a[10][10],int r1,int c1,int r2,int c2){

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
int LBISHOP(char a[10][10],int r1,int c1,int r2,int c2){
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

 int lbishop (char a[10][10],int r1,int c1,int r2,int c2){
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

int LQUEEN (char a[10][10],int r1,int c1,int r2,int c2) {
        int flag =0;
        if(LROOKS(a,r1,c1,r2,c2)|| LBISHOP(a,r1,c1,r2,c2)) flag =1;
          return flag;
       }

int lqueen (char a[10][10],int r1,int c1,int r2,int c2) {
        int flag =0;
        if(lrooks(a,r1,c1,r2,c2)|| lbishop(a,r1,c1,r2,c2)) flag =1;
          return flag;
       }

void Lmoveing (char a[10][10],int r1,int c1,int r2,int c2){
            if(a[r2][c2] != ' ')  DEAD[d++]= a[r2][c2];
            a[r2][c2]= a[r1][c1];
            a[r1][c1]= ' ';
            turn++;
            if(CASTLE) { a[1][8]=' '; a[1][6]='R'; CASTLE=0;  }
            if(castle){ a[8][8]=' '; a[8][6]='r';  castle=0;  }
  }

