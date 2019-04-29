#include <kipr/botball.h>
int rm=0;//right motor
int lm=3;//left motor
int bm=1;
int bs=1500;
int rs=1000;//right motor speed
int ls=1000;//left motor speed
int claw=1;//claw that open and closes
int arm=0;//arm that claw attaches to
int back=3;//arm in the back attached to mini servo
int claw_close=600; //claw commands for puff balls
int claw_open=1600; 
int arm_up=606; //up position for arm
int back_down=1400;//when arm goes down to attach to water unit
int back_up=386; //back arm up 
void counter(int dis);
void starting_position();
void down_slow(int arm_position);
void open_slow(int claw_position);
void close_slow(int claw_position);
int main()
{
    printf("Hello World\n");
    enable_servos();
    shut_down_in(119);
    //starting positions for claws
    starting_position();
    
    //open bacc klaw
    mav(bm,bs);
    msleep(4000);
    ao();
    
	//back dawn to get unit
    set_servo_position(back,back_down);
    msleep(400);
    
    //back to get unit
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(500);
    ao();
    
    //back up till black line in front of start
    while(analog(0) < 3900)
    {
        mav(rm,-rs);
        mav(lm,-ls);
    }
    ao();
    
    msleep(400);
    
    //grab unit
    mav(bm,-bs);
    msleep(3500);
    ao();
    
    //wait
    msleep(500);
    
    //turn around
    mav(rm,rs);
    mav(lm,-ls);
    msleep(1030);
    ao();
    
	//back to allign robot with 1st water
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(3520);
    ao();
    
    //turn to get 1 water
    mav(rm,rs);
    mav(lm,-ls);
    msleep(765);
    ao();
    
    msleep(500);
    
    //forward to get water
    mav(rm,rs);
    mav(lm,ls);
    msleep(2230);
    ao();
    
    //open to get water
    set_servo_position(claw,claw_open);
    msleep(500);
    
    //down to get water
    down_slow(1870);
	msleep(400);
    
    //close to pick up water
     close_slow(600);
    msleep(400);
    
    //back up to put water in
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(650);
    ao();
    
 // up to put water in
    mav(rm,rs);
    mav(lm,ls);
    msleep(500);
    ao();
    
    //turn to put 2nd pile
    mav(rm,-rs);
    mav(lm,ls);
    msleep(482);
    ao(); 
    
    //open to get water
    set_servo_position(claw,claw_open);
    msleep(500);
    
	//forward for 2nd pile
    mav(rm,rs);
    mav(lm,ls);
    msleep(1630);
    ao();
    
    //close to pick up water
    close_slow(600);
    msleep(400);
    
    //backup a bit to not hit pipe
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(500);
    ao();
    
    //let go of thing
    mav(bm,bs);
    msleep(5000);
    ao();
    
    //lift back up
    set_servo_position(back,back_up);
    msleep(500);
    
    //pickk up balls
    set_servo_position(arm,1024);
    msleep(400);
    
    
    //turn to put water in unit
    mav(rm,-rs);
    mav(lm,ls);
    msleep(1806);
    ao();
    
    //forward a bit 
    mav(rm,rs);
    mav(lm,ls);
    msleep(80);
    ao();
    
    //open to put water in unit
    open_slow(1300);
    msleep(500);
    ao();
    
    msleep(500);
    
    //forward to not get stuck
    mav(rm,rs);
    mav(lm,-ls);
    msleep(30);
    ao();
    
    //turn around to get unit after deposit
    mav(rm,rs);
    mav(lm,-ls);
    msleep(1600);
    ao();
    
    //open a bit to get unit and not git stuck after 2nd pile
    mav(bm,bs);
    msleep(1000);
    ao();
    
    //forward to not hit unit
    mav(rm,rs);
    mav(lm,ls);
    msleep(50);
    ao();
   
    //back down to get unit
    set_servo_position(back,back_down);
    msleep(400);
    
    //close to get unit
    mav(bm,-bs);
    msleep(6000);
    ao();
    
    //go back a bit
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(300);
    ao();
    
    //arm down for next pile
    down_slow(1655);
    msleep(400);
    
    //open claw
    set_servo_position(claw,claw_open);
    msleep(500);
    
    //turn right for other pile
    mav(rm,-rs);
    mav(lm,ls);
    msleep(150);
    ao();
   
    //forward for next pile
    mav(rm,rs);
    mav(lm,ls);
    msleep(2600);
    ao();
    
    //arm down for 3rd pile
    down_slow(1870);
	msleep(400);
    
    //forward for 3rd pile
    mav(rm,rs);
    mav(lm,ls);
    msleep(1500);
    ao();
    
    //close on puff balls
    close_slow(600);
    msleep(400);
    
    //back up to get water in unit
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(1250);
    ao();
    
     //let go of thing
    mav(bm,bs);
    msleep(5000);
    ao();
    
    //lift back up
    set_servo_position(back,back_up);
    msleep(500);
    
    //close a bit to not hit building
    mav(bm,-bs);
    msleep(2000);
    ao();
    
    //pickk up balls
    set_servo_position(arm,1024);
    msleep(400);
    
    
    //turn to put water in unit
    mav(rm,-rs);
    mav(lm,ls);
    msleep(1780);
    ao();
    
    //forward a bit 
    mav(rm,rs);
    mav(lm,ls);
    msleep(70);
    ao();
    
    //open to put water in unit
    open_slow(1300);
    msleep(500);
    
   msleep(500);
    
    //turn around to get unit after deposit
    mav(rm,rs);
    mav(lm,-ls);
    msleep(1750);
    ao();
    
    //forward a bit to not git stuk
    mav(rm,rs);
    mav(lm,ls);
    msleep(60);
    ao();
    
    //open a bit after dat
    mav(bm,bs);
    msleep(2000);
    ao();
    
    //back down to get unit
    set_servo_position(back,back_down);
    msleep(400);
    
    //close to get unit
    mav(bm,-bs);
    msleep(5000);
    ao();
    
    //backup to allign for 4th pile
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(800);
    ao();
    
    //arm down to get 4th pile
    down_slow(1655);
	msleep(400);
    
    //open to get pile
    set_servo_position(claw,claw_open);
    msleep(400);
    
    //turn a bit to get 4th pile
    mav(rm,rs);
    mav(lm,-ls);
    msleep(40);
    ao();
    
    //forward to allign
    mav(rm,rs);
    mav(lm,ls);
    msleep(600);
    ao();
    
    //forward for piles
    mav(rm,rs);
    mav(lm,ls);
    msleep(900);
    ao();
    
    down_slow(1877);
	msleep(400);
    
    
    mav(rm,rs);
    mav(lm,ls);
    msleep(1800);
    ao();
    
    //close to pick up water
    close_slow(580);
    msleep(400);
    
    //let go of thing
    mav(bm,bs);
    msleep(5000);
    ao();
    
    //lift back up
    set_servo_position(back,back_up);
    msleep(400);
    
    //close a bit to not hit building
    mav(bm,-bs);
    msleep(2000);
    ao();
    
    //pickk up balls
    set_servo_position(arm,1024);
    msleep(400);
    
    
    //turn to put water in unit
    mav(rm,-rs);
    mav(lm,ls);
    msleep(1780);
    ao();
    
    //forward a bit 
    mav(rm,rs);
    mav(lm,ls);
    msleep(70);
    ao();
    
    //open to put water in unit
    open_slow(1300);
    msleep(500);
    
   msleep(500);
    
    //turn around to get unit after deposit
    mav(rm,rs);
    mav(lm,-ls);
    msleep(1750);
    ao();
    
    //open to get unit after 4th pile
    mav(bm,bs);
    msleep(3000);
    ao();
    
    //forward a bit to not git stuk
    mav(rm,rs);
    mav(lm,ls);
    msleep(60);
    ao();
    
    //back down to get unit
    set_servo_position(back,back_down);
    msleep(400);
    
    //close to get unit
    mav(bm,-bs);
    msleep(5200);
    ao();
    
    //front claw up to not hit building when going to zone
    set_servo_position(arm,arm_up);
    msleep(400);
    
    //turn to go to unit
    mav(rm,1499);
    mav(lm,-1499);
    msleep(1200);
    ao();
    
    //to zone
    mav(rm,-1499);
    mav(lm,-1499);
    msleep(5000);
    ao();
    
    disable_servos();
    return 0;
}
//starting positions 
void starting_position()
{
    set_servo_position(arm,arm_up);
    msleep(400);
    
    set_servo_position(back,back_up);
    msleep(400);
    
    set_servo_position(claw,claw_close);
    msleep(400);
    
    msleep(500);
    
}
// certain distance in ticks/cm
void counter(int dis)
{
    clear_motor_position_counter(rm);
    while(get_motor_position_counter(rm)<dis)
    {
    mav(rm,1150);
    mav(lm,ls);
    ao();
    }
}
void down_slow(int arm_position)
{

    while(get_servo_position(arm) < arm_position)

    {
        set_servo_position(arm,get_servo_position(arm) +10);
        msleep(15);
    }
	}
void open_slow(int claw_position)
{
    
    while(get_servo_position(claw) < claw_position)

    {
        set_servo_position(claw,get_servo_position(claw) +10);
        msleep(15);
    }
	}
void close_slow(int claw_position)
{

    while(get_servo_position(claw) > claw_position)

    {
        set_servo_position(claw,get_servo_position(claw) -10);
        msleep(15);
    }
    
	}
