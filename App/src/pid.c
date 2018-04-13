#include "pid.h"


Speed_mode car_mode = LOW_SPEED;
float steer_engine_degree = 0;              //�����ƫת�Ƕȣ������ɸ������Ҹ���
int motor_speed = 0;

void Control_core()
{
	int degree_change_speed = 0;
	int degree_change = 0;

	if (LOW_SPEED == car_mode)
	{
		steer_engine_degree = average_offset*5;
		if (steer_engine_degree > DEGREE_MAX) steer_engine_degree = DEGREE_MAX;
		if (steer_engine_degree < -DEGREE_MAX) steer_engine_degree = -DEGREE_MAX;
		motor_speed = 150;
	}
	
	else if (MIDDLE_SPEED == car_mode)
	{
		if (average_offset < M_QUITE_AREA && average_offset > -M_QUITE_AREA)   //���ƫ���С������ȶ��� ps:�Ժ����ȶ�������������
		{
			steer_engine_degree = average_offset*5;   //�Ժ���Ը��ݵ�����ٶ���ѡ�����ĸ�����������ȣ�
			//steer_engine_degree = average_offset;
		}
		else
		{
			degree_change = average_offset - average_offset_before;

			if (average_offset_before > 0)
			{
				if (degree_change > 0 || 0 == degree_change)
				{
					if (degree_change > M_BACK1)
					{
						degree_change_speed = M_BACK1_SPEED;
						ui_data[1]++;
					}
					else if (degree_change > M_BACK2)
					{
						degree_change_speed = M_BACK2_SPEED;
						ui_data[2]++;
					}
					else
					{
						degree_change_speed = M_BACK_SPEED;
						ui_data[3]++;
					}
					steer_engine_degree += degree_change_speed;
				}
				if (degree_change < 0 && (fabs(average_offset)<M_BUFF_AREA)) steer_engine_degree -= M_BUFF_SPEED;
			}
			else if (average_offset_before < 0)
			{
				if (degree_change < 0 || 0 == degree_change)
				{
					if (degree_change < -M_BACK1)
					{
						degree_change_speed = -M_BACK1_SPEED;
						ui_data[1]++;
					}
					else if(degree_change < -M_BACK2)
					{
						 degree_change_speed = -M_BACK2_SPEED;
						ui_data[2]++;
					}
					else
					{
						degree_change_speed = -M_BACK_SPEED;
						ui_data[3]++;
					}
					steer_engine_degree += degree_change_speed;
				}
				if (degree_change > 0 && (abs(average_offset)<M_BUFF_AREA)) steer_engine_degree += M_BUFF_SPEED;
			}	
		}
		if (steer_engine_degree > DEGREE_MAX) steer_engine_degree = DEGREE_MAX;
		if (steer_engine_degree < -DEGREE_MAX) steer_engine_degree = -DEGREE_MAX;
		motor_speed = 150;
		if(abs(steer_engine_degree)>10) motor_speed = 100;     //�������
	}

	else{}

	//ftm_pwm_duty(FTM0, FTM_CH5, motor_speed);                    //���
	////ftm_pwm_duty(FTM0, FTM_CH5, 0);
	//ftm_pwm_duty(FTM0, FTM_CH6, 380 + steer_engine_degree);
	
}

