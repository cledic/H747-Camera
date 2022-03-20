/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_filex.c
  * @author  MCD Application Team
  * @brief   FileX applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_filex.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "ux_api.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

FX_FILE my_file;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/**
  * @brief  Application FileX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT MX_FileX_Init(VOID *memory_ptr)
{
  UINT ret = FX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

  /* USER CODE BEGIN MX_FileX_MEM_POOL */
  (void)byte_pool;
  /* USER CODE END MX_FileX_MEM_POOL */

  /* USER CODE BEGIN MX_FileX_Init */

  /* Initialize FileX.  */
  fx_system_initialize();

  /* USER CODE END MX_FileX_Init */
  return ret;
}

/* USER CODE BEGIN 1 */

/**
  * @brief  Application Write File process.
  * @param  none
  * @retval UINT status
  */
UINT App_File_Close(FX_MEDIA *fx_media)
{
  UINT status;

  /* Close File after Finish writing */
  status = fx_file_close(&my_file);

  /* Check the file close status. */
  if (status != FX_SUCCESS)
  {
    /* Error writing to a file. */
    status = FX_IO_ERROR;
  }

  /* Flush media.  */
  status =  fx_media_flush(fx_media);

  /* Check the file close status. */
  if (status != FX_SUCCESS)
  {
    /* Error writing to a file. */
    status = FX_IO_ERROR;
  }
  return status ;
}

/**
* @brief  Application Create File process.
* @param  none
* @retval FX_FILE * opened file
*/
FX_FILE * App_File_Create(FX_MEDIA *fx_media)
{
  UINT status;

  /* Create a file called CAMERA.RAW in the root directory. */
  status = fx_file_create(fx_media, "CAMERA.RAW");

  /* Check the create status. */
  if ((status == FX_SUCCESS) || (status == FX_ALREADY_CREATED))
  {
    /* File Creation success. */
    status = FX_SUCCESS;
  }
  else
  {
    /* File Creation Fail. */
	  printf("File creation failed : %d\r\n", status);
	  return NULL;
  }

  /* Open "CAMERA.RAW" file. */
  status = fx_file_open(fx_media, &my_file, "CAMERA.RAW", FX_OPEN_FOR_WRITE);

  /* Check the file open status. */
  if (status != FX_SUCCESS)
  {
    /* Error opening file, break the loop. */
	  printf("File open failed : %d\r\n", status);
    return NULL;
  }

  /* Seek the start of File*/
  fx_file_seek(&my_file, 0);

  return &my_file;
}

/* USER CODE END 1 */
