
#include "IRremote.h"

//***********************定义电机腳位*************************

int MotorLeft1 = 11;
int MotorLeft2 = 6;
int MotorRight1 = 3;
int MotorRight2 = 5;
int counter = 0;

const int irReceiverPin = 2; //红外线接收器 接在 pin 2

char val;
//***********************设定红外遥控码值 IRcode*************************
long IRfront = 0x00FF629D;       //前进
long IRback =  0x00FFA857;        //后退
long IRturnright = 0x00FFC23D;  //右转
long IRturnleft = 0x00FF22DD;    //左转
long IRstop = 0x00FF02FD;       //停止





IRrecv irrecv(irReceiverPin);  // 红外接收对象
decode_results results;       // 红外解码结果


//********************************************************************(SETUP)
void setup()
{
  Serial.begin(9600);
  pinMode(MotorRight1, OUTPUT);  // 
  pinMode(MotorRight2, OUTPUT);  // 
  pinMode(MotorLeft1,  OUTPUT);  // 
  pinMode(MotorLeft2,  OUTPUT);  // 
  irrecv.enableIRIn();     // 启动红外线解码
  
  Serial.println("-----------------");
}
//******************************************************************(Void)
void advance(int a) // 前进
{
  Serial.println("advance");
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
  delay(a * 100);
}
void right(int b) //右转 单轮
{
  Serial.println("right");
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, LOW);
  delay(b * 100);
}
void left(int c) //左转 轮
{
  Serial.println("left");
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, LOW);
  delay(c * 100);
}
void turnR(int d) //右转 双轮
{
  Serial.println("turnR");
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
  delay(d * 100);
}
void turnL(int e) //左转 双轮
{
  Serial.println("turnL");
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
  delay(e * 100);
}
void stopp(int f) //停止
{
  Serial.println("stopp");
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, LOW);
  delay(f * 100);
}
void back(int g) //后退
{
  Serial.println("back");
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);;
  delay(g * 100);
}
//******************************************************************************(LOOP)
void loop()
{

  //**********************正常遥控模式
  if (irrecv.decode(&results))
  { // 解碼成功，收到码值

    Serial.println(results.value, HEX);
    /***********************************************************************/
    if (results.value == IRfront)//前进
    {
      advance(10);//前进
    }
    /***********************************************************************/
    if (results.value ==  IRback)//后退
    {
      back(10);//后退
    }
    /***********************************************************************/
    if (results.value == IRturnright)//右转
    {
      right(6); // 右转
    }
    /***********************************************************************/
    if (results.value == IRturnleft)//左转
    {
      left(6); // 左转
    }
    /***********************************************************************/
    if (results.value == IRstop)//停止
    {
      Serial.println("stop");
      digitalWrite(MotorRight1, LOW);
      digitalWrite(MotorRight2, LOW);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorLeft2, LOW);
    }
    

    irrecv.resume();    // 继续接收红外信号
  }
}
