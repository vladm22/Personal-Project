
#include <main.h>
#include <stdio.h>
#include <string.h>
#include "hc12.h"

/*
 * Fonction pour initialiser la structure du module HC-12
 * Ne retourne rien
 */
void hc12_init(HC12_t *DataStruct)
{
	for (uint8_t i = 0; i < Frame_Lenght; i++)
	{
		DataStruct->Uart_rx_buffer[i] = 0;
		DataStruct->Frame_To_Send[i] = 0;
		DataStruct->Frame_Read[i] = 0;
	}

	DataStruct->Uart_rx_data = 0;
	DataStruct->Uart_rx_cnt = 0;
	DataStruct->Uart_rx_flag = 0;

	DataStruct->Frame_To_Send[Frame_Start_Index] = Start_Frame_Byte;
	DataStruct->Frame_To_Send[Frame_End_Index] = End_Frame_Byte;

	DataStruct->Current_Drone_Mode = Mode_Initialisation;
	DataStruct->Last_Drone_Mode = Mode_Initialisation;

	DataStruct->Dep_Target_X = 0;
	DataStruct->Dep_Target_Y = 0;
	DataStruct->Dep_Target_Z = 0;
	DataStruct->Dep_Target_V = 0;

	DataStruct->GPS_X = 1;
	DataStruct->GPS_Y = 1;
	DataStruct->GPS_Z = 1;

	DataStruct->V_bat = 12000;
}

/*
 * Fonction appelé par l'interruption pour sauvegarder l'octet recu via l'uart
 * Ne retourne rien
 */
void hc12_uart_new_byte_management(HC12_t *DataStruct)
{
	DataStruct->Uart_rx_buffer[DataStruct->Uart_rx_cnt] = DataStruct->Uart_rx_data;
	DataStruct->Uart_rx_cnt++;

	if (DataStruct->Uart_rx_cnt == Frame_Lenght)
	{
		DataStruct->Uart_rx_cnt = 0;
		DataStruct->Uart_rx_flag = 1;
	}
}

/*
 * Fonction qui gere la reception des trames et la reponse vers le master
 * Ne retourne rien
 */
void hc12_manage_new_recived_frames(UART_HandleTypeDef *huart_debug, UART_HandleTypeDef *huart_hc12, HC12_t *DataStruct)
{
	if(DataStruct->Uart_rx_flag == 1)
	{
		if(hc12_read_master_frame(DataStruct) == 1)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);  //RED
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);  //GREEN
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);   //BLUE

			hc12_print_read_frame(huart_debug, DataStruct);

			if(hc12_update_answare_frame(DataStruct) == 1)
			{
			  hc12_print_drone_data(huart_debug, DataStruct);

			  if(HAL_UART_Transmit(huart_hc12, DataStruct->Frame_To_Send, Frame_Lenght, HAL_MAX_DELAY) == HAL_OK)
			  {
				  hc12_print_send_frame(huart_debug, DataStruct);
			  }
			  else
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);      //RED
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);    //GREEN
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);   //BLUE

				  hc12_error_msg(huart_debug);
			  }
			}
		}

		hc12_reset_frames(DataStruct);
		DataStruct->Uart_rx_flag = 0;
	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);    //RED
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);    //GREEN
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);   //BLUE
}

/*
 * Fonction qui verifie si la trame recu est correcte
 * retourne 1 si trame ok, si non 0
 */
uint8_t hc12_read_master_frame(HC12_t *DataStruct)
{
  if(DataStruct->Uart_rx_buffer[Frame_Start_Index] == Start_Frame_Byte)
  {
	  if(DataStruct->Uart_rx_buffer[Frame_End_Index] == End_Frame_Byte)
	  {
		  if(DataStruct->Uart_rx_buffer[Frame_ID_Index] == Drone_ID)
		  {
			  if(DataStruct->Uart_rx_buffer[Frame_Checksum_Index] == hc12_calcul_read_frame_checksum(DataStruct))
			  {
				  //save_new_received_frame
				  for (uint8_t i = 0; i < Frame_Lenght; i++)
				  {
					  DataStruct->Frame_Read[i] = DataStruct->Uart_rx_buffer[i];
				  }

				  return 1;
			  }
			  else
			  {
				  return 0;
			  }
		  }
		  else
		  {
			  return 0;
		  }
	  }
	  else
	  {
		  return 0;
	  }
  }
  else
  {
	  return 0;
  }
}

/*
 * Fonction met a jour le contenu de la trame a envoyer au master
 * retourne 1 si trame d'envoie ok, si non 0
 */
