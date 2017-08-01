/*
TRIS da linea di comando (Command Line Tic-Tac-Toe)
Author: Edoardo M. F. Tullio "tuzzo"
Release date:
Version: 0.8
Note: For any problem with ncurses/curses libraries see "readme.txt" file
License:
*/

#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include <termios.h>
#include <unistd.h>
#define N 4

char cas[]={'1','2','3','4','5','6','7','8','9'};
char play1[20],play2[20],hh[30];

typedef struct score{
	char nome[10];
	int punteggio;
}score;

score punti[100];

int mygetch( ) {
	  struct termios oldt, newt;
	  int ch;
	  tcgetattr( STDIN_FILENO, &oldt );
	  newt = oldt;
	  newt.c_lflag &= ~( ICANON | ECHO );
	  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	  ch = getchar();
	  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	  return ch;
}

void cancl(int a, int b){
	move(a,b);
	deleteln();
	move(a,b);
	insertln();
}

void stampa_logo(){
	printf(" _________   _______   ____  ______\n");
	printf("|         | |       |  |  | |    __|\n");
	printf("|___   ___| |  |_|  |  |  | |	|__\n");
	printf("    | |     |	__  /  |  | |___   |\n");
	printf("    | |     |   |\\  \\  |  |  ___|  |\n");
	printf("    |_|     |___| \\__| |__| |______|\n\n");
}

void gio(){
	printf("Inserire nome giocatore 1 ->\t");
	scanf("%s",play1);
	printf("Inserire nome giocatore 2 ->\t");
	scanf("%s",play2);
	if((strcmp(play1,play2))==0){
		printf("\nI giocatori non possono avere lo stesso nome!\n\n");
		sleep(2);
		gio();
	}
}

void stampa_griglia(char cas[]){
	mvprintw((LINES/2)-3,(COLS/2)-8,"    %c|    %c|   %c",cas[0],cas[1],cas[2]);
	mvprintw((LINES/2)-2,(COLS/2)-8," ____|_____|____");
	mvprintw((LINES/2)-1,(COLS/2)-8,"    %c|    %c|   %c",cas[3],cas[4],cas[5]);
	mvprintw((LINES/2),(COLS/2)-8," ____|_____|____");
	mvprintw((LINES/2)+1,(COLS/2)-8,"    %c|    %c|   %c",cas[6],cas[7],cas[8]);
	mvprintw((LINES/2)+2,(COLS/2)-8,"     |     |");
}

int contr_cas(int a, char cas[], int b){
	if(cas[a]=='X' || cas[a]=='O'){
		mvprintw((LINES/2)+5,(COLS/2)-20,"Spiacente, la casella è già occupata!");
		b=1;
	}
	return b;
}

int contr_x(int a, char cas[]){
	if(cas[0]=='X' && cas[1]=='X' && cas[2]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[3]=='X' && cas[4]=='X' && cas[5]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[6]=='X' && cas[7]=='X' && cas[8]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[0]=='X' && cas[3]=='X' && cas[6]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[1]=='X' && cas[4]=='X' && cas[7]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[2]=='X' && cas[5]=='X' && cas[8]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[0]=='X' && cas[4]=='X' && cas[8]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	if(cas[2]=='X' && cas[4]=='X' && cas[6]=='X'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play1);
		a=5;
	}
	return a;
}

