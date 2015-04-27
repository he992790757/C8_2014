
#define __KEYDISPOSE1

#include "Keydispose1.h"
#include "Keydispose.h"
#include "ucos_ii.h"
#include "stdint.h"
#include "global.h"
#include "KeyScan.h"
#include "performance.h"
#include "Led.h"
#include "config.h"
#include "communication.h" 
#include "V6MDebug.h"
#include "Adjustir.h"


#ifdef C9_2011C_SAM

void  SensorChange()
{
	//sensor1�л���sensor2
	
	//1��¼֮ǰ�İ���ֵ
	if(System.Dsp.Sensor == SENSOR1)
	{  System.Dsp.Sensor = SENSOR2 ;
       switch(System.Key.OldValue)
       {
            case 2: if(System.Led.Statu == TOP_WHITE_ON) 
                    {
                       Top_W_Small_On();  
			        }System.Dsp.Sensor = SENSOR1	;break ; 
				   		
			case 3: Top_Ir940_Small_On();System.Dsp.Sensor = SENSOR1	; break ;
			case 4: TopLeft_Uv_On() ;System.Dsp.Sensor = SENSOR1	; break ;
			case 5: System.Dsp.Sensor = SENSOR1	; break; 
			case 6: System.Dsp.Sensor = SENSOR1	; break; 
			case 7: System.Dsp.Sensor = SENSOR1	;return ;
		    case 8: System.Dsp.Sensor = SENSOR1	;return ;
			case 9: System.Dsp.Sensor = SENSOR1	;return ; 
			default:System.Dsp.Sensor = SENSOR1	;break ; 	
	   }
       
	}
	else if(System.Dsp.Sensor == SENSOR2)
	{  System.Dsp.Sensor = SENSOR1 ;
       switch(System.Key.OldValue)
       {    
            case 2: if(System.Led.Statu == T_W_SMAL_ON) 
                    {
                       Top_W_On();   
			        }System.Dsp.Sensor = SENSOR2 ;break ; 
				   		
			case 3: Top_IR850_On() ; System.Dsp.Sensor = SENSOR2 ; break ;
			case 4: Double_UV_On();System.Dsp.Sensor = SENSOR2 ;   break ;
			case 5: System.Dsp.Sensor = SENSOR2 ; break; 
			case 6: System.Dsp.Sensor = SENSOR2 ;break; 
			case 7: System.Dsp.Sensor = SENSOR2 ;return ;
		    case 8: System.Dsp.Sensor = SENSOR2 ;return ;
			case 9: System.Dsp.Sensor = SENSOR2 ;return ; 
			default:System.Dsp.Sensor = SENSOR2	;break ; 		
	   }  
	}
}