uint8_t hc12_update_answare_frame(HC12_t *DataStruct)
{
	DataStruct->Frame_To_Send[Frame_Start_Index] = Start_Frame_Byte;
	DataStruct->Frame_To_Send[Frame_End_Index] = End_Frame_Byte;
	DataStruct->Frame_To_Send[Frame_ID_Index] = Drone_ID;

	if(DataStruct->Frame_Read[Frame_Service_Index] == Read_Mode)
	{
		hc12_service_B1_mode_ordre(DataStruct);
		return 1;
	}
	else if(DataStruct->Frame_Read[Frame_Service_Index] == Answare_Mode)
	{
		hc12_service_A1_mode_requete(DataStruct);
		return 1;
	}
	else if(DataStruct->Frame_Read[Frame_Service_Index] == Read_Deplacement)
	{
		hc12_service_B2_dep_ordre(DataStruct);
		return 1;
	}
	else if(DataStruct->Frame_Read[Frame_Service_Index] == Answare_Deplacement)
	{
		hc12_service_A2_dep_requete(DataStruct);
		return 1;
	}
	else if(DataStruct->Frame_Read[Frame_Service_Index] == Answare_GPS)
	{
		hc12_service_A3_gps_requete(DataStruct);
		return 1;
	}
	else if(DataStruct->Frame_Read[Frame_Service_Index] == Answare_Batterie)
	{
		hc12_service_A4_batterie_requete(DataStruct);
		return 1;
	}

	return 0;
}

/*
 * Fonction qui calcul le checksum de la trame recu
 * retourne le checksum
 */
uint8_t hc12_calcul_read_frame_checksum(HC12_t *DataStruct)
{
  uint16_t checksum = 0;

  for (uint8_t i = Frame_ID_Index; i < Frame_Checksum_Index; i++)
  {
    checksum = checksum + DataStruct->Uart_rx_buffer[i]*i;
  }

  checksum = checksum & 0xff;

  return (uint8_t)checksum;
}

/*
 * Fonction qui calcul le checksum de la trame a envoyer
 * retourne le checksum
 */
uint8_t hc12_calcul_send_frame_checksum(HC12_t *DataStruct)
{
  uint16_t checksum = 0;

  for (uint8_t i = Frame_ID_Index; i < Frame_Checksum_Index; i++)
  {
    checksum = checksum + DataStruct->Frame_To_Send[i]*i;
  }

  checksum = checksum & 0xff;

  return (uint8_t)checksum;
}

/*
 * Fonction qui efface le contenu de la trame a envoyer au master car deja envoyé
 * Ne retourne rien
 */
void hc12_reset_frames(HC12_t *DataStruct)
{
	for (uint8_t i = 0; i < Frame_Lenght; i++)
	{
		DataStruct->Frame_To_Send[i] = 0;
		DataStruct->Frame_Read[i] = 0;
	}
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_A1_mode_requete
 * Ne retourne rien
 */
void hc12_service_A1_mode_requete(HC12_t *DataStruct)
{
	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF1;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 1] = DataStruct->Last_Drone_Mode;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 3] = DataStruct->Current_Drone_Mode;
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_B1_mode_ordre
 * Ne retourne rien
 */
void hc12_service_B1_mode_ordre(HC12_t *DataStruct)
{
	DataStruct->Last_Drone_Mode = DataStruct->Current_Drone_Mode;
	DataStruct->Current_Drone_Mode = DataStruct->Frame_Read[Frame_Data_Begin_Index + 1];

	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF1;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 1] = DataStruct->Last_Drone_Mode;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 3] = DataStruct->Current_Drone_Mode;
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_A2_dep_requete
 * Ne retourne rien
 */
void hc12_service_A2_dep_requete(HC12_t *DataStruct)
{
	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF2;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index] = hc12_get_high_byte(DataStruct->Dep_Target_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 1] = hc12_get_low_byte(DataStruct->Dep_Target_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 2] = hc12_get_high_byte(DataStruct->Dep_Target_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 3] = hc12_get_low_byte(DataStruct->Dep_Target_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 4] = hc12_get_high_byte(DataStruct->Dep_Target_Z);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 5] = hc12_get_low_byte(DataStruct->Dep_Target_Z);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 6] = hc12_get_high_byte(DataStruct->Dep_Target_V);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 7] = hc12_get_low_byte(DataStruct->Dep_Target_V);
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_B2_dep_ordre
 * Ne retourne rien
 */
void hc12_service_B2_dep_ordre(HC12_t *DataStruct)
{
	DataStruct->Dep_Target_X = hc12_get_value(DataStruct->Frame_Read[Frame_Data_Begin_Index],DataStruct->Frame_Read[Frame_Data_Begin_Index + 1]);
	DataStruct->Dep_Target_Y = hc12_get_value(DataStruct->Frame_Read[Frame_Data_Begin_Index + 2],DataStruct->Frame_Read[Frame_Data_Begin_Index + 3]);
	DataStruct->Dep_Target_Z = hc12_get_value(DataStruct->Frame_Read[Frame_Data_Begin_Index + 4],DataStruct->Frame_Read[Frame_Data_Begin_Index + 5]);
	DataStruct->Dep_Target_V = hc12_get_value(DataStruct->Frame_Read[Frame_Data_Begin_Index + 6],DataStruct->Frame_Read[Frame_Data_Begin_Index + 7]);

	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF2;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index] = hc12_get_high_byte(DataStruct->Dep_Target_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 1] = hc12_get_low_byte(DataStruct->Dep_Target_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 2] = hc12_get_high_byte(DataStruct->Dep_Target_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 3] = hc12_get_low_byte(DataStruct->Dep_Target_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 4] = hc12_get_high_byte(DataStruct->Dep_Target_Z);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 5] = hc12_get_low_byte(DataStruct->Dep_Target_Z);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 6] = hc12_get_high_byte(DataStruct->Dep_Target_V);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 7] = hc12_get_low_byte(DataStruct->Dep_Target_V);
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_A3_gps_requete
 * Ne retourne rien
 */