int contr_o(int a, char cas[]){
	if(cas[0]=='O' && cas[1]=='O' && cas[2]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[3]=='O' && cas[4]=='O' && cas[5]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[6]=='O' && cas[7]=='O' && cas[8]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[0]=='O' && cas[3]=='O' && cas[6]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[1]=='O' && cas[4]=='O' && cas[7]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[2]=='O' && cas[5]=='O' && cas[8]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[0]=='O' && cas[4]=='O' && cas[8]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	if(cas[2]=='O' && cas[0]=='O' && cas[6]=='O'){
		cancl((LINES/2)+5,0);
		mvprintw((LINES/2)+5,(COLS/2)-25,"\tTRIS!\n\t-----Il vincitore è %s!\n",play2);
		a=5;
	}
	return a;
}

int inserisci_cas(char player[], int dis){
	char segno,t;
	int c,z=0;
	if((strcmp(player,play1))==0)
		segno='X';
	else
		segno='O';
	mvscanw(LINES-1, 32+dis,"%d",  &c);
	if((c<1)||(c>9)){
		mvprintw((LINES/2)+5,(COLS/2)-25,"Mi spiace %s, devi scegliere una casella della griglia!",player);
		inserisci_cas(player,dis);
	}
	cancl((LINES/2)+5,0);
	cancl((LINES/2)+6,0);
	t=contr_cas(c-1,cas,t);
	if(t==1){
		refresh();
		stampa_griglia(cas);
		inserisci_cas(player,dis);
	}
	else{
		cas[c-1]=segno;
		refresh();
		stampa_griglia(cas);
	}
	if((strcmp(player,play1))==0)
		z=contr_x(z,cas);
	if((strcmp(player,play2))==0)
		z=contr_o(z,cas);
	return z;
}

void ultima(int a){
	int ul=0,f=0,ctr=0;
	cancl(LINES-1,0);
	mvprintw(LINES-1,0,"%s, scegli l'ultima casella -> ",play1);
	mvscanw(LINES-1, 32+a,"%d",  &ul);
	cancl((LINES/2)+5,0);
	if((ul<1)||(ul>9)){
		mvprintw((LINES/2)+5,(COLS/2)-25,"Mi spiace %s, devi scegliere una casella della griglia!",play1);
		ultima(a);
	}
	cancl((LINES/2)+5,0);
	cancl((LINES/2)+6,0);
	f=contr_cas(ul-1,cas,f);
	if(f==1){
		refresh();
		stampa_griglia(cas);
		ultima(a);
	}
	else{
		cas[ul-1]='X';
		refresh();
		stampa_griglia(cas);
		ctr=contr_x(ctr,cas);
		if(ctr==5){}
		else
			mvprintw((LINES/2)+5,(COLS/2)-25,"-----Pareggio!\n\n");
	}
}

void giocare()	{
	int p=0,j=0,ch=0,q=0;
	gio();
	j=strlen(play1);
	q=strlen(play2);
	initscr();
	mvprintw(0,0,"%s",play1);
	mvprintw(0,COLS-8,"%s",play2);
	//mvprintw(LINES-2,COLS-9,"Mosse");
	//mvprintw(LINES-1,COLS-11,"rimanenti: ");
	stampa_griglia(cas);
	while(p<N){
		cancl(LINES-1,0);
		mvprintw(LINES-1,0,"%s, inserisci numero casella ->", play1);
		ch=inserisci_cas(play1,j);
		if(ch==5)
			break;
		cancl(LINES-1,0);
		mvprintw(LINES-1,0,"%s, inserisci numero casella ->", play2);
		ch=inserisci_cas(play2,q);
		if(ch==5)
			break;
		p++;
	}
	if(ch!=5){
		ultima(j);
		
	}
}

void high(){
	FILE *fp;
	char *res;
	fp=fopen("highscore.txt","r");
	if(fp){
		while(1){
			res=fgets(hh,30,fp);
			if(res==NULL)
				break;
			printf("%s",hh);
		}
		fclose(fp);
	}
	else
		printf("\nErrore durante la lettura del file!\n\n");
}

/*int numero_l(){
	FILE *fp;
	int ch, numb=0;
	fp=fopen("highscore.txt","r");
	do{
		ch = fgetc(myfile);
    		if(ch == '\n')
    			numb++;
	} while (ch != EOF);
	if(ch != '\n' && numb != 0) 
    		numb++;
	fclose(fp);
	return numb;
}*/

/*void mod_hh(){
	FILE *fp;
	char temp;
	int i,n;
	n=numero_l();
	fp=fopen("highscore.txt","r+");
	for(i=0;i<l-1;i++){
		temp=fscanf(fp,"%s",&punti[i].nome);
		temp=fscanf(fp,"%d",&punti[i].punteggio);
	}
}*/

void come(){
	printf("\nLa modalità di gioco è semplicissima: verrà mostrata una griglia con 9 caselle numerate in cui dovranno essere posizionati i simboli di ogni giocatore che sono X e O.\n\n Ad ogni turno verrà chiesto ad un giocatore per volta il numero della casella in cui si vuole inserire il simbolo e ad ogni inserimento verrà controllata la presenza di un Tris.\n\n Il Tris porta alla vittoria del giocatore che lo esegue, ovvero devono esserci 3 suoi simboli affiancati e le combinazioni dei 3 simboli possono avvenire in tutte le direzioni: orizzontale, verticale ed anche in obliquo.\n\nDetto questo, DIVERTITEVI!\n\n");
}

int main(){
	int i=0,t=0,g=0;
	stampa_logo();
	printf("Premere un tasto qualsiasi per continuare\n");
	g=mygetch();
	printf("\n-----Selezionare una opzione-----\n\n\t(G)iocare\n\t(H)ighscore\n\t(I)struzioni\n\n");
	g=mygetch();
	tolower(g);
	switch(g){
		case('g'):
		giocare();
		break;
		case('G'):
		giocare();
		break;
		case('h'):
		high();
		break;
		case('H'):
		high();
		break;
		case('I'):
		come();
		break;
		case('i'):
		come();
		break;
	}
	getch();
	endwin();
}
