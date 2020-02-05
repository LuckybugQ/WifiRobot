/*
版权声明：
深圳市小二极客科技（小R科技）旗下：WIFI机器人网·机器人创意工作室版权所有www.wifi-robots.com
您可以任意修改本程序，并应用于自行研发的智能小车机器人及其他电子产品上，但是禁止用于商业牟利。
小R科技保留付诸法律起诉侵权的权利！
* 文件名称：Ultrasonic
* 文件标识：
* 摘    要：WiFi机器人智能小车控制
* 描    述：超声波模块文件
* 当前版本：Arduino UNO R3 V2.5
* 作    者：BY WIFI机器人网·机器人创意工作室
* 完成日期：2017年6月
*/

/*
*********************************************************************************************************
** 函数名称 ：Get_Distence
** 函数功能 ：检测超声波的测得的距离值并返回(单位cm)
** 入口参数 ：无
** 出口参数 ：Ldistance
*********************************************************************************************************
*/ 
char Get_Distance()//测出距离
{
  digitalWrite(Trig, LOW);   // 让超声波发射低电压2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // 让超声波发射高电压10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // 维持超声波发射低电压
  float Ldistance = pulseIn(Echo, HIGH,5000);  // 读差相差时间
  Ldistance = Ldistance / 5.8 / 10; // 将时间转为距离距离（单位：公分）
  //Serial.println(Ldistance);      //显示距离
  return Ldistance;
}

/*
*********************************************************************************************************
** 函数名称 ：Send_Distance
** 函数功能 ：向上位机发送超声波数据(数据格式:0XFF,0X03，角度(默认0X00),距离(dis),0XFF)
** 入口参数 ：无
** 出口参数 ：无
*********************************************************************************************************
*/
void Send_Distance()//超声波距离PC端显示
{
  int dis = Get_Distance();
  Sendbyte(0xff);
  Sendbyte(0x03);
  Sendbyte(0x00);
  Sendbyte(dis);
  Sendbyte(0xff);
  delay(1000);
}