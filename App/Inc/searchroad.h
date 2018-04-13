#ifndef _searchroad_H_
#define _searchroad_H_

#include "common.h"
#include "include.h"

#define	LINE_NUM         60      //��Ҫɨ�������
#define BLANK_LINE_NUM   0       //��ʼʱ�����ʼ�ļ���
#define OFF_CENTER       5       //��һ��ɨ��ƫ����һ�����ĵ����ظ���
#define DEGREE_OF_ERROR  5       //��������֮��������߲�ֵ������ֵʱ�����ݽ��ᱻ����
#define CLOSE_TO_EDGE    5       //�����߽ӽ�ͼ��ı�Ե������ɨ��
#define ROAD_BEGIN       65      //����ROAD_BEGIN��ROAD_END֮�����δɨ�赽�����ж���ת��
#define ROAD_END         45
#define SHARP_TURN_LEFT  1       //����ת��
#define SHARP_TURN_RIGHT 2
#define TURN_DEGREE      13      //
#define REFLECT_LIGHT_ERROR  4   //���ڷ��⵼�µ�����ƫ�����ֵʱ��֮�������������
#define REFLECT_LIGHT_AREA   30  //��ⷴ�������ӵ�40�п�ʼ
#define CAMERA_HARDWARE_ERROR  5          //����ͷ��ƫ�����ߵ��µ�Ӳ��ƫ��,��ƫΪ��
#define TRAPEZOID_CORRECT   0.3     //���ν���

extern uint8 sharp_turn;                  //�������ת�仹����ת��
extern uint8 img[][CAMERA_W];     //��Ž�ѹ��ͼ�������
extern uint8 imgbuff[];        //����洢����ͼ�������
extern float average_offset;
extern float average_offset_before;
extern  void Search_line_init();
extern  void Search_line();
extern float Find_slope();

#endif