void hc12_service_A3_gps_requete(HC12_t *DataStruct)
{
	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF3;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index] = hc12_get_high_byte(DataStruct->GPS_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 1] = hc12_get_low_byte(DataStruct->GPS_X);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 3] = hc12_get_high_byte(DataStruct->GPS_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 4] = hc12_get_low_byte(DataStruct->GPS_Y);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 6] = hc12_get_high_byte(DataStruct->GPS_Z);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 7] = hc12_get_low_byte(DataStruct->GPS_Z);
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui remplie la trame de reponse vers le master pour le service_A4_batterie_requete
 * Ne retourne rien
 */
void hc12_service_A4_batterie_requete(HC12_t *DataStruct)
{
	DataStruct->Frame_To_Send[Frame_Service_Index] = 0xF4;
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 4] = hc12_get_high_byte(DataStruct->V_bat);
	DataStruct->Frame_To_Send[Frame_Data_Begin_Index + 5] = hc12_get_low_byte(DataStruct->V_bat);
	DataStruct->Frame_To_Send[Frame_Checksum_Index] = hc12_calcul_send_frame_checksum(DataStruct);
}

/*
 * Fonction qui prend un entier de 16 bits et retourne les 8 bits de poids fort
 * Retourne les 8 bits de poids fort
 */
uint8_t hc12_get_high_byte(int16_t value)
{
  return (uint8_t)((value & 0xFF00) >> 8);
}

/*
 * Fonction qui prend un entier de 16 bits et retourne les 8 bits de poids faible
 * Retourne les 8 bits de poids faible
 */
uint8_t hc12_get_low_byte(int16_t value)
{
  return (uint8_t)((value & 0x00FF));
}

/*
 * Fonction qui prend deux entier de 8 bits (Hight et low bits) et retourne un entier de 16 bits
 * Retourne l'entier de 16 bits
 */
int16_t hc12_get_value(uint8_t high, uint8_t low)
{
  return (int16_t)(high << 8) + low;
}

/*
 * Fonction qui affiche les données du drone
 * Retourne rien
 */
void hc12_print_drone_data(UART_HandleTypeDef *huartx, HC12_t *DataStruct)
{
    char buffer[128];
    int len = snprintf(buffer, sizeof(buffer),
        "-------------\nCurrent Mode: %x\r\nLast Mode: %x\r\nDep X: %d, Y: %d, Z: %d, V: %d\r\nGPS X: %d, Y: %d, Z: %d\r\nV_bat: %d\r\n------------- \n ",
        DataStruct->Current_Drone_Mode,
        DataStruct->Last_Drone_Mode,
        DataStruct->Dep_Target_X, DataStruct->Dep_Target_Y, DataStruct->Dep_Target_Z, DataStruct->Dep_Target_V,
        DataStruct->GPS_X, DataStruct->GPS_Y, DataStruct->GPS_Z,
        DataStruct->V_bat);

    HAL_UART_Transmit(huartx, (uint8_t*)buffer, len, HAL_MAX_DELAY);
}

/*
 * Fonction qui affiche la trame recu du master
 * Retourne rien
 */
void hc12_print_read_frame(UART_HandleTypeDef *huartx, HC12_t *DataStruct)
{
	char buffer[100];
	uint8_t offset = sprintf(buffer, "%s :", "Read Frame");
    for (size_t i = 0; i < Frame_Lenght; i++)
    {
        offset += sprintf(buffer + offset, " %x", DataStruct->Frame_Read[i]);
    }
    sprintf(buffer + offset, "\r\n");

    HAL_UART_Transmit(huartx, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

/*
 * Fonction qui affiche la trame envoyé au master
 * Retourne rien
 */
void hc12_print_send_frame(UART_HandleTypeDef *huartx, HC12_t *DataStruct)
{
	char buffer[100];
	uint8_t offset = sprintf(buffer, "%s :", "Send Frame");
    for (size_t i = 0; i < Frame_Lenght; i++)
    {
        offset += sprintf(buffer + offset, " %x", DataStruct->Frame_To_Send[i]);
    }
    sprintf(buffer + offset, "\r\n\n");

    HAL_UART_Transmit(huartx, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

/*
 * Fonction qui affiche un message d'erreur
 * Retourne rien
 */
void hc12_error_msg (UART_HandleTypeDef *huartx)
{
	char buffer[100];
	sprintf(buffer, "Error\r\n");
	HAL_UART_Transmit(huartx, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}
