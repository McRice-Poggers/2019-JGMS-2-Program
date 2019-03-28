#include <kipr/botball.h>
int rm=0;//right motor
int lm=3;//left motor
int rs=1000;//right motor speed
int ls=1000;//left motor speed
int claw=1;//claw that open and closes
int arm=0;//arm that claw attaches to
int back=3;//arm in the back attached to mini servo
int claw_close=1200; //claw commands for puff balls
int claw_open=2000; 
int arm_up=915; //up position for arm
int back_down=1000;//when arm goes down to attach to water unit
int back_up=111; //back arm up 
void counter(int dis);
void starting_position();
void down_slow(int arm_position);
int main()
{
    printf("Hello World\n");
    enable_servos();
    //starting position
    starting_position(); 
    
    //back up out of start box and get unit
    mav(rm,-rs);
    mav(lm,-ls);
    msleep(718);
    
   //back mini servo down to get unit
    set_servo_position(back,back_down);
    msleep(400);
    
  //back up till black line
    while(analog(0) < 1500)
    {
        mav(rm,-rs);
        mav(lm,-ls);
    }
    ao();
    
    //turn after grabbing unit
    mav(rm,-rs);
    mav(lm,ls);
    msleep(1300);
    
    
    

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
}
// certain distance in ticks/cm
void counter(int dis)
{
    clear_motor_position_counter(rm);
    while(get_motor_position_counter(rm)<dis)
    {
    mav(rm,rs);
    mav(lm,ls);
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
