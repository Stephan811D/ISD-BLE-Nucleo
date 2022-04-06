/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : App/custom_app.c
 * Description        : Custom Example Application (Server)
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  /* DHT11 */
  uint8_t               Send_Notification_Status;
  uint8_t               Recv_Notification_Status;
  uint8_t               Clock_Notification_Status;
  uint8_t               Round_Notification_Status;
  uint8_t               Value_Notification_Status;
  /* USER CODE BEGIN CUSTOM_APP_Context_t */

  /* USER CODE END CUSTOM_APP_Context_t */

  uint16_t              ConnectionHandle;
} Custom_App_Context_t;

/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/**
 * START of Section BLE_APP_CONTEXT
 */

PLACE_IN_SECTION("BLE_APP_CONTEXT") static Custom_App_Context_t Custom_App_Context;

/**
 * END of Section BLE_APP_CONTEXT
 */

/* USER CODE BEGIN PV */
uint8_t UpdateCharData[247];
uint8_t NotifyCharData[247];

uint8_t SecureReadData;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
  /* DHT11 */
static void Custom_Send_Update_Char(void);
static void Custom_Send_Send_Notification(void);
static void Custom_Recv_Update_Char(void);
static void Custom_Recv_Send_Notification(void);
static void Custom_Clock_Update_Char(void);
static void Custom_Clock_Send_Notification(void);
static void Custom_Round_Update_Char(void);
static void Custom_Round_Send_Notification(void);
static void Custom_Value_Update_Char(void);
static void Custom_Value_Send_Notification(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_1 */

  /* USER CODE END CUSTOM_STM_App_Notification_1 */
  switch(pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* USER CODE END CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

  /* DHT11 */
    case CUSTOM_STM_SEND_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SEND_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_SEND_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_SEND_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SEND_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_SEND_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_RECV_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_RECV_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_RECV_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_RECV_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_RECV_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_RECV_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_CLOCK_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_CLOCK_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_CLOCK_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_CLOCK_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_CLOCK_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_CLOCK_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_ROUND_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_ROUND_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_ROUND_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_ROUND_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_ROUND_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_ROUND_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_VALUE_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_VALUE_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_VALUE_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_VALUE_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_VALUE_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_VALUE_NOTIFY_DISABLED_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_STM_App_Notification_default */

      /* USER CODE END CUSTOM_STM_App_Notification_default */
      break;
  }
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_2 */

  /* USER CODE END CUSTOM_STM_App_Notification_2 */
  return;
}

void Custom_APP_Notification(Custom_App_ConnHandle_Not_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_APP_Notification_1 */

  /* USER CODE END CUSTOM_APP_Notification_1 */

  switch(pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_APP_Notification_Custom_Evt_Opcode */

    /* USER CODE END P2PS_CUSTOM_Notification_Custom_Evt_Opcode */
    case CUSTOM_CONN_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_CONN_HANDLE_EVT */

      /* USER CODE END CUSTOM_CONN_HANDLE_EVT */
      break;

    case CUSTOM_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_DISCON_HANDLE_EVT */

      /* USER CODE END CUSTOM_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_APP_Notification_default */

      /* USER CODE END CUSTOM_APP_Notification_default */
      break;
  }

  /* USER CODE BEGIN CUSTOM_APP_Notification_2 */

  /* USER CODE END CUSTOM_APP_Notification_2 */

  return;
}

void Custom_APP_Init(void)
{
  /* USER CODE BEGIN CUSTOM_APP_Init */

  /* USER CODE END CUSTOM_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

  /* DHT11 */
void Custom_Send_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_SEND, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Send_UC*/

  /* USER CODE END Send_UC*/
  return;
}

void Custom_Send_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Send_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_SEND, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Send_NS*/

    /* USER CODE END Send_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

void Custom_Recv_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_RECV, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Recv_UC*/

  /* USER CODE END Recv_UC*/
  return;
}

void Custom_Recv_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Recv_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_RECV, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Recv_NS*/

    /* USER CODE END Recv_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

void Custom_Clock_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_CLOCK, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Clock_UC*/

  /* USER CODE END Clock_UC*/
  return;
}

void Custom_Clock_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Clock_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_CLOCK, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Clock_NS*/

    /* USER CODE END Clock_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

void Custom_Round_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_ROUND, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Round_UC*/

  /* USER CODE END Round_UC*/
  return;
}

void Custom_Round_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Round_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_ROUND, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Round_NS*/

    /* USER CODE END Round_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

void Custom_Value_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_VALUE, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Value_UC*/

  /* USER CODE END Value_UC*/
  return;
}

void Custom_Value_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Value_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_VALUE, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Value_NS*/

    /* USER CODE END Value_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/

/* USER CODE END FD_LOCAL_FUNCTIONS*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
