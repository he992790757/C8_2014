
#ifndef CONFIG_H
#define CONFIG_H

#include "DrvGPIO.h"	 
 


#define    	L1	GPC_15//�������
#define		L2	GPC_14//�������
#define    	L3	GPB_8//�������
#define		H1	GPB_14//�������
#define    	H2	GPB_13//�������
#define    	H3	GPA_11//�������

 
// 
// 
//#define		K1_LED  GPC_15//����ָʾ��1
//#define		K2_LED  GPC_14//����ָʾ��2
//#define		K3_LED  GPB_8 //����ָʾ��3
//#define		K4_LED  GPB_14//����ָʾ��4
//#define		K5_LED  GPB_13//����ָʾ��5
//#define		K6_LED  GPB_12//����ָʾ��6
//#define		K7_LED  GPA_11//����ָʾ��7
//#define		K8_LED  GPA_10//����ָʾ��8 	

#define		K7	GPA_10//���ڶ�������������
#define		K6	GPA_9//���ڶ����������ĸ� 
#define		K5	GPB_7// ���ڶ��������ڶ���
#define		K4	GPB_6// ���ڶ���������һ�� 
#define		K3	GPB_5//���ڶ����������߸�
#define		K2	GPB_4//���ڶ�������������
#define		K1	GPA_8//���ڶ������������






///**************���̶���*************/ 

//#define		K5	GPA_10
//#define		K6	GPC_1	//	GPA_9
//#define		K2	GPC_0	//GPA_8
//#define		K7	GPB_4//���ڶ�������������
//#define		K3	GPB_5//���ڶ����������߸�
//#define		K8	GPB_6// ���ڶ���������һ�� 
//#define		K4	GPB_7// ���ڶ��������ڶ���
//#define		K9  GPB_12//
//#define		K1  GPA_11//
 

/************����LED����IO**********/
#define    	TOP_W       	GPA_0   //��850����
#define    	TOP_IR850      	GPA_2   //��940����
#define    	TOP_IR940      	GPA_1   //���׹�
#define    	LEFT_W      	GPC_7   //��׹�
#define 	RIGHT_UV    	GPA_4  	// GPB_2
#define    	LEFT_UV         GPA_3   //�װ׹�  
#define     BOT_W       	GPA_5   //ǰ�ϵ�	
#define    	BOT_IR     		GPA_6   //�׺���
#define    	LEFT_IR850     	GPA_7   //�����

#define 	C3_PWR 			GPA_15  //C608

#define 	RIGHT_LASER		    GPB_9	//����
#define    	LEFT_BLUE       	GPE_5 //�������
#define    	LEFT_W_SMAL     	GPB_11  //��׹�С�Ӵ�
#define 	TOP_LEFT_UV         GPC_11	// 

#define 	RIGHT_W 		GPA_13 //
#define     RIGHT_IR850	    GPA_14             //   
#define    	RIGHT_IR770     GPA_10  //��׹�

#define 	BOT_UV              GPB_10	// 
#define    	TOP_IR940_SMAL     GPA_9    //��׹�
#define    	TOP_W_SMAL         GPC_2  //��׹�


//δ����

#define    	LEFT_OnAxis        GPC_11  //ͬ���






//#define 	JG 			GPA_15
//#define    	TEST_LED    GPB_9  
/***************4639*****************/
#define    	A1      	GPC_8 
#define    	A0      	GPC_9  
#define    	EN       	GPC_10 
/***************IRCUT*****************/
#define 	CUT_A1 		GPC_0
#define 	CUT_A2 		 GPC_1

#define 	CUT_B1 		GPE_11//GPE_5 
#define 	CUT_B2 		GPE_11//GPB_11
//#define		CUT_C1 		GPB_3
//#define 	CUT_C2 		GPB_2


#define		DSP_INIT_PIN  GPB_3	  ///////-----------------/////////////////////


#endif