void KeyInfoDispose()
{
	
	
		//������⴦��
	System.Key.Value = KeyScan() ;
	System.Key.Keylong = &Keylong ; 
	if(!System.Key.Value)
		{
			// �������߲��� 
			if(System.Key.NoKeyTime == 180)
				{
					if(System.Dsp.Mode == CHECK_MODE||VIEW_MODE)
						{
							System.Dsp.Mode = SLEEP_MODE ; 
							Light_Init() ; 
						//	SHOW_SCREEN(0xE8,  " "); 
						}
				}
			else if ((System.Key.NoKeyTime == 300)&&(System.Dsp.Mode == SLEEP_MODE))
				{
				 	System.Dsp.Mode = SLEEP_MODE ;
				  //	SHOW_SCREEN(0xE8,  "Power Saving Mode"); 
						SHOW_SCREENW(0xE8, WcharToChar(L"�ڵ�ģʽ") );
					OSTimeDly(200);			   //������
				}
		}
	else
		{
		//	GR_DBG_PRINTF("keylong is  %d OK it is  %d\n\n",*System.Key.Keylong,Keylong);
			// �����Ѳ���
			System.Key.NoKeyTime = 0 ;
			if(System.Dsp.Mode == SLEEP_MODE)
				{	
					CheckMode(); 
					OSTimeDly(200) ; 
				}
//			//����������
			switch(System.Key.Value)
				{

				case 1 ://ȫ��--�ֲ� �����������608
					{
						if(*System.Key.Keylong)
						{
							if((System.Dsp.Mode ==CHECK_MODE)
								||(System.Dsp.Mode ==PCCAM_MODE))
							{						
								if(System.Led.Statu == C608_PWR_ON)
								{
									CheckMode(); 
								}
								else
								{
									C608_On() ;
								}
	
							}
						}												  
						else
						{
							if(System.Led.Statu == C608_PWR_ON)
							{
								CheckMode(); 
							} else
						    {
								if((System.Dsp.Mode ==CHECK_MODE)
								   ||(System.Dsp.Mode ==PCCAM_MODE))
								{
                                   // SensorChange();
                                 	if(System.Dsp.Sensor == SENSOR1)
                                	{  System.Dsp.Sensor = SENSOR2 ;
                                       switch(System.Key.OldValue)
                                       {
                                            case 2: if(System.Led.Statu == TOP_WHITE_ON) 
                                                    {
                                                       Top_W_Small_On();  
                                			        }System.Dsp.Sensor = SENSOR1	;break ; 
                                				   		
                                			case 3: Top_Ir940_Small_On();System.Dsp.Sensor = SENSOR1	; break ;
                                			case 4: TopLeft_Uv_On() ;System.Dsp.Sensor = SENSOR1	; break ;
                                		//	case 5: System.Dsp.Sensor = SENSOR1	; break; 
                                		//	case 6: System.Dsp.Sensor = SENSOR1	; break; 
                                			case 7: System.Dsp.Sensor = SENSOR1	;return ;
                                		    case 8: System.Dsp.Sensor = SENSOR1	;return ;
                                			case 9: System.Dsp.Sensor = SENSOR1	;return ; 
                                			default: System.Dsp.Sensor = SENSOR1	;break ; 	
                                	   }															//  pFuc();
                                       
                                	}
                                	else if(System.Dsp.Sensor == SENSOR2)
                                	{  System.Dsp.Sensor = SENSOR1 ;
                                       switch(System.Key.OldValue)
                                       {    
                                            case 2: if(System.Led.Statu == T_W_SMAL_ON) 
                                                    {
                                                       Top_W_On();   
                                			        }System.Dsp.Sensor = SENSOR2 ;break ; 
                                				   		
                                			case 3: Top_IR850_On() ; System.Dsp.Sensor = SENSOR2 ; break ;
                                			case 4: Double_UV_On();System.Dsp.Sensor = SENSOR2 ;   break ;
                                		//	case 5: System.Dsp.Sensor = SENSOR2 ; break; 
                                		//	case 6: System.Dsp.Sensor = SENSOR2 ;break; 
                                			case 7: {System.Dsp.Sensor = SENSOR2 ;return ;}
                                		    case 8: System.Dsp.Sensor = SENSOR2 ;return ;
                                			case 9: System.Dsp.Sensor = SENSOR2 ;return ; 
                                			default:System.Dsp.Sensor = SENSOR2	;break ; //	pFuc();	
                                	   }  
                                	}
//									
									if(System.Dsp.Sensor == SENSOR1)
									{
										Sensor2(); 	
										Check_View_Zoom(X0);						
									}
									else
									{
										Sensor1() ; 
									}
								}
							}
						}
					}break ; 
					case 2 ://ȫ��������׹⣬����׹⡢
					        //�ֲ���ͬ��⣬��׹⣬����⣨�෽��
						{
							if(System.Dsp.Sensor == SENSOR1 )
							{
								if((System.Dsp.Mode ==CHECK_MODE)
    								||(System.Dsp.Mode ==PCCAM_MODE))
    								{	
                                       if(System.Led.Statu == TOP_WHITE_ON) 
                                       {
                                           Left_W_On() ;
									   }else
									   {
                                          Top_W_On(); 
									   }
    								}								
							}
							else if(System.Dsp.Sensor == SENSOR2)
							{
								if((System.Dsp.Mode ==CHECK_MODE)
    								||(System.Dsp.Mode ==PCCAM_MODE))
    								{	
                                       if(System.Led.Statu == T_W_SMAL_ON) 
                                       {
                                          Left_W_On() ;
									   }
									   else
									   {
                                           Top_W_Small_On();
									   }
    								}								
							}
							else
							{
                                 CheckMode(); 
							}							
						}break ; 
//
					case 3 ://����850������940�����ڶ��Σ�������850��940����ѭ��
			
						{										
							if(*System.Key.Keylong)// ����У������
								{
									if(System.Dsp.Mode == CHECK_MODE)
										{
										//	PriorExposure();
										//	ExProsure() ;
										}
								}
							else
								{
            						if(System.Dsp.Sensor == SENSOR1 )
            						{
    									if((System.Dsp.Mode ==CHECK_MODE)
    										||(System.Dsp.Mode ==PCCAM_MODE))
    										{
    											if(System.Led.Statu == TOP_IR850_ON)
    												{
    													Top_IR940_On() ; 
    												}
//    											else if(System.Led.Statu == TOP_IR940_ON)
//    												{
//    													Top_IR850_940_Blink();
//    												}
    											else
    												{
    													Top_IR850_On() ; 
    												}
    										}
            						}
									else if(System.Dsp.Sensor == SENSOR2 )
									{
     									if((System.Dsp.Mode ==CHECK_MODE)
    										||(System.Dsp.Mode ==PCCAM_MODE))
    										{
//    											if(System.Led.Statu == RIGHT_IR770_ON)
//    												{
    													Top_Ir940_Small_On();
//    												}
//												else
//    												{
//    													Right_IR770_On(); 
//    												}
    										}                                       
									}
								}
						}break ; 

					case 4 ://ȫ�������Ϲ�365�������Ϲ�254
					        //�ֲ���UV-LED�����⣨�Ŵ�3X)
						{  						
							if(*System.Key.Keylong)// ����У������
								{
									
								}
							else
								{
    								if(System.Dsp.Sensor == SENSOR1 )
    							    {
    									if((System.Dsp.Mode ==CHECK_MODE)
    										||(System.Dsp.Mode ==PCCAM_MODE))
    										{
												
                                                Double_UV_On(); 
    										}
    								}
        							if(System.Dsp.Sensor == SENSOR2 )
        							{
    									if((System.Dsp.Mode ==CHECK_MODE)
    										||(System.Dsp.Mode ==PCCAM_MODE))
    										{
                                                TopLeft_Uv_On();
    									    }
        							}
								}					
						}break ; 
 
					
					case 5 ://͸��׹⡢͸���⣬ѭ��
						{
								if((System.Dsp.Mode ==CHECK_MODE)
									||(System.Dsp.Mode ==PCCAM_MODE))
								{
									
									if(System.Led.Statu == LEFT_W_ON)
									{
										Right_W_On(); 
									}
									else if(System.Led.Statu == RIGHT_W_ON)
									{
                                        Left_IR850_On();
									}
									else if(System.Led.Statu == LEFT_IR850_ON)
									{
                                        Right_IR850_On();
									}
									else
									{
										Left_W_On();
									}
								}						 
										
						}break ; 

					case 6 ://����⡢�����ѭ��	
						{											
						        if((System.Dsp.Mode ==CHECK_MODE)
									||(System.Dsp.Mode ==PCCAM_MODE))
								{
									if(System.Led.Statu == BOT_W_ON)
									{
										Bot_IR_On(); 
									}
									else
									{
										Bot_W_On() ; 
									}
								}		                        
						}break ;
					case 7 ://�ֲ��ӳ����׹⡢���⣨����Ƭ�л���
						{
							if(*System.Key.Keylong)// ����У������
							{
							}
							else								
							{
								if((System.Dsp.Mode ==CHECK_MODE)
									||(System.Dsp.Mode ==PCCAM_MODE))
								{
									  Sensor2(); 
									  Check_View_Zoom(X0);
									  if(System.Key.OldValue != 7)
									  {
                                         Bot_Uv_On( );
										 break ;//return ;
									  }
  
									  if(System.Led.Statu == BOT_UV_ON)
									  {
                                         TopLeft_Uv_On(); 
									  }	
									  else  if(System.Led.Statu == TOP_LEFT_UV_ON)
									  {
                                         Left_IR850_On();
									  }								  
									  else
									  {
                                         Bot_Uv_On( );
									  }
								}
							}					
												
						}break ; 
					
					case 8 ://a)	M��Ԥ�����ط�ģʽ�л�
						{

						        if((System.Dsp.Mode ==CHECK_MODE)
									||(System.Dsp.Mode ==PCCAM_MODE))
								{
									  Sensor2(); 
									  Check_View_Zoom(X1)	;

									  if(System.Key.OldValue != 8)
									  {
                                         Top_W_On();
										 break;
									  }									  
//									  if(System.Led.Statu == TOP_WHITE_ON)
//									  {
//                                         Right_IR770_On(); 
//									  }
//									  else 
									  if(System.Led.Statu == TOP_WHITE_ON)
									  {
                                         TopLeft_Uv_On();
									  }									  
									  else if(System.Led.Statu == TOP_LEFT_UV_ON)
									  {
                                         Left_IR850_On();
									  }	
									  else if(System.Led.Statu == LEFT_IR850_ON)
									  {
                                         Left_W_On(); 
									  }										  
									  else
									  {
                                         Top_W_On(); 
									  }
								}			
						}break ; 
					case 9 :/*Ԥ��ģʽ�£��޲�����
                            �ط�ģʽ�£�ǰ��ҳ
                            ��Ƭ�Ŵ�ģʽ�£���΢��
                            */
                            {	
								if(*System.Key.Keylong) 
								{
									 if(System.Dsp.Mode ==CHECK_MODE)
									 {
										PccamMode(); 
									 }
									 else   if(System.Dsp.Mode ==PCCAM_MODE)
									 {
									 	 CheckMode(); 
									 }
								}
								else
								{
    						        if((System.Dsp.Mode ==CHECK_MODE)
    									||(System.Dsp.Mode ==PCCAM_MODE))
    								{
    									  Sensor2(); 
										  Check_View_Zoom(X0)	;
    									  if(System.Key.OldValue != 9)
    									  {
                                             TopLeft_Uv_On();
											 break ;
    									  }
										  
    									  if(System.Led.Statu == TOP_LEFT_UV_ON)
    									  {
                                             Right_Laser_On();
    									  }
    									  else if(System.Led.Statu == RIGHT_LASER_ON)
    									  {
                                             Left_Blue_On();
    									  }									  									  
    									  else
    									  {
                                             TopLeft_Uv_On();
    									  }
    								} 
								}
						    }break ; 							
					default : break ; 
				}
			    if(System.Key.Value !=1 )System.Key.OldValue = System.Key.Value ; 
		}
}



#endif 
