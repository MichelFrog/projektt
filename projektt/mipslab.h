/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
void display_image(uint8_t array[]);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
void display_game(uint8_t array[]);
void move(int x, int y, int array[],int arrayLength);
//Enemies
void spawn_enemy(int x, int y, int array[], int arrayLength);  //new
void spawn_enemies(int gamecount); //spawn enemies in relation to gamecount(updated in func,#409) NEW W.I.P
void move_enemies(int number_of_enemies);
void test(void);
void set_coordinate(int x, int y, uint8_t array[], int setClr);
uint8_t spi_send_recv(uint8_t data);

void clear_game(void);
void clr_game(void);
extern int ship_placementY;
extern int ship_placementX;
void start_pos(void);
//Projectiles
void create_projectile(int startX, int startY, int faction);
void move_projectiles(void);
void hitbox(int projectiles[], int enemyship[]); //new W.I.P

void update_game(uint8_t  arr[]);
void paint_map(void);
void move_map(void);
void update_map(void);
void paint_life(void);




//counters
extern int commandCount;
extern int projectileCount;
extern int createProjectileCount;
extern int mapCount;
extern int buttonCount;
extern int secCount;
extern int createMapCount;
extern int randCount;
extern int gamecount;       //count for spawning enemies NEW
extern int number_of_enemies;
extern int TIE1_alive;
extern int TIE2_alive;
extern int TIE3_alive;
extern int TIE4_alive;
extern int TIE5_alive;
extern int pause;


void run_projectile(void);
void run_control(void);
void run_map(void);
//void run_pause(void);

/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );


/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern uint8_t game[128*4];
extern uint8_t map[144];
extern uint8_t projectiles[128*4];
extern uint8_t font[128*8];
extern uint8_t life[10];
extern int ship[22];
extern int TIE1[32]; //new
extern int TIE2[32]; //new
extern int TIE3[32]; //new
extern int TIE4[32]; //ne
extern int TIE5[32]; //new
extern uint8_t cloud_1[13];
extern uint8_t cloud_2[7];
extern uint8_t cloud_3[12];
extern uint8_t cloud_4[];
extern int lives;

//void start_random_counter(void);
int random(int mod);


//Structures
typedef struct Enemy  {     //W.I.P
int TIE1[32]; //new
int TIE2[32];
int TIE3[32];
int TIE4[32];
};





/* Declare bitmap array containing icon */
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
int getbtns(void);
int getsw(void);
void enable_interrupt(void);

//Initializing
void set_init(void);